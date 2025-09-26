#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "../Module_tableau_dynamique/tableaudynamique.h"
#include "../Module_sequence/sequence.h"
#include "../Module_sequence/hash.h"


// Fonction qui recherche un noeud et/ou ajoute un noeud (si besoin est).
Node *recherche_N_gramme(Node *root) {
    sequence_itStart();
    while (sequence_itHasNext()) {
        const char *word = sequence_itNext();
        Node *child = NULL;
        int trouver = 0;

        int nb_child = root->children->size;

        for (int j = 0; j < nb_child; j++) {
            child = (Node *)LectTab(root->children, j);
            if (compare_nodes(child, (void *)word) == 0) {
                trouver = 1;
                root = child;
                break;
            }
        }

        if (!trouver) {
            Node *new_child = (Node *)malloc(sizeof(Node));
            if (new_child == NULL) {
                fprintf(stderr, "Erreur d'allocation mémoire pour un nouveau noeud\n");
                return NULL;
            }

            new_child->word = strdup(word);
            new_child->children = CreaInitTab(4, 5);
            AjoutEle(root->children, (void *)new_child);
            root = new_child;
        }
    }

    return root;
}

//Fonction qui recherche un mots dans un nœud et retourne le nœud avec l'incrémentation de l'occurence ou ajoute le mot s'il existe pas
Node *recherche_mot(Node *root, const char *word) {
    if (!root) {
        fprintf(stderr, "Le nœud parent est NULL.\n");
        return NULL;
    }

    int nb_child = root->children->size;

    for (int i = 0; i < nb_child; i++) {
        Node *child = (Node *)LectTab(root->children, i);
        if (strcmp(child->word, word) == 0) {
            child->occurrences++;
            return child;
        }
    }

    Node *new_child = (Node *)malloc(sizeof(Node));
    if (!new_child) {
        fprintf(stderr, "Erreur d'allocation mémoire pour un nouveau nœud.\n");
        return NULL;
    }

    new_child->word = strdup(word);
    new_child->occurrences = 1;
    new_child->children = CreaInitTab(4, 5);

    AjoutEle(root->children, (void *)new_child);

    return new_child;
}


// Fonction qui recherche dans les nœuds feuilles accessibles
// depuis le nœud final du chemin d'un N-grammes, le mot qui
// présente le nombre maximum d'occurrences.
Node *recherche_occ_max(Node *root) {
    if (!root) {
        fprintf(stderr, "Le nœud parent est NULL.\n");
        return NULL;
    }

    if (!root->children || root->children->size == 0) {
        fprintf(stderr, "Pas d'enfants dans ce nœud.\n");
        return NULL;
    }

    int max_occ = 0;
    Node *wordm = (Node *)malloc(sizeof(Node));

    int nb_child = root->children->size;

    for (int i = 0; i < nb_child; i++) {
        Node *child = (Node *)LectTab(root->children, i);
        if(child && child->occurrences > max_occ) {
            max_occ = child->occurrences;
            wordm = child;
        }
        
    }
    return wordm;
}