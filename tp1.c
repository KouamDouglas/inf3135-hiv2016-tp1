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

    FILE* fichierVille;
    FILE* fichierPays;

    if(argc!=2){
        printf("Attention!!Le nombres d'arguments doit etre egal a 2 SVP!\n");
        return 1;
    }

    long n;
    n=atol(argv[1]);
    if(MIN_SAISIE_CLAVIER>n||n>MAX_SAISIE_CLAVIER){
        printf("Attention!La valeur entree doit etre comprise entre 1 et 5000 SVP!\n");
        return 1;
    }    

    fichierVille=fopen("cities15000.txt","r");
    fichierPays=fopen("countryInfo.txt","r");

    if(!fichierVille||!fichierPays){
        printf("Veuillez verifier les fichiers!\n");

    }else{
        //recuperartion des donnees utiles
        //traitement des donnees

    }
//stockage dans des tableaux
//effectuer des correspondances
//affichage 
//fermeture des fichiers

return 0;
}

