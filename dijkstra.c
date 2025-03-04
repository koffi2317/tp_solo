//
// Created by stephane on 08/01/25.
//

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
//  Ecrire le prototype de la fonction 'initialiser_couts' ici

/**
 * @brief Initialise toutes les cases a non visitee.
 * @name initialiser_visitees
 * @param visitees le tableau bi-dimensionnel qui indique, pour chaque case, si elle a deja ete visitee ou non.
 */
//  Ecrire le prototype de la fonction 'initialiser_visitees' ici

/**
 * @brief Indique si une case donnee a deja ete visitee au cours de l'algorithme.
 * @name est_case_visitee
 * @param visitees le tableau a 2 dimensions qui indique, pour chaque case, si elle a deja ete visitee durant l'algorithme
 * @param case_ligne la ligne de la case a tester
 * @param case_colonne la colonne de la case a tester
 * @return true si la case a deja ete visitee, false sinon
 */
//  Ecrire le prototype de la fonction 'est_case_visitee' ici

/**
 * @brief Recherche la case non visitee qui possede le plus petit cout.
 * @name choisir_min_dist_non_visitee
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique si une case a deja ete visitee ou pas
 * @param case_choisie_ligne l'adresse ou deposer la ligne de la case choisie
 * @param case_choisie_colonne l'adresse ou deposer la colonne de la case choisie
 */
//  Ecrire le prototype de la fonction 'choisir_min_dist_non_visitee' ici

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
// Definir la fonction 'initialiser_couts' ici

// Definir la fonction 'initialiser_visitees' ici

// Definir la fonction 'est_case_visitee' ici

// Definir la fonction 'choisir_min_dist_non_visitee' ici

// Definir la fonction 'cout_deplacement' ici

// Definir la fonction 'maj_voisins' ici

// Definir la fonction 'afficher_couts' ici

// Definir la fonction 'calculer_chemin_bonus' ici

// Definir la fonction 'dijkstra' ici

// Definir la fonction 'afficher_direction_suggeree' ici
