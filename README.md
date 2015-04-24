# DNS_208

//updclient_dns.c UDP

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
 
// Default server port
#define PORT 7777

 
int main(int argc, char *argv[])
{
int socketfd, size;
char buffer[3000],msg[3000];
struct hostent *h;
// Server address information
struct sockaddr_in server;
 
// Extract Host Details
if((h=gethostbyname(argv[1])) == NULL)
{
    perror("gethostbyname()");
    exit(1);
}
else
    printf("The Remote Server is: %s\n", argv[1]);
//Create socket  
if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
{
    perror("socket()");
    exit(1);
}
else
    printf("Socket has been created \n");
 
// host byte order
server.sin_family = AF_INET;
// short, network byte order
printf("Connected to %s with port %d...\n", argv[1], PORT);
server.sin_port = htons(PORT);
server.sin_addr = *((struct in_addr *)h->h_addr);
// zero remaining struct
memset(&(server.sin_zero), '\0', 8);
 
if(connect(socketfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
{
    perror("connect()");
    exit(1);
}
else
    printf("The connection has been established by client!!\n");


printf("write your hostname : ");
        printf("%s",msg);
 
while(1)
   {
     printf("write the data to be send :\n ");
        gets(buffer);
       
        if( send(sock , msg, 3000 , 0) < 0)
        {
            printf("Error in sending data\n");
            return 1;
        }
        //Receive response from the server

        if( recv(sock , server_reply , 3000 , 0) < 0)
        {
           printf("Response failed");
            break;
        }
               printf("Respnse arrived:\n %s",message);                                  
}

 

return 0;
}

