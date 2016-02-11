# Travail pratique 1

## Description

 Le projet consiste à initier à la programmation en C, en manipulant des données
provenant de la base de données GeoNames.A partir des données géographiques ouvertes de
celle-ci le travail consistera à recuperer des informations a partir de deux (02) fichiers
cities15000.zip et countryInfo.txt faire le lien entre les 2 fichiers et pouvoir dresser la
liste des villes les plus peuplées du monde ajoutant population et nom de pays correspondant.

 Ce projet est developpé dans le cadre du cours INF3135 Construction et maintenance de logiciels
HIVER 2016 au sein de l'UNIVERSITE DU QUEBEC A MONTREAL(UQAM) donné par Alexandre Blondin Massé

## Auteur

Prenom et Nom  :  Douglas Kouokam Kouam
Code Permanent :  KOUD16019209

## Fonctionnement

 Le programme fonctionne comme suit:
A partir des 2 fichiers telechargés le travail consiste a extraire les données dans
les differents fichiers lignes par ligne.Remplir un tableau de structures de pays en attribuant a chaque 
fois nom et code a un pays.Ensuite remplir un tableau de structures de ville avec le nom,la population et
aussi en faisant une correspondance de code pour pouvoir identifier a quel pays appartient une ville.
La correspondance ainsi faite et le tableau etant plein.Un tri par ordre decroissant des populations 
s'effectue.Notons bien ici que le nombre de ville a affiche que le programme accepte est entre 1 et 5000.
Les executions se presentant ainsi sous ces formes.

Exemple:1er cas d'utilisation

[bc491136@malt CoursProgrammation]$ ./tp1 10
Rang    Nom                           Pays                               Population 
----    ---                           ----                               ---------- 
   1    Shanghai                      China                              22315474
   2    Buenos Aires                  Argentina                          13076300
   3    Mumbai                        India                              12691836
   4    Mexico City                   Mexico                             12294193
   5    Beijing                       China                              11716620
   6    Karachi                       Pakistan                           11624219
   7    Istanbul                      Turkey                             11174257
   8    Tianjin                       China                              11090314
   9    Guangzhou                     China                              11071424
  10    Delhi                         India                              10927986

Exemple:2eme cas d'utilisation DEPASSEMENT DE BORNE

[bc491136@malt CoursProgrammation]$ ./tp1 5001
Attention!La valeur entree doit etre comprise entre 1 et 5000 SVP!

Exemple:3eme cas d'utilisation NOMBRE D'ARGUMENTS INVALIDES

[bc491136@malt CoursProgrammation]$ ./tp1
Attention arguments invalides!!Le nombres d'arguments doit etre egal a 2 SVP!

## Contenu du projet

<décrivez brièvement chacun des fichiers contenus dans le projet (une phrase
par fichier)>

## Références

 L'algorithme du tri QSORT a été inspiré et adapté du tri obtenu sur
le site http://www.bien-programmer.fr/qsort.htm
COPYRIGTH hiveNzin0 25/04/2009 21:28:20 Bien programmer en langage C

## Statut

Le projet a été completé avec succes.
