#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MIN_SAISIE_CLAVIER 1
#define MAX_SAISIE_CLAVIER 5000
#define LONG_NOM_PAYS 100
#define LONG_CODE_PAYS 50
#define LONG_NOM_VILLE 100
#define TAILLE_DU_BUFFER 3700
#define TAILLE_TAB_PAYS 310
#define TAILLE_TAB_VILLE 30000


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
void affichage(Ville[],int);


/* 
 * Fonction main.
 */ 
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
        static Pays paysTabValidation[TAILLE_TAB_PAYS];
        static Ville villeTabValidation[TAILLE_TAB_VILLE];
       
        traitementDuFichierPays(fichierPays,paysTabValidation);
	traitementDuFichierVille(fichierVille,paysTabValidation,villeTabValidation);       

        qsort (villeTabValidation, sizeof villeTabValidation / sizeof *villeTabValidation, sizeof *villeTabValidation, compare_population_ville); 
        
        affichage(villeTabValidation,n);
        fclose(fichierVille);
        fclose(fichierPays);
    }
    return 0;
}

/* 
 * Fonction ouvertureFichier qui verifie la presence des fichiers lors
 * du lancement du programme.
 * 
 * @param FILE* fichierVille
 * @param FILE* fichierPays
 * Arret du programme et affichage d'un message d'erreur si
 * un des 2 fichiers est manquant.
 */
void ouvertureFichier(FILE* fichierVille,FILE* fichierPays){
    if(!fichierVille||!fichierPays){
        printf("Veuillez verifier les fichiers 1!\n");
        exit(1);     
    }
}


/*
 * Fonction validationEntree qui verifie le nombre d'argument.
 *
 * @param int argc nombre d'arguments entres lors de l'execution du programme.
 * Arret du programme et affichage d'un message d'erreur si
 * le nombre est different de 2.
 */
void validationEntree(int argc){
    if(argc!=2){
        printf("Attention arguments invalides!!Le nombres d'arguments doit etre egal a 2 SVP!\n");
        exit(1);
    }   
}

/* Fonction testDeParametre qui verifie l'intervalle du nombre saisi en
 * parametre
 *
 * @param int nombreDeVille determine le nombre de ville que l'on veut afficher
 * Arret du programme et affichage d'un message d'erreur si le nombre n'est pas
 * compris entre 1 et 5000 inclusivement.
 *
 */
void testeDeParametre(int nombreDeVille){
    if(MIN_SAISIE_CLAVIER>nombreDeVille||nombreDeVille>MAX_SAISIE_CLAVIER){
        printf("Attention!La valeur entree doit etre comprise entre 1 et 5000 SVP!\n");
        exit(1);
    }
}


/*
 * Fonction traitementDuFichierPays qui decoupe le fichier en ligne,recupere
 * les informations essentielles a savoir le code et le nom et le stocke dans
 * un tableau de structure pays.
 *
 * @param FILE* fichierPays fichier pays
 * @param Pays paysTab[] tableau de structure pays
 */
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


/*
 * Fonction traitementDuFichierVille qui decoupe le fichier ville en ligne,
 * recupere les informations neccessaires a savoir le nom et la population 
 * effectuant une correspondance de code a travers le tableau de pays 
 * et remplissant ainsi integralement le tableau de ville.
 *
 * @param FILE* fichierVille fichier ville 
 * @param Pays paysTab[] tableau de structure pays
 * @param Ville villeTabValidation[] tableau de structure de ville. 
 */
void traitementDuFichierVille(FILE* fichierVille,Pays paysTab[],Ville villeTab[]){
    char bufferVille[TAILLE_DU_BUFFER];
    char *tokenVille, *psVille ;
    int remplissageVille=0;
    while (fgets(bufferVille,TAILLE_DU_BUFFER,fichierVille)){
            if (bufferVille[0]=='#') {
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
                        if (strcmp(paysTab[c].code,correspondance)==0) {
                            villeTempo.pays=paysTab[c];
                        }
                    }
                }
                compteurVille++;
            }
            villeTab[remplissageVille] = villeTempo;
            remplissageVille++;         
        }   
}

/* Affichage du tableau de ville rempli  en fonction
 * du nombre passe en parametre.
 *
 * @param Ville villeTabValidation[] tableau de structure de ville. 
 * @param int n nombre passe lors de lexecution du programme.
 *
 */
void affichage(Ville villeTabValidation[],int n){   
    int lecture=0;
    printf("Rang    Nom                           Pays                               Population \n");
    printf("----    ---                           ----                               ---------- \n");
    for (lecture=0; lecture<n; lecture++) {
        printf("%4d ", lecture+1);
        printf("   %-30s", villeTabValidation[lecture].nom);
        printf("%-33s", villeTabValidation[lecture].pays.nom);
        printf("  %10ld\n", villeTabValidation[lecture].population);
    }
}
