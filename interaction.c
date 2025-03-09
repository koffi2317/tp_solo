//
// Created by stephane on 09/01/25.
//

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

#include <stdio.h>
#include "interaction.h"
#include "jeu.h"


void interaction_presenter_jeu() {
    printf("----Jeux de déplacement de véhicule avec gestion de carburant----\n");
    printf("\n");
    printf("****************************REGLEMENT****************************\n");
    printf("Le but du jeu est de permettre au véhicule d'atteindre la sortie.\n");
    printf("Pour cela, vous devrez gérer le carburant tout en effectuant les \n");
    printf("bons choix.L'arret du véhicule avant la sortie entrainera un échec\n");
    printf("\n");
    printf("***************************MODE DE JEU****************************\n");
    printf("Les déplacements consomment 1 litre de carburant, qui peut soit \n");
    printf("augmenter la quantité de carburant du joueur ou bien la diminuer \n");
    printf("Bonus de déplacement: permet au joueur de se déplacer de 4 cases \n");
    printf("de suite contre 10 litres de carburant.( À votre discretion ) \n");
    printf("\n");
    printf("Astuce!:Chaque case présente dans le terrain contient une quantité\n");
    printf("de carburant,aléatoire, de 0 à 9 qui sera ajouté à votre véhicule.\n");
    printf("*******************************************************************\n");
    printf("\n");
}

void interaction_afficher_options() {
   int carburant, choix, distance = 1;

    printf("options d'intéractions \n");
    printf("\n");
    printf("Étape 1: Le déplacement\n");

    if (carburant >= 10) {
        printf("Vous avez la possibilité d'activé le bonus de déplacement\n");
        printf("preferez-vous avancer de 4 cases en échange de  10 litres de carburant?\n");
        printf("utilisé la touche 0 pour refusé la transaction ou la touche 1 pour accepter la transaction:\n");

        scanf("%d", &choix);
        if (choix == 1) {
            distance = 4;
        }
    } else { //je dois mettre cette partie en gris
        printf("Il est impossible pour vous de s'approprié un bonus\n");
        printf("*******  carburant requis est insuffisant  ********\n");
    }

    printf("fin de la séquence d'intéraction\n");
}

int interaction_demander_action(int carburant) {
    int choix;
   // t_action decision;

        printf("utilisé la touche 0 pour refusé la transaction.\n");
        printf("la touche 1 pour accepter la transaction\n");
        printf("la touche 2 pour quitter le domaine de transaction\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix != 0 || choix != 1 || choix != 2) {
          printf("Le choix entré ne correspond pas aux options présentées\n");
          return ACTION_INVALIDE;
        }

    // ReSharper disable once CppDFAUnreachableCode
    switch (choix) {
            case 0:
                return ACTION_DEPLACER;
            case 1:
                if (carburant >= 10) {
                    return ACTION_ACHETER_BONUS;
                } else {
                    printf("Votre carburant est actuellement insuffisant!\n");
                    printf("il est impossible d'acheter un bonus\n");
                }
                break;
            case 2:
                return ACTION_QUITTER;
            default: ;
        }
}

t_direction interaction_demander_direction_deplacement() {
    char direction;

    printf("Veuillez entré une direction selon les critères établits\n");
    printf("H-aut, B-as, G-auche, D-roite : ");
    scanf(" %c", &direction);

    switch (direction) {
        case 'H':
          return DIRECTION_HAUT;

        case 'B':
          return DIRECTION_BAS;

        case 'G':
          return DIRECTION_GAUCHE;

        case 'D':
          return DIRECTION_DROITE;

        default:
            printf("La direction entrée ne correspond pas aux choix présentés.\n");
            return DIRECTION_ERRONEE;
    }
}

void interaction_afficher_echec() {
    printf("\n*****************************************\n");
    printf("Vous n'avez pas atteint l'objectif demandée\n");
    printf("Tu ne peux pas t'attendre à toujours gagner\n");
    printf("\n*****************************************\n");
    printf("\n");
    printf("votre réservce de carburant est vidé de toute énergie.\n");
    printf("La sortie n'a pas été atteint en raison de votre planification.\n");
    printf(" Veuillez réessayez en planifiant vos déplacements.\n");
}

void interaction_afficher_victoire(int carburant) {

    printf("\n*****************************************\n");
    printf("******* un chemin épique! VICTOIRE! *******\n");
    printf("*******************************************\n");
    printf("\n");
    printf("Victoire! Vous etes arrivé a la sortie tout en\n");
    printf("planifiant un chemin efficace a votre reussite\n");
    printf("\n");
    printf("Le carburant restant est de : %d litres\n", carburant);
}


t_action interaction_verifier_choix_action(t_action action, int carburant) {

  switch (action) {
        case ACTION_DEPLACER:
            return ACTION_DEPLACER;

        case ACTION_ACHETER_BONUS:
            if (carburant >= 10) {
                return ACTION_ACHETER_BONUS;
            } else {
                printf("La quantité de carburant est insuffisante pour obtenir un bonus.\n");
                return ACTION_INVALIDE;
            }

        case ACTION_QUITTER:
            return ACTION_QUITTER;

        default:
            printf("L'action entrée est invalide\n");
            return ACTION_INVALIDE;
    }
}
