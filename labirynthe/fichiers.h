#ifndef FICHIERS
#define FICHIERS

#include <string>
#include "type.h"
void sauvegarder(Cartes unPlateau[][7], Cartes uneCarteRestante, int desPosPion[], int uneNouvelleVersion, std::string uneDate);
void versionSauvegarde(Cartes unPlateau[][7], Cartes uneCarteRestante, int desPosPion[]);
void restauration(Cartes unPlateau[][7], Cartes & uneCarteRestante, int desPosPion[]);

#endif // FICHIERS

