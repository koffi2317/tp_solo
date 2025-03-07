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

// Definir la fonction 'jeu_deplacer_joueur' ici
int jeu_deplacer_joueur(int *joueur_ligne, int *joueur_colonne, t_direction direction) {
    int ligne_supplementaire = *joueur_ligne, colonne_supplementaire = *joueur_colonne;

    switch (direction) {
        case DIRECTION_HAUT:
            ligne_supplementaire--;
            break;

        case DIRECTION_BAS:
            ligne_supplementaire++;
            break;

        case DIRECTION_GAUCHE:
            colonne_supplementaire--;
            break;

        case DIRECTION_DROITE:
            colonne_supplementaire++;
            break;

        default:
            return FALSE;
    }

    if (nouvelle_ligne >= 0 && nouvelle_ligne < 10 && nouvelle_colonne >= 0 &&
        nouvelle_colonne < 10) {
        *joueur_ligne = ligne_supplementaire;
        *joueur_colonne = colonne_supplementaire;
        return TRUE;
    }
    return FALSE;
}

// Definir la fonction 'jeu_init' ici

void jeu_init(int terrain[NB_LIGNES][NB_COLONNES], int *joueur_ligne, int
              *joueur_colonne, int *joueur_carburant, int *destination_ligne,
              int *destination_colonne) {
}

// Definir la fonction 'jeu_afficher_direction' ici

void jeu_afficher_direction(int direction) {

if(direction==DIRECTION_BAS) {
    printf("DIRECTION BAS");
}
else if(direction==DIRECTION_HAUT) {
    printf("DIRECTION HAUT");
}

else if(direction==DIRECTION_DROITE) {
    printf("DIRECTION DROITE");
}

    else if(direction==DIRECTION_GAUCHE) {
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