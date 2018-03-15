#include <iostream>
#include "type.h"

void affichage(Cartes unPlateau[][7], Cartes uneCarteRestante){
    //Affichage du plateau
    std::cout << "\nPLATEAU :\n";
    std::cout << "     I     J     K\n";
    for (int ligPl(0); ligPl<7; ligPl++){ //parcours des lignes du tableau de struct
        for (int ligCa(0); ligCa<3; ligCa++){ //parcours des lignes des Cartes
            if (ligPl==1 && ligCa==1){ std::cout << 'L'; } //Affichage des caractère
            else if (ligPl==3 && ligCa==1){ std::cout << 'M'; }
            else if (ligPl==5 && ligCa==1){ std::cout << 'N'; }
            else{ std::cout << ESP; }
            for (int colPl(0); colPl<7; colPl++){
                for (int colCa(0); colCa<3; colCa++){
                    std::cout << unPlateau[ligPl][colPl].lesCases[ligCa][colCa];
                }
            }
            if (ligPl==1 && ligCa==1){ std::cout << 'l' << '\n'; }
            else if (ligPl==3 && ligCa==1){ std::cout << 'm' << '\n'; }
            else if (ligPl==5 && ligCa==1){ std::cout << 'n' << '\n'; }
            else{ std::cout << ESP << '\n'; }
        }
    }
    std::cout << "     i     j     k\n";

    //Affichage de la carte restante
    std::cout << "Carte restante :\n";
    for (int lig(0); lig<3; lig++){
        for (int col(0); col<3; col++){
            std::cout << uneCarteRestante.lesCases[lig][col];
        }
        std::cout << '\n';
    }
}
