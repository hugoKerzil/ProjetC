#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "hash.h"

// Initialise le N-gramme avec des mots vides
extern void sequence_initialize(struct strhash_table *ht);

// Gestion de l'iterateur permettant de parcourir le N-gramme
// initialise l'iterateur sur le premier mot du N-gramme courant
extern void sequence_itStart(void);

// retourne le mot correspondant a la position de l'iterateur
// avance la position de l'iterateur
extern const char * sequence_itNext(void);

// test si l'iterateur est a la fin du N-gramme
extern int sequence_itHasNext(void);

// Nouveau mot de fin du prochain N-gramme
// definit le nouveau mot qui entrera dans le N-gramme
extern void sequence_addWord(const char * wordi, struct strhash_table *ht);

// retourne le nouveau mot qui entrera dans le N-gramme
extern const char * sequence_nextWord(void);

// avance le N-gramme pour integrer le nouveau mot ecrit
extern void sequence_progress(void);

// Debug
// afiiche le N-gramme courant, les mots sont separes par des /
extern void sequence_print(void);

// sequence sous forme d'une chaine de caracteres
extern char * sequence_printInTab(void);

// Pour les testes
extern void pritnftst(void);

#endif
