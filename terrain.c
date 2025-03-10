//
// Created by stephane on 08/01/25.
//
#include "terrain.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'terrain_generer_position_sortie' ici

void terrain_generer_position_sortie(int *sortie_colonne, int *sortie_ligne) {
    *sortie_colonne = util_generer_nombre_aleatoire(0, (NB_COLONNES - 1));
    *sortie_ligne = util_generer_nombre_aleatoire(0, (NB_LIGNES - 1));
}


// Definir la fonction 'terrain_generer_position_depart' ici

void terrain_generer_position_depart(int destination_ligne, int destination_colonne, int
*depart_lignes, int *depart_colonne) {
    int distance_tot = 0;
    int distance_ligne = 0;
    int distance_colonne = 0;

    do {
        *depart_lignes = util_generer_nombre_aleatoire(0, NB_LIGNES - 1);
        *depart_colonne = util_generer_nombre_aleatoire(0, NB_COLONNES - 1);

        distance_ligne = abs(destination_ligne - *depart_lignes);
        distance_colonne = abs(destination_colonne - *depart_colonne);
        distance_tot = distance_ligne + distance_colonne;

    } while (distance_tot < DISTANCE_MIN);
}

// Definir la fonction 'terrain_contient' ici

int terrain_contient(int position_ligne, int position_colonne) {
    if (position_ligne < 0 || position_ligne > NB_LIGNES - 1) {
        return FALSE;
    } else if (position_colonne < 0 || position_colonne > NB_COLONNES - 1) {
        return FALSE;
    }

    return TRUE;
}

// Definir la fonction 'terrain_get_carburant' ici

int terrain_get_carburant(int terrain[NB_LIGNES][NB_COLONNES], int position_ligne, int
position_colonne) {
    int carburant = 0;

    carburant = terrain[position_ligne][position_colonne];

    return carburant;
}


// Definir la fonction 'terrain_set_carburant' ici
/*a ne pas oublier! tres important!*/

void terrain_set_carburant(int terrain[NB_LIGNES][NB_COLONNES],int position_ligne, int
position_colonne, int carburant) {

    terrain[position_ligne][position_colonne] = carburant;
}

// Definir la fonction 'terrain_init' ici

void terrain_init(int terrain[NB_LIGNES][NB_COLONNES]) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            terrain[i][j] = 0;
        }
    }
}

// Definir la fonction 'terrain_creer_stations_carburant' ici

void terrain_creer_stations_carburant(int terrain[NB_LIGNES][NB_COLONNES], int
quantité_globale) {
    int carburant = 0;

    while (quantité_globale > 0) {
        int i = 0;
        int j = 0;

        i = util_generer_nombre_aleatoire(0,NB_LIGNES - 1);
        j = util_generer_nombre_aleatoire(0,NB_COLONNES - 1);
        if (terrain[i][j] == 0) {
            carburant = util_generer_nombre_aleatoire(0,STATION_MAX_CARBURANT);
            if (carburant > quantité_globale) {
                do {
                    carburant = util_generer_nombre_aleatoire(0,STATION_MAX_CARBURANT);
                } while (carburant > quantité_globale);
            }
            terrain[i][j] = carburant;
        }
        quantité_globale -= carburant;
    }
}

// Definir la fonction 'terrain_afficher' ici

void terrain_afficher(int terrain[NB_LIGNES][NB_COLONNES], int courante_ligne, int courante_colonne,
                      int destination_ligne, int destination_colonne) {
    printf("TERRAIN :\n");
    printf("\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t\n");
    for (int i = 0; i < NB_LIGNES; i++) {
        printf("%i\t",i);
        for (int j = 0; j < NB_COLONNES; j++) {
            if (i == courante_ligne && j == courante_colonne) {
                printf("X\t");
            } else if (i == destination_ligne && j == destination_colonne) {
                printf("S\t");
            } else {
                printf("%i\t", terrain[i][j]);
            }
        }
        printf("\n");
    }
}