#include <iostream>
#include "type.h"
#include "deplacements.h"
#include "affichage.h"
#include "fichiers.h"

Cartes rotation(Cartes uneCarte, int unAngleRotation, bool uneIncrementation){
    for (int i=0;i<unAngleRotation;i++){//unAngleRotation va servir à répeter la boucle et donc à tourner la carte plusieurs fois
        char unCharTemp(0);//création d'un variable temporaire
        // Dans la rotation vers la droite d'une carte, seul les 4 cases autour de la case5 se déplacent
        unCharTemp=uneCarte.lesCases[0][1];//sauvegarder la case du haut
        uneCarte.lesCases[0][1]=uneCarte.lesCases[1][0];//déplacer la case de gauche en haut
        uneCarte.lesCases[1][0]=uneCarte.lesCases[2][1];//déplacer la case du bas à gauche
        uneCarte.lesCases[2][1]=uneCarte.lesCases[1][2];//déplacer la case de droite en bas
        uneCarte.lesCases[1][2]=unCharTemp;//déplacer la case du haut à droite
        if (uneIncrementation==1){//si on veux incrementer
            if (uneCarte.angleRotation==3){//si c'est à 270, on remet à 0 au lieu de 360
                uneCarte.angleRotation=0;
            }else{
                uneCarte.angleRotation++;//sinon on ajoute +90
            }
        }
    }

    return uneCarte;
}

void deplacementCartesGauche(Cartes unPlateau[][7], int uneLigne, Cartes & uneCarteRestante, int desPosPion[]){
    Cartes uneCarteTemp;//creation d'une carte temporaire
    uneCarteTemp=uneCarteRestante;//on met la carte restante dans la carte temp
    uneCarteRestante=unPlateau[uneLigne][0];//la carte restante devient la carte qui sort du plateau
    for(int uneColonne(0); uneColonne<6; uneColonne++){
        unPlateau[uneLigne][uneColonne]=unPlateau[uneLigne][uneColonne+1];//on décale toutes les cartes
    }
    unPlateau[uneLigne][6]=uneCarteTemp;//on insère la carte restante
    if (desPosPion[0]==uneLigne){//On va vérifier si le pion n'est pas dans la rangée
        if (desPosPion[1]==0){//Si il est sur la carte restante on le met sur la carte entrée
            desPosPion[1]=6;
            unPlateau[uneLigne][6].lesCases[1][1]='1';
            uneCarteRestante.lesCases[1][1]=ESP;
        }else{//sinon on décale simplement sa position
            desPosPion[1]--;
        }
    }
}

void deplacementCartesDroite(Cartes unPlateau[][7], int uneLigne, Cartes & uneCarteRestante, int desPosPion[]){
    Cartes uneCarteTemp;
    uneCarteTemp=uneCarteRestante;
    uneCarteRestante=unPlateau[uneLigne][6];
    for(int uneColonne(6); uneColonne>=0; uneColonne--){
        unPlateau[uneLigne][uneColonne]=unPlateau[uneLigne][uneColonne-1];
    }
    unPlateau[uneLigne][0]=uneCarteTemp;
    if (desPosPion[0]==uneLigne){
        if (desPosPion[1]==6){
            desPosPion[1]=0;
            unPlateau[uneLigne][0].lesCases[1][1]='1';
            uneCarteRestante.lesCases[1][1]=ESP;
        }else{
            desPosPion[1]++;
        }
    }
}

void deplacementCartesHaut(Cartes unPlateau[][7], int uneColonne, Cartes & uneCarteRestante, int desPosPion[]){
    Cartes uneCarteTemp;
    uneCarteTemp=uneCarteRestante;
    uneCarteRestante=unPlateau[0][uneColonne];
    for(int uneLigne(0); uneLigne<6; uneLigne++){
        unPlateau[uneLigne][uneColonne]=unPlateau[uneLigne+1][uneColonne];
    }
    unPlateau[6][uneColonne]=uneCarteTemp;
    if (desPosPion[1]==uneColonne){
        if (desPosPion[0]==0){
            desPosPion[0]=6;
            unPlateau[6][uneColonne].lesCases[1][1]='1';
            uneCarteRestante.lesCases[1][1]=ESP;
        }else{
            desPosPion[0]--;
        }
    }
}

void deplacementCartesBas(Cartes unPlateau[][7], int uneColonne, Cartes & uneCarteRestante, int desPosPion[]){
    Cartes uneCarteTemp;
    uneCarteTemp=uneCarteRestante;
    uneCarteRestante=unPlateau[6][uneColonne];
    for(int uneLigne(6); uneLigne>=0; uneLigne--){
        unPlateau[uneLigne][uneColonne]=unPlateau[uneLigne-1][uneColonne];
    }
    unPlateau[0][uneColonne]=uneCarteTemp;
    if (desPosPion[1]==uneColonne){
        if (desPosPion[0]==6){
            desPosPion[0]=0;
            unPlateau[0][uneColonne].lesCases[1][1]='1';
            uneCarteRestante.lesCases[1][1]=ESP;
        }else{
            desPosPion[0]++;
        }
    }
}

