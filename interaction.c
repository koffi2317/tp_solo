//
// Created by stephane on 09/01/25.
//

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

#include <stdio.h>
#include "interaction.h"
#include "jeu.h"
#include <ctype.h>


void interaction_presenter_jeu() {
    printf("========= Jeu de navigation et gestion de carburant =========\n\n");

    printf("********************** REGLEMENT **********************\n");
    printf("Le but du jeu est d'atteindre la sortie avant d'épuiser le carburant.\n");
    printf("Chaque déplacement consomme 1 litre de carburant.\n");
    printf("Si le véhicule s'arrête avant la sortie, la partie est perdue.\n\n");

    printf("********************** MODE DE JEU **********************\n");
    printf("Déplacements : Chaque mouvement coûte 1 litre de carburant.\n");
    printf("Bonus de déplacement : Déplacez-vous de 4 cases d'un coup contre 10 litres.\n");
    printf("Stratégie : Gérez bien votre carburant pour éviter la panne !\n\n");

    printf("Astuce : Chaque case du terrain contient une quantité aléatoire de\n");
    printf("carburant (de 0 à 9 litres) qui sera ajoutée à votre réserve.\n");
    printf("*********************************************************\n\n");
}

void interaction_afficher_options(int carburant) {
    printf("Carburant restant : %i",carburant);
    printf("---------------------------------------------------------");
    printf("CHOIX D'ACTION \n");
    printf("\n");

    if (carburant >= 10){
        printf("1. Se deplacer\n");
        printf("2. Acheter un bonus\n"); //la couleur est celle normal
        printf("3. Quitter\n");
    } else {
        printf("1. Se deplacer\n");
        printf("2. Acheter un bonus\n"); // la couleur doit etre grise si < 10 carburant
        printf("3. Quitter\n");
    }
}

int interaction_demander_action(int carburant) {
    int choix;

    do{
        printf("Votre choix : ");
        scanf("%d", &choix);
        if (choix != 1 && choix != 2 && choix != 3){
            printf("Erreur : choix invalide !\n");
            printf("Veuillez entrer une option valide parmi celles proposees.\n");
        }
    } while (choix != 1 && choix != 2 && choix != 3);


    switch (choix) {
        case 1:
            return ACTION_DEPLACER;
        case 2:
            return ACTION_ACHETER_BONUS;
        case 3:
            return ACTION_QUITTER;
    }

}

t_direction interaction_demander_direction_deplacement() {
    char direction;

    printf("Veuillez choisir une direction parmi les options suivantes :\n");
    printf("H - Haut, B - Bas, G - Gauche, D - Droite : ");
    scanf(" %c", &direction);

    direction = toupper(direction);

    switch (direction) {
        case 'H':
          return DIRECTION_HAUT;

        case 'B':
          return DIRECTION_BAS;

        case 'G':
          return DIRECTION_GAUCHE;

        case 'D':
          return DIRECTION_DROITE;

        default:                    //Possibilite de mettre un message d'erreur ici
            return DIRECTION_ERRONEE;
    }
}

void interaction_afficher_echec() {
    printf("********************** GAME OVER **********************\n");
    printf("Vous êtes tombé en panne de carburant !\n");
    printf("Le véhicule ne peut plus avancer. Vous devez gérer votre carburant ");
    printf("avec plus de précaution.\n");
    printf("Essayez de nouveau pour atteindre la sortie !\n");
}

void interaction_afficher_victoire(int carburant) {
    printf("********************** VICTOIRE **********************\n");
    printf("Félicitations ! Vous avez atteint la sortie avec succès ! "
           "Vous avez bien géré votre carburant et pris les bonnes décisions.\n");
    printf("Carburant restant : %d litres\n", carburant);
    printf("Bravo et merci d'avoir joué !\n");
}


t_action interaction_verifier_choix_action(t_action action, int carburant) {
    switch (action) {
        case ACTION_DEPLACER:
            return ACTION_DEPLACER;

        case ACTION_ACHETER_BONUS:
            if (carburant >= 10) {
                return ACTION_ACHETER_BONUS;
            }
            printf("Carburant insuffisant !\n");
            printf("Vous ne pouvez pas acheter de bonus pour le moment.\n");
            return ACTION_INVALIDE;

        case ACTION_QUITTER:
            return ACTION_QUITTER;
    }
}