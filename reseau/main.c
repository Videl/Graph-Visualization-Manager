//
//  main.c
//  
//
//  Created by Manon Signoret on 03/05/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#include <stdio.h>
#include "reseau.h"

int main()
{
    
    S_Depot** Depot;
    int Nb_depot_graphe = 0;
    int i = 0;
    char** Nom_Depot;
    
    printf("###################################\n");
    printf("# Création de dépôt déjà existant #\n");
    printf("###################################\n");
    
    Depot = Charge_Graphe(Depot, &Nom_Depot, &Nb_depot_graphe);
    
    printf("Format d'affichage : (index dépôt, distance)\n");
    printf("*** Note : index dépôt commence à zéro ! ***\n");

    for( i = 0 ; i < Nb_depot_graphe ; i++ ){

        Afficher_Liste(Depot[i], Nom_Depot[i]);
        printf("\n");
    }

    printf("\n");
    
    Init_Dijkstra(Depot, Nb_depot_graphe, Nom_Depot);
    
    printf("\n");
    
    for ( i = 0 ; i < Nb_depot_graphe ; i++)
    {
        free(Nom_Depot[i]);
        free(Depot[i]);
    }
    free(Nom_Depot);
    free(Depot);
    
    return 0;
    
    
    
}

