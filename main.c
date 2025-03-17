/*************************************************************************************
 * Programme : Jeu d'exploration
 * Auteur: Wassim Ouali, Jacob Arsenault, Koffi Akakpo, Alex Olivier François
 * Date : 16 Mars 2025
 * Description : Le joueur contrôle un véhicule qui se déplace sur un terrain afin d'accumuler du carburant
 * et atteindre une position de sortie. Chaque case du terrain contient une quantité de carburant
 * entre 0 et 9, que le véhicule peut récupérer en se déplaçant dessus. Les déplacements consomment
 * 1 litre de carburant, mais peuvent également augmenter la quantité de carburant si la case contient
 * du carburant.
 *
 * Le but du jeu est de gérer judicieusement son carburant pour atteindre la sortie avant qu'il ne
 * soit épuisé. Un bonus de déplacement permet au joueur de se déplacer de 4 cases d'affilée contre
 * 10 litres de carburant.
 *
 * L'algorithme de Dijkstra est intégré pour déterminer le chemin optimal vers la sortie en prenant
 * en compte la quantité de carburant disponible sur les cases adjacentes.
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interaction.h"
#include "jeu.h"
#include "terrain.h"
#include "dijkstra.h"

int main(void){
    //Déclaration des variables
    int sortie_colonne, sortie_ligne; // Coordonnées de la sortie du terrain
    int depart_ligne, depart_colonne; //Coordonnées du joueur au départ
    int terrain[NB_LIGNES][NB_COLONNES]; //Terrain de jeu
    int carburant = JOUEUR_CARBURANT_INITIAL; //Carburant initial du joueur

    //Initialisation du générateur de nombres aléatoires
    srand((unsigned int) time(NULL));

    //Présentation du jeu à l'utilisateur
    interaction_presenter_jeu();

    //Initialisation du jeu (terrain, position de départ et de sortie, carburant)
    jeu_init(terrain,&depart_ligne,&depart_colonne,
             &carburant,&sortie_ligne, &sortie_colonne);

    //boucles principale du jeu
    while (jeu_verifier_fin(depart_ligne, depart_colonne, carburant,
                            sortie_ligne, sortie_colonne) == JEU_ETAT_EN_COURS){
        //Affichage des options disponibles pour le joueur
        interaction_afficher_options(carburant);

        //Demande et validation de l'action du joueur
        t_action action = interaction_verifier_choix_action(interaction_demander_action(carburant), carburant);

        //Gestion des actions du joueur
        switch (action) {
            case ACTION_DEPLACER:
                //Si le déplacement est valide
                if (jeu_deplacer_joueur(&depart_ligne, &depart_colonne,
                                        interaction_demander_direction_deplacement())){
                    //Affichage du terrain
                    terrain_afficher(terrain, depart_ligne, depart_colonne,
                                     sortie_ligne, sortie_colonne);
                    //Mise à jour du carburant en fonction du déplacement
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
                //Appel de la fonction qui applique l'algorithme de dijkstra.
                dijkstra_acheter_bonus(terrain,depart_ligne, depart_colonne, &carburant, sortie_ligne, sortie_colonne);
                break;

            case ACTION_QUITTER:
                //Fin du jeu
                return 0;
        }
    }
    //Vérification de la condition de fin de jeu (Victoire ou échec)
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