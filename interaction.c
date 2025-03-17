/*************************************************************************************
** Nom du fichier : interaction.c
** Description  : Cette partie des fichier s'occupe de la communication entre le joueur et
le jeu en offrant des fonctionnalités pour afficher des données, solliciter des décisions
de la part de l'utilisateur et confirmer les actions qu'il désire entreprendre.

** connectivité :  stdio.h, interaction.h, ctype.h, couleur.h
*************************************************************************************/

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

#include <stdio.h>
#include "interaction.h"
#include <ctype.h>
#include "couleur.h"

//Affichage d'une petite presentation du jeu. (regles + astuce incluse)
void interaction_presenter_jeu() {
    printf("*********************************************************\n");
    couleur_set(0, 32, 40);
    printf("            Bienvenue dans le Jeu !\n");
    couleur_reset();
    printf("*********************************************************\n");

    printf("\n*********************** REGLEMENT ***********************\n");
    printf("Le but du jeu est d'atteindre la sortie avant d'epuiser le carburant.\n");
    printf("Chaque deplacement consomme 1 litre de carburant.\n");
    printf("Si le vehicule s'arrete avant la sortie, la partie est perdue.\n\n");

    printf("********************** MODE DE JEU **********************\n");
    printf("Deplacements : Chaque mouvement coute 1 litre de carburant.\n");
    printf("Bonus de deplacement : Deplacez-vous de 4 cases d'un coup contre 10 litres.\n");
    printf("Strategie : Gerez bien votre carburant pour eviter la panne !\n\n");

    printf("Astuce : Chaque case du terrain contient une quantite aleatoire de\n");
    printf("carburant (de 0 a 9 litres) qui sera ajoutee a votre reserve.\n");
    printf("*********************************************************\n\n");
}

//Les différents modes d'intéractions accessibles a l'utilisateur
void interaction_afficher_options(int carburant) {
    printf("Carburant restant : %i\n",carburant);
    printf("\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("\n");
    printf("CHOIX D'ACTION :\n");

    if (carburant >= 10){
        printf("1. Se deplacer\n");
        printf("2. Acheter un bonus\n");
        printf("3. Quitter\n");
    } else {
        printf("1. Se deplacer\n");
        couleur_set(0,90, 40);
        printf("2. Acheter un bonus\n");
        couleur_reset();
        printf("3. Quitter\n");
    }
}
//Cette fonction demande la choix de l'utilisateur parmis les choix proposes
int interaction_demander_action(int carburant) {
    int choix;

    do{
        printf("\nVotre choix : ");
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
//Cette fonction permet a l'utilisateur de choisir la direction de son choix
t_direction interaction_demander_direction_deplacement() {
    char direction;

    printf("Veuillez choisir une direction parmi les options suivantes :\n");
    printf("H - Haut, B - Bas, G - Gauche, D - Droite : ");
    scanf(" %c", &direction);
    direction = toupper(direction);

    return jeu_verifier_choix_deplacement(&direction);
}
// Lorsque l'utilisateur échoue le jeu, un message d'échec apparait.
void interaction_afficher_echec() {
    printf("\n");
    couleur_set(0, 31, 40);
    printf("********************** GAME OVER **********************\n");
    couleur_reset();
    printf("Vous etes tombe en panne de carburant !\n");
    printf("Le vehicule ne peut plus avancer. Vous devez gerer votre carburant ");
    printf("avec plus de precaution.\n");
    printf("Essayez de nouveau pour atteindre la sortie !\n");
}
//Lorsque l'utilisateur gagne le jeu, un message de victoire apparait
void interaction_afficher_victoire(int carburant) {
    printf("\n");
    couleur_set(0, 32, 40);
    printf("********************** VICTOIRE **********************\n");
    couleur_reset();
    printf("Felicitations ! Vous avez atteint la sortie avec succes !\n");
    printf("Vous avez bien gere votre carburant et pris les bonnes decisions.\n");
    printf("\n");
    printf("Carburant restant : %d litres\n", carburant);
    printf("Bravo et merci d'avoir joue !\n");
}

//Vérification de l'action choisie par l'utilisateur.
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
            printf("Merci d'avoir jouer, a la prochaine !");
            return ACTION_QUITTER;
    }
}