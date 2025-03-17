/**
Nom du fichier : util.c
Description  :
Ce module propose des fonctionnalités qui simplifient diverses opérations fondamentales,
comme la comparaison de chiffres, la création de nombres aléatoires et la gestion de valeurs symétriques.

Ils seront employés dans d'autres modules du projet. Pour cela, les fichiers util.h et util.c
Ils pourront implémenter les programmes suivants :

Macro fonction qui calcule le plus petit de deux entiers passés en paramètre.
Paramètres : a = le premier entier à comparer et b = le second entier à comparer.
Résultat: Le plus petit des deux entiers, a ou b.

Macro fonction ABS qui calcule la valeur absolue d’un entier passé en paramètre.
Paramètres : a = l’entier dont on veut la valeur absolue.
Résultat: La valeur absolue de a.

 connectivité : util.h, stdio.h, stdlib.h, time.h
**/

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

//fonction qui calcule le plus petit de deux entiers passés en paramètre.
int retour_du_plus_petit(int nombre_a, int nombre_b) {
    return MIN(nombre_a, nombre_b);
}

//fonction qui calcule la valeur absolue d’un entier passé en paramètre.
int valeur_absolue_donnee(int nombre_a) {
    return ABS(nombre_a);
}

//fonction qui génère et retourne un nombre entier pseudo-aléatoire. Elle est compris dans un intervalle défini par les bornes passées en paramètre.
int util_generer_nombre_aleatoire(int min, int max) {
    return min + (int) (rand() / (RAND_MAX + 0.001) * (max - min + 1));
}
//fonction qui calcule et retourne le symétrique d'un entier. C'est défini dans un intervalle par ses bornes.
int util_symetrique(int min, int max, int nombre_n) {
    return (max - (nombre_n - min));
}