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
#include <limits.h>

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

/**
 * @brief Initialise tous les couts avec le plus grand entier du type int.
 * Initialise egalement le cout de la case du joueur a 0.
 * @name initialiser_couts
 * @param couts le tableau bi-dimensionnel des couts a initialiser
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 */
//  Ecrire le prototype de la fonction 'initialiser_couts' ici
void initialiser_couts(t_couts couts, int joueur_ligne, int joueur_colonne);

/**
 * @brief Initialise toutes les cases a non visitee.
 * @name initialiser_visitees
 * @param visitees le tableau bi-dimensionnel qui indique, pour chaque case, si elle a deja ete visitee ou non.
 */
//  Ecrire le prototype de la fonction 'initialiser_visitees' ici
void initialiser_visitees(t_visites visitees);

/**
 * @brief Indique si une case donnee a deja ete visitee au cours de l'algorithme.
 * @name est_case_visitee
 * @param visitees le tableau a 2 dimensions qui indique, pour chaque case, si elle a deja ete visitee durant l'algorithme
 * @param case_ligne la ligne de la case a tester
 * @param case_colonne la colonne de la case a tester
 * @return true si la case a deja ete visitee, false sinon
 */
//  Ecrire le prototype de la fonction 'est_case_visitee' ici
bool est_case_visitee(t_visites visitees, int case_ligne, int case_colonne);

/**
 * @brief Recherche la case non visitee qui possede le plus petit cout.
 * @name choisir_min_dist_non_visitee
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique si une case a deja ete visitee ou pas
 * @param case_choisie_ligne l'adresse ou deposer la ligne de la case choisie
 * @param case_choisie_colonne l'adresse ou deposer la colonne de la case choisie
 */
//  Ecrire le prototype de la fonction 'choisir_min_dist_non_visitee' ici
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
//  Ecrire le prototype de la fonction 'cout_deplacement' ici
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
//  Ecrire le prototype de la fonction 'maj_voisins' ici
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
//  Ecrire le prototype de la fonction 'afficher_couts' ici
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
//  Ecrire le prototype de la fonction 'calculer_chemin_bonus' ici
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
//  Ecrire le prototype de la fonction 'dijkstra' ici
void dijkstra(t_terrain terrain, int joueur_ligne, int joueur_colonne, int destination_ligne
              , int destination_colonne, t_precedents precedents);

/**
 * @brief Affiche les 4 premieres directions a suivre sur le plus court chemin pour joindre la destination a partir de la position du joueur
 * @name afficher_direction_suggeree
 * @param dircetions les premieres directions a suivre sur le plus court chemin
 * @param nb le nombre de directions a suivre
 */
//  Ecrire le prototype de la fonction 'afficher_direction_suggeree' ici
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
//la chaine de caractère qui contient les lettres associés a ces déplacement
char Charact_direction[4] = {'H','B','G','D'};

//La fonction qui non seulement permet a l'utilisateur d'acheter un bonus mais construit également le chemin optimal.
void dijkstra_acheter_bonus(int terrain[NB_LIGNES][NB_COLONNES], int joueur_ligne, int joueur_colonne,
                            int *joueur_carburant, int destination_ligne, int destination_colonne) {

     *joueur_carburant -= 10;
    printf("Felicitations, vous avez achete le bonus ! Il vous reste %d litres de carburant.\n"
           , *joueur_carburant);

    // Appel de l'algorithme Dijkstra pour calculer le plus court chemin
    t_precedents precedents; // Assurez-vous que la structure t_precedents est bien définie dans votre code
    dijkstra(terrain, joueur_ligne, joueur_colonne, destination_ligne, destination_colonne, precedents);

}




//  *********************************
//  Definitions des fonctions privees
//  *********************************

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


void initialiser_visitees(t_visites visitees) {
    //Les lignes et colonnes dans le tableau t_visites sont explorés.
    //Lorsque l'utilisateur n'a pas visité la case, cette derniere est marqué comme FALSE
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            visitees[i][j] = FALSE;
        }
    }
}

bool est_case_visitee(t_visites visitees, int case_ligne, int case_colonne) {
//Lorsque la case est visitée par le joueur, elle est considérée TRUE
    if (visitees[case_ligne][case_colonne] == TRUE) {
        return TRUE;
    }
    return FALSE;
}

void choisir_min_dist_non_visitee(t_couts couts, t_visites visitees, int *case_choisie_ligne
                                  , int *case_choisie_colonne) {

    int min_cout = INT_MAX;
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

int cout_deplacement(t_couts couts, int voisine_ligne, int voisine_colonne) {
    return 1 + (9 - couts[voisine_ligne][voisine_colonne]);
}

void maj_voisins(t_couts couts, t_visites visitees, t_terrain terrain, t_precedents precedents
                 , int courante_ligne, int courante_colonne) {

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int d = 0; d < 4; d++) {
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

        // Vérifier que la direction est valide (0-3) avant de l'utiliser
        if (direction >= 0 && direction < 4) {
            // Stocker la direction dans le tableau de sortie
            directions[lexique_des_repères++] = direction;

            // Calculer les nouvelles coordonnées en fonction de la direction
            ligne -= directions_possibles[direction][0];  // Déplacement en ligne
            colonne -= directions_possibles[direction][1]; // Déplacement en colonne
        } else {
            // Si une direction invalide est rencontrée, sortir de la boucle
            break;
        }
    }

    // Inverser les directions pour obtenir le chemin du départ vers la destination
    for (int i = 0; i < lexique_des_repères / 2; i++) {
        int temp = directions[i];
        directions[i] = directions[lexique_des_repères - 1 - i];
        directions[lexique_des_repères - 1 - i] = temp;
    }

    // Retourner le nombre de directions calculées
    return lexique_des_repères;
}

void dijkstra(t_terrain terrain, int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne,
              t_precedents precedents) {
    t_couts couts;
    t_visites visitees;

    // Initialisation des coûts et des cases visitées
    initialiser_couts(couts, joueur_ligne, joueur_colonne);
    initialiser_visitees(visitees);

    while (TRUE) {
        // Chercher la case non visitée avec le coût minimal
        int case_ligne, case_colonne;
        choisir_min_dist_non_visitee(couts, visitees, &case_ligne, &case_colonne);

        // Si toutes les cases ont été visitées ou si la destination est atteinte
        if (case_ligne == -1 || (case_ligne == destination_ligne && case_colonne == destination_colonne)) {
            break;
        }
        if (!est_case_visitee(visitees, case_ligne, case_colonne)) {
            // Marquer la case comme visitée
            visitees[case_ligne][case_colonne] = TRUE;

            // Mettre à jour les voisins de la case courante
            maj_voisins(couts, visitees, terrain, precedents, case_ligne, case_colonne);
        }
    }

    // Calculer le chemin depuis la destination jusqu'au point de départ
    int directions_suggerees[4];
    int nb_directions = calculer_chemin_bonus(precedents,joueur_ligne, joueur_colonne
                                              , destination_ligne, destination_colonne, directions_suggerees);

    // Afficher les directions suggérées
    afficher_direction_suggeree(directions_suggerees,nb_directions);
}

void afficher_direction_suggeree(int directions[], int nb) {
    const char *nom_chemin[4] = {"Haut", "Bas", "Gauche", "Droite"};

    printf("A partir de l'algorithme, les directions suggerees sont: ");
    for (int i = 0; i < nb; i++) {  // Utilisez 'nb' pour afficher les directions suggérées
        printf("%s ", nom_chemin[directions[i]]);  // Correction de la syntaxe du printf
    }
    printf("\n");
}
