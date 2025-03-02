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
    *sortie_ligne = util_generer_nombre_aleatoire(0, (NB_COLONNES - 1));
}


// Definir la fonction 'terrain_generer_position_depart' ici

void terrain_generer_position_depart(int destination_ligne, int destination_colonne, int
                                     *depart_lignes, int *depart_colonne) {
    int distance_tot = 0;
    int distance_ligne = 0;
    int distance_colonne = 0;
    *depart_lignes = util_generer_nombre_aleatoire(0, (NB_COLONNES - 1));
    *depart_colonne = util_generer_nombre_aleatoire(0, (NB_COLONNES - 1));

    distance_ligne = destination_ligne - *depart_lignes;
    distance_colonne = destination_colonne - *depart_colonne;

    if (distance_ligne < 0) {
        distance_ligne *= -1;
    }
    if (distance_colonne < 0) {
        distance_colonne *= -1;
    }

    distance_tot = distance_ligne + distance_colonne;

    if (distance_tot < DISTANCE_MIN) {
        do {
            *depart_lignes = util_generer_nombre_aleatoire(
                (NB_LIGNES - 1), (NB_COLONNES - 1));
            *depart_colonne = util_generer_nombre_aleatoire(
                NB_LIGNES - 1, (NB_COLONNES - 1));

            distance_ligne = destination_ligne - *depart_lignes;
            distance_colonne = destination_colonne - *depart_colonne;

            if (distance_ligne < 0) {
                distance_ligne *= -1;
            }
            if (distance_colonne < 0) {
                distance_colonne *= -1;
            }

            distance_tot = distance_ligne + distance_colonne;
        } while (distance_tot < DISTANCE_MIN);
    }
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

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (i == position_ligne && j == position_colonne) {
                carburant = terrain[i][j];
            }
        }
    }

    return carburant;
}


// Definir la fonction 'terrain_set_carburant' ici


// Definir la fonction 'terrain_init' ici

void terrain_init(int terrain[NB_LIGNES][NB_COLONNES]) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            terrain[i][j] = NULL;
        }
    }
}


// Definir la fonction 'terrain_creer_stations_carburant' ici

// Definir la fonction 'terrain_afficher' ici
