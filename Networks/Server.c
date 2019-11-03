#include<stdio.h>
#include<WinSock2.h>
#define PORT 8080

int main(){
int sock;
struct sockaddr_in serverAddr, cliAddr;
char buffer[1024]={0};


sock=socket(AF_INET,SOCK_STREAM,0);

if (sock==-1){
printf("Failed in connecting to the socket\n");
}
else{
printf("Socket created:%d \n",sock);
}

serverAddr.sin_family=AF_INET;
serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
serverAddr.sin_port=htons(PORT);

int b=bind(sock,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

if (b<0){
printf("Binding failed\n");
}
else{
printf("Binding succesful %d\n",b);
}

int l=listen(sock,3);

//printf("Listening: %d\n",l);

int clilen=sizeof(cliAddr);

int nsd=accept(sock, (struct sockaddr*)&cliAddr,&clilen);

if (nsd<0){
printf ("nsd: %d",nsd);
}
else{
printf("Connected\n");
}

//close(sock);

return 0;
}
