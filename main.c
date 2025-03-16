#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "couleur.h"
#include "interaction.h"
#include "jeu.h"
#include "terrain.h"
#include "util.h"



int main(void)
{
    //Déclaration des variables
    int sortie_colonne, sortie_ligne; //Coordonnées de la sortie du terrain
    int depart_ligne, depart_colonne; //Coordonnées du joueur au départ 
    int terrain[NB_LIGNES][NB_COLONNES]; //Terrain de jeu
    int carburant = JOUEUR_CARBURANT_INITIAL;//Carburant initial du joueur

    //Initialisation du générateur de nombres aléatoires 
    srand((unsigned int) time(NULL));

    interaction_presenter_jeu();

    jeu_init(terrain,&depart_ligne,&depart_colonne,
             &carburant,&sortie_ligne, &sortie_colonne);

    while (jeu_verifier_fin(depart_ligne, depart_colonne, carburant,
                            sortie_ligne, sortie_colonne) == JEU_ETAT_EN_COURS){
        //printf("***********************************************************************************************\n");

        interaction_afficher_options(carburant);

        t_action action = interaction_verifier_choix_action(interaction_demander_action(carburant), carburant);

        switch (action) {
            case ACTION_DEPLACER:
                if (jeu_deplacer_joueur(&depart_ligne, &depart_colonne,
                                        interaction_demander_direction_deplacement())){
                    terrain_afficher(terrain, depart_ligne, depart_colonne,
                                     sortie_ligne, sortie_colonne);
                    jeu_maj_carburant_joueur(depart_ligne, depart_colonne, &carburant,
                                             terrain);
                } else {
                    printf("Erreur : deplacement impossible !\n");
                    printf("Veuillez entrer une option possible dans les limites du terrain !\n");
                    printf("\n");
                    terrain_afficher(terrain, depart_ligne, depart_colonne,
                                     sortie_ligne, sortie_colonne);
                }
                break;

            case ACTION_ACHETER_BONUS:
                break;
            case ACTION_QUITTER:
                return 0;
        }
    }

    if (jeu_verifier_fin(depart_ligne, depart_colonne, carburant,
                         sortie_ligne, sortie_colonne) == JEU_ETAT_VICTOIRE){
        interaction_afficher_victoire(carburant);
        return 0;
    }
    else if (jeu_verifier_fin(depart_ligne, depart_colonne, carburant,
                                sortie_ligne, sortie_colonne) == JEU_ETAT_ECHEC){
    interaction_afficher_echec(carburant);
        return 0;
    }
}
