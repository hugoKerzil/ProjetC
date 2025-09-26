#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "../Module_tableau_dynamique/tableaudynamique.h"
#include "../Module_sequence/sequence.h"
#include "../Module_sequence/hash.h"

// Fonction de comparaison pour rechercher un mot dans les fils
int compare_nodes(void *a, void *b) {
    Node *node_a = (Node *)a;
    char *word_b = (char *)b;
    return strcmp(node_a->word, word_b);
}

int main(void) {
    // Création de la racine de l'arbre
    Node *root = (Node *)malloc(sizeof(Node));
    if (root == NULL) {
        printf("Erreur!");
        return 1;
    }

    root->word = NULL;
    root->children = CreaInitTab(4, 5);

    // Exemple de N-grammes
    struct strhash_table *ht = strhash_create(100);
    sequence_initialize(ht);
    sequence_addWord("toto", ht);
    sequence_progress();
    sequence_addWord("titi", ht);
    sequence_progress();
    sequence_addWord("tata", ht);
    sequence_progress();

    // recherche d'un N-gramme et print du dernière mot de celui-ci
    printf("recherche d'un N-gramme et print du dernière mot de celui-ci\n");
    Node* dernier = recherche_N_gramme(root);
    printf("Dernier noeud : %s\n", dernier->word);
    printf("\n");

    // recherche du mot tata
    printf("recherche d'un mot tata\n");
    const char *word2 = "tata";
    Node *words2 = recherche_mot(root, word2);
    printf("Le mots est : %s\n", words2->word);
    printf("L'occurrence est : %d\n", words2->occurrences);
    printf("\n");
    
    // recherche du mot tutu qui n'existe pas et son ajout
    printf("recherche du mot tutu qui n'existe pas et son ajout\n");
    const char *word = "tutu";
    Node *words = recherche_mot(root, word);
    printf("Le mots est : %s\n", words->word);
    printf("L'occurrence est : %d\n", words->occurrences);
    printf("\n");

    // rajout une deuxième fois le mot tutu
    Node *new_child = (Node *)malloc(sizeof(Node));
    if (new_child == NULL) {
        printf("Erreur d'allocation mémoire pour un nouveau noeud\n");
        return 1;
    }

    //Node *lh = recherche_mot(root, word);

    new_child->word = strdup(word); // Copie du mot
    new_child->children = CreaInitTab(4, 5);
    AjoutEle(root->children, (void *)new_child);

    // recherche du mot tutu après deux ajout
    printf("recherche du mot tutu après deux ajout\n");
    Node *words3 = recherche_mot(root, word);
    printf("Le mots est : %s\n", words3->word);
    printf("L'occurrence est : %d\n", words3->occurrences);
    printf("\n");

    // recherche du mot avec le plus d'occurrence
    printf("recherche du mot avec le plus d'occurrence\n");
    Node *words4 = recherche_occ_max(root);
    printf("Le mots est : %s\n", words4->word);
    printf("L'occurrence est : %d\n", words4->occurrences);
    printf("\n");

    // rajout une troisème fois le mot tutu
    Node *new_child2 = (Node *)malloc(sizeof(Node));
    if (new_child2 == NULL) {
        printf("Erreur d'allocation mémoire pour un nouveau noeud\n");
        return 1;
    }

    new_child2->word = strdup(word); // Copie du mot
    new_child2->children = CreaInitTab(4, 5);
    AjoutEle(root->children, (void *)new_child2);

    // recherche du mot tutu après trois ajout
    printf("recherche du mot tutu après trois ajout\n");
    Node *words7 = recherche_mot(root, word);
    printf("Le mots est : %s\n", words7->word);
    printf("L'occurrence est : %d\n", words7->occurrences);
    printf("\n");

    // rajout une deuxième fois le mot tata
    Node *new_child3 = (Node *)malloc(sizeof(Node));
    if (new_child3 == NULL) {
        printf("Erreur d'allocation mémoire pour un nouveau noeud\n");
        return 1;
    }

    char *w = "tata";

    new_child3->word = strdup(w); // Copie du mot
    new_child3->children = CreaInitTab(4, 5);
    AjoutEle(root->children, (void *)new_child3);

    // recherche du mot tata après deux ajout
    printf("recherche du mot tata après deux ajout\n");
    Node *words8 = recherche_mot(root, w);
    // if (strcmp(words8->word, "tata\n") && words8->occurrences == 2) {
    //     printf("C'est bon\n");
    // } else {
    //     printf("C'est pas bon\n");
    // }
    printf("Le mots est : %s\n", words8->word);
    printf("L'occurrence est : %d\n", words8->occurrences);
    printf("\n");
    printf("\n");

    // recherche du mot avec le plus d'occurrence
    printf("recherche du mot avec le plus d'occurrence\n");
    Node *words6 = recherche_occ_max(root);
    printf("Le mots est : %s\n", words6->word);
    printf("L'occurrence est : %d\n", words6->occurrences);
    printf("\n");

    free(root);
    
    return 0;
}