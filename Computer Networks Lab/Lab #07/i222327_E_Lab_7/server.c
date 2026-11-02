/* server.c
 * Multi-threaded Password Strength Checker Server (beginner-friendly)
 *
 * Compile:
 *   gcc -pthread server.c -o server
 *
 * Run:
 *   ./server
 *
 * The server listens on port 9000. For each client it creates a thread.
 * Each password gets a simulated 5-second processing delay, then the server
 * returns a detailed breakdown (✓/✗ per criterion) and overall strength.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 9000
#define BUFFER_SIZE 1024
#define BACKLOG 10

// Structure to hold password check result (keeps beginner-friendly shape)
struct PasswordResult {
    int score;
    int length_ok;
    int upper_ok;
    int lower_ok;
    int digit_ok;
    int special_ok;
    char strength[16];
};

// Check password against criteria and fill PasswordResult
void check_password(const char *pwd, struct PasswordResult *res) {
    size_t len = strlen(pwd);

    res->length_ok = (len >= 8);
    res->upper_ok = 0;
    res->lower_ok = 0;
    res->digit_ok = 0;
    res->special_ok = 0;

    for (size_t i = 0; i < len; ++i) {
        unsigned char ch = pwd[i];
        if (isupper(ch)) res->upper_ok = 1;
        else if (islower(ch)) res->lower_ok = 1;
        else if (isdigit(ch)) res->digit_ok = 1;
        else if (ispunct(ch) || strchr("@#$!%^&*()-_=+[]{};:'\",.<>/?\\|`~", ch)) res->special_ok = 1;
    }

    res->score = res->length_ok + res->upper_ok + res->lower_ok + res->digit_ok + res->special_ok;

    if (res->score <= 2) strcpy(res->strength, "Weak");
    else if (res->score == 3) strcpy(res->strength, "Medium");
    else strcpy(res->strength, "Strong");
}

// Build a readable result string to send to client
void build_result_text(const struct PasswordResult *r, char *out, size_t out_sz) {
    // Use ✓ and ✗ where supported by terminal; if not, they will appear as characters.
    snprintf(out, out_sz,
        "Password Strength Check Result:\n"
        "--------------------------------\n"
        "Length >= 8 characters : %s\n"
        "Contains uppercase     : %s\n"
        "Contains lowercase     : %s\n"
        "Contains digit         : %s\n"
        "Contains special char  : %s\n"
        "--------------------------------\n"
        "Score: %d / 5\n"
        "Overall Strength: %s\n",
        r->length_ok ? "✓" : "✗",
        r->upper_ok  ? "✓" : "✗",
        r->lower_ok  ? "✓" : "✗",
        r->digit_ok  ? "✓" : "✗",
        r->special_ok? "✓" : "✗",
        r->score,
        r->strength
    );
}

// Thread function: handles one client session
void *client_thread(void *arg) {
    int client_sock = *((int *)arg);
    free(arg);

    struct sockaddr_in peer_addr;
    socklen_t peer_addr_len = sizeof(peer_addr);
    if (getpeername(client_sock, (struct sockaddr *)&peer_addr, &peer_addr_len) == 0) {
        printf("[Thread %lu] Connected to %s:%d\n",
               (unsigned long)pthread_self(),
               inet_ntoa(peer_addr.sin_addr),
               ntohs(peer_addr.sin_port));
    } else {
        printf("[Thread %lu] Connected to client (address unknown)\n", (unsigned long)pthread_self());
    }

    char buffer[BUFFER_SIZE];
    ssize_t n;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = recv(client_sock, buffer, sizeof(buffer)-1, 0);
        if (n < 0) {
            perror("[server] recv");
            break;
        } else if (n == 0) {
            // client closed connection
            printf("[Thread %lu] Client disconnected\n", (unsigned long)pthread_self());
            break;
        }

        // trim newline characters
        while (n > 0 && (buffer[n-1] == '\n' || buffer[n-1] == '\r')) {
            buffer[n-1] = '\0';
            --n;
        }
        buffer[n] = '\0';

        if (strcmp(buffer, "exit") == 0) {
            printf("[Thread %lu] Client sent exit, closing session\n", (unsigned long)pthread_self());
            break;
        }

        printf("[Thread %lu] Received password to check: \"%s\"\n", (unsigned long)pthread_self(), buffer);

        // Artificial processing delay to simulate heavy work
        printf("[Thread %lu] Checking password (5 sec)...\n", (unsigned long)pthread_self());
        sleep(5);

        // Evaluate password
        struct PasswordResult res;
        memset(&res, 0, sizeof(res));
        check_password(buffer, &res);

        // Build human readable result
        char out[BUFFER_SIZE];
        build_result_text(&res, out, sizeof(out));

        // Send the result back to client
        ssize_t sent = send(client_sock, out, strlen(out), 0);
        if (sent < 0) {
            perror("[server] send");
            break;
        }
        printf("[Thread %lu] Result sent to client (score=%d, strength=%s)\n",
               (unsigned long)pthread_self(), res.score, res.strength);
    }

    close(client_sock);
    printf("[Thread %lu] Thread exiting\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Reuse address to avoid "address already in use" during quick restarts
    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        // not fatal; continue
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // listen on all interfaces
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, BACKLOG) < 0) {
        perror("listen");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("[Parent PID %d] Server listening on port %d\n", getpid(), PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            if (errno == EINTR) continue; // interrupted by signal
            perror("accept");
            continue;
        }

        printf("[Parent] New connection from %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Allocate memory to pass client socket to thread
        int *pclient = malloc(sizeof(int));
        if (pclient == NULL) {
            perror("malloc");
            close(client_sock);
            continue;
        }
        *pclient = client_sock;

        pthread_t tid;
        if (pthread_create(&tid, NULL, client_thread, pclient) != 0) {
            perror("pthread_create");
            free(pclient);
            close(client_sock);
            continue;
        }

        // Detach thread: resources will be freed when thread exits
        pthread_detach(tid);
        printf("[Parent] Spawned thread %lu for client\n", (unsigned long)tid);
    }

    close(server_sock);
    return 0;
}
