#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

string findWinner(string c1, string c2) {
    if (c1 == c2)
        return "It's a tie!";
    else if ((c1 == "rock" && c2 == "scissors") ||
             (c1 == "scissors" && c2 == "paper") ||
             (c1 == "paper" && c2 == "rock"))
        return "Player 1 wins!";
    else
        return "Player 2 wins!";
}

int main() {
    int serverSocket, client1, client2;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize;

    // 1. Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        cout << "Error creating socket." << endl;
        return -1;
    }
    cout << "Server socket created." << endl;

    // 2. Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind the socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cout << "Bind failed." << endl;
        return -1;
    }
    cout << "Bind successful." << endl;

    // 4. Listen for connections
    listen(serverSocket, 2);
    cout << "Server is waiting for players..." << endl;

    // 5. Accept first client
    addrSize = sizeof(clientAddr);
    client1 = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
    cout << "Player 1 connected." << endl;

    // 6. Accept second client
    client2 = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
    cout << "Player 2 connected." << endl;

    // 7. Ask for choices
    char buffer1[1024] = {0};
    char buffer2[1024] = {0};

    send(client1, "Enter rock, paper or scissors: ", 33, 0);
    send(client2, "Enter rock, paper or scissors: ", 33, 0);

    recv(client1, buffer1, 1024, 0);
    recv(client2, buffer2, 1024, 0);

    string choice1(buffer1);
    string choice2(buffer2);

    // remove newline if any
    choice1.erase(choice1.find_last_not_of("\n\r") + 1);
    choice2.erase(choice2.find_last_not_of("\n\r") + 1);

    cout << "Player 1 chose: " << choice1 << endl;
    cout << "Player 2 chose: " << choice2 << endl;

    // 8. Determine winner
    string result = findWinner(choice1, choice2);

    // 9. Send result to both players
    send(client1, result.c_str(), result.size(), 0);
    send(client2, result.c_str(), result.size(), 0);

    cout << "Result sent to both players." << endl;

    // 10. Close connections
    close(client1);
    close(client2);
    close(serverSocket);

    cout << "Game ended. Server closed." << endl;

    return 0;
}
