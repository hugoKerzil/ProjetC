#ifndef _ARBRE_H_
#define _ARBRE_H_

#include "../Module_tableau_dynamique/tableaudynamique.h"
#include "../Module_sequence/sequence.h"
#include "../Module_sequence/hash.h"

typedef struct Node {
    char *word;
    tabdyna *children;
    int occurrences;
} Node;

// Fonction de comparaison pour rechercher un mot dans les fils
extern int compare_nodes(void *a, void *b);

// Fonction qui recherche un noeud et/ou ajoute un noeud (si besoin est).
extern Node *recherche_N_gramme(Node *root);

//Fonction qui recherche un mots dans un nœud et retourne le nœud avec l'incrémentation de l'occurence ou ajoute le mot s'il existe pas
extern Node *recherche_mot(Node *parent, const char *word);

// Fonction qui recherche dans les nœuds feuilles accessibles
// depuis le nœud final du chemin d'un N-grammes, le mot qui
// présente le nombre maximum d'occurrences.
extern Node *recherche_occ_max(Node *root);

#endif
