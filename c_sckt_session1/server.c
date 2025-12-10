#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


#define BUFFER_SIZE 255

void error (const char* msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    if (argc < 2){
        printf("Port number not provided program terminated \n");
        exit(1);

    }
    
    int sockfd , newsock , portno , n;
    char buffer[BUFFER_SIZE];
    
    struct sockaddr_in server_addr , client_addr;
    socklen_t client_len;

    sockfd = socket(AF_INET,SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error opening scoket");
    }

    bzero((char *) &server_addr , sizeof(server_addr));
    portno = atoi(argv[1]);

    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(portno); 
    
    if (bind(sockfd, (struct sockaddr*) &server_addr ,sizeof(server_addr))<0)
    {
        error("Error binding failed");
    }

    return 0;


}
