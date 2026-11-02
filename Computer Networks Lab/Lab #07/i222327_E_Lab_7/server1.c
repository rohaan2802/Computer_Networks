/*
 * server.c
 * Concurrent Spell Checker Server using fork()
 *
 * Compile:
 *   gcc server.c -o server
 *
 * Run:
 *   ./server
 *
 * The server:
 * - Loads a dictionary from words.txt (one word per line).
 * - Listens on port 8888.
 * - For each new connection, forks a child process to handle that client.
 * - Each child receives sentences, checks each word against the dictionary,
 *   and returns either "All words are correct." or
 *   "Misspelled words: w1, w2, ...".
 * - Child continues until client sends "exit".
 * - Parent continues accepting new clients and reaps children with SIGCHLD handler.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8888
#define BUFFER_SIZE 2048
#define MAX_WORDS 50000
#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "words.txt"

/* ==================== DATA STRUCTURES ==================== */
typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count;
} dictionary_t;

dictionary_t dictionary;

/* Prototype functions */
void sigchld_handler(int sig);
int load_dictionary(const char *filename);
void handle_client(int client_sock);
int check_spelling(const char *word);
void process_sentence(const char *sentence, char *result, size_t result_sz);
void to_lowercase(char *str);
void strip_nonalpha_edges(char *s);

/* SIGCHLD handler to reap zombie children */
void sigchld_handler(int sig) {
    (void)sig;
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

/* Convert string to lowercase (in-place) */
void to_lowercase(char *str) {
    for (; *str; ++str) *str = (char)tolower((unsigned char)*str);
}

/* Remove non-alphabetic characters at the start and end of a token.
   This keeps internal punctuation like "don't" intact (you can change this behavior). */
void strip_nonalpha_edges(char *s) {
    int len = strlen(s);
    int start = 0, end = len - 1;

    while (start <= end && !isalpha((unsigned char)s[start])) start++;
    while (end >= start && !isalpha((unsigned char)s[end])) end--;

    if (start > 0 || end < len - 1) {
        int j = 0;
        for (int i = start; i <= end; ++i) s[j++] = s[i];
        s[j] = '\0';
    }
}

/* Simple linear search in the loaded dictionary.
   Returns 1 if word found, 0 otherwise. */
int check_spelling(const char *word) {
    if (word == NULL || word[0] == '\0') return 1; // treat empty as correct (no word)
    for (int i = 0; i < dictionary.word_count; ++i) {
        if (strcmp(dictionary.words[i], word) == 0) return 1;
    }
    return 0;
}

/* Load dictionary file into memory (lowercased). Returns number of words loaded or -1 on error */
int load_dictionary(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("fopen dictionary");
        return -1;
    }
    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), f) && count < MAX_WORDS) {
        // trim newline and whitespace
        char *p = line;
        while (*p && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) ++p;
        // remove trailing newline/whitespace
        char *end = p + strlen(p) - 1;
        while (end >= p && (*end == '\r' || *end == '\n' || *end == ' ' || *end == '\t')) {
            *end = '\0';
            --end;
        }
        if (strlen(p) == 0) continue;
        // lowercase and copy
        to_lowercase(p);
        strncpy(dictionary.words[count], p, MAX_WORD_LENGTH-1);
        dictionary.words[count][MAX_WORD_LENGTH-1] = '\0';
        count++;
    }
    fclose(f);
    dictionary.word_count = count;
    return count;
}

/* Process a sentence:
   - tokenize by whitespace
   - strip punctuation at edges
   - lowercase
   - check each word
   - write either "All words are correct." or "Misspelled words: ..." to result */
void process_sentence(const char *sentence, char *result, size_t result_sz) {
    char temp[BUFFER_SIZE];
    strncpy(temp, sentence, sizeof(temp)-1);
    temp[sizeof(temp)-1] = '\0';

    char *token;
    char *saveptr = NULL;
    char miss[BUFFER_SIZE];
    miss[0] = '\0';
    int miss_count = 0;

    token = strtok_r(temp, " \t\r\n", &saveptr);
    while (token) {
        char word[MAX_WORD_LENGTH];
        strncpy(word, token, MAX_WORD_LENGTH-1);
        word[MAX_WORD_LENGTH-1] = '\0';

        // remove leading/trailing non-alpha (punctuation, numbers)
        strip_nonalpha_edges(word);

        // convert to lowercase (dictionary is lowercase)
        to_lowercase(word);

        if (word[0] != '\0') {
            if (!check_spelling(word)) {
                if (miss_count > 0) strncat(miss, ", ", sizeof(miss) - strlen(miss) - 1);
                strncat(miss, word, sizeof(miss) - strlen(miss) - 1);
                miss_count++;
            }
        }

        token = strtok_r(NULL, " \t\r\n", &saveptr);
    }

    if (miss_count == 0) {
        snprintf(result, result_sz, "All words are correct.");
    } else {
        snprintf(result, result_sz, "Misspelled words: %s", miss);
    }
}

/* Child process: handle client socket until client sends "exit" or disconnects */
void handle_client(int client_sock) {
    char buf[BUFFER_SIZE];
    ssize_t n;

    printf("[Child %d] Started to handle client (sock=%d)\n", getpid(), client_sock);

    while (1) {
        memset(buf, 0, sizeof(buf));
        n = recv(client_sock, buf, sizeof(buf)-1, 0);
        if (n < 0) {
            perror("[child] recv");
            break;
        } else if (n == 0) {
            printf("[Child %d] Client disconnected\n", getpid());
            break;
        }
        // Trim trailing newline/carriage returns
        while (n > 0 && (buf[n-1] == '\n' || buf[n-1] == '\r')) {
            buf[n-1] = '\0';
            --n;
        }
        buf[n] = '\0';

        if (strcmp(buf, "exit") == 0) {
            printf("[Child %d] Client requested exit\n", getpid());
            break;
        }

        printf("[Child %d] Received sentence: \"%s\"\n", getpid(), buf);

        char result[BUFFER_SIZE];
        memset(result, 0, sizeof(result));
        process_sentence(buf, result, sizeof(result));

        // send response back to client
        ssize_t sent = send(client_sock, result, strlen(result), 0);
        if (sent < 0) {
            perror("[child] send");
            break;
        }
    }

    close(client_sock);
    printf("[Child %d] Exiting\n", getpid());
    exit(0);
}

/* Main: load dictionary, set up listening socket, accept and fork per client */
int main() {
    int server_sock;
    struct sockaddr_in server_addr;

    printf("Loading dictionary from %s ...\n", DICTIONARY_FILE);
    int loaded = load_dictionary(DICTIONARY_FILE);
    if (loaded < 0) {
        fprintf(stderr, "Failed to load dictionary file '%s'. Exiting.\n", DICTIONARY_FILE);
        return 1;
    }
    printf("Loaded %d words into dictionary.\n", dictionary.word_count);

    /* Setup SIGCHLD handler to prevent zombies */
signal(SIGCHLD, sigchld_handler);


    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        return 1;
    }

    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        // not fatal
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; /* listen on all interfaces */
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_sock);
        return 1;
    }

    if (listen(server_sock, 10) < 0) {
        perror("listen");
        close(server_sock);
        return 1;
    }

    printf("[Parent %d] Listening on port %d ...\n", getpid(), PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock < 0) {
            if (errno == EINTR) continue; /* interrupted by signal, retry */
            perror("accept");
            continue;
        }

        printf("[Parent] New connection from %s:%d (sock=%d)\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), client_sock);

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            close(client_sock);
            continue;
        } else if (pid == 0) {
            /* Child process: close listening socket and handle client */
            close(server_sock);
            handle_client(client_sock);
            /* handle_client will exit() when done */
        } else {
            /* Parent process: close client socket (child handles it) and continue */
            close(client_sock);
            printf("[Parent] Forked child %d to handle client\n", pid);
        }
    }

    /* unreachable in normal runs */
    close(server_sock);
    return 0;
}
