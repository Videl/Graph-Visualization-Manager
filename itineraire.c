//
//  itineraire.c
//  Travelling
//
//  Created by Manon Signoret on 12/04/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#include <stdio.h>
#include "reseau.h"
#include "itineraire.h"


int i=0, j=0;

matrice allouer_matrice(int l, int c)
{
    matrice m;
    m.l=l;
    m.c=c;
    my = (unsigned int **)malloc(sizeof(unsigned int *)*m.l);
    for ( i = 0 ; i < m.l ; i++ )
        my[i] = (unsigned int *)malloc(sizeof(unsigned int)*m.c);
    m.tab = my;
    if(m.tab == NULL)
    {
        m.l = 0;
        m.c = 0;
    }
    return m;
}

void liberer_matrice(matrice m)
{
    for( i = 0 ; i < m.l ; i++ ){
        free(m.tab[i]);
    }
    free(m.tab);
}


int est_matrice_invalide(matrice m)
{
    int resultat = 0;
    if(m.l == 0)
        resultat = 1;
    if(m.c == 0)
        resultat = 1;
    return resultat;
}

unsigned int *acces_matrice(matrice m, int i, int j)
{
    if(i > m.c || j > m.l)
        return NULL;
    else {
        double *resultat;
        resultat = &m.donnees[i][j];
        return resultat;
}

int nb_lignes_matrice(matrice m)
{
    int resultat;
    resultat = m.l;
    return resultat;
}

int nb_colonnes_matrice(matrice m)
{
    int resultat;
    resultat = m.c;
    return resultat;
}
    
    
    
    liaisons creer_liaison(reseau *res, depot *dep1, depot *dep2, liaisons *liais){
        int somme = nbDepot ;
        for( i = 0 ; i < somme ; i++ ){
            for( j = 0 ; j < somme ; j++){
                while( (res.dep[i] != res.dep1) || (res.dep[j] != res.dep2)){
                    if( tab[i][j] != NULL )
                        tab[i][j] = liais.poidsLiaison ;
                    else
                        return -1 ;   
                }
            }
        }
    }
    
    
    boolean existe_liaison(reseau *res, depot *dep1, depot *dep2){
        
        int somme = nbDepot ;
        for( i = 0 ; i < somme ; i++ ){
            for( j = 0 ; j < somme ; j++){
                while( (res.dep[i] != res.dep1) || (res.dep[j] != res.dep2)){
                    if( tab[i][j] != NULL )
                        return false;
                    else
                        return true; ;   
                }
            }
        }
       
    }

    
void initialiserSommets(reseau *res, depot *depart)
{    
    num = res.nbDepot ;
    matrice m = allouer_matrice( res.nbDepot , res.nbDepot);
    for( i = 0 ; i < num ; i++){
        if( strcmp(res.depart.nom,res.dep[i].nom) != 0){
            res.dep.poidsSommet = infini;
            res.depart.poidsSommet = 0;
        }
        else
            return -1;
        
        for( j=0 ; i < num ; j++ ){
            if( i == j )
                tab[i][j] = 0;
            else
                tab[i][j] = res.dep.poidsSommet;
        
    }
}
    
    
    depot trouve_min(reseau *res){
        unsigned int minimum;
        minimum = tab[0][0];
        for( i = 0 ; i < nbDepot ; i++){
            for( j = 1 ; j < nbDepot ; j++){
                if( tab[i][j] < minimum)
                    minimum = tab[i][j];
            }
        }
        return rechercherDepot(res, minimum);
    }
    
    
   void maj_distances(depot *dep1, depot *dep2){
        if(dep2.poidsSommet > (dep1.poidsSommet + poids(dep1,dep2)))
            dep2.poidsSommet = dep1.poidsSommet + poids(dep1,dep2);
    }
    
    
    depot Dijkstra(reseau *res, int poids, depot *dep_depart, depot *dep_arrivee){
        initialiserSommets(des, dep_depart);
        depot *total = NULL;
        depot *total2 = NULL;
        for( i = 0 ; i < nbDepot ; i++ ){
            total = total + res.dep[i];
        }
        
        while( total != NULL ){
            depot *d1 = trouve_min(res.total);
            total = total - d1;
            for( i = 0 ; i < nbDepot ; i++){
                if( existe_liaison(res, res.d1, res.dep[i]) == true ){
                    maj_distances(res.d1, res.dep[i]);
                }
            }
        }
        depot *a = NULL;
        depot *b = dep_arrivee;
        while (b != dep_depart) {
            a = a + b;
            s = predecessor[s];
        } // fonction a finir la fin n'est pas bonne
        
    }
    
    
    unsigned int poids(depot *dep1, depot *dep2){
        unsigned int poids;
        for( i = 0 ; i < nbDepot ; i++){
            if(strcmp(res.dep1.nom,res.dep[i].nom) == 0){
                for( j = 0 ; j < nbDepot ; j++){
                    if(strcmp(res.dep2.nom,res.dep[j].nom) == 0)
                        poids = tab[i][j];
                        }
            }
            return -1;
        }
        return poids;
    }










