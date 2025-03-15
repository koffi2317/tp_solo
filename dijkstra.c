//
// Created by stephane on 08/01/25.
//

//  ****************************
//  Definitions des types prives
//  ****************************
//  Type pour le tableau des couts qui donne le cout en carburant du plus court chemin du depart a l'une des cases du terrain
#include "dijkstra.h"
#include "terrain.h"
#include "jeu.h"
#include <stdbool.h>
#include <stdio.h>
#define INFINITY 9
#define NB_DIRECTIONS 4
typedef int t_couts[NB_LIGNES][NB_COLONNES];

//  Type pour le tableau 2D permettant de savoir si une case a deja ete visitee lors de l'algorithme de Dijkstra
typedef bool t_visites[NB_LIGNES][NB_COLONNES];

//  Type pour coder la direction d'ou on vient pour atteindre l'une des cases du terrain en suivant le plus court chemin
typedef t_direction t_precedents[NB_LIGNES][NB_COLONNES];

//  **********************************
//  Declarations des fonctions privees
//  **********************************

void initialiser_couts(t_couts couts, int joueur_ligne, int joueur_colonne);
void initialiser_visitees(t_visites visitees);
bool est_case_visitee(t_visites visitees, int case_ligne, int case_colonne);
void choisir_min_dist_non_visitee(t_couts couts, t_visites visitees, int *case_choisie_ligne, int *case_choisie_colonne);
int cout_deplacement(int carburant_case);
void maj_voisins(t_couts couts, t_visites visitees, t_terrain terrain, t_precedents precedents, int courante_ligne, int courante_colonne);
void dijkstra(t_terrain terrain, int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne, t_precedents precedents);
int calculer_chemin_bonus(t_precedents precedents, int depart_ligne, int depart_colonne, int destination_ligne, int destination_colonne, int directions[4]);
void afficher_couts(t_couts couts, t_visites visitees, int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne);
void afficher_direction_suggeree(int directions[]);
/*
 * @brief Initialise tous les couts avec le plus grand entier du type int.
 * Initialise egalement le cout de la case du joueur a 0.
 * @name initialiser_couts
 * @param couts le tableau bi-dimensionnel des couts a initialiser
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 */
<<<<<<< Updated upstream
//  Ecrire le prototype de la fonction 'initialiser_couts' ici bon!
=======
//  Ecrire le prototype de la fonction 'initialiser_couts' ici
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  //à l'exception de la case de départ du joueur, dont le coût est initialisé à 0.


/**
 * @brief Initialise toutes les cases a non visitee.
 * @name initialiser_visitees
 * @param visitees le tableau bi-dimensionnel qui indique, pour chaque case, si elle a deja ete visitee ou non.
 */
//  Ecrire le prototype de la fonction 'initialiser_visitees' ici bon!

/**
 * @brief Indique si une case donnee a deja ete visitee au cours de l'algorithme.
 * @name est_case_visitee
 * @param visitees le tableau a 2 dimensions qui indique, pour chaque case, si elle a deja ete visitee durant l'algorithme
 * @param case_ligne la ligne de la case a tester
 * @param case_colonne la colonne de la case a tester
 * @return true si la case a deja ete visitee, false sinon
 */
//  Ecrire le prototype de la fonction 'est_case_visitee' ici bon!

/**
 * @brief Recherche la case non visitee qui possede le plus petit cout.
 * @name choisir_min_dist_non_visitee
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique si une case a deja ete visitee ou pas
 * @param case_choisie_ligne l'adresse ou deposer la ligne de la case choisie
 * @param case_choisie_colonne l'adresse ou deposer la colonne de la case choisie
 */
//  Ecrire le prototype de la fonction 'choisir_min_dist_non_visitee' ici bon!

/**
 * @brief Retourne le cout de deplacement pour aller d'une case a une case voisine.
 * @name cout_deplacement
 * @param couts le tableau a 2 dimensions des couts
 * @param voisin_ligne la ligne de la case voisine vers laquelle on veut aller
 * @param voisin_colonne la colonne de la case voisine vers laquelle on veut aller
 * @return le cout du chemin pour se rendre a la case voisine specifiee en parametre
 * @note le cout pour aller d'une case a l'une de ses voisines est 1 + (9 - carburant dans la case voisine)
 */
