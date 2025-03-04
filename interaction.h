//
// Created by stephane on 09/01/25.
//

#ifndef CODE_INTERACTION_H
#define CODE_INTERACTION_H


typedef enum {
    ACTION_INVALIDE, ACTION_DEPLACER, ACTION_ACHETER_BONUS, ACTION_QUITTER
} t_action;

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

/**
 * @brief Affiche une petite presentation du jeu.
 * @name interaction_presenter_jeu
  */
//  Ecrire le prototype de la fonction 'interaction_presenter_jeu' ici

/**
 * @brief Affiche les options du menu de jeu.
 * Une option non valide sera grisee.
 * @name interaction_afficher_options
 * @param carburant la quantite de carburant du joueur
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_options' ici

/**
 * @brief Demande un choix a l'utilisateur sur une des options du menu
 * @name interaction_demander_action
 * @param carburant la quantite de carburant du joueur
 * @return ACTION_DEPLACER, ACTION_ACHETER_BONUS ou ACTION_QUITTER selon l'option choisie par le joueur
 */
//  Ecrire le prototype de la fonction 'interaction_demander_action' ici

/**
 * @brief Demande une direction de deplacement au joueur.
 * @name interaction_demander_direction_deplacement
 * @return DIRECTION_ERRONEE si la direction choisie est invalide.
 * DIRECTION_DROITE, DIRECTION_BAS, DIRECTION_HAUT ou DIRECTION_GAUCHE selon le choix du joueur, sinon
 */
//  Ecrire le prototype de la fonction 'interaction_demander_direction_deplacement' ici

/**
 * @brief Affiche un message d'echec de la mission.
 * @name interaction_afficher_echec
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_echec' ici

/**
 * @brief Affiche un message de victoire de la mission ainsi que la quantite de
 * carburant restant dans le reservoir du joueur.
 * @name interaction_afficher_victoire
 * @param carburant la quantite de carburant du joueur
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_victoire' ici

/**
 * @brief Verifie que l'action choisie par le joueur est correcte.
 * @name interaction_verifier_choix_action
 * @param action l'action choisie par le joueur
 * @param carburant la quantite de carburant du joueur
 * @return action si elle est correcte, ACTION_INVALIDE sinon
 */
//  Ecrire le prototype de la fonction 'interaction_verifier_choix_action' ici

#endif //CODE_INTERACTION_H
