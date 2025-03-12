//
// Created by stephane on 08/01/25.
//
#include "interaction.h"
#include "terrain.h"
#include <stdio.h>
#include <ctype.h>
#include "jeu.h"

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

int jeu_deplacer_joueur (int *joueur_ligne, int *joueur_colonne, t_direction direction) {

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

    if(terrain_contient(nouvelle_ligne, nouvelle_colonne)){
        *joueur_ligne = nouvelle_ligne;
        *joueur_colonne = nouvelle_colonne;
        jeu_afficher_direction(direction);
        return TRUE;
    } else {
        return FALSE;
    }
    //si le déplacement n'a pu se faire dans les limites du terrain, c'est false.
    if (nouvelle_ligne < 0) {
        return FALSE;
    } else if (nouvelle_ligne >= TAILLE_TAB) {
        return FALSE;
    } else if (nouvelle_colonne < 0) {
        return FALSE;
    } else if (nouvelle_colonne >= TAILLE_TAB) {
        return FALSE;
    } else {
        //Changement des coordonnées du joueur pour la case choisie
        return TRUE;
    }
}

// Definir la fonction 'jeu_init' ici

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

// Definir la fonction 'jeu_afficher_direction' ici

void jeu_afficher_direction(int direction) {

if(direction==DIRECTION_BAS) {
    printf("VOUS VOUS ETES DIRIGE VERS LE BAS !\n");  //a changer ** le message
    printf("\n");
}
else if(direction==DIRECTION_HAUT) {
    printf("VOUS VOUS ETES DIRIGE VERS LE HAUT !\n");
    printf("\n");
}

else if(direction==DIRECTION_DROITE) {
    printf("VOUS VOUS ETES DIRIGE VERS LA DROITE !\n");
    printf("\n");
}

    else if(direction==DIRECTION_GAUCHE) {
        printf("VOUS VOUS ETES DIRIGE VERS LA GAUCHE !\n");
    printf("\n");
    }
}

// Definir la fonction 'jeu_verifier_choix_deplacement' ici

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
            return DIRECTION_ERRONEE;  // Direction non valide
    }
}

// Definir la fonction 'jeu_calculer_voisin' ici

void jeu_calculer_voisin(int case_ligne, int case_colonne, int direction, int
                         *voisin_ligne, int *voisin_colonne) {
    if (direction==DIRECTION_BAS) {
        *voisin_ligne = case_ligne;
        *voisin_colonne = case_colonne + 1;
    } else if (direction== DIRECTION_HAUT) {
        *voisin_ligne = case_ligne;
        *voisin_colonne = case_colonne - 1;
    } else if (direction == DIRECTION_DROITE) {
        *voisin_ligne = case_ligne + 1;
        *voisin_colonne = case_colonne;
    } else if (direction== DIRECTION_GAUCHE) {
        *voisin_ligne = case_ligne - 1;
        *voisin_colonne = case_colonne;
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
