#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define BUFFER_SIZE 256

// Function to reverse a string using a loop
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(1);
    }

    // Listen
    listen(server_socket, 5);
    printf("Server listening on port %d...\n", PORT);

    // Accept connection
    client_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len);
    if (client_socket < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(1);
    }
    printf("Client connected!\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline if present
        printf("Message from client: %s\n", buffer);

        // If client says "quit", just echo back and close
        if (strcmp(buffer, "quit") == 0) {
            send(client_socket, buffer, strlen(buffer), 0);
            printf("Client requested termination.\n");
            break;
        }

        // Reverse the message
        reverse_string(buffer);

        // Send back to client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
    close(server_socket);
    return 0;
}
