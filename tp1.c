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
 
static int compare_population_ville (void const *a, void const *b) {
    struct Ville const *pa = a;
    struct Ville const *pb = b;
    return ((int)pb->population - (int)pa->population);
}

void ouvertureFichier(FILE*,FILE*);
void validationEntree(int);
void testeDeParametre(int);
void traitementDuFichierPays(FILE*,Pays[]);
void traitementDuFichierVille(FILE*,Pays[],Ville[]);

int main(int argc, char** argv){
    FILE* fichierVille=fopen("cities15000.txt","r");
    FILE* fichierPays=fopen("countryInfo.txt","r");
    validationEntree(argc);
    ouvertureFichier(fichierVille,fichierPays);

    long n;
    n=atol(argv[1]);
    testeDeParametre(n);     
   
    if(!fichierVille||!fichierPays){
        printf("Veuillez verifier les fichiers!\n");
    }else{
        Pays paysTabValidation[TAILLE_TAB_PAYS];
        char buffer[TAILLE_DU_BUFFER];
       
        traitementDuFichierPays(fichierPays,paysTabValidation);
	
	Ville villeTab[TAILLE_TAB_VILLE];
        char bufferVille[TAILLE_DU_BUFFER];
        char *tokenVille, *psVille ;
        int remplissageVille=0;
        while ( fgets(bufferVille,TAILLE_DU_BUFFER,fichierVille)){
            if (buffer[0]=='#') {
                continue;
            }
            Ville villeTempo;
            int compteurVille = 0;
            psVille = bufferVille;
            char correspondance[10];
            while ((tokenVille = strsep(&psVille, "\t")) != NULL) {
                if(compteurVille == 2){
                    strcpy(villeTempo.nom, tokenVille);
                }
                if(compteurVille == 14 ){
                    villeTempo.population=atol(tokenVille);
                }
                if(compteurVille ==8 ){
                    strcpy(correspondance, tokenVille);
                    int c=0;
                    for (c=0; c<TAILLE_TAB_PAYS; c++) {
                        if (strcmp(paysTabValidation[c].code,correspondance)==0) {
                            villeTempo.pays=paysTabValidation[c];
                        }
                    }
                }
                compteurVille++;
            }
            villeTab[remplissageVille] = villeTempo;
            remplissageVille++;   	
        }
        qsort (villeTab, sizeof villeTab / sizeof *villeTab, sizeof *villeTab, compare_population_ville); 
        int lecture=0;
        printf("Rang    Nom                           Pays                               Population \n");
        printf("----    ---                           ----                               ---------- \n");
        for (lecture=0; lecture<n; lecture++) {
            printf("%4d ", lecture+1);
            printf("   %-30s", villeTab[lecture].nom);
            printf("%-33s", villeTab[lecture].pays.nom);
            printf("%10ld\n", villeTab[lecture].population);
        }
    fclose(fichierVille);
    fclose(fichierPays);
    }
    return 0;
}

void ouvertureFichier(FILE* fichierVille,FILE* fichierPays){
    if(!fichierVille||!fichierPays){
        printf("Veuillez verifier les fichiers 1!\n");
        exit(1);     
    }
}

void validationEntree(int argc){
    if(argc!=2){
        printf("Attention arguments invalides!!Le nombres d'arguments doit etre egal a 2 SVP!\n");
        exit(1);
    }   
}

void testeDeParametre(int nombreDeVille){
    if(MIN_SAISIE_CLAVIER>nombreDeVille||nombreDeVille>MAX_SAISIE_CLAVIER){
        printf("Attention!La valeur entree doit etre comprise entre 1 et 5000 SVP!\n");
        exit(1);
    }
}

void traitementDuFichierPays(FILE* fichierPays,Pays paysTab[]){
    char buffer[TAILLE_DU_BUFFER];
    char *token, *ps;
    int remplissage=0;
    while ( fgets(buffer,TAILLE_DU_BUFFER,fichierPays) ){
            if (buffer[0]=='#') {
                continue;
            }
            Pays paysTempo;
            int compteur = 0;
            ps = buffer;
            while ((token = strsep(&ps, "\t")) != NULL) {
                if(compteur == 0){
                    strcpy(paysTempo.code, token);
                }
                if(compteur == 4 ){
                    strcpy(paysTempo.nom, token);
                }
                compteur++;
            }
            paysTab[remplissage] = paysTempo;
            remplissage++;
        }
}

