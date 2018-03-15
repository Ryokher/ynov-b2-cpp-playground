#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "type.h"
#include "deplacements.h"

void initPlateau(Cartes unPlateau[][7], int unNbCartes[]){
    unPlateau[0][0]=ANGLEF;//placement de toutess les crtes fixées
    unPlateau[0][2]=TEF;
    unPlateau[0][4]=TEF;
    unPlateau[0][6]=rotation(ANGLEF, 1, 1);
    unPlateau[2][0]=rotation(TEF, 3, 1);
    unPlateau[2][2]=rotation(TEF, 3, 1);
    unPlateau[2][4]=TEF;
    unPlateau[2][6]=rotation(TEF, 1, 1);
    unPlateau[4][0]=rotation(TEF, 3, 1);
    unPlateau[4][2]=rotation(TEF, 2, 1);
    unPlateau[4][4]=rotation(TEF, 1, 1);
    unPlateau[4][6]=rotation(TEF, 1, 1);
    unPlateau[6][0]=rotation(ANGLEF, 3, 1);
    unPlateau[6][2]=rotation(TEF, 2, 1);
    unPlateau[6][4]=rotation(TEF, 2, 1);
    unPlateau[6][6]=rotation(ANGLEF, 2, 1);
    unNbCartes[0]-=4; unNbCartes[1]-=12; unNbCartes[3]-=4+12;//décompte de toutes les cartes fixes placées

    srand(time(NULL));//initialisation de rand()
    int leNbAleatoire, nbMobile;

    for (int ligne(0); ligne<7; ligne++){
        switch (ligne%2){
        case 0: nbMobile=2; break;
        case 1: nbMobile=1;
        }

        for(int colonne(nbMobile-1); colonne<7; colonne+=nbMobile){
            leNbAleatoire = rand() % unNbCartes[3]+1;
            if(leNbAleatoire<=unNbCartes[0]){
                unPlateau[ligne][colonne] = rotation(ANGLE, rand()%4, 1);
                unNbCartes[0]--;
            }
            else if(leNbAleatoire<=unNbCartes[0]+unNbCartes[1]){
                unPlateau[ligne][colonne] = rotation(TE, rand()%4, 1);
                unNbCartes[1]--;
            }
            else{
                unPlateau[ligne][colonne] = rotation(LIGNE, rand()%4, 1);
                unNbCartes[2]--;
            }
            unNbCartes[3]--;
        }
    }
}
