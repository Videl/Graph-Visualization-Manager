//
//  reseau.c
//  Travelling
//
//  Created by Manon Signoret on 12/04/13.
//  Copyright (c) 2013 ESIAL. All rights reserved.
//

#include <stdio.h>
#include "reseau.h"





void initialiserReseau(reseau *res){
    res.dep = NULL;
    res.arc = NULL;
    res.nbDepot = 0;
    res.nbLiaison = 0;
}

int ajouterDepot(reseau *res, char *nomDep){
    int trouve = rechercherDepot(res,nomDep);
    if( trouve == -1){     // depot n'appartenant pas au reseau
        if( res.nbDepot == dep_max ){
            res.dep = (depot *)malloc(sizeof(depot)*(dep_max + res.nbDepot));
        }
        strcpy(res.dep[res.nbDepot].nom,nomDep);
        trouve = res.nbDepot ++;
    }
    return res;
}

int ajouterLiaison(reseau *res, char *nomLiaison){
    int trouve = rechercherLiaison(res,nomLiaison);
    if( trouve == -1){     // liaison n'appartenant pas au reseau
        if( res.nbLiaison == liais_max ){
            res.arc = (liaisons *)malloc(sizeof(liaisons)*(liais_max + res.nbLiaison));
        }
        strcpy(res.arc[res.nbLiaison].nom,nomLiaison);
        trouve = res.nbLiaison ++;
    }
    return res;
}

depot rechercherDepot(reseau *res, unsigned int poids_som){
    int i =0;
    while ( i < res.nbDepot ) {
        if( res.dep[i].poidsSommet == poids_som){
            return i;
        }
        i++;
    }
    return -1;

}


liaisons rechercherLiaison(reseau *res, char *nomLiaison){
    int i =0;
    while ( i < res.nbLiaison ) {
        if( strcmp(nomLiaison,res.arc[i].nom) == 0){
            return i;
        }
        i++;
    }
    return -1;
}

void supprimerReseau(reseau *res){
    free(res.dep);
    free(res.arc);
}





