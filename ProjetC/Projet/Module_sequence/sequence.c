#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

//nb de mots dans les N-grammes
enum { Lg_N_gramme = 3 };

// tab N-gramme
static char *table[Lg_N_gramme + 1];
static int nouveau_mot; // indice de pochain mot ajouter
static int dernier_mot; // indice du dernier mot ajouter
static int premier_mot; // indice du premier mot ajouter 


// Initialise le N-gramme avec des mots vides
void sequence_initialize(struct strhash_table *ht) {
    const char *word = "";
    char *pt = strhash_wordAdd(ht, word); // Ajoute le mot vide dans la table de hachage
    
    for (int i = 0; i <= Lg_N_gramme; i++) {
        table[i] = pt; // ajout du pt du mot vide dans le N-gramme a l'indice i
    }
    nouveau_mot = 0;
    dernier_mot = Lg_N_gramme;
    return;
}

// Gestion de l'iterateur permettant de parcourir le N-gramme
// initialise l'iterateur sur le premier mot du N-gramme courant
void sequence_itStart(void) {
    premier_mot = nouveau_mot + 1;
    if(premier_mot > Lg_N_gramme) { // permet de ne pas depasser la taille du tableau
        premier_mot = 0;
    }
    return;
}

// retourne le mot correspondant a la position de l'iterateur
// avance la position de l'iterateur
const char * sequence_itNext(void) {
    const char *word = table[premier_mot];
    if (++premier_mot > Lg_N_gramme) {
        premier_mot = 0;
    }
    return word;
}

// test si l'iterateur est a la fin du N-gramme
int sequence_itHasNext(void) {
    if (nouveau_mot == premier_mot) {
        return 0;
    }
    return 1;
}



// Nouveau mot de fin du prochain N-gramme
// definit le nouveau mot qui entrera dans le N-gramme
void sequence_addWord(const char * wordi, struct strhash_table *ht) {
    table[nouveau_mot] = strhash_wordAdd(ht, wordi);
    return;
}

// retourne le nouveau mot qui entrera dans le N-gramme
const char * sequence_nextWord(void) {
    return table[nouveau_mot];
}

// avance le N-gramme pour integrer le nouveau mot ecrit
void sequence_progress(void) {
    dernier_mot = nouveau_mot;
    if (nouveau_mot++ >= Lg_N_gramme) {
        nouveau_mot = 0;
    }
    return;
}



// Debug
// afiiche le N-gramme courant, les mots sont separes par des /
void sequence_print(void) {
    sequence_itStart();
    while (sequence_itHasNext()) {
        //printf("%d\n", premier_mot);
        const char *s = sequence_itNext();
        printf("%s/", s);
    }
    printf("\n");
    return;
}

// sequence sous forme d'une chaine de caracteres
char * sequence_printInTab(void) {
    static char chaine[1000];

    chaine[0] = '\0'; // chaine vide

    // Creer la chaîne de caractères
    sequence_itStart();
    while (sequence_itHasNext()) {
        strcat(chaine, sequence_itNext());
        strcat(chaine, " / ");
    }

    return chaine;
}

// Pour les testes
void pritnftst(void) {
    for (int i = 0; i <= Lg_N_gramme; i++) {
        printf("%s/", table[i]);
    }
    printf("\n");
}