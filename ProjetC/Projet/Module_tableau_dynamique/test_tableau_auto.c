#include <stdio.h>
#include <stdlib.h>
#include "tableaudynamique.h"

// Fonction de comparaison des éléments
int compare_elements(void* a, void* b) {
    if(a == NULL || b == NULL) {
        return 1;
    }
    return (*(int*)a - *(int*)b);
}

int main(void) {

    // Création et initialisation du tableau
    printf("Création et Initialisation d'un tableau\n");
    tabdyna* tab = CreaInitTab(4, 5);
    if (!tab) {
        return 1;
    }

    printf("C'est bon \n");
    printf("\n");

    // Ajout d'éléments dans le tableau
    printf("Ajout d'éléments dans le tableau\n");
    int* pt = (int*)malloc(tab->size_max * sizeof(int));
    if (!pt) {
        printf("Erreur d'allocation mémoire pour pt\n");
        DestruTab(tab);
        return 1;
    }

    for (int i = 0; i < tab->size_max; i++) {
        pt[i] = i;
        AjoutEle(tab, &pt[i]);
        if(tab->tab[i] != &pt[i]) {
            return 1;
        }
    }
    printf("C'est bon \n");
    printf("\n");

    // Modification de l'ordre des éléments
    int x = 2;
    int val = 10;
    void* ele = &val;
    void* ele0 = tab->tab[0];
    void* ele1 = tab->tab[1];
    void* ele2 = tab->tab[2];
    void* ele3 = tab->tab[3];
    printf("Ajout d'un élément (valeur %d) dans le tableau à l'indice %d\n", val, x);
    ModifTab(tab, ele, x);
    if(tab->tab[0] == ele0 && tab->tab[1] == ele1 && tab->tab[2] == ele && tab->tab[3] == ele2 && tab->tab[4] == ele3) {
        printf("C'est bon\n");
    } else {
        printf("C'est pas bon\n");
    }
    printf("\n");

    int v = 100;
    void* p = &v;
    printf("Ajout d'un élément (valeur %d) dans le tableau\n", v);
    AjoutEle(tab, p);
    if(tab->tab[0] == ele0 && tab->tab[1] == ele1 && tab->tab[2] == ele && tab->tab[3] == ele2 && tab->tab[4] == ele3 && tab->tab[5] == p) {
        printf("C'est bon\n");
    } else {
        printf("C'est pas bon\n");
    }
    printf("\n");

    // Ajout d'un élément non entier (char) à l'indice i
    x = 2;
    char val2 = 'e';

    printf("Ajout d'un élément ('%c') dans le tableau à l'indice %d\n", val2, x);
    ModifTab(tab, &val2, x);

    if(tab->tab[0] == ele0 && tab->tab[1] == ele1 && tab->tab[2] == &val2 && tab->tab[3] == ele && tab->tab[4] == ele2 && tab->tab[5] == ele3 && tab->tab[6] == p) {
        printf("C'est bon\n");
    } else {
        printf("C'est pas bon\n");
    }
    printf("\n");

    // Modification de la valeur de 'val' et réinsertion à l'indice x
    char val3 = 'd';
    printf("Ajout d'un élément ('%c') dans le tableau à l'indice %d\n", val3, x);
    ModifTab(tab, &val3, x);
    if(tab->tab[0] == ele0 && tab->tab[1] == ele1 && tab->tab[2] == &val3 && tab->tab[3] == &val2 && tab->tab[4] == ele && tab->tab[5] == ele2 && tab->tab[6] == ele3 && tab->tab[7] == p) {
        printf("C'est bon\n");
    } else {
        printf("C'est pas bon\n");
    }
    printf("\n");

    // Ajout d'un autre élément non entier (char) à un autre indice
    x = 9;
    char val4 = 'x';
    printf("Ajout d'un élément ('%c') dans le tableau à l'indice %d\n", val4, x);
    ModifTab(tab, &val4, x);
    if(tab->tab[0] == ele0 && tab->tab[1] == ele1 && tab->tab[2] == &val3 && tab->tab[3] == &val2 && tab->tab[4] == ele && tab->tab[5] == ele2 && tab->tab[6] == ele3 && tab->tab[7] == p && tab->tab[9] == &val4) {
        printf("C'est bon\n");
    } else {
        printf("C'est pas bon\n");
    }
    printf("\n");

    // Recherche d'un élément
    printf("Recherche de l'élément %d\n", v);
    RechercheEle(tab, &v, compare_elements);
    printf("\n");

    int a = 12;
    printf("Recherche de l'élément %d\n", a);
    RechercheEle(tab, &a, compare_elements);
    printf("\n");

    printf("Recherche de l'élément %c\n", val3);
    RechercheEle(tab, &val3, compare_elements);
    printf("\n");

    // Libération de la mémoire
    printf("Libération de la mémoire\n");
    DestruTab(tab);
    free(pt);

    return 0;
}
