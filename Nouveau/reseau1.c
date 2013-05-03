//
//  reseau.c
//  
//
//  Created by Manon Signoret on 22/04/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#include <stdio.h>
#include "reseau.h"


S_Depot** Charge_Graphe(S_Depot** Graphe, char*** Nom_depot, int *Nb_depot_graphe)
{

    int       Nb_suc = 0;      //nombre de successeur d'un dépot
    FILE*     Fichier;         //le fichier.dot qui contient le graphe
    S_Depot * temp = NULL;     //sous-ensemble temporaire qui récupère les données du nouveau dépot
    int       i, j;            
    
    //ouvre le fichier
    Fichier = fopen(".\\graphe.txt", "r+");
    assert(Fichier && "Impossible d'ouvrir le fichier");
    
    //récupère le nombre de dépots du graphe
    fscanf(Fichier, "%d", Nb_depot_graphe);
    
    //allocation de la mémoire    
    Graphe = (S_Depot**)malloc(sizeof(S_Depot*));
    (*Nom_depot) = (char**)malloc(sizeof(char*));
    
    //pour chaque depot du graphe
    for(i=0; i<(*Nb_depot_graphe); i++)
    {
        //allocation et initialisation de la liste de successeurs
        Graphe[i] = (S_Depot*)malloc(sizeof(S_Depot));
        Graphe[i] = NULL;
        
        //allocation pour les noms des dépots
        (*Nom_depot)[i] = (char*)malloc(50*sizeof(char));
        //récupère le nom du dépot
        fscanf(Fichier, "%s", (*Nom_depot)[i]);
        
        //récupère le nombre de dépot suivant
        fscanf(Fichier, "%d", &Nb_suc);
        
        
        if(Nb_suc != 0)
        {
            
            for(j=0; j<Nb_suc; j++)
            {
                temp = (S_Depot*)malloc(sizeof(S_Depot));                //alloue le sous-ensemble
                fscanf(Fichier, "%d %f", &(temp->num_depot), &(temp->dist));   
                Graphe[i] = Ajouter_Depot(Graphe[i], temp);                //ajoute le sous-ensemble
            }
        }
    }
    
    fclose(Fichier);
    return Graphe;    
}


S_Depot* Ajouter_Depot(S_Depot* liste_depot, S_Depot* nouveau_depot){
    
    if(liste_depot == NULL)
    {
        liste_depot = nouveau_depot;
        liste_depot->suiv = NULL;
    }
    
 
    else
    {
        nouveau_depot->suiv = liste_depot;    //ajout le nouveau dépot en tête de liste
        liste_depot = nouveau_depot;
    }
    return liste_depot;
    
}

void Afficher_Liste(S_Depot* liste_depot, char* Nom_depot){
    
    printf("Successeurs du dépot %s: ", Nom_depot);
    
    if( !liste_depot )
        printf("Pas de successeur");    
    
    else
    {
        while( liste_depot != NULL )
        {
            printf("(%d, %0.0f) ", liste_depot->num_depot, liste_depot->dist);
            liste_depot = liste_depot->suiv;
        }
    }
    
}

