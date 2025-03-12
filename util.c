//
// Created by akakp on 24/02/2025.
//
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

int retour_du_plus_petit(int nombre_a, int nombre_b) {
    return MIN(nombre_a, nombre_b);
}

int valeur_absolue_donnee(int nombre_a) {
    return ABS(nombre_a);
}

int util_generer_nombre_aleatoire(int min, int max) {
    return min + (int) (rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

int util_symetrique(int min, int max, int nombre_n) {
    return (max - (nombre_n - min));
}