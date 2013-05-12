/**
 * Code compatible avec *GNU99*
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "network_generation.h"

void go_to_random()
{
    srand(time(NULL));
    int number_of_depot;
    int i;

    number_of_depot = rand() % MAX_DEPOT_ALLOWED  + MIN_DEPOT_ALLOWED;
    printf("Nombres de dépôts créés : %d.\n", number_of_depot);

    char **names = malloc(number_of_depot*sizeof(char*));
    for(i = 0; i < number_of_depot; i++)
    {
        names[i] = malloc(7*sizeof(char));
        names[i][0] = 'd';
        names[i][1] = 'e';
        names[i][2] = 'p';
        names[i][3] = 'o';
        names[i][4] = 't';
        names[i][5] = (char) i;
        names[i][6] = '\0';
    }
    
    printf("%d dépôts créés.\n", number_of_depot);

    int *number_of_relations = malloc(number_of_depot*sizeof(int));

    for(i = 0; i < number_of_depot; i++)
    {
        number_of_relations[i] = rand() % MAX_RELATIONS_PER_DEPOT +
        MIN_RELATIONS_PER_DEPOT;
        printf("%d relations pour le dépôt numéro %d.\n", number_of_relations[i], i);
    }



    /* Freeing */
    for(i = 0; i < number_of_depot; i++)
    {
        free(names[i]);
    }
    free(names);
}


void go_to_manual()
{
    printf("Mode manuel activé.\n");
    printf("Bienvenue !\n");

    int number_of_depot;
    printf("Nombre de dépôts : ");
    scanf("%d", &number_of_depot);
    getchar();

    printf("%d dépôts choisis.\n", number_of_depot);

    int i,j;
    char **names = malloc(number_of_depot*sizeof(char*));
    int *number_of_relations = malloc(number_of_depot*sizeof(int));
    int **relations_with = malloc(number_of_depot*sizeof(int*));
    int **distance = malloc(number_of_depot*sizeof(int*));

    for(i = 0; i < number_of_depot; i++)
    {
        printf("################\n");
        printf("#  Dépôt n°%d  #\n", i);
        printf("################\n");
        
        names[i] = malloc(NAME_SIZE*sizeof(char));
        if(names[i] == NULL)
        {
            printf("Erreur lors de l'attribution de la mémoire pour le dépôt numéro %d. Fin du programme.\n", i);
            exit(1);
        }


        printf("Nom du dépôt %d : ", i);
        scanf("%s", names[i]);
        getchar();
        
        printf("Nom choisi : %s\n", names[i]);

        printf("Combien de relations : ");
        scanf("%d", &number_of_relations[i]);
        getchar();
        
        printf("%d relations pour le dépôt n°%d.\n", number_of_relations[i], i);

        relations_with[i] = malloc(number_of_relations[i]*sizeof(int));
        distance[i] = malloc(number_of_relations[i]*sizeof(int));
        for(j = 0; j < number_of_relations[i]; j++)
        {
            printf("Relations n°%d/%d se fait avec :\n", j, number_of_relations[i]);
            printf("Attention, c'est le *numéro* du dépôt, et il commence à zéro : ");
            scanf("%d", &relations_with[i][j]);
            getchar();

            printf("Quelle distance entre dépôt n°%d et dépôt n°%d : ", i, relations_with[i][j]);
            scanf("%d", &distance[i][j]);
            getchar();
        }
    }

    printf("Fin de la capture.\n");
    printf("Quel est le nom du fichier de sortie ? ");
    char *sortie = malloc(NAME_SIZE*sizeof(char));
    scanf("%s", sortie);
    getchar();

    printf("Nom du fichier de sortie : %s\n", sortie);

    FILE *output = fopen(sortie, "a+");

    if(output == NULL)
    {
        printf("Problème lors de l'ouverture du fichier de sortie \"%s\".\n", sortie);
        exit(4);
    }


    fprintf(output, "%d\n", number_of_depot);
    for(i = 0; i < number_of_depot; i++)
    {
        fprintf(output, "%s %d", names[i], number_of_relations[i]);

        for(j = 0; j < number_of_relations[i]; j++)
        {
            fprintf(output, " %d %d", relations_with[i][j]+1, distance[i][j]);
        }
        
        fprintf(output, "\n");
    }
    fclose(output);

    printf("Fin de la génération du fichier %s.\n", sortie);

    /* Free */
    for(i = 0; i < number_of_depot; i++)
    {
        free(names[i]);
        free(relations_with[i]);
        free(distance[i]);
    }
    
    free(number_of_relations);
    free(names);
    free(relations_with);
    free(distance);
}


