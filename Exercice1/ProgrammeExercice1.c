/*
 *Programme Realiser Par L'etudiant CHABI Gael
 * Etudiant Genie Logiciel 2
 * Exercice 1
 * chabigaelle@gmail.com 
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1, pid2, pid3;
	int status;

	printf("Je suis le pere\n");
	pid1 = fork();
	if(pid1<0)
	{
		printf("Erreur de création du fils 1\n");
		pid1 = wait(&status);
		exit(-1);
	}
	if(pid1==0)
	{
		execv("./fils1", NULL);
	}
	else
	{
		pid2 = fork();
		if(pid2<0)
		{
			printf("Erreur de creation du fils 2\n");
			pid1 = wait(&status);
			pid2 = wait(&status);
			exit(-1);
		}
		if(pid2==0)
		{
			execv("./fils2", NULL);
		}
		else
		{
			pid3 = fork();
			if(pid3<0)
			{
				printf("Erreur de creation du fils 3\n");
				pid1 = wait(&status);
				pid2 = wait(&status);
				pid3 = wait(&status);
				exit(-1);
			}
			if(pid3==0)
			{
				execv("./fils3", NULL);
			}
			else
			{
				pid1 = wait(&status);
				printf("Je suis le fils 1 de PID : %d et de status : %d \n", pid1, status);
				
				pid2 = wait(&status);
				printf("Je suis le fils 2 de PID : %d et de status : %d \n", pid2, status);
				pid3 = wait(&status);
				printf("Je suis le fils 3 de PID : %d et de status : %d \n", pid3, status);
			}
		}
	}
	return 0;
}
