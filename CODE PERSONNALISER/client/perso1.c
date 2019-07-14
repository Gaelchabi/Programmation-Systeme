#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
 
 
#define SERV "192.168.9.103"
#define PORT 12345
 
 int main()
{ 
	int port,sock;
       
  struct  sockaddr_in     serv_addr;
  struct  hostent         *serveur;
 
  port = PORT;
  serveur = gethostbyname(SERV);
  if (!serveur){
	  fprintf(stderr, "Problème serveur \"%s\"\n",SERV); 
	  exit(1);
	  }
 
  sock = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy(serveur->h_addr, &serv_addr.sin_addr.s_addr,serveur->h_length);
  serv_addr.sin_port = htons(port);
 
printf("demande connexion\n");
 
if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
   {
	   perror("Connexion impossible");
	   exit (1);
	   }
    printf("client connecte \n");
    printf("fin client \n");
    close(sock);
    return 0;
} 