//  Ecrire le prototype de la fonction 'cout_deplacement'  bon!

/**
 * @brief Parcourt les voisins d'une case donnee et met a jour leur cout dans le tableau des couts.
 * @name maj_voisins
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique, pour toute case, si elle a deja ete visitee
 * @param terrain le terrain qui contient les stations de carburant
 * @param precedents le tableau des precedents qui est mis a jour si l'un des chemins ameliore un chemin deja trouve auparavant
 * @param courante_ligne la ligne de la position courante a partir de laquelle on regarde les voisins
 * @param courante_colonne la colonne de la position courante a partir de laquelle on regarde les voisins
 */
//  Ecrire le prototype de la fonction 'maj_voisins' ici

/**
 * @brief Affiche le tableau des couts
 * @name afficher_couts
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique si une case a deja ete visitee ou pas durant l'algorithme
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param destination_ligne la ligne de la position a atteindre
 * @param destination_colonne la colonne de la position a atteindre
 */
//  Ecrire le prototype de la fonction 'afficher_couts' ici

/**
 * @brief Calcule les 4 premieres cases du plus court chemin en terme de carburant
 * @name calculer_chemin_bonus
 * @param precedents tableau de directions qui indique de quelle direction on vient pour atteindre une case du terrain en suivant le plus court chemin
 * @param depart_ligne la ligne de la case de depart
 * @param depart_colonne la colonne de la case de depart
 * @param destination_ligne la ligne de la case a atteindre
 * @param destination_colonne la colonne de la case a atteindre
 * @param directions les 4 premieres directions (au plus) a suivre sur le plus court chemin du depart a l'arrivee
 * @return le nombre de directions proposees par l'algorithme (normalement 4, mais peut etre plus petit)
 */
//  Ecrire le prototype de la fonction 'calculer_chemin_bonus' ici

/**
 * @brief Algorithme de Dijkstra pour calculer le plus court chemin en partent de la position du joueur pour atteindre
 * la position de destination.
 * @name dijkstra
 * @param terrain la terrain sur lequel le joueur evolue
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param destination_ligne la ligne de la case a atteindre
 * @param destination_colonne la colonne de la case a atteindre
 * @param directions les 4 premieres directions a suivre sur le plus court chemin
 * @return
 */
//  Ecrire le prototype de la fonction 'dijkstra' ici

/**
 * @brief Affiche les 4 premieres directions a suivre sur le plus court chemin pour joindre la destination a partir de la position du joueur
 * @name afficher_direction_suggeree
 * @param dircetions les premieres directions a suivre sur le plus court chemin
 * @param nb le nombre de directions a suivre
 */
//  Ecrire le prototype de la fonction 'afficher_direction_suggeree' ici

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************
// Definir la fonction 'dijkstra_acheter_bonus' ici

//  *********************************
//  Definitions des fonctions privees
//  *********************************

void initialiser_couts(t_couts couts, int joueur_ligne, int joueur_colonne) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if ( i == joueur_ligne && j == joueur_colonne ) {
                couts[i][j] = 0;
            }
            couts[i][j] = INFINITY;
        }
    }
}

void initialiser_visitees(t_visites visitees) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            visitees[i][j] = false;
        }
    }
}

bool est_case_visitee(t_visites visitees, int case_ligne, int case_colonne) {

    if (visitees[case_ligne][case_colonne] == TRUE) {
        return TRUE;
    }
    return FALSE;
}

void choisir_min_dist_non_visitee(t_couts couts, t_visites visitees, int *case_choisie_ligne, int *case_choisie_colonne) {

    int min_cout = INFINITY;
    *case_choisie_ligne = -1;
    *case_choisie_colonne = -1;

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (visitees[i][j] == FALSE && couts[i][j] < min_cout) {
                min_cout = couts[i][j];
                *case_choisie_ligne = i;
                *case_choisie_colonne = j;
            }
        }
    }
}

int cout_deplacement(t_couts couts, int voisine_ligne, int voisine_colonne) {

    return 1 + (9 - couts[voisine_ligne][voisine_colonne]);
}

