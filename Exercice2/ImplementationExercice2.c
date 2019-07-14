/*
 *Programme Realiser Par L'etudiant CHABI Gael
 * Etudiant Genie Logiciel 2
 * Exercice 2
 * chabigaelle@gmail.com 
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h> 
#include <sys/shm.h>  
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>           
#include <sys/stat.h>      
#include <semaphore.h>

int main()
{
    pid_t pid1,pid2,pid3;
    int status;
	key_t key = ftok("shmfile",65);

    int a = 0; // shared data (la variable partagée)

    // On demande au system de creer la memoire partagee 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
    // on attache la memoire partagee a str
    char *str = (char*) shmat(shmid,(void*)0,0); 
    // ecriture de 0 dans la mémoire partagée
    sprintf(str, "%d", a);
	pid1=fork();
   // char **argp= {"p",NULL};
    if(pid1<0)
    {
        perror("Erreur de création du processus 1");
        exit(EXIT_FAILURE);
    }
    if(pid1==0)
    {
		//sleep(3);
        execv("./p",NULL);
       
    }
    else
    {
        pid2=fork();
       // char** argp={"./p",NULL,NULL};
        if(pid2<0)
        {
            perror("Erreur de création du processus 2");
            exit(EXIT_FAILURE);
        }
        if(pid2==0)
        {
		//	sleep(1);
            execv("./p",NULL);
             pid1=wait(&status);
            
        }
        else
        {
            pid3=fork();
            //char** argp={"./p",NULL,NULL};
            if(pid3<0)
            {
                perror("Erreur dans la création du processus 3");
                exit(EXIT_FAILURE);
            }
            if(pid3==0)
            {
			//	sleep(5);
                execv("./p",NULL);
                pid1=wait(&status);
                pid2=wait(&status);
            }
            else
            {
                pid1 = wait(&status);
                pid2 = wait(&status);
                pid3 = wait(&status);
                printf("\n\n");
                printf("Statut de l'arret du fils  %d ️ \n", pid1);
                printf("Statut de l'arret du fils  %d  \n", pid2);
                printf("Statut de l'arret du fils  %d  \n", pid3);
                printf("Valeur dans la mémoire partagée %d\n",atoi(str));
            }
        }
    }
    shmdt(str);
    //destruction de la mémoire
    shmctl(shmid,IPC_RMID,NULL);
    
	return 0;
}

