#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to Calculator Server.\n");

    while (1) {
        char input[1024];
        printf("\nEnter calculation (num1 num2 operator) or 'exit' to quit:\n> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove newline

        send(sock, input, strlen(input), 0);

        if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting...\n");
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        int valread = read(sock, buffer, sizeof(buffer));
        if (valread > 0) {
            printf("Server Response: %s\n", buffer);
        }
    }

    close(sock);
    return 0;
}
