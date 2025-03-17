/*************************************************************************************
 * Nom du fichier  : dijkstra.c
 * Description     : Ce fichier implémente l'algorithme de Dijkstra pour calculer
 *                   le chemin optimal d'un véhicule sur un terrain en tenant
 *                   compte de la consommation de carburant et de la gestion des
 *                   ressources. Le programme permet au joueur de se déplacer tout
 *                   en optimisant son parcours vers la destination finale. Il
 *                   gère les visites des cases, les mises à jour des coûts et
 *                   propose un bonus de déplacement pour optimiser le trajet.
 *                   L'algorithme explore les voisins de chaque case pour déterminer
 *                   le chemin le moins coûteux en carburant et suit un ensemble de
 *                   directions pour garantir l'efficacité du trajet.
 *
 * Connectivité    : dijkstra.h, terrain.h, stdio.h, limits.h, jeu.h, stdbool.h
 *************************************************************************************/

#include "dijkstra.h"
#include "terrain.h"
#include "jeu.h"
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

//  ****************************
//  Definitions des types prives
//  ****************************
//  Type pour le tableau des couts qui donne le cout en carburant du plus court chemin du depart a l'une des cases du terrain
typedef int t_couts[NB_LIGNES][NB_COLONNES];

//  Type pour le tableau 2D permettant de savoir si une case a deja ete visitee lors de l'algorithme de Dijkstra
typedef bool t_visites[NB_LIGNES][NB_COLONNES];

//  Type pour coder la direction d'ou on vient pour atteindre l'une des cases du terrain en suivant le plus court chemin
typedef t_direction t_precedents[NB_LIGNES][NB_COLONNES];

//  **********************************
//  Declarations des fonctions privees
//  **********************************

/**
 * @brief Initialise tous les couts avec le plus grand entier du type int.
 * Initialise egalement le cout de la case du joueur a 0.
 * @name initialiser_couts
 * @param couts le tableau bi-dimensionnel des couts a initialiser
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 */
void initialiser_couts(t_couts couts, int joueur_ligne, int joueur_colonne);

/**
 * @brief Initialise toutes les cases a non visitee.
 * @name initialiser_visitees
 * @param visitees le tableau bi-dimensionnel qui indique, pour chaque case, si elle a deja ete visitee ou non.
 */
void initialiser_visitees(t_visites visitees);

/**
 * @brief Indique si une case donnee a deja ete visitee au cours de l'algorithme.
 * @name est_case_visitee
 * @param visitees le tableau a 2 dimensions qui indique, pour chaque case, si elle a deja ete visitee durant l'algorithme
 * @param case_ligne la ligne de la case a tester
 * @param case_colonne la colonne de la case a tester
 * @return true si la case a deja ete visitee, false sinon
 */
bool est_case_visitee(t_visites visitees, int case_ligne, int case_colonne);

/**
 * @brief Recherche la case non visitee qui possede le plus petit cout.
 * @name choisir_min_dist_non_visitee
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique si une case a deja ete visitee ou pas
 * @param case_choisie_ligne l'adresse ou deposer la ligne de la case choisie
 * @param case_choisie_colonne l'adresse ou deposer la colonne de la case choisie
 */
void choisir_min_dist_non_visitee(t_couts couts, t_visites visitees, int *case_choisie_ligne,
                                  int *case_choisie_colonne);

/**
 * @brief Retourne le cout de deplacement pour aller d'une case a une case voisine.
 * @name cout_deplacement
 * @param couts le tableau a 2 dimensions des couts
 * @param voisin_ligne la ligne de la case voisine vers laquelle on veut aller
 * @param voisin_colonne la colonne de la case voisine vers laquelle on veut aller
 * @return le cout du chemin pour se rendre a la case voisine specifiee en parametre
 * @note le cout pour aller d'une case a l'une de ses voisines est 1 + (9 - carburant dans la case voisine)
 */
int cout_deplacement(t_couts couts, int voisin_ligne, int voisin_colonne);

/**
* @brief Parcourt les voisins d'une case donnee et met a jour leur cout dans le tableau des couts.
*@name maj_voisins
* @param couts le tableau des couts
* @param visitees le tableau qui indique, pour toute case, si elle a deja ete visitee
* @param terrain le terrain qui contient les stations de carburant
* @param precedents le tableau des precedents qui est mis a jour si l'un des chemins ameliore un chemin deja trouve auparavant
* @param courante_ligne la ligne de la position courante a partir de laquelle on regarde les voisins
* @param courante_colonne la colonne de la position courante a partir de laquelle on regarde les voisins
 */
