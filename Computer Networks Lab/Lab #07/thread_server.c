#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 9000

#define BUFFER_SIZE 1024
void *handle_client(void *arg){
    //extract client socket from argument
    int client_socket= *((int *)arg);
    free(arg);
    printf("thread %lu,started a new client socket %d\n", pthread_self(), client_socket);
    
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while(1){
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read= recv(client_socket, buffer, BUFFER_SIZE-1, 0);
        if (bytes_read <= 0) { 
            
            break;
        }
        buffer[bytes_read]= '\0';

        printf("[Thread %lu] Received: %s", pthread_self(), buffer);
        // Check for quit command
        if (strncmp(buffer, "quit", 4) == 0) {
            printf("Thread %lu: Client sent 'quit', closing connection\n", pthread_self());
            break;
        }
        send(client_socket, buffer, strlen(buffer), 0);
        
    }
    close(client_socket);
    printf("[Thread %lu] Thread exiting\n", pthread_self());
    return NULL;

}
int main(){

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len= sizeof(client_address);
    pthread_t tid;
    //create a sokcet

    server_socket= socket(AF_INET, SOCK_STREAM,0);
    if(server_socket<0){
        perror("socket creation F");
        exit(1);
    }
    int opt=1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    //bind
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family= AF_INET;
    server_address.sin_addr.s_addr=INADDR_ANY;
    server_address.sin_port= htons(PORT);

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    listen(server_socket, 10);
    printf("server is listening on port %d\n", PORT);

    while(1){
        client_socket= accept(server_socket,(struct sockaddr*)&client_address, &client_len);
        printf("\n=== New connection from %s:%d ===\n",
               inet_ntoa(client_address.sin_addr), 
               ntohs(client_address.sin_port));
        //allocate
        //malloc
        int *pclient= malloc(sizeof(int));
        if(pclient ==NULL){
            perror
            close(client_socket);
            continue;
        }
        pclient = client_socket;
        pthread_create(&tid, 0, handle_client, pclient)











        int *pclient= malloc(sizeof(int));
        if(pclient== NULL){
            perror("malloc failed");
            close(client_socket);
            continue;
        }
        *pclient= client_socket;
        if(pthread_create(&tid, NULL, handle_client, pclient)!=0){
            perror("thread creation failed");
            free(pclient);
            close(client_socket);
            continue;
        }
        printf("Thread %lu created for the client\n", tid);

        pthread_detach(tid);

    }
    close(server_socket);
    return 0;
}