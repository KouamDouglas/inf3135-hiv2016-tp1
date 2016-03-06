Évaluation
~~~~~~~~~~

+-------------------------+----------------------------+-----------+-----------+
| Critère                 | Sous-critère               | Résultat  | Sur       |
+=========================+============================+===========+===========+
|                         | Chargement des pays        | 10        | 10        |
|                         +----------------------------+-----------+-----------+
|                         | Chargement des villes      | 10        | 10        |
|                         +----------------------------+-----------+-----------+
| Fonctionnabilité        | Tri selon la population    | 10        | 10        |
|                         +----------------------------+-----------+-----------+
|                         | Arguments de la fonction   | 10        | 10        |
|                         | ``main``                   |           |           |
|                         +----------------------------+-----------+-----------+
|                         | Qualité de l'affichage     | 10        | 10        |
|                         | (colonnes alignées)        |           |           |
+-------------------------+----------------------------+-----------+-----------+
|                         | Modularité fonctionnelle   | 10        | 10        |
|                         +----------------------------+-----------+-----------+
|                         | Style de programmation     | 4         | 5         |
| Qualité du code         +----------------------------+-----------+-----------+
|                         | Documentation (en-tête du  | 4         | 5         |
|                         | fichier et des fonctions)  |           |           |
+-------------------------+----------------------------+-----------+-----------+
|                         | Compilation et nettoyage   |           |           |
|                         | (``make`` et               | 10        | 10        |
|                         | ``make clean``)            |           |           |
| Makefile                +----------------------------+-----------+-----------+
|                         | Téléchargement des données | 5         | 5         |
|                         | (``make database``)        |           |           |
+-------------------------+----------------------------+-----------+-----------+
|                         | Commits significatifs      | 8         | 10        |
| Utilisation de Git      +----------------------------+-----------+-----------+
|                         | Qualité des messages de    | 5         | 5         |
|                         | commits                    |           |           |
+-------------------------+----------------------------+-----------+-----------+
| **Total**                                            | **96**    | **100**   |
+-------------------------+----------------------------+-----------+-----------+

Commentaires
------------

- Au niveau de l'exécution, tout est fonctionnel.
- Bonne modularité.
- Style de programmation. Très bien dans l'ensemble.
  
  * Éviter les valeurs magiques (qui devraient être des constantes);
  * Documenter l'en-tête de fichier;
  * Documenter les structures de données;
  * Une ligne du programme est longue et devrait être raccourcie.

- Le fichier README n'utilise pas Markdown à son plein potentiel. Pour les
  énumérations, mettre un espace après le tiret pour obtenir une listes, pour
  les bouts de code, utiliser la syntaxe pour les délimiter (voir par exemple
  https://bitbucket.org/tutorials/markdowndemo/overview#markdown-header-code-and-syntax-highlighting).
- Makefile correct. Il serait préférable d'utiliser des variables pour les noms
  de fichiers.
- Très bonne utilisation de Git, sauf pour un élément : il ne faut pas
  versionner les fichiers volumineux, qui utilisent inutilement de l'espace
  pour le projet.