void maj_voisins(t_couts couts, t_visites visitees, t_terrain terrain, t_precedents precedents,
                 int courante_ligne, int courante_colonne);
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
void afficher_couts(t_couts couts, t_visites visitees, int joueur_ligne, int joueur_colonne
                    , int destination_ligne, int destination_colonne);

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
int calculer_chemin_bonus(t_precedents precedents, int depart_ligne, int depart_colonne
                          , int destination_ligne, int destination_colonne, int directions[4]);

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
void dijkstra(t_terrain terrain, int joueur_ligne, int joueur_colonne, int destination_ligne
              , int destination_colonne, t_precedents precedents);

/**
 * @brief Affiche les 4 premieres directions a suivre sur le plus court chemin pour joindre la destination a partir de la position du joueur
 * @name afficher_direction_suggeree
 * @param dircetions les premieres directions a suivre sur le plus court chemin
 * @param nb le nombre de directions a suivre
 */
void afficher_direction_suggeree(int directions[], int nb);


//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Le principe de case représente une position dans le terrain, selon la ligne, la colonne et le carburant.
typedef struct {
    int ligne, colonne, carburant;
} Case;
//elle est constitué des coordonnées verticale, horizontale ainsi que le cout attribué a une case

// Les différents chemin qu'un utlisateur peut emprunter est représenter par "haut, bas, gauche, droite"
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//ce tableau détient chaque direction possible pour un utilisateur. elles sont liées a
//la chaine de caractère qui contient les lettres associés a ces déplacements
char Charact_direction[4] = {'H','B','G','D'};

//La fonction qui non seulement permet a l'utilisateur d'acheter un bonus mais construit également le chemin optimal.
void dijkstra_acheter_bonus(int terrain[NB_LIGNES][NB_COLONNES], int joueur_ligne, int joueur_colonne,
                            int *joueur_carburant, int destination_ligne, int destination_colonne) {

     *joueur_carburant -= 10;
    printf("Felicitations, vous avez achete le bonus ! Il vous reste %d litres de carburant.\n"
           , *joueur_carburant);

    // Appel de l'algorithme Dijkstra pour calculer le plus court chemin
    t_precedents precedents;
    dijkstra(terrain, joueur_ligne, joueur_colonne, destination_ligne, destination_colonne, precedents);
}

//  *********************************
//  Definitions des fonctions privees
//  *********************************

/*Cette fonction Initialise tous les couts avec le plus grand entier du type int.
Initialise egalement le cout de la case du joueur a 0.*/
void initialiser_couts(t_couts couts, int joueur_ligne, int joueur_colonne) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (i == joueur_ligne && j == joueur_colonne) {
                couts[i][j] = 0;
            } else {
                couts[i][j] = INT_MAX;
            }
        }
    }
}

//Cette fonction initialise toutes les cases a non visitee (FALSE)
void initialiser_visitees(t_visites visitees) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            visitees[i][j] = FALSE;
        }
    }
}

//Cette fonction indique si une case donnee a deja ete visitee au cours de l'algorithme et retourne TRUE
bool est_case_visitee(t_visites visitees, int case_ligne, int case_colonne) {

    if (visitees[case_ligne][case_colonne] == TRUE) {
        return TRUE;
    }
    return FALSE;
}

//Cette fonction recherche la case non visitee qui possede le plus petit cout.
void choisir_min_dist_non_visitee(t_couts couts, t_visites visitees, int *case_choisie_ligne
                                  , int *case_choisie_colonne) {

    // min_cout : Coût minimal actuel, initialisé à la valeur maximale.
    int min_cout = INT_MAX;
    // ligne_choisie, colonne_choisie : Coordonnées de la case avec le coût minimal.
    int ligne_choisie = -1, colonne_choisie = -1;

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (!visitees[i][j] && couts[i][j] < min_cout) {
                min_cout = couts[i][j];
                ligne_choisie = i;
                colonne_choisie = j;
            }
        }
    }

    *case_choisie_ligne = ligne_choisie;
    *case_choisie_colonne = colonne_choisie;
}

//Cette fonction retourne le cout de deplacement pour aller d'une case a une case voisine.
int cout_deplacement(t_couts couts, int voisine_ligne, int voisine_colonne) {
    return 1 + (9 - couts[voisine_ligne][voisine_colonne]);
}

//Cette fonction parcourt les voisins d'une case donnee et met a jour leur cout dans le tableau des couts.
void maj_voisins(t_couts couts, t_visites visitees, t_terrain terrain, t_precedents precedents
                 , int courante_ligne, int courante_colonne) {

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int d = 0; d < 4; d++) {
        // Calcul des coordonnées du voisin en fonction de la direction actuelle (d).
        int voisin_ligne = courante_ligne + directions[d][0];
        int voisin_colonne = courante_colonne + directions[d][1];

        if (voisin_ligne >= 0 && voisin_ligne < NB_LIGNES && voisin_colonne >= 0 && voisin_colonne < NB_COLONNES) {

            if (!visitees[voisin_ligne][voisin_colonne]) {
                int nouveau_cout = couts[courante_ligne][courante_colonne] +
                        cout_deplacement(terrain,voisin_ligne,voisin_colonne);

                if (nouveau_cout < couts[voisin_ligne][voisin_colonne]) {
                    couts[voisin_ligne][voisin_colonne] = nouveau_cout;
                    precedents[voisin_ligne][voisin_colonne] = d;                }
            }
        }
    }
}

