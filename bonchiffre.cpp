#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ( int argc, char** argv )
{
    int compteur = 0, choixDifficulte = 0;
    int nombreMystere = 0, nombreEntre = 0;
    const int MIN = 1;
    const int MAX = 1000;

{
        printf("Tu doit trouver le nombre juste entre 0 et 1000:\n");
    //On génere le nombre à trouver
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    //La boucle en dessous ce répete jusqu'a ce que l'utilisateur trouve la réponse
    do
    {
        printf("\nQuel est le nombre ?\n ");
        scanf("%d", &nombreEntre);
        compteur = compteur + 1;
        if (nombreMystere > nombreEntre)
            printf("\nC'est plus\n\n");
        else if (nombreMystere < nombreEntre)
            printf("\nC'est moins\n\n");
        else
            printf ("\n\n Tu as trouvé la réponse en %d coup !!!\n\n", compteur);
    } while (nombreEntre != nombreMystere);
}
}