/*
 *Programme Realiser Par L'etudiant CHABI Gael
 * Etudiant Genie Logiciel 2
 * Exercice 1
 * chabigaelle@gmail.com 
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

char static *args[3];
void affiche(int n)
{
    int cfd;
    int success; // etat de la connection
    int port;
    int i;
   
  
   struct sockaddr_in srv_addr; // socket addr du serveur 

   
   
   cfd = socket(AF_INET, SOCK_STREAM, 0); // création de la socket
   if (cfd < 0){ // Une erreur s'est produite la socket n'a pas pu être créer
      printf("Le SE n'a pas pu créer la socket %d\n", cfd);
      exit(-1);
   }
   /* donne une identite a la socket. 
    * AF_INET pour dire que c'est le protocole TCP qui sera utilisé
    * SRV_PORT est le port du serveur distant que le client desire contacter
    * SRV_ADDR est l'adresse du serveur distant que le client desire contacter
    * */
   port = atoi(args[2]);

   srv_addr.sin_family = AF_INET;
   srv_addr.sin_port = htons (port);
   inet_aton(args[1], (struct in_addr *)&srv_addr.sin_addr.s_addr);

   /* connexion au serveur 
    * A l'aide de la fonction connect() on se connecte au serveur distant
    * on utilise pour cela la socket qui a été créée par l'SE du client 
    * on utilise aussi l'identité du serveur qui vient d'être construite */ 
   success = connect(cfd, (struct sockaddr *) &srv_addr,
                 sizeof(struct sockaddr_in));
   if(success < 0){ // la connexion a echouée
      printf("Impossible de se connecter au serveur %s:%d error %d\n", 
               args[1], port, success);
      exit(-1);
   }
   /* */

	send(cfd, "Execute", sizeof("Execute"), 0);
	printf("Envoie du signal\n");
	close(cfd);

}

int main(int argc, char *argv[]){
  int i;
   signal(SIGALRM, affiche);
     if(argc!=3)
     {
       printf("USAGE: ./client <serveur_ip_addr> <serveur_port>\n");
       exit(-1);
     }
      //send(cfd, "Execute", sizeof("Execute"), 0);
      args[0] = argv[0];
      args[1] = argv[1];
      args[2] = argv[2];
  	while(1)
  	{
  	  alarm(10);
  	  pause();
  	}
  	
  	
   /* Après avoir dit bonjour au serveur nous demandons au SE de libérer
    * la socket */
   return(0);
}

