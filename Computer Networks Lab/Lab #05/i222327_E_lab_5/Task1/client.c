#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9000
#define BUFFER_SIZE 256

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(1);
    }
    printf("Connected to server.\n");

    while (1) {
        printf("Enter message (type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline

        // Send message to server
        send(sock, input, strlen(input), 0);

        // Receive reply
        memset(buffer, 0, sizeof(buffer));
        int recv_size = recv(sock, buffer, sizeof(buffer), 0);
        if (recv_size <= 0) {
            printf("Server disconnected.\n");
            break;
        }
        buffer[recv_size] = '\0';
        printf("Server reply: %s\n", buffer);

        // If quit, break loop
        if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    close(sock);
    return 0;
}
