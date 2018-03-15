# YNOV INGESUP B2 CPP Playground 

# EXOS D'ENTRAINEMENT
Au début j'ai fait des exos pour m'entraîner puis j'ai essayer de faire le jeu du juste prix en c.

------------------------------------------------------------------------------------------------------------------------------------------
 # LABIRYNTHE
Nous avons réaliser les jeu du labirynthe.

Membres du groupe: Thomas Mahé - Lukas Presencia - Charles Huet - Geoffrey Moreau

Régles du jeu:
Le but du jeu est d'arriver sur la case en bas à droite en partant d'en haut à gauche (le joueur est représenté par le chiffre 1)
Il faut d'abord déplacer une rangée (verticalement: IJK ijk ou horizontalement LMN lmn)  afin de créer un passage pour le joueur.
Il faut ensuite rentrer le mouvement du joueur case par case: H = haut, B= bas, G= Gauche, D= Droite.

Par exemple si je veux faire monter la colonne de gauche (I i) et bouger de trois vers la droite je dois rentrer : iDDD.

Note: on peut bouger des cartes sans se déplacer mais on ne peut pas se déplacer sans en bouger préalablement.                        
Exemple: je peux faire pour commencer: I puis m puis lDDD mais je ne peux pas faire: DDD ni GDH
                              
 Le jeu est jouable avec le .exe mais aussi avec les fichier situés dans le dossier du même nom.
 Attention cepandant car le compiler MinGw fournit avec code blocks ne peut pas lancer le jeu il faut utiliser celui la:http://mingw-w64.org/doku.php/download
