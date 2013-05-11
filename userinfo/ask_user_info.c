#include <stdio.h>
#include <stdlib.h>
#include "network_generation.h"

int main(void)
{
    printf("##################################\n");
    printf("# Assistant de création de dépôt #\n");
    printf("##################################\n");

    char choice;

    printf("Voulez-vous créer vos dépôts de manière aléatoire ? [O/N] ");
    scanf("%c", &choice);
    getchar();

    if(choice == 'O')
    {
        printf("Création de manière aléatoire choisie.\n");
        go_to_random();
    } else
    {
        printf("Création de manière manuelle choisie.\n");
        go_to_manual();
    }

    return 0;
}
