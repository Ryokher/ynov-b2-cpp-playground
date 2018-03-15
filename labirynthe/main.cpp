#include <iostream>
#include "type.h"
#include "initplateau.h"
#include "affichage.h"
#include "deplacements.h"

int main()
{
    Cartes lePlateau[7][7];
    int leNbCartes[4]={19,18,13,50};
    //nombres de cartes Angle, TE et ligne non placées ainsi
    //que le nombre total de carte non placées restantes

    //initialisation du plateau
    initPlateau(lePlateau, leNbCartes);

    //détermination de la carte restante
    Cartes laCarteRestante;
    if(leNbCartes[0]==1){//si c'est un angle
        laCarteRestante=ANGLE;
    }else if(leNbCartes[1]==1){//sinon si c'est un TE
        laCarteRestante=TE;
    }else{//sinon c'est une ligne
        laCarteRestante=LIGNE;
    }

    //positionnement du pion
    int lesPosPion[2]={0,0};//{ligne, colonne}
    lePlateau[0][0].lesCases[1][1]='1';

    //lancement du premier affichage
    affichage(lePlateau, laCarteRestante);

    //démarrage de la partie
    sequencesDeplacements(lePlateau, lesPosPion, laCarteRestante);

    return 0;
}

