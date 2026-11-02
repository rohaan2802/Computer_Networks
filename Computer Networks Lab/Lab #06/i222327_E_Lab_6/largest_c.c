#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9010
#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUF_SIZE];
    socklen_t addr_size;

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Configure server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    addr_size = sizeof(serverAddr);

    printf("=== Largest Number Client ===\n");

    while (1) {
        printf("Enter three numbers (comma-separated) or EXIT: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline

        // Send input
        sendto(sockfd, buffer, strlen(buffer), 0,
               (struct sockaddr*)&serverAddr, addr_size);

        // Exit case
        if (strcasecmp(buffer, "EXIT") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Receive server response
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0,
                         (struct sockaddr*)&serverAddr, &addr_size);
        buffer[n] = '\0';

        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
