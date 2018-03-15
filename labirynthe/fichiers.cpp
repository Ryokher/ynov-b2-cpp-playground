#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <ctime>
#include <string>
#include "type.h"
#include "deplacements.h"

void sauvegarder(Cartes unPlateau[][7], Cartes uneCarteRestante, int desPosPion[], int uneNouvelleVersion, std::string uneDate){
    std::string nomFichier, laVersion(std::to_string(uneNouvelleVersion));//le n° de version devient un string
    if (uneNouvelleVersion==1){//si c'est la 1ere sauvegarde aujourd'hui
        nomFichier=uneDate+".labyrinthe";
    }else{//sinon rajouter le n° de version
        nomFichier=uneDate+"_v"+laVersion+".labyrinthe";
    }
    std::ofstream leFichier (nomFichier);//ouverture en ecriture du fichier de sauvegarde
    if (leFichier){
        for (int lig(0); lig<7; lig++){
            for (int col(0); col<7; col++){
                leFichier << unPlateau[lig][col].leType << '\n' //ajouter le type de carte
                          << unPlateau[lig][col].angleRotation << '\n'; // et ajouter son angle de rotation
            }
        }
        leFichier << uneCarteRestante.leType << '\n'
                  << uneCarteRestante.angleRotation << '\n'
                  << desPosPion[0] << '\n'//la position ligne du pion
                  << desPosPion[1] << '\n';//la position colonne du pion
        std::cout << "La partie a ete sauvee sous le nom " << nomFichier << '\n';
    }else{
        std::cout << "Erreur lors de la creation du fichier de sauvegarde\n";
    }
    leFichier.close();
    std::ofstream lesSauvegardes ("listeSauvegarde.txt", std::ios::app);
    lesSauvegardes << nomFichier << '\n';//ajout du nom de fichier dans la liste
    lesSauvegardes.close();
}

void versionSauvegarde(Cartes unPlateau[][7], Cartes uneCarteRestante, int desPosPion[]){
    time_t _time;
    struct tm timeInfo;
    char date[32];
    time(&_time);

    localtime_s(&timeInfo, &_time); //changement
    strftime(date, 32, "%d_%m_%Y", &timeInfo);

    std::ifstream nbSauvegardeAjd ("nombreSauvegardeAujourdhui.txt");
    int laNouvelleVersion(1);
    std::string laDate, leNbSauvegarde;
    if (nbSauvegardeAjd){
        int leCpt(0);
        std::string laLigne;
        while (getline(nbSauvegardeAjd, laLigne)){//verifier la date et version de la dernier sauvegarde
            switch(leCpt){
            case 0: laDate=laLigne; break;
            case 1: leNbSauvegarde=laLigne; break;
            }
            leCpt++;
        }
        laNouvelleVersion=std::stoi(leNbSauvegarde)+1;//transformer en int
        if (laDate==date){//si ce n'est pas la premiere aujourd'hui
            sauvegarder(unPlateau, uneCarteRestante, desPosPion, laNouvelleVersion, date);
        }else{//Sinon ca sera la 1ere version aujourd'hui
            sauvegarder(unPlateau, uneCarteRestante, desPosPion, 1, date);
        }
    }else{//Si le fichier n'existe pas alors c'est la 1ere version aujourd'hui
        sauvegarder(unPlateau, uneCarteRestante, desPosPion, 1, date);
    }
    nbSauvegardeAjd.close();
    std::ofstream nouveauNbSauvegardeAjd ("nombreSauvegardeAujourdhui.txt");
    nouveauNbSauvegardeAjd << date << '\n'
                           << laNouvelleVersion;//indiquer qu'on a sauvegarder aujourd'hui
    nouveauNbSauvegardeAjd.close();


}

void restauration(Cartes unPlateau[][7], Cartes & uneCarteRestante, int desPosPion[]){
    std::ifstream lesSauvegardes ("listeSauvegarde.txt");
    std::string laLigne;
    int nbLignes(0);
    if (lesSauvegardes){
        while (getline(lesSauvegardes, laLigne)){
            nbLignes++;//compter le nombre de lignes
        }
        std::string lesNomsSauvegardes[nbLignes];//créer un tableaux en fonctions du nbr de lignes
        std::cout << "Liste des fichiers dispnobiles :\n num\tnom\n";
        lesSauvegardes.close();

        std::ifstream lesSauvegardes ("listeSauvegarde.txt");
        int leCpt(0);
        while (getline(lesSauvegardes, laLigne)){
            lesNomsSauvegardes[leCpt]=laLigne;
            std::cout << ' ' << leCpt+1 << '\t'
                      << lesNomsSauvegardes[leCpt] << '\n';//afficher les choix de restauration disponibles
            leCpt++;
        }
        std::cout << "Votre choix ? "; int leChoix;
        std::cin >> leChoix;

        if (leChoix>0 && leChoix<=nbLignes){//Si le choix indiqué par l'user est dans la liste
            std::ifstream laSauvegarde (lesNomsSauvegardes[leChoix-1]);
            if (laSauvegarde){
                int leCpt2(1), laPosLigne, laPosColonne, laLigneInt1, laLigneInt2;
                while (getline(laSauvegarde, laLigne)){
                    if (leCpt2<=98){//Si c'est les numéros des crtes du plateau
                        laPosLigne=((leCpt2-1)/2)/7;//calculer la ligne actuelle en fonction du cpt2
                        laPosColonne=((leCpt2-1)/2)%7;//calculer la colonne actuelle en fonction du cpt2
                        if (leCpt2%2==0){
                            laLigneInt2=std::stoi(laLigne);
                            switch (laLigneInt1){
                            case 0: unPlateau[laPosLigne][laPosColonne]=rotation(ANGLE, laLigneInt2, 0); break;
                            case 1: unPlateau[laPosLigne][laPosColonne]=rotation(TE, laLigneInt2, 0); break;
                            case 2: unPlateau[laPosLigne][laPosColonne]=rotation(LIGNE, laLigneInt2, 0); break;
                            case 3: unPlateau[laPosLigne][laPosColonne]=rotation(ANGLEF, laLigneInt2, 0); break;
                            case 4: unPlateau[laPosLigne][laPosColonne]=rotation(TEF, laLigneInt2, 0);
                            }
                        }else{
                            laLigneInt1=std::stoi(laLigne);
                        }
                    }else if(leCpt2==99){
                        laLigneInt1=std::stoi(laLigne);
                    }else if(leCpt2==100){
                        laLigneInt2=std::stoi(laLigne);
                        switch (laLigneInt1){
                        case 0: uneCarteRestante=rotation(ANGLE, laLigneInt2, 0); break;
                        case 1: uneCarteRestante=rotation(TE, laLigneInt2, 0); break;
                        case 2: uneCarteRestante=rotation(LIGNE, laLigneInt2, 0);
                        }
                    }else if(leCpt2==101){
                        desPosPion[0]=std::stoi(laLigne);
                    }else{
                        desPosPion[1]=std::stoi(laLigne);
                        unPlateau[desPosPion[0]][desPosPion[1]].lesCases[1][1]='1';
                    }
                    leCpt2++;
                }
            }else{
                std::cout << "Erreur lors de la restauration\n";
            }
        }else{
            std::cout << "Erreur lors de la restauration";
        }
    }else{
        std::cout << "Aucune sauvegarde disponible\n";
    }
    lesSauvegardes.close();
}
