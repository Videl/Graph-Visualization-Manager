//
//  general.c
//  
//
//  Created by Manon Signoret on 15/05/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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
    
    
    
}
