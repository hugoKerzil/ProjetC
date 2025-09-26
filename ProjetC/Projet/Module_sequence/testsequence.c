#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequence.h"
#include "hash.h"


int main(void) {

    

    // creation de la table de hachage
    struct strhash_table *ht = strhash_create(100);

    // teste de l'initialisation du N-gramme
    sequence_initialize(ht);


    sequence_print();

    // teste de l'ajout de mot et du dépassement/suppression du mot le plus ancien pour le remplacer par un nouveau mot
    sequence_addWord("toto", ht);
    printf("%s\n", sequence_nextWord());
    sequence_progress();

    sequence_addWord("titi", ht);
    sequence_progress();

    sequence_addWord("tata", ht);
    sequence_progress();
 
    sequence_addWord("toto2", ht);
    sequence_progress();

    sequence_addWord("test", ht);
    sequence_progress();

    sequence_print();
    
    printf("%s\n", sequence_printInTab());
    printf("\n");

    // Réinitialisation de N-gramme
    printf("Réinitialisation\n");

    sequence_initialize(ht);
    sequence_print();
    printf("%s\n", sequence_printInTab());
    printf("\n");

    // Le meme mot dans toute les cases
    printf("Le meme mot\n");

    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    pritnftst();
    sequence_print();
    printf("%s\n", sequence_printInTab());
    printf("\n");

    // avec le nouveau mot dans la derniere case du N-gramme
    printf("Derniere case du N-gramme\n");
    sequence_addWord("titi", ht);
    sequence_progress();

    sequence_addWord("tata", ht);
    sequence_progress();
    pritnftst();
    sequence_print();
    printf("%s\n", sequence_printInTab());
    printf("\n");

    // Le meme mot dans toute les cases
    printf("Le meme mot\n");

    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    sequence_addWord("mot", ht);
    sequence_progress();
    pritnftst();
    sequence_print();
    printf("%s\n", sequence_printInTab());
    printf("\n");

    // avec le nouveau mot dans la premiere case du N-gramme
    printf("premiere case du N-gramme\n");
    sequence_addWord("titi", ht);
    sequence_progress();

    sequence_addWord("tata", ht);
    sequence_progress();

    sequence_addWord("toto", ht);
    sequence_progress();
    pritnftst();
    sequence_print();
    printf("%s\n", sequence_printInTab());
    printf("\n");



    return 1;
}