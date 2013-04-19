//
//  itineraire.h
//  Travelling
//
//  Created by Manon Signoret on 12/04/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#ifndef Travelling_itineraire_h
#define Travelling_itineraire_h

// Constante pour marquer la valeur infini quand il n'existe pas de liaisons entre le point de depart et le point d'arrivee
#define infini ((unsigned int)~0)

typedef struct{
    int l;      // nombre de lignes qui correspond ici a tous les sommets
    int c;      // nombre de colonnes qui correspond ici a tous les poids des sommets
    unsigned int **tab;
}matrice;


matrice allouer_matrice(int l, int c);

int est_matrice_invalide(matrice m);

unsigned int *acces_matrice(matrice m, int i, int j);

int nb_lignes_matrice(matrice m);

int nb_colonnes_matrice(matrice m);

void liberer_matrice(matrice m);

// creer une liaison entre deux depots et lui attribuer un poids
liaisons creer_liaison(reseau *res, depot *dep1, depot *dep2, liaisons *liais);
 
// existe ou non une liaison
boolean existe_liaison(reseau *res, depot *dep1, depot *dep2);

// on initialise les sommets autre que depot_depart a la valeur infini et on met depot_depart a 0
void initialiserSommets(reseau *res, depot *depart);

// pour rechercher le depot le plus pres
depot trouve_min(reseau *res);

// fonction qui met a jour les distances apres chaque parcours des depots
void maj_distances(depot *dep1, depot *dep2);

// fonction Dijkstra ( pas encore finie )
depot Dijkstra(reseau *res, int poids, depot *dep_depart, depot *dep_arrivee);

// unsigned car cela peut etre egal a l'infini, et elle calcule le pods de la liaison entre les deux depots
unsigned int poids(depot *dep1, depot *dep2);




#endif
