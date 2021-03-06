#include<stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char msg[2000] , server_reply[2000];

    sock = socket(AF_INET , SOCK_STREAM , 0); //create socket
    if (sock == -1)
    {
        printf("could not create socket");
    }
    printf("Socket created");

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    
//Connect to remote server_addr TCP
    if (connect(sock , (struct sockaddr *)&server_addr , sizeof(server_addr)) < 0)
    {
        printf("connection error");
        return 1;
    }

    printf("Connected to server :) \n");

   //Server Reply
    while(1)
   {
printf("write your hostname : ");
        printf("%s",msg);
     
if (send(sock,msg, 2000 , 0) < 0)
        {
            printf("send error");
            return 1;
        }

       //msg=NULL;
        if(recv(sock , server_reply , 2000 , 0) < 0)
        {
           printf("recv failed");
            break;
        }
        printf("Reply From Server : %s \n ",server_reply);
}


    return 0;
}
