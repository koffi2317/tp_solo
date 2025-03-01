//
// Created by akakp on 24/02/2025.
//
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int retour_du_plus_petit(int nombre_a, int nombre_b) {
    return MIN(nombre_a, nombre_b);
}

int valeur_absolue_donnee(int nombre_a) {
    return ABS(nombre_a);
}

int util_generer_nombre_aleatoire(int min, int max) {
    srand((unsigned int) time(NULL));
    rand();
    return min + (int) (rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

int util_symetrique(int min, int max, int nombre_n) {
    int symetrie = 0;
    int position = 0;
    int millieu = 0;

    millieu = (max - min) / 2;

    position = min + millieu;
    if (nombre_n > position) {
        symetrie = (max - nombre_n);
        symetrie = min + symetrie;
    } else if (nombre_n < position) {
        symetrie = (nombre_n - min);
        symetrie = max - symetrie;
    }


    return symetrie;
}
