#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 9011
#define BUF_SIZE 1024

int isPalindrome(char *word) {
    int i = 0, j = strlen(word) - 1;
    while (i < j) {
        if (tolower(word[i]) != tolower(word[j])) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }
    return 1; // Palindrome
}

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

    printf("=== Palindrome Server ===\n");
    printf("Listening on port %d...\n", PORT);

    addr_size = sizeof(clientAddr);

    while (1) {
        // Receive word
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0,
                         (struct sockaddr*)&clientAddr, &addr_size);
        buffer[n] = '\0';

        // Exit case
        if (strcasecmp(buffer, "EXIT") == 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("Received word: %s\n", buffer);

        // Check palindrome
        char response[BUF_SIZE];
        if (isPalindrome(buffer)) {
            strcpy(response, "Yes, it is a palindrome.");
        } else {
            strcpy(response, "No, it is not a palindrome.");
        }

        // Send response
        sendto(sockfd, response, strlen(response), 0,
               (struct sockaddr*)&clientAddr, addr_size);
    }

    close(sockfd);
    return 0;
}
