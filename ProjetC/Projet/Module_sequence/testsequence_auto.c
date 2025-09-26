#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequence.h"
#include "hash.h"


int main(void) {

    

    // creation de la table de hachage
    struct strhash_table *ht = strhash_create(100);

    // teste de l'initialisation du N-gramme
    printf("Initialisation du N-gramme\n");
    sequence_initialize(ht);


    if (strcmp(" / / / ",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");

    // teste de l'ajout de mot et du dépassement/suppression du mot le plus ancien pour le remplacer par un nouveau mot
    printf("Test 1 afficher un mot\n");
    sequence_addWord("toto", ht);
    if (strcmp("toto\n",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");
    printf("Test 2\n");
    sequence_progress();

    sequence_addWord("titi", ht);
    sequence_progress();

    sequence_addWord("tata", ht);
    sequence_progress();
 
    sequence_addWord("toto2", ht);
    sequence_progress();

    sequence_addWord("test", ht);
    sequence_progress();

    if (strcmp("tata / toto2 / test / \n",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");

    // Réinitialisation de N-gramme
    printf("Réinitialisation\n");

    sequence_initialize(ht);
    if (strcmp(" / / / ",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");

    // Le meme mot dans toute les cases
    printf("Le meme mot\n");

    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    if (strcmp("mot / mot / mot / \n",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");

    // avec le nouveau mot dans la derniere case du N-gramme
    printf("Derniere case du N-gramme\n");
    sequence_addWord("titi", ht);
    sequence_progress();

    sequence_addWord("tata", ht);
    sequence_progress();
    if (strcmp("mot / titi / tata / \n",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");

    // Le meme mot dans toute les cases
    printf("Le meme mot\n");

    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    if (strcmp("mot / mot / mot / \n",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");

    // avec le nouveau mot dans la premiere case du N-gramme
    printf("premiere case du N-gramme\n");
    sequence_addWord("titi", ht);
    sequence_progress();

    sequence_addWord("tata", ht);
    sequence_progress();

    sequence_addWord("toto", ht);
    sequence_progress();
    if (strcmp("titi / tata / toto / \n",sequence_printInTab())) {
        printf("C'est bon.\n");
    } else {
        printf("Pas bon.\n");
    }
    printf("\n");



    return 1;
}