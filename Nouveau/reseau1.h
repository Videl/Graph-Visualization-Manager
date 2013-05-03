//
//  reseau.h
//  
//
//  Created by Manon Signoret on 22/04/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#ifndef _reseau_h
#define _reseau_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include <string.h>

typedef struct depot
{
    int    num_depot;        //numéro du dépot
    float  dist;             //distance entre ce dépot et le précédent
    struct depot *suiv;      //sous-ensemble suivant
}S_Depot;


// Fonction qui charge le graphe depuis le fichier.dot  
S_Depot** Charge_Graphe(S_Depot** Graphe, char*** Nom_depot, int *Nb_depot_graphe);

// Ajoute un dépot à une liste 
S_Depot* Ajouter_Depot(S_Depot* liste_depot, S_Depot* nouveau_depot);

// Fonction pour afficher une liste de dépots
void Afficher_Liste(S_Depot* liste_depot, char* Nom_depot);

// Fonction qui initialise l'algorithme de Dijkstra pour un graphe
void Init_Dijkstra(S_Depot** Graphe, int Nb_depot_graphe, char** Nom_depot);

// Fonction qui calcule le minimum entre deux flottants
float minimum(float a, float b);

// Fonction de l'algorithme de Dijkstra 
void F_Dijkstra(S_Depot** Graphe, int Nb_depot_graphe, float* Dist, int* Pred, int S, int* Dijkstra, int Nb_traites);

// Fonction qui affiche le plus court chemin entre deux points

void Affiche_Parcours_Min(float* Dist, int* Pred, int depart, int arrivee, char** Nom_depot);



#endif
