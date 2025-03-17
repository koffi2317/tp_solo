/*************************************************************************************
 * Nom du fichier : jeu.c
 * Description  : Ce composant s'occupe de superviser les relations entre le joueur et l'environnement de jeu,
 * ainsi que de la mécanique du jeu lui-même. Il facilite la gestion des mouvements du joueur, des ressources en carburant,
 * et des critères déterminant la victoire ou la défaite.

 * connectivité :  interaction.h, terrain.h, stdio.h, ctype.h, jeu.h
*************************************************************************************/

#include "terrain.h"
#include <stdio.h>
#include <ctype.h>
#include "jeu.h"

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Cette fonction met a jour le carburant en fonction de son déplacement.
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int *joueur_carburant,
                              int terrain[NB_LIGNES][NB_COLONNES]) {
    *joueur_carburant -= COUT_DEPLACEMENT_VOISIN;

    if (terrain[joueur_ligne][joueur_colonne] > 0) {
        *joueur_carburant += terrain[joueur_ligne][joueur_colonne];
    }
    terrain[joueur_ligne][joueur_colonne] = 0;
    //lorsque la case ne détient pas d'escence, la quantité du joueur reste identique
}

//La direction choisie par l'utilisateur, sera effectuer par la fonction
int jeu_deplacer_joueur(int *joueur_ligne, int *joueur_colonne, t_direction direction) {

    int nouvelle_ligne = *joueur_ligne;
    int nouvelle_colonne = *joueur_colonne;
    //les nouvelles coordonnées sont maintenant ajoutées et enregistrées.

    //La direction choisie par l'utilisateur pour effectuer le déplacement.
    //Les coordonnées seront modifier selon la direction
    switch (direction) {
        case DIRECTION_DROITE:
            nouvelle_colonne++;
            break;
        case DIRECTION_BAS:
            nouvelle_ligne++;
            break;
        case DIRECTION_HAUT:
            nouvelle_ligne--;
            break;
        case DIRECTION_GAUCHE:
            nouvelle_colonne--;
            break;
        default:
            return FALSE;
    }

    if (terrain_contient(nouvelle_ligne, nouvelle_colonne)) {
        *joueur_ligne = nouvelle_ligne;
        *joueur_colonne = nouvelle_colonne;
        jeu_afficher_direction(direction);
        return TRUE;
    } else {
        return FALSE;
    }
}

//Cette fonction va initialiser le terrain avec les stations de gas pour les cases.
void jeu_init(int terrain[NB_LIGNES][NB_COLONNES], int *joueur_ligne, int
*joueur_colonne, int *joueur_carburant, int *destination_ligne,
              int *destination_colonne) {
    terrain_generer_position_sortie(destination_ligne, destination_colonne);

    terrain_generer_position_depart(*destination_ligne, *destination_colonne,
                                    joueur_ligne, joueur_colonne);

    terrain_init(terrain);

    terrain_creer_stations_carburant(terrain, TOTAL_CARBURANT_NIVEAU_1);
    terrain[*joueur_ligne][*joueur_colonne] = 0;

    terrain_afficher(terrain, *joueur_ligne, *joueur_colonne,
                     *destination_ligne, *destination_colonne);

    *joueur_carburant = JOUEUR_CARBURANT_INITIAL;
}

//Cette fonction affiche une direction ( en lettres )
void jeu_afficher_direction(int direction) {
    if (direction == DIRECTION_BAS) {
        printf("VOUS VOUS ETES DIRIGE VERS LE BAS !\n"); //a changer ** le message
        printf("\n");
    } else if (direction == DIRECTION_HAUT) {
        printf("VOUS VOUS ETES DIRIGE VERS LE HAUT !\n");
        printf("\n");
    } else if (direction == DIRECTION_DROITE) {
        printf("VOUS VOUS ETES DIRIGE VERS LA DROITE !\n");
        printf("\n");
    } else if (direction == DIRECTION_GAUCHE) {
        printf("VOUS VOUS ETES DIRIGE VERS LA GAUCHE !\n");
        printf("\n");
    }
}

// La fonction recupere une direction saisie sous la forme d'une chaine de caracteres
int jeu_verifier_choix_deplacement(char *choix) {
    char direction = toupper(choix[0]);

    switch (direction) {
        case 'B':
            return DIRECTION_BAS;
        case 'H':
            return DIRECTION_HAUT;
        case 'D':
            return DIRECTION_DROITE;
        case 'G':
            return DIRECTION_GAUCHE;
        default:
            return DIRECTION_ERRONEE; // Direction non valide
    }
}

//Cette fonction calcule la position d'un voisin dans une direction donnee.
void jeu_calculer_voisin(int case_ligne, int case_colonne, int direction, int
*voisin_ligne, int *voisin_colonne) {
    if (direction == DIRECTION_BAS) {
        *voisin_ligne = case_ligne;
        *voisin_colonne = case_colonne + 1;
    } else if (direction == DIRECTION_HAUT) {
        *voisin_ligne = case_ligne;
        *voisin_colonne = case_colonne - 1;
    } else if (direction == DIRECTION_DROITE) {
        *voisin_ligne = case_ligne + 1;
        *voisin_colonne = case_colonne;
    } else if (direction == DIRECTION_GAUCHE) {
        *voisin_ligne = case_ligne - 1;
        *voisin_colonne = case_colonne;
    }
}

// Cette fonctiomn verifie si le jeu est termine ou non.
int jeu_verifier_fin(int joueur_ligne, int joueur_colonne, int joueur_carburant, int
destination_ligne, int destination_colonne) {
    if (joueur_ligne == destination_ligne && joueur_colonne == destination_colonne) {
        return JEU_ETAT_VICTOIRE;
    }
    if (joueur_carburant == 0) {
        return JEU_ETAT_ECHEC;
    }
    return JEU_ETAT_EN_COURS;
}