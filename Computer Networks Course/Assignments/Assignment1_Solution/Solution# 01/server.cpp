#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <fstream>
using namespace std;

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    char buffer[1024];
    ofstream logFile("attendance_log.txt", ios::app); // file to record attendance

    // 1. Create socket (UDP)
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket < 0) {
        cout << "Error creating socket." << endl;
        return -1;
    }
    cout << "Server socket created successfully." << endl;

    // 2. Set server address info
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind the socket to port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cout << "Bind failed." << endl;
        return -1;
    }
    cout << "Server is running and waiting for client data..." << endl;

    int clientCount = 0;
    addr_size = sizeof(clientAddr);

    // 4. Handle up to 5 clients (simple loop)
    while (clientCount < 5) {
        memset(buffer, 0, sizeof(buffer));
        recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &addr_size);

        cout << "\nData received from client " << clientCount + 1 << endl;
        cout << "-----------------------------------" << endl;
        cout << buffer << endl;

        // log the data into a file
        logFile << "Client " << clientCount + 1 << ": " << buffer << endl;

        // Example response creation
        string data(buffer);
        string name, location, temp, service;
        // very simple (manual) parsing just for demo, assumes data order
        // Name: Sana, Time: 9:00, Location: 2nd floor, Temp: 26, Service: meeting room
        size_t namePos = data.find("Name:");
        size_t locPos = data.find("Location:");
        size_t tempPos = data.find("Temp:");
        size_t servPos = data.find("Service:");

        if (namePos != string::npos && locPos != string::npos &&
            tempPos != string::npos && servPos != string::npos) {
            name = data.substr(namePos + 5, locPos - (namePos + 5));
            location = data.substr(locPos + 9, tempPos - (locPos + 9));
            temp = data.substr(tempPos + 5, servPos - (tempPos + 5));
            service = data.substr(servPos + 8);
        }

        string reply = "Details noted: " + service + ", temp " + temp +
                       " from " + name + " at " + location;

        sendto(serverSocket, reply.c_str(), reply.size(), 0,
               (struct sockaddr*)&clientAddr, addr_size);

        cout << "Reply sent to client.\n";
        clientCount++;
    }

    cout << "\nMax 5 clients served. Closing server..." << endl;
    logFile.close();
    close(serverSocket);
    return 0;
}
