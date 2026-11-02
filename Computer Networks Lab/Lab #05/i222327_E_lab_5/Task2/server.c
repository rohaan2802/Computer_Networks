#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024];
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(server_fd, 3);
    printf("Calculator Server listening on port %d...\n", PORT);

    client_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if (client_socket < 0) {
        perror("accept failed");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int valread = read(client_socket, buffer, sizeof(buffer));
        if (valread <= 0) break;  // client disconnected

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Client requested exit. Closing connection.\n");
            break;
        }

        double num1, num2, result;
        char op;
        char response[1024];

        // Parse client input: "num1 num2 op"
        if (sscanf(buffer, "%lf %lf %c", &num1, &num2, &op) != 3) {
            snprintf(response, sizeof(response), "Invalid input format. Use: num1 num2 operator");
        } else {
            switch (op) {
                case '+': result = num1 + num2;
                          snprintf(response, sizeof(response), "Result: %.2lf", result);
                          break;
                case '-': result = num1 - num2;
                          snprintf(response, sizeof(response), "Result: %.2lf", result);
                          break;
                case '*': result = num1 * num2;
                          snprintf(response, sizeof(response), "Result: %.2lf", result);
                          break;
                case '/': if (num2 == 0) {
                              snprintf(response, sizeof(response), "Error: Division by zero");
                          } else {
                              result = num1 / num2;
                              snprintf(response, sizeof(response), "Result: %.2lf", result);
                          }
                          break;
                default: snprintf(response, sizeof(response), "Error: Unknown operator %c", op);
            }
        }

        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
    close(server_fd);
    return 0;
}
