//
// Created by stephane on 08/01/25.
//

#ifndef CODE_TERRAIN_H
#define CODE_TERRAIN_H

//  taille du terrain
#define NB_LIGNES 10
#define NB_COLONNES 10

//  *****************************
//  Definitions des types publics
//  *****************************

//  - Le type pour les cases du terrain
//  Chaque case du terrain contient une certaine quantite de carburant (eventuellement 0)
//  Seul ce module peut acceder aux valeurs des cases en passant par les indices des cases.
//  Les autres modules DOIVENT utiliser les fonctions d'acces qui se trouvent dans ce module-ci.
typedef int t_terrain[NB_LIGNES][NB_COLONNES];

//  Quantite maximale de carburant par case de terrain
#define STATION_MAX_CARBURANT 9

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

/**
 * @brief Propose un position de sortie aleatoire pour un terrain de dimensions NB_LIGNES x NB_COLONNES
 * @name terrain_generer_position_sortie
 * @param sortie_ligne l'adresse ou deposer une ligne de sortie aleatoire
 * @param sortie_colonne l'adresse ou deposer une colonne de sortie aleatoire
 */
//  Ecrire le prototype de la fonction 'terrain_generer_position_sortie' ici

/**
 * @brief Propose une position de depart aleatoire pour un terrain de dimensions NB_LIGNES x NB_COLONNES
 * @name terrain_generer_position_depart
 * @param destination_ligne la ligne de la sortie actuelle
 * @param destination_colonne la colonne de la sortie actuelle
 * @param depart_ligne l'adresse ou deposer la ligne choisie aleatoirement
 * @param depart_colonne l'adresse ou deposer la colonne choisie aleatoirement
 * @note la distance Manahttan entre la position de depart et la position de sortie doit etre plus grande que 10.
 */
//  Ecrire le prototype de la fonction 'terrain_generer_position_depart' ici

/**
 * @brief Verifie qu'une position se trouve bien dans les limites du terrain de NB_LIGNES x NB_COLONNES
 * @name terrain_contient
 * @param position_ligne la ligne de la case a tester
 * @param position_colonne la colonne de la case a tester
 * @return true si la position se trouve a l'interieur du terrain, false sinon
 */
//  Ecrire le prototype de la fonction 'terrain_contient' ici

/**
 * @brief Retourne la quantite de carburant qui se trouve sur une case donnee du terrain
 * @name terrain_get_carburant
 * @param terrain la terrain
 * @param position_ligne la ligne de la case dont on veut connaitre la quantite de carburant
 * @param position_colonne la colonne de la case dont on veut connaitre la quantite de carburant
 * @return la quantite de carburant presente a cette position
 */
//  Ecrire le prototype de la fonction 'terrain_get_carburant' ici

/**
 * @brief Initialise la quantite de carburant sur une case du terrain
 * @name terrain_set_carburant
 * @param terrain le terrain dont on va modifier une case
 * @param position_ligne la ligne de la case a modifier
 * @param position_colonne la colonne de la case a modifier
 * @param carburant le carburant qui se trouvera dans la case
 */
//  Ecrire le prototype de la fonction 'terrain_set_carburant' ici

/**
 * @brief Initialise toutes les cases d'un terrain a 0 (zero)
 * @name terrain_init
 * @param terrain le terrain dont on veut initialiser les cases
 */
//  Ecrire le prototype de la fonction 'terrain_init' ici

/**
 * @brief Cree aleatoirement les stations de gas sur le terrain. La quantite_globale des quantites de gas des stations est passee en parametre.
 * @name terrain_creer_stations_carburant
 * @param terrain le terrain sur lequel on veut creer les stations de gas
 * @param quantite_globale la quantite globale de carburant a allouer sur l'ensemble des stations
 */
//  Ecrire le prototype de la fonction 'terrain_creer_stations_carburant' ici

/**
 * @brief Affiche la quantite de gas pour toutes les cases d'un terrain.
 * De plus, presente la case courante et la case de destination avec des couleurs differentes.
 * @name terrain_afficher
 * @param terrain le terrain a afficher
 * @param courante la position de la case courante
 * @param destination_ligne la ligne de la position de la case de destination
 * @param destination_colonne la ligne de la position de la case de destination
 */
//  Ecrire le prototype de la fonction 'terrain_afficher' ici

#endif //CODE_TERRAIN_H
