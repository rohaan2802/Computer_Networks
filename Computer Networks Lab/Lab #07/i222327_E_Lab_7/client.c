/* client.c
 * Simple TCP client for the password strength server (beginner-friendly).
 *
 * Compile:
 *   gcc client.c -o client
 *
 * Run:
 *   ./client 127.0.0.1
 *
 * Then type passwords and press Enter. Type "exit" to close the client side session.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <server-ip>\n", argv[0]);
        printf("Example: %s 127.0.0.1\n", argv[0]);
        return 1;
    }

    const char *server_ip = argv[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sock);
        return 1;
    }

    printf("Connected to %s:%d\n", server_ip, PORT);
    printf("Type passwords to check. Type 'exit' to quit.\n");

    char pwd[512];
    char recvbuf[BUFFER_SIZE];
    while (1) {
        printf("\nEnter password: ");
        if (!fgets(pwd, sizeof(pwd), stdin)) break;

        // remove newline
        size_t ln = strlen(pwd);
        if (ln > 0 && (pwd[ln-1] == '\n' || pwd[ln-1] == '\r')) pwd[ln-1] = '\0';

        if (send(sock, pwd, strlen(pwd), 0) < 0) {
            perror("send");
            break;
        }

        if (strcmp(pwd, "exit") == 0) {
            printf("Sent exit to server. Closing client socket.\n");
            break;
        }

        // Wait for server reply (server may delay 5 seconds)
        memset(recvbuf, 0, sizeof(recvbuf));
        ssize_t n = recv(sock, recvbuf, sizeof(recvbuf)-1, 0);
        if (n < 0) {
            perror("recv");
            break;
        } else if (n == 0) {
            printf("Server closed connection.\n");
            break;
        }

        recvbuf[n] = '\0';
        printf("\nServer response:\n%s\n", recvbuf);
    }

    close(sock);
    return 0;
}
