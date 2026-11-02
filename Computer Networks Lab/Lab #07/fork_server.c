#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>    // For waitpid() and WNOHANG
#include <signal.h>      // For signal() and SIGCHLD

#define PORT 9000
#define BUFFER_SIZE 1024

// Signal handler to reap zombie child processes
void sigchld_handler(int sig) {
    // waitpid() with WNOHANG prevents blocking
    // -1 means wait for any child process
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

void handle_child(int client_socket){
    char buffer[BUFFER_SIZE];
    int bytes_read;
    printf("[CHILD PID %d] handling a new client\n", getpid());

    while(1){
        bytes_read= recv(client_socket, &buffer, BUFFER_SIZE-1, 0);
        buffer[bytes_read]= '\0';
        printf("CHILD PID %d] Reacieved: %s", getpid(), buffer);

        send(client_socket, buffer, strlen(buffer), 0 );
        sleep(1);
    }
    printf("CHILD PID %d] client disconnected\n", getpid());
    close(client_socket); 
}
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len= sizeof(client_address);   
    // Set up signal handler for zombie processes
    signal(SIGCHLD, sigchld_handler);
    //create socket
    server_socket= socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket <0){
        perror("socket creation failed");
    }

    //allow reuse of the address

    int opt= 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    //bind socket to address
    memset(&server_address,0, sizeof(server_address));
    server_address.sin_family= AF_INET;
    server_address.sin_addr.s_addr= INADDR_ANY;
    server_address.sin_port= htons(PORT);

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    //listen for connections
    listen(server_socket,5);

    printf("[Parent PID %d] Server listening on the port %d\n", getpid(), PORT);

    //accept the connections
    while(1){

        client_socket= accept(server_socket, (struct sockaddr*)&client_address, &client_len);
        printf("Parent ID %d] New connection accepted\n", getpid());

        //FORK: create child process
        pid_t pid= fork();
        if (pid<0){
            perror("Fork failed");
            close(client_socket);
            continue;
        }
        else if (pid==0){
            //child process
            //child doesnt need the listening socket
            close(server_socket);

            //handle the client

            handle_child(client_socket);
            

            //exit the child process when done

            exit(0);
        }
        else{
            //PARENT PROCESS
            //parent doesnt need client socket
            close(client_socket);

            //parent continues to accept more clients

            printf("[PARENT ID %d] Forked a child PID %d\n", getpid(), pid);
        }
    }
    close (server_socket);
    return 0;
    

}