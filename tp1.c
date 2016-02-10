#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MIN_SAISIE_CLAVIER 1
#define MAX_SAISIE_CLAVIER 5000
#define LONG_NOM_PAYS 100
#define LONG_CODE_PAYS 50
#define LONG_NOM_VILLE 100
#define TAILLE_DU_BUFFER 3700
#define TAILLE_TAB_PAYS 304
#define TAILLE_TAB_VILLE 23493

typedef struct Pays {
    char nom[LONG_NOM_PAYS];
    char code[LONG_CODE_PAYS];
}Pays;

typedef struct Ville {
    char nom[LONG_NOM_VILLE];
    long population;
    Pays pays;
}Ville;


int main(int argc, char** argv){
   
//test des arguments
//test des fichiers
//ouverture des fichiers
//recuperartion des donnees utiles
//traitement des donnees
//stockage dans des tableaux
//effectuer des correspondances
//affichage 
//fermeture des fichiers

return 0;
}

