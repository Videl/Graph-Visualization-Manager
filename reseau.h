//
//  reseau.h
//  Travelling
//
//  Created by Manon Signoret on 12/04/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#ifndef Travelling_reseau_h
#define Travelling_reseau_h

// nombre maximal de caractère d'un dépot
#define dep_nom_max 20 

// nombre de depots maximal
#define dep_max 10

//nombre de liaisons maximal
#define liais_max 50


// création d'une structure de lieux de dépot
typedef struct{
    char nom[dep_nom_max];
    unsigned int poidsSommet;  // ici on met unsigned car il pourra etre égal a l'infini
}depot;

// creation d'une structure de liaisons entre les lieux de depot
typedef struct{
    char nom[dep_nom_max];
    int poidsLiaison;   // indique le poids de l'arc entre deux depots
    int depart;    // depot de depart
    int arrivee;   // depot d'arrivee
}liaisons;


typedef struct{
    depot *dep;     //tableau contenant les informations sur chaque depots
    liaisons *arc;  // tableau contenant les informations sur chaque ligne
    int nbDepot;
    int nbLiaison;
}reseau;

void initialiserReseau(reseau *res);

int ajouterDepot(reseau *res, char *nomdep);

int ajouterLiaison(reseau *res, char *nomliaison);

depot rechercherDepot(reseau *res, char *nomdep);

liaisons rechercherLiaison(reseau *res, char *nomliaison);

void supprimerReseau(reseau *res);





#endif