void maj_voisins(t_couts couts, t_visites visitees, t_terrain terrain, t_precedents precedents, int courante_ligne, int courante_colonne) {/**/
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int d = 0; d < 4; d++) {
        int voisin_ligne = courante_ligne + directions[d][0];
        int voisin_colonne = courante_colonne + directions[d][1];

        if (voisin_ligne >= 0 && voisin_ligne < NB_LIGNES && voisin_colonne >= 0 && voisin_colonne < NB_COLONNES) {

            if (!visitees[voisin_ligne][voisin_colonne]) {
                int nouveau_cout = couts[courante_ligne][courante_colonne] + cout_deplacement(terrain[voisin_ligne][voisin_colonne]);

                if (nouveau_cout < couts[voisin_ligne][voisin_colonne]) {
                    couts[voisin_ligne][voisin_colonne] = nouveau_cout;
                    precedents[voisin_ligne][voisin_colonne] = d;                }
            }
        }
    }
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
/**
 * @brief Algorithme de Dijkstra pour calculer le plus court chemin en partent de la position du joueur pour atteindre
 * la position de destination.
 * @name dijkstra
 * @param terrain la terrain sur lequel le joueur evolue
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param destination_ligne la ligne de la case a atteindre
 * @param destination_colonne la colonne de la case a atteindre
 * @param directions les 4 premieres directions a suivre sur le plus court chemin
 * @return
 */
//  Ecrire le prototype de la fonction 'dijkstra' ici

<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
 void dijkstra(t_terrain terrain, int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne, t_precedents precedents) {
    t_couts couts;
    t_visites visitees;

    initialiser_couts(couts, joueur_ligne, joueur_colonne);
    initialiser_visitees(visitees);

    while (TRUE) {
        int case_ligne, case_colonne;
        choisir_min_dist_non_visitee(couts, visitees, &case_ligne, &case_colonne);

        /*if (case_ligne == -1 || (case_ligne == destination_ligne && case_colonne == destination_colonne)) {
            break;
        }*/
        while ( case_ligne == -1) {
            if (case_ligne == destination_ligne && case_colonne == destination_colonne) {
                break;
            }
        }

        visitees[case_ligne][case_colonne] = TRUE;
        //maj_voisins(couts, visitees, terrain, precedents, case_ligne, case_colonne);
    }
}

int calculer_chemin_bonus(t_precedents precedents, int depart_ligne, int depart_colonne, int destination_ligne, int destination_colonne, int directions[4]) {
    int ligne = destination_ligne, colonne = destination_colonne;
    int i = 0;
    while (i < 4 && (ligne != depart_ligne || colonne != depart_colonne)) {
        int direction = precedents[ligne][colonne];
        directions[i++] = direction;
        ligne -= (direction == 1) - (direction == 0);
        colonne -= (direction == 3) - (direction == 2);
    }
    return i;
}

//  Ecrire le prototype de la fonction 'afficher_couts' ici
void afficher_couts(t_couts couts, t_visites visitees, int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {

            if (i == joueur_ligne && j == joueur_colonne) {
<<<<<<< Updated upstream
<<<<<<< Updated upstream
                printf("  ");
            } else if (i == destination_ligne && j == destination_colonne) {
                printf("  ");
=======
                printf(" X ");
            } else if (i == destination_ligne && j == destination_colonne) {
                printf(" S ");
>>>>>>> Stashed changes
=======
                printf(" X ");
            } else if (i == destination_ligne && j == destination_colonne) {
                printf(" S ");
>>>>>>> Stashed changes
            } else if (visitees[i][j]) {
                printf(" %2d ", couts[i][j]);
            } else {
                printf("  \n");
            }
        }
    }
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    // printf(tab couts)?
=======
    // printf(tab couts)
>>>>>>> Stashed changes
=======
    // printf(tab couts)
>>>>>>> Stashed changes
}

void afficher_direction_suggeree(int directions[]) {
    printf("À partir de l'algorithme, les directions suggérées sont:\n ");
    for (int i = 0; i < NB_DIRECTIONS; i++) {
        printf("%d ", directions[i]);
    }
}
/**
 * @brief Affiche les 4 premieres directions a suivre sur le plus court chemin pour joindre la destination a partir de la position du joueur
 * @name afficher_direction_suggeree
 * @param dircetions les premieres directions a suivre sur le plus court chemin
 * @param nb le nombre de directions a suivre
 */