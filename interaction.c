//
// Created by stephane on 09/01/25.
//

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

#include <stdio.h>
#include "interaction.h"


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

/*ne pas oublier de faire le texte en gris! important! demande a mister koffi*/
//possiblement devoir refaire cett section! Koffi! si tu ne comprends pas  pk tu me le diras
void interaction_afficher_options() {
   int carburant, choix, distance = 1;

   //il est dit qu'il y a DES options.... mais je ne sai spas quoi rajouté de plus(demander a koffi)
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
    } else { //stp koffi! je dois mettre cette partie en gris
        printf("Il est impossible pour vous de s'approprié un bonus\n");
        printf("*******  carburant requis est insuffisant  ********\n");
    }
   // return distance;

    printf("fin de la séquence d'intéraction\n");
}

int interaction_demander_action(int carburant) {
    int choix;
   // t_action decision;

    do {
        printf("utilisé la touche 0 pour refusé la transaction.\n");
        printf("la touche 1 pour accepter la transaction\n");
        printf("la touche 2 pour quitter le domaine de transaction\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix != 0 || choix != 1 || choix != 2) {
          printf("Le choix entré ne correspond pas aux options présentées\n");
          return ACTION_INVALIDE;
        }

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
        }
    } while();
}

// Definir la fonction 'interaction_demander_direction_deplacement' ici

// Definir la fonction 'interaction_afficher_echec' ici

// Definir la fonction 'interaction_afficher_victoire' ici

// Definir la fonction 'interaction_verifier_choix_action' ici
