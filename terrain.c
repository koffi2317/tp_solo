//
//// Created by stephane on 08/01/25.
////
#include "terrain.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "couleur.h"

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'terrain_generer_position_sortie' ici

void terrain_generer_position_sortie(int *sortie_ligne, int *sortie_colonne) {
    *sortie_colonne = util_generer_nombre_aleatoire(0, (NB_COLONNES - 1));
    *sortie_ligne = util_generer_nombre_aleatoire(0, (NB_LIGNES - 1));
}


// Definir la fonction 'terrain_generer_position_depart' ici

void terrain_generer_position_depart(int destination_ligne, int destination_colonne, int
*depart_ligne, int *depart_colonne) {
    int distance_tot = 0;
    int distance_ligne = 0;
    int distance_colonne = 0;

    do {
        *depart_ligne = util_generer_nombre_aleatoire(0, NB_LIGNES - 1);
        *depart_colonne = util_generer_nombre_aleatoire(0, NB_COLONNES - 1);

        distance_ligne = valeur_absolue_donnee(destination_ligne - *depart_ligne);
        distance_colonne = valeur_absolue_donnee(destination_colonne - *depart_colonne);
        distance_tot = distance_ligne + distance_colonne;

    } while (distance_tot < DISTANCE_MIN);
}

// Definir la fonction 'terrain_contient' ici

int terrain_contient(int position_ligne, int position_colonne) {
    if (position_ligne < 0) {
        return FALSE;
    } else if (position_ligne >= TAILLE_TAB) {
        return FALSE;
    } else if (position_colonne < 0) {
        return FALSE;
    } else if (position_colonne >= TAILLE_TAB) {
        return FALSE;
    } else {
        //Changement des coordonnées du joueur pour la case choisie
        return TRUE;
    }
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

void terrain_creer_stations_carburant(int terrain[NB_LIGNES][NB_COLONNES], int quantite_globale) {
    while (quantite_globale > 0) {

        int carburant;
        int i, j;

        do {
            i = util_generer_nombre_aleatoire(0, NB_LIGNES - 1);
            j = util_generer_nombre_aleatoire(0, NB_COLONNES - 1);
        } while (terrain[i][j] != 0);

        carburant = util_generer_nombre_aleatoire(0, (quantite_globale < STATION_MAX_CARBURANT ?
                                                      quantite_globale : STATION_MAX_CARBURANT));

        terrain[i][j] = carburant;

        quantite_globale -= carburant;
    }
}
// Definir la fonction 'terrain_afficher' ici

void terrain_afficher(int terrain[NB_LIGNES][NB_COLONNES], int courante_ligne, int courante_colonne,
                      int destination_ligne, int destination_colonne) {
    printf("TERRAIN :\n");
    printf("\n");
    //couleur_set(7,30,47);
    printf("\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t\n");
    //couleur_reset();
    for (int i = 0; i < NB_LIGNES; i++) {
        //couleur_set(7, 30, 47);
        printf("%i\t",i);
        //couleur_reset();
        for (int j = 0; j < NB_COLONNES; j++) {
            if (i == courante_ligne && j == courante_colonne) {
                //couleur_set(0, 32, 40);
                printf("X\t");
                //couleur_reset();
            } else if (i == destination_ligne && j == destination_colonne) {
                //couleur_set(0, 31, 40);
                printf("S\t");
                //couleur_reset();
            } else {
                printf("%i\t", terrain[i][j]);
            }
        }
        printf("\n");
    }
}