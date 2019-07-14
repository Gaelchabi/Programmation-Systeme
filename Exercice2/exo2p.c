/*
 *Programme Realiser Par L'etudiant CHABI Gael
 * Etudiant Genie Logiciel 2
 * Exercice 2
 * chabigaelle@gmail.com 
*/

#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>           
#include <sys/stat.h>        


#define ITER 100



int main() 
{ 
  // on genere la clé de la mémoire partagée
  key_t key = ftok("shmfile",65); 
  int i;
  int a = 0; // shared data

    

  // shmget returns an identifier in shmid 
  int shmid = shmget(key,1024,0666); 
  // shmat to attach to shared memory 
  char *str = (char*) shmat(shmid,(void*)0,0); 


  for(i=0; i < ITER; i++){
     // lecture de a
     a = atoi(str);
    a++;
   
   // printf("Processus %d %d\n", getpid(), a);
    printf("valeur de a : %d\n",a);
     sprintf(str,"%d", a);
     printf("Processus %d a écrit %d\n", getpid(), a);
     }
     
     
     
     // modification de a
    // sleep(4);
    
  //detach from shared memory 
  shmdt(str); 
  return 0; 
} 
