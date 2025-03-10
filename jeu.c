//
// Created by stephane on 08/01/25.
//
#include "jeu.h"
#include "terrain.h"
#include <stdio.h>
#include <string.h>
//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'jeu_maj_carburant_joueur' ici
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int *joueur_carburant,
                              int terrain[NB_LIGNES][NB_COLONNES]) {
    *joueur_carburant -= COUT_DEPLACEMENT_VOISIN;

    if (terrain[joueur_ligne][joueur_colonne] > 0) {
        *joueur_carburant += terrain[joueur_ligne][joueur_colonne];
    }
    terrain[joueur_ligne][joueur_colonne] = 0;
}

int jeu_deplacer_joueur (int *joueur_ligne, int *joueur_colonne, t_direction direction){

    //joueur_ligne l'adresse de la ligne ou se trouve le joueur avant le deplacement et qui sera mise a jour
    int nouvelle_ligne = *joueur_ligne;
    //joueur_colonne Pointeur vers la colonne du joueur avant déplacement, mise à jour après déplacement.
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
        // La direction entrée par l'utilisateur est invalide
    }

    //Changement des coordonnées du joueur pour la case choisie
    *joueur_ligne = nouvelle_ligne;
    *joueur_colonne = nouvelle_colonne;

    //si le déplacement n'a pu se faire dans les limites du terrain, c'est false.
    if(nouvelle_ligne < 0 || nouvelle_colonne < 0||nouvelle_ligne >= TAILLE_TAB||nouvelle_colonne >= TAILLE_TAB ) {
        return FALSE;
    }
        return TRUE;
    }
    //true si le déplacement a pu se faire dans les limites du terrain.

// Definir la fonction 'jeu_init' ici

void jeu_init(int terrain[NB_LIGNES][NB_COLONNES], int *joueur_ligne, int
              *joueur_colonne, int *joueur_carburant, int *destination_ligne,
              int *destination_colonne) {
}

// Definir la fonction 'jeu_afficher_direction' ici

void jeu_afficher_direction(int direction) {

    if(direction==DIRECTION_BAS) {
        printf("DIRECTION BAS");
    }else if(direction==DIRECTION_HAUT) {
        printf("DIRECTION HAUT");
    }else if(direction==DIRECTION_DROITE) {
        printf("DIRECTION DROITE");
    }else if(direction==DIRECTION_GAUCHE) {
        printf("DIRECTION GAUCHE");
    }
}

// Definir la fonction 'jeu_verifier_choix_deplacement' ici

int jeu_verifier_choix_deplacement(const char *choix) {
    if (strcmp(choix, "B") == 0|| strcmp(choix, "b")==0) {
        return DIRECTION_BAS;
    } else if (strcmp(choix, "H") == 0|| strcmp(choix, "h")==0) {
        return DIRECTION_HAUT;
    } else if (strcmp(choix, "D") == 0 || strcmp(choix, "d")==0) {
        return DIRECTION_DROITE;
    } else if (strcmp(choix, "G") == 0 || strcmp(choix, "g")==0) {
        return DIRECTION_GAUCHE;
    }

    return DIRECTION_ERRONEE;
}

// Definir la fonction 'jeu_calculer_voisin' ici

void jeu_calculer_voisin(int case_ligne, int case_colonne, int direction, int
                         *voisin_ligne, int *voisin_colonne) {
    if (direction==DIRECTION_BAS) {
        *voisin_ligne = case_ligne + 1;
        *voisin_colonne = case_colonne;
    } else if (direction== DIRECTION_HAUT) {
        *voisin_ligne = case_ligne - 1;
        *voisin_colonne = case_colonne;
    } else if (direction == DIRECTION_DROITE) {
        *voisin_ligne = case_ligne;
        *voisin_colonne = case_colonne + 1;
    } else if (direction== DIRECTION_GAUCHE) {
        *voisin_ligne = case_ligne;
        *voisin_colonne = case_colonne - 1;
    }
}

// Definir la fonction 'jeu_verifier_fin' ici

int jeu_verifier_fin(int joueur_ligne, int joueur_colonne, int joueur_carburant, int
destination_ligne, int destination_colonne) {

if(joueur_ligne==destination_ligne && joueur_colonne==destination_colonne) {
    return JEU_ETAT_VICTOIRE;
}
    if(joueur_carburant==0) {
        return JEU_ETAT_ECHEC;
    }

return JEU_ETAT_EN_COURS;

}
