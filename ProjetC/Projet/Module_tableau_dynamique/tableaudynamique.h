#ifndef _TABLEAUDYNAMIQUE_H_
#define _TABLEAUDYNAMIQUE_H_

// Structure pour un tableau dynamique
struct tabdyna {
    int size;
    int size_max;
    void** tab;
    int fmulti;
};

typedef struct tabdyna tabdyna;

// Création initiale d'un tableau dynamique
extern tabdyna* CreaInitTab(int size_max, int fmulti);

// Destruction du tableau dynamique
extern void DestruTab(tabdyna* t);

// Lecture d'un élément du tableau à une position donnée
extern void *LectTab(tabdyna* t, int i);

// Ajout d'un élément à la fin du tableau
extern void AjoutEle(tabdyna* tab, void* ele);

// Modification d'un élément dans le tableau à une position donnée
extern void ModifTab(tabdyna* tab, void* ele, int i);

// Fonction de comparaison d'éléments
extern int compare_elements(void* a, void* b);

// Recherche d'un élément dans le tableau
extern void RechercheEle(tabdyna* t, void* element, int (*compare)(void*, void*));

#endif
