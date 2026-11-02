#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9010
#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[BUF_SIZE];
    socklen_t addr_size;

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(1);
    }

    printf("=== Largest Number Server ===\n");
    printf("Listening on port %d...\n", PORT);

    addr_size = sizeof(clientAddr);

    while (1) {
        // Receive message
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0,
                         (struct sockaddr*)&clientAddr, &addr_size);
        buffer[n] = '\0';

        // Check exit
        if (strcasecmp(buffer, "EXIT") == 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("Received numbers: %s\n", buffer);

        // Parse three numbers
        int a, b, c;
        sscanf(buffer, "%d,%d,%d", &a, &b, &c);

        // Find largest
        int largest = a;
        if (b > largest) largest = b;
        if (c > largest) largest = c;

        // Prepare response
        char response[BUF_SIZE];
        sprintf(response, "Largest number is: %d", largest);

        // Send response
        sendto(sockfd, response, strlen(response), 0,
               (struct sockaddr*)&clientAddr, addr_size);
    }

    close(sockfd);
    return 0;
}
