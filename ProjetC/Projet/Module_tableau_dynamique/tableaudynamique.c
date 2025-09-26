#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableaudynamique.h"

// Fonction pour créer et initialiser le tableau dynamique
tabdyna* CreaInitTab(int size_max, int fmulti) {
    tabdyna* t = (tabdyna*)malloc(sizeof(tabdyna));
    if (t == NULL) {
        printf("Erreur malloc\n");
        return NULL;
    }
    t->fmulti = fmulti;
    t->size = 0;
    t->size_max = size_max;
    t->tab = (void**)malloc(t->size_max * sizeof(void*));
    if (t->tab == NULL) {
        fprintf(stderr,"Erreur malloc pour le tableau\n");
        free(t);
        return NULL;
    }

    for (int i = 0; i < t->size_max; i++) {
        t->tab[i] = NULL;
    }

    return t;
}

// Fonction pour détruire le tableau dynamique
void DestruTab(tabdyna* t) {
    if (t) {
        free(t->tab);
        free(t);
        printf("Le tableau a bien été supprimé\n");
    }
}

// Fonction pour lire un élément du tableau
void *LectTab(tabdyna* t, int i) {
    if (i < 0 || i >= t->size) {
        printf("Indice invalide : %d\n", i);
        return NULL;
    }
    if (t->tab[i] == NULL) {
        return NULL;
    } else {
        return t->tab[i];
    }
    return NULL;
}

// Fonction pour ajouter un élément en fin de tableau
void AjoutEle(tabdyna* tab, void* ele) {
    if (tab->size >= tab->size_max) {
        tab->size_max *= tab->fmulti;
        void** new_tab = (void**) realloc(tab->tab, tab->size_max * sizeof(void*));
        if (new_tab == NULL) {
            printf("Erreur realloc\n");
            return;
        }
        tab->tab = new_tab;
        for (int i = tab->size; i < tab->size_max; i++) {
            tab->tab[i] = NULL;
        }
    }
    tab->tab[tab->size++] = ele;
}

// Fonction pour ajouter un élément dans le tableau à une position spécifique
void ModifTab(tabdyna* tab, void* ele, int i) {
    if (i >= tab->size_max) {
        int old_max = tab->size_max;
        tab->size_max = old_max * tab->fmulti;

        void** new_tab = (void**) realloc(tab->tab, tab->size_max * sizeof(void*));
        if (new_tab == NULL) {
            printf("Erreur realloc\n");
            return;
        }
        tab->tab = new_tab;
        for (int j = old_max; j < tab->size_max; j++) {
            tab->tab[j] = NULL;
        }
    }

    for (int j = tab->size; j > i; j--) {
        tab->tab[j] = tab->tab[j - 1];
    }
    
    tab->tab[i] = ele;
    if(i > tab->size) {
        tab->size = i + 1;
    } else {
        tab->size++;
    }
}



// Fonction de recherche d'un élément
void RechercheEle(tabdyna* t, void *element, int (*compare)(void*, void*)) {
    for (int i = 0; i < t->size; i++) {
        
        if(t->tab[i] == NULL) {
            return;
        } else {
            if (compare(t->tab[i], element) == 0) {
                printf("L'élément a été trouvé à l'indice %d\n", i);
                return;
            }
        }
    }
    printf("L'élément n'a pas été trouvé\n");
    return;
}
