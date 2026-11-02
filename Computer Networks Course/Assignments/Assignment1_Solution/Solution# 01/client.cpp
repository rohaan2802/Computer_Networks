#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    char buffer[1024];

    // 1. Create UDP socket
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket < 0) {
        cout << "Error creating socket." << endl;
        return -1;
    }

    // 2. Server info
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr_size = sizeof(serverAddr);

    // 3. Get input from user
    string name, time, location, temp, service;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter arrival time: ";
    getline(cin, time);
    cout << "Enter your location (e.g., 2nd floor): ";
    getline(cin, location);
    cout << "Enter preferred temperature (°C): ";
    getline(cin, temp);
    cout << "Enter requested service (e.g., meeting room, coffee, cleaning): ";
    getline(cin, service);

    // 4. Combine data into one message
    string data = "Name:" + name + ", Time:" + time +
                  ", Location:" + location + ", Temp:" + temp +
                  ", Service:" + service;

    // 5. Send to server
    sendto(clientSocket, data.c_str(), data.size(), 0,
           (struct sockaddr*)&serverAddr, addr_size);

    cout << "\nSending data to server..." << endl;

    // 6. Receive reply
    memset(buffer, 0, sizeof(buffer));
    recvfrom(clientSocket, buffer, sizeof(buffer), 0, NULL, NULL);

    cout << "Server reply: " << buffer << endl;

    // 7. Close socket
    close(clientSocket);
    return 0;
}
