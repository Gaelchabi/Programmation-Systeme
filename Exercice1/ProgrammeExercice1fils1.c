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


int main()
{
	printf("Je suis le fils 1 et mon PID est : %ld. \n", (long)getpid());
	
	return 0;
}

