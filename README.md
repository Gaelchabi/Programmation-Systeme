# Programmation-Systeme
Exercice 1: Programme bien resolue aucun problème majeur rencontré

Exercice 2:

Question1: La valeur finale dans la mémoire partagée est 300

Question2: Pour résoudre ce problème nous pouvons utiliser la bibliothèque #include<semaphore.h>
pour bloquer l'utilisation anarchique de la mémoire partager par les trois processus

-Il faut bloquer des processus pour qu'un seul travaille et les autres attendent la fin pour agir. Utilisation de semaphore

Implementation(Voir code)

Exercice 3:

Question1: En ce qui concerne le problème que nous serons amener a resoudre,
nous pouvons dire qu'on aura besoin de trois processus; le premier servant a arranger les éléments entrer par l'utilisateur, 
le second permettant de faire la multiplication deux a deux entre les éléments du haut et du bas; et le troisième qui permet de faire la somme des éléments. Nous pouvons aussi avoir un processus qui envoie le résultat a la matrice.
Eviter que les processus écrivent dans un désordre.

Question2: utiliser un marqueur et verrouiller chaque case i,j pour l'occuper que par un seul processus, lecture dans un fichier, utilisation de de sémaphore et de 3 mémoires partagées;

Question3: Implementation(Voir code)

Exercice 4:

Question1: Comment faire le transfert de tous les types de fichiers entre le client et le serveur

Question2: Le client envoie le fichier par bytes sur le serveur en ayant envoyé le nom, le serveur crée un fichier de meme nom et écrit par bytes le fichier dans celui après avoir envoyé ok au client qui attend cette réponse avant d'écrire par bytes sur le socket auquel le serveur lit.

Question3:(Voir code)

Exercice 5:

Question1:
