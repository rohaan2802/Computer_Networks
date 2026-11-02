#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024] = {0};

    // 1. Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        cout << "Error creating socket." << endl;
        return -1;
    }

    // 2. Define server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    // 3. Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cout << "Connection failed." << endl;
        return -1;
    }

    // 4. Receive prompt from server
    recv(clientSocket, buffer, 1024, 0);
    cout << buffer;

    // 5. Take user input
    string choice;
    cin >> choice;

    // 6. Send choice to server
    send(clientSocket, choice.c_str(), choice.size(), 0);

    // 7. Wait for result
    memset(buffer, 0, sizeof(buffer));
    recv(clientSocket, buffer, 1024, 0);

    cout << "Result: " << buffer << endl;

    // 8. Close connection
    close(clientSocket);

    return 0;
}
