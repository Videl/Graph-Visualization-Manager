//
//  general.c
//  
//
//  Created by Manon Signoret on 15/05/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{ 
    int choix;
    
    printf("###############################################\n");
    printf("#                   Projet C                  #\n");
    printf("#    Visualisation d'un réseau de transport   #\n");
    printf("###############################################\n");
    
   printf("Comment voulez-vous utiliser ce programme ?\n");
    
    do {
        printf("1. Utiliser un réseau deja existant\n");
        printf("2. Créer son propre reseau\n");
        printf("%% ");
        scanf("%d", &choix);
        getchar();
    } while (choix<=0 || choix>2);
    
    switch (choix) {
        case 1:
            system("cd reseau && ./main");
            break;
            
        case 2:
            system("cd userinfo/ && ./ask_user_info");
            break;
            
        default:
        break;
    }

    char link[300] = "./dot_maker/text_to_dot ";
    char link2[300] = "dot -T png -o ";
    char input[50];
    char input2[50];
    char input3[50];

    printf("Indiquez le nom du fichier texte contenant les informations :\n");
    printf("(Le lien complet à partir de la racine du projet) : ");

    scanf("%s", input);
    getchar();

    strcat(link, input);

    printf("Indiquer le nom du fichier .dot en sortie : ");
    scanf("%s", input2);
    getchar();

    strcat(link, " ");
    strcat(link, input2);

    printf("%s... ", link);
    system(link);
    printf("exécuté.\n");


    printf("Indiquer le nom du fichier image (.png) en sortie : ");
    scanf("%s", input3);
    getchar();

    strcat(link2, input3);
    strcat(link2, " ");
    strcat(link2, input2);

    printf("%s...", link2);
    system(link2);
    
    printf("exécuté.\n");
    
}
