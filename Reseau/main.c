//
//  main.c
//  
//
//  Created by Manon Signoret on 03/05/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#include <stdio.h>
#include "reseau1.h"

int main(int argc, char *argv[])
{
    
    FILE* Fichier = NULL;
    S_Depot** Depot;
    int Nb_depot_graphe = 0;
    int i = 0;
    char** Nom_Depot;
    
    printf(" ====================\n");
    printf(" Projet C : \n");
    printf(" Visualisation d'un réseau de transport \n");
    printf(" ====================\n");
    
   Depot = Charge_Graphe(Depot, &Nom_Depot, &Nb_depot_graphe);
    
    for( i = 0 ; i < Nb_depot_graphe ; i++ ){
        Afficher_Liste(Depot[i], Nom_Depot[i]);
        printf("\n");
    }
    printf("\n\n");
    
    Init_Dijkstra(Depot, Nb_depot_graphe, Nom_Depot);
    
    printf("\n\n");
    
    system("PAUSE");
    return 0;
    
    
    
}