void Init_Dijkstra(S_Depot** Graphe, int Nb_depot_graphe, char** Nom_depot)
{
    
    int       depart = -1;        //numéro du dépot de départ
    int       arrivee = -1;        //numéro du dépot d'arrivée
    float*    distance;        //tableau des distances de chaque depot par rapport au dépot de départ
    int*      pred;            //tableau des predecesseurs
    int*      dijkstra;        //tableau qui indique quels sommets ont été parcourus
    int       i;               
    char      saisie[50];      //nom de saisie d'un dépot
    
   
    do
    {
        printf("Quelle est le dépot de depart ? ");
        scanf("%s", saisie);
        for(i=0; i<Nb_depot_graphe; i++)
            if(strcmp(saisie, Nom_depot[i]) == 0)
                depart = i;
    }while(depart == -1);
    
    
    do
    {
        printf("Quelle est le dépot d'arrivee ? ");
        scanf("%s", saisie);
        for(i=0; i<Nb_depot_graphe; i++)
            if(strcmp(saisie, Nom_depot[i]) == 0)
                arrivee = i;
    }while(arrivee == -1);
    
    //allocation de la mémoire
    distance   = (float*)malloc(Nb_depot_graphe*sizeof(float));
    pred       = (int*)malloc(Nb_depot_graphe*sizeof(int));
    dijkstra   = (int*)malloc(Nb_depot_graphe*sizeof(int));
    
    //initialise chaque distance à l'infini et aucun predecesseur pour chaque point
    for(i=0; i<Nb_depot_graphe; i++)
    {
        distance[i] = FLT_MAX;   //distance infinie
        pred[i] = -1;            //pas de predecesseur
        dijkstra[i] = 0;
    }
    
    distance[depart] = 0;           //distance du départ à lui-même
    dijkstra[depart] = 1;           //le sommet de départ est traité
    
    //lance l'algo
    F_Dijkstra(Graphe, Nb_depot_graphe, distance, pred, depart, dijkstra, 1);
    
    printf("\n");
    
    Affiche_Parcours_Min(distance, pred, depart, arrivee, Nom_depot);
}


float minimum(float a, float b)
{
    
    float min = 0; 
    
    if(a<b)
        min = a;
    
    else
        min = b;
    
    return min;
}


void F_Dijkstra(S_Depot** Graphe, int Nb_depot_graphe, float* Dist, int* Pred, int S, int* Dijkstra, int Nb_traites)
{
    // numéro du sommet a etudier
    
    int      nouveau_sommet = -1;       //nouveau sommet à parcourir
    S_Depot* copy = NULL;          //liste qui parcoure notre liste
    float    min_sommet = FLT_MAX; //distance du sommet successeur le plus proche
    float    tmp_dist = 0;         //valeur temporaire pour savoir si on a changé de distances
    int      i;                    
    
    //allocation de la mémoire
    copy = (S_Depot*)malloc(sizeof(S_Depot));
    
    copy = Graphe[S];
    
    //parcourir la liste des successeurs
    while(copy != NULL)
    {
        //calcule la distance la plus courte de chaque sommet
        tmp_dist = Dist[copy->num_depot];
        Dist[copy->num_depot] = minimum(Dist[copy->num_depot], Dist[S] + copy->dist); //calcule la plus courte distance
        
        //si on a modification de la distance minimale alors on a changement de prédécesseur
        if(tmp_dist != Dist[copy->num_depot])
            Pred[copy->num_depot] = S;
        copy = copy->suiv;
    }
    
    //recherche le sommet suivant qui est le sommet de distance minimal non traité par dijkstra
    for(i=0; i<Nb_depot_graphe; i++)
    {
        if(Dijkstra[i] == 0)
        {
            min_sommet = minimum(min_sommet, Dist[i]);  //choisis la distance du successeur le plus proche
            if(min_sommet == Dist[i])               //choisis le successeur le plus proche
                nouveau_sommet = i;
        }
    }    
    
    //ce nouveau sommet est considéré comme traité
    Dijkstra[nouveau_sommet] = 1;
    Nb_traites++;
    
    //relance l'algorithme tant que tous les sommets non pas été traités
    if(Nb_traites != Nb_depot_graphe)
        F_Dijkstra(Graphe, Nb_depot_graphe, Dist, Pred, nouveau_sommet, Dijkstra, Nb_traites);
}


void Affiche_Parcours_Min(float* Dist, int* Pred, int depart, int arrivee, char** Nom_depot)
{
    int parcours = arrivee;
    int temp = 0;
    
    //affiche le parcours minimal
    printf("Trajet : \n");
    
    if(Dist[arrivee] == FLT_MAX)
        printf("Il n'y a pas de trajet\n");
    
    else{
        while(parcours != Dep){
                
            temp = Dist[parcours];      //sauvegarde de la distance
            
            printf("%s(%0.0f)", Nom_depot[parcours], Dist[parcours]);
            parcours = Pred[parcours]; //le successeur devient le prédecesseur
            printf(" <-(%0.0f)- ", temp-Dist[parcours]); //distance entre 2 sommets
        }
        printf("%s", Nom_depot[depart]);      //affiche le point de départ
    }    
}    


