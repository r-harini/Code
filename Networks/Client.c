#include<stdio.h>
#include<netinet/in.h>
#define PORT 8080

int main(){
struct sockaddr_in serverAddr, cliAddr;

int csd=socket(AF_INET,SOCK_STREAM,0);

if (csd==-1){
printf("Failed in connecting to the socket\n");
}
else{
printf("Socket created:%d \n",csd);
}

serverAddr.sin_family=AF_INET;
serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
serverAddr.sin_port=htons(PORT);

int c=connect(csd, (struct sockaddr*)&serverAddr,sizeof(serverAddr));

if (c<0){
printf("Connection failed/n");
}
else{
printf("Connected\n");
}

//close(csd);

return 0;
}