//Cette fonction affiche le tableau des couts
void afficher_couts(t_couts couts, t_visites visitees, int joueur_ligne, int joueur_colonne
                    , int destination_ligne, int destination_colonne) {

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {

            if (i == joueur_ligne && j == joueur_colonne) {
                printf(" X ");
            } else if (i == destination_ligne && j == destination_colonne) {
                printf(" S ");
            } else if (visitees[i][j]) {
                printf(" %2d ", couts[i][j]);
            } else {
                printf("  \n");
            }
        }
    }
}

//Cette fonction calcule les 4 premieres cases du plus court chemin en terme de carburant.
int calculer_chemin_bonus(t_precedents precedents, int depart_ligne, int depart_colonne, int destination_ligne
                          , int destination_colonne, int directions[4]) {

    int lexique_des_repères = 0;   // Compteur pour les directions trouvées
    int ligne = destination_ligne; // Ligne de la destination
    int colonne = destination_colonne; // Colonne de la destination

    // Directions possibles (haut, bas, gauche, droite)
    int directions_possibles[4][2] =
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Remonter le chemin depuis la destination en utilisant le tableau des précédents
    while (ligne != depart_ligne || colonne != depart_colonne) {
        // Vérification si on a déjà trouvé 4 directions, on s'arrête si oui
        if (lexique_des_repères >= 4) {
            break;
        }

        printf("Case (%d, %d) -> precedents = %d\n", ligne, colonne, precedents[ligne][colonne]);

        // Trouver la direction vers laquelle nous venons (en utilisant le tableau precedents)
        int direction = precedents[ligne][colonne];

        if (direction >= 0 && direction < 4) {
            directions[lexique_des_repères++] = direction;

            // Calculer les nouvelles coordonnées en fonction de la direction
            ligne -= directions_possibles[direction][0];  // Déplacement en ligne
            colonne -= directions_possibles[direction][1]; // Déplacement en colonne
        } else {

            break;
        }
    }

    // Inverser les directions pour obtenir le chemin du départ vers la destination
    for (int i = 0; i < lexique_des_repères / 2; i++) {
        int temp = directions[i];
        directions[i] = directions[lexique_des_repères - 1 - i];
        directions[lexique_des_repères - 1 - i] = temp;
    }

    return lexique_des_repères;
}

//Cette fonction contient l'algorithme de Dijkstra pour calculer le plus court chemin en partent
// de la position du joueur pour atteindre la position de destination.
void dijkstra(t_terrain terrain, int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne,
              t_precedents precedents) {
    // Déclaration d'une structure pour stocker les coûts associés à chaque case.
    t_couts couts;
    // Déclaration d'une structure pour suivre les cases visitées.
    t_visites visitees;


    initialiser_couts(couts, joueur_ligne, joueur_colonne);
    initialiser_visitees(visitees);

    while (TRUE) {
        // Chercher la case non visitée avec le coût minimal
        int case_ligne, case_colonne;
        choisir_min_dist_non_visitee(couts, visitees, &case_ligne, &case_colonne);

        if (case_ligne == -1 || (case_ligne == destination_ligne && case_colonne == destination_colonne)) {
            break;
        }
        if (!est_case_visitee(visitees, case_ligne, case_colonne)) {
            visitees[case_ligne][case_colonne] = TRUE;

            maj_voisins(couts, visitees, terrain, precedents, case_ligne, case_colonne);
        }
    }

    // Tableau pour stocker les directions suggérées (haut, bas, gauche, droite).
    int directions_suggerees[4];
    /* Appel de la fonction calculer_chemin_bonus pour calculer le chemin optimal et stocker les directions
     suggérées dans le tableau directions_suggerees. */
    int nb_directions = calculer_chemin_bonus(precedents,joueur_ligne, joueur_colonne
                                              , destination_ligne, destination_colonne, directions_suggerees);

    afficher_direction_suggeree(directions_suggerees,nb_directions);
}

//Cette fonction affiche les 4 premieres directions a suivre sur le plus court chemin pour joindre
// la destination a partir de la position du joueur.
void afficher_direction_suggeree(int directions[], int nb) {
    const char *nom_chemin[4] = {"Haut", "Bas", "Gauche", "Droite"};

    printf("A partir de l'algorithme, les directions suggerees sont: ");
    for (int i = 0; i < nb; i++) {  // Utilisez 'nb' pour afficher les directions suggérées
        printf("%s ", nom_chemin[directions[i]]);  // Correction de la syntaxe du printf
    }
    printf("\n");
}
