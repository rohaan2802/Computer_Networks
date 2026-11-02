/*
 * client.c
 * Simple client for the Concurrent Spell Checker Server
 *
 * Compile:
 *   gcc client.c -o client
 *
 * Run:
 *   ./client 127.0.0.1
 *
 * Then type sentences and press Enter. Type "exit" to close the client session.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <server-ip>\n", argv[0]);
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

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sock);
        return 1;
    }

    printf("Connected to %s:%d\n", server_ip, PORT);
    printf("Type sentences and press Enter. Type 'exit' to quit.\n");

    char line[1024];
    char recvbuf[BUFFER_SIZE];

    while (1) {
        printf("\nEnter sentence: ");
        if (!fgets(line, sizeof(line), stdin)) break;

        // Remove trailing newline
        size_t len = strlen(line);
        if (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r')) line[len-1] = '\0';

        if (send(sock, line, strlen(line), 0) < 0) {
            perror("send");
            break;
        }

        if (strcmp(line, "exit") == 0) {
            printf("Sent exit, closing client.\n");
            break;
        }

        // Wait for response
        ssize_t n = recv(sock, recvbuf, sizeof(recvbuf)-1, 0);
        if (n < 0) {
            perror("recv");
            break;
        } else if (n == 0) {
            printf("Server closed connection.\n");
            break;
        }
        recvbuf[n] = '\0';
        printf("Server response: %s\n", recvbuf);
    }

    close(sock);
    return 0;
}
