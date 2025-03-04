//
// Created by stephane on 08/01/25.
//

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'jeu_maj_carburant_joueur' ici
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int *joueur_carburant, Terrain *) {

    *joueur_carburant += (terrain=carburant[joueur_ligne][joueur_colonne]);
    terrain=(carburant[joueur_ligne][joueur_colonne] = 0);
    *joueur_carburant -= COUT_DEPLACEMENT_VOISIN;
}


// Definir la fonction 'jeu_deplacer_joueur' ici
bool jeu_deplacer_joueur(int *joueur_ligne, int *joueur_colonne, t_direction direction) {
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
          return false;
    }

    if (nouvelle_ligne >= 0 && nouvelle_ligne < 10 && nouvelle_colonne >= 0 && nouvelle_colonne < 10) {
        *joueur_ligne =  ligne_supplementaire;
        *joueur_colonne = colonne_supplementaire;
        return true;
    }
    return false;
}
// Definir la fonction 'jeu_init' ici

// Definir la fonction 'jeu_afficher_direction' ici

// Definir la fonction 'jeu_verifier_choix_deplacement' ici

// Definir la fonction 'jeu_calculer_voisin' ici

// Definir la fonction 'jeu_verifier_fin' ici