void sequencesDeplacements(Cartes unPlateau[][7], int desPosPion[2], Cartes & uneCarteRestante){
    do{
        std::string sequenceMouvement;
        std::cout << "Sequence de mouvements (H/B/D/G)?";
        std::cin >> sequenceMouvement;
        bool sequenceErrone(0), deplacementCarte(0);
        for (int i(0);//on parcours la séquence de mouvement
             sequenceMouvement[i]>=65 && sequenceMouvement[i]<=122 && sequenceErrone==0 && unPlateau[6][6].lesCases[1][1]==ESP;
             i++){
            //si c'est bien un caractère, que la sequence n'est pas erronne et que l'on a pas gagné
            switch(sequenceMouvement[i]){

            //R
            case 82:if(deplacementCarte==0){//Si l'on a pas déjà inséré de carte
                    uneCarteRestante=rotation(uneCarteRestante,1,1);
                }else{ sequenceErrone=1; }break;//Sinon on annule le reste de la séquence

            case 73:if(deplacementCarte==0){//I
                    deplacementCartesBas(unPlateau, 1, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 74:if(deplacementCarte==0){//J
                    deplacementCartesBas(unPlateau, 3, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 75:if(deplacementCarte==0){//K
                    deplacementCartesBas(unPlateau, 5, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;

            case 76:if(deplacementCarte==0){//L
                    deplacementCartesDroite(unPlateau, 1, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 77:if(deplacementCarte==0){//M
                    deplacementCartesDroite(unPlateau, 3, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 78:if(deplacementCarte==0){//N
                    deplacementCartesDroite(unPlateau, 5, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;

            case 105:if(deplacementCarte==0){//i
                    deplacementCartesHaut(unPlateau, 1, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 106:if(deplacementCarte==0){//j
                    deplacementCartesHaut(unPlateau, 3, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 107:if(deplacementCarte==0){//k
                    deplacementCartesHaut(unPlateau, 5, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;

            case 108:if(deplacementCarte==0){//l
                    deplacementCartesGauche(unPlateau, 1, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 109:if(deplacementCarte==0){//m
                    deplacementCartesGauche(unPlateau, 3, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;
            case 110:if(deplacementCarte==0){//n
                    deplacementCartesGauche(unPlateau, 5, uneCarteRestante, desPosPion); deplacementCarte=1;
                }else{ sequenceErrone=1; }break;

                //Haut
            case 72:if(desPosPion[0]>0 &&
                       unPlateau[desPosPion[0]][desPosPion[1]].lesCases[0][1]==ESP &&
                       unPlateau[desPosPion[0]-1][desPosPion[1]].lesCases[2][1]==ESP &&//Si l'on peux bouger dans cette direction
                       deplacementCarte==1){//Si l'on a déjà bougé la carte
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]=ESP;//Remplacement de l'ancienne position du pion
                    desPosPion[0]-=1;//Déplacement
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]='1';//Ecriture de la nouvelle position
                }else{ sequenceErrone=1; }break;//Sinon indiquer qu'il ne faut pas faire les prochains mouvements
                //Bas
            case 66:if(desPosPion[0]<6 &&
                       unPlateau[desPosPion[0]][desPosPion[1]].lesCases[2][1]==ESP &&
                       unPlateau[desPosPion[0]+1][desPosPion[1]].lesCases[0][1]==ESP &&
                       deplacementCarte==1){
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]=ESP;
                    desPosPion[0]+=1;
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]='1';
                }else{ sequenceErrone=1; }break;
                //Gauche
            case 71:if(desPosPion[1]>0 &&
                       unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][0]==ESP &&
                       unPlateau[desPosPion[0]][desPosPion[1]-1].lesCases[1][2]==ESP &&
                       deplacementCarte==1){
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]=ESP;
                    desPosPion[1]-=1;
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]='1';
                }else{ sequenceErrone=1; }break;
                //Droite
            case 68:if(desPosPion[1]<6 &&
                       unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][2]==ESP &&
                       unPlateau[desPosPion[0]][desPosPion[1]+1].lesCases[1][0]==ESP &&
                       deplacementCarte==1){
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]=ESP;
                    desPosPion[1]+=1;
                    unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]='1';
                }else{ sequenceErrone=1; }break;

            case 83://S
            case 115://s
                versionSauvegarde(unPlateau, uneCarteRestante, desPosPion);
                break;

            case 79://O
            case 111://o
                restauration(unPlateau, uneCarteRestante, desPosPion);
                break;

            case 81://Q
                break;

            default ://Si c'est un autre caractère la séquence est Erronée
                sequenceErrone=1;
            }
        }
        std::cout << "\n\n\n";
        affichage(unPlateau, uneCarteRestante);//affichage des déplacements sur le plateau
    }while(unPlateau[6][6].lesCases[1][1]==ESP);//Boucler tant que le pion n'est pas en bas
    std::cout << "FIN\n";
}
