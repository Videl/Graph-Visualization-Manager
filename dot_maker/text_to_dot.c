/**
 * Code compatible avec *GNU99*
 * en fait non, problème
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAME 100 // Strings name will be 100 chars *max*
#define SIZE_NUMBER 3
#define SOLUTION_MAX 30

int charToInt(const char c);
int myPow(const int a, const int b);
int isSolution(const char *depotOne, const char *depotTwo, const char
**solution);
int myAbs(const int a);


int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf("usage: %s input_file output_file [debug]\n", argv[0]);
        printf("Beware : no file generated on debug mode, you only see the output.\n");
        printf("Exiting...\n");
        exit(1);
    }

    int output = 0;
    if(argc == 4)
        output = strcmp(argv[3], "nodebug");

    FILE *inputFileP = NULL;
    FILE *outputFileP = NULL;

    inputFileP = fopen(argv[1], "r");

    if(inputFileP == NULL)
    {
        if(output)
            printf("Error while opening the input file !\n");
        if(output)
            printf("Exiting...\n");
        exit(2);
    }

    int c;
    int mark = -1;
    int locations = 0;
    /**
      mark
      if mark == -1:
      we are reading the number of locations
      if mark == 0:
      we are still reading the name
      if mark == 1:
      we are reading the number of locations
      if mark == 2:
      we are reading an id corresponding to a name
      if mark == 3:
      we are reading a label

     */
    fscanf(inputFileP, "%d", &locations);

    if(output)
        printf("We have %d locations in the network.\n", locations);

    /** Allocating future memory **/

    /** Names **/
    char **names = malloc(locations*sizeof(char*));
    char **solutions = malloc(SOLUTION_MAX*sizeof(char*));
    
    int i;
    int j;


    for(i = 0; i < locations; i++)
    {
        names[i] = malloc(SIZE_NAME*sizeof(char));
    }

    for(i = 0; i < SOLUTION_MAX; i++)
    {
        solutions[i] = malloc(SIZE_NAME*sizeof(char*));
    }


    int charMarker = 0;
    int locationMarker = 0;
    int labelIntMarker = 0;
    int curserCurrentRelation = 0;
    int solutionMarker = 0;
    int solutionStrMarker = 0;
    int *nbOfRelations = malloc(locations*sizeof(int));
    int **relations = malloc(locations*sizeof(int*));
    int **relationsLabel = malloc(locations*sizeof(int*));

    if(output)
        printf("Reading the input file.\n");
    do
    {
        c = fgetc(inputFileP);
        //printf("locationMarker : %d, Lecture de >>> %c <<<\n", locationMarker, c);
        if(locationMarker < locations)
        {
            if(mark == -1)
            {
                if(c == '\n')
                    mark++;
            }
            else if(mark == 0) // name
            {
                if(c == ' ')
                {
                    mark++;
                    names[locationMarker][charMarker] = '\0';
                    charMarker = 0;
                }
                else
                {
                    names[locationMarker][charMarker++] = c;
                }
            }
            else if(mark == 1) // number of relations
            {
                if(c == ' ')
                {
                    relations[locationMarker] = malloc(nbOfRelations[locationMarker]*sizeof(int));
                    relationsLabel[locationMarker] = malloc(nbOfRelations[locationMarker]*sizeof(int));
                    for(i = 0; i < nbOfRelations[locationMarker]; i++)
                    {
                        relationsLabel[locationMarker][i] = 0;
                    }
                    mark++;
                }
                else if(c == '\n')
                {
                    locationMarker++;
                }
                else
                {
                    nbOfRelations[locationMarker] = charToInt(c);
                }
            }
            else if(mark == 2) // id of relation
            {
                if(c == ' ')
                {
                    mark++;
                    labelIntMarker = SIZE_NUMBER;
                }
                else
                { 
                    relations[locationMarker][curserCurrentRelation] = charToInt(c) - 1;
                }
            }
            else if(mark == 3) // label of relation
            {
                if(c == '\n')
                {
                    locationMarker++;
                    curserCurrentRelation = 0;
                    mark = 0;
                }
                else if(c == ' ')
                {
                    mark--;
                    curserCurrentRelation++;
                }
                else
                {
                    int add = relationsLabel[locationMarker][curserCurrentRelation];
                    //int oadd = add;
                    add = add + charToInt(c) * myPow(10, --labelIntMarker);
                    //printf("add(%d) = add(%d) + %d * %d\n", add, oadd,
                    //charToInt(c), myPow(10, labelIntMarker));
                    relationsLabel[locationMarker][curserCurrentRelation] = add;
                }
            }
        } else   // We are done looking for files, we are now registering the
                // solution
        {
            if(c == ' ' || c == '\n')
            {
                solutions[solutionMarker++][solutionStrMarker] = '\0';
                solutionStrMarker = 0;
                //printf("Capture de %s !\n", solutions[solutionMarker-1]);
            }
            else
                solutions[solutionMarker][solutionStrMarker++] = c;
        }
    }
    while(c != EOF);

    fclose(inputFileP);
    solutionMarker = 0;
    solutionStrMarker = 0;

    if(output)
    {
        printf("End of parsing input file \"%s\".\n", argv[1]);
        printf("Beginning of writing into \"%s\".\n", argv[2]);
    }

    outputFileP = fopen(argv[2], "a+");

    if(outputFileP == NULL)
    {
        if(output)
        {
            printf("Error when creating/opening %s.\n", argv[2]);
            printf("Exiting...\n");
        }
        exit(3);
    }


    if(output)
        printf("digraph G {\n");
    else
        fprintf(outputFileP, "digraph G {\n");


    for(i = 0; i < locations; i++)
    {
        for(j = 0; j < nbOfRelations[i]; j++)
        {
            if(output)
            {
                int sol = isSolution(names[i], names[relations[i][j]], solutions);
                if(sol == 0)
                    printf("%s->%s [label = \"%d\", color=red]\n", names[i],
                    names[relations[i][j]], relationsLabel[i][j]);
                else
                    printf("%s->%s [label = \"%d\"]\n", names[i], names[relations[i][j]], relationsLabel[i][j]);
            }
            else
            {   
                int sol = isSolution(names[i], names[relations[i][j]], solutions);
                if(sol == 0)                 
                    fprintf(outputFileP, "%s->%s [label = \"%d\", color=red]\n", names[i], 
                        names[relations[i][j]], relationsLabel[i][j]);
                else
                    fprintf(outputFileP, "%s->%s [label = \"%d\"]\n", names[i], 
                        names[relations[i][j]], relationsLabel[i][j]); 
            }
        }
    }

    if(output)
        printf("}\n");
    else
        fprintf(outputFileP, "}\n");


    fclose(outputFileP);


    for(i = 0; i < locations; i++)
    {
        free(relations[i]);
        free(relationsLabel[i]);
        free(names[i]);
    }
    for(i = 0; i < SOLUTION_MAX; i++)
    {
        free(solutions[i]);
    }

    free(relations);
    free(relationsLabel);
    free(names);
    free(nbOfRelations);
    free(solutions);

    return 0;
}

int charToInt(const char c)
{
    if(c > 47 && c < 58)
        return c - 48;
    else
        return 0;
}

/**
  a^b = pow(a,b)
 */
int myPow(const int a, const int b)
{
    int i;
    int acc = 1;
    if(b > 0)
    {
        for(i = 0; i < b; i++)
        {
            acc *= a;
        }
    }
    return acc;
}

int myAbs(const int a)
{
    return ((a > 0) ? a : -a);
}

int isSolution(const char *depotOne, const char *depotTwo, const char **solution)
{
    int i;
    int iOne = -1;
    int iTwo = -1;
    int markOne = -1;
    int markTwo = -1;

    for(i = 0; i < SOLUTION_MAX; i++)
    {
        if(strcmp(solution[i], depotOne) == 0)
        {
            markOne = 0;
            iOne = i;
        }
        else if(strcmp(solution[i], depotTwo) == 0)
        {
            markTwo = 0;
            iTwo = i;
         }
    }
    return ((markOne == 0 && markTwo == 0 && myAbs(iOne - iTwo) == 1) ? 0 : -1);
}

