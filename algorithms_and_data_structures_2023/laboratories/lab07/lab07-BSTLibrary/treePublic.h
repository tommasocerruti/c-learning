#ifndef _TREE_PUBLIC_INCLUDED
#define _TREE_PUBLIC_INCLUDED

#include "data.h"

#define PREORDER  (-1)
#define INORDER    (0)
#define POSTORDER  (1)

typedef struct node node_t;

data_t getData (node_t *);
node_t *createEmptyTree ();
node_t *readTree(FILE *);
node_t *searchI (node_t *, data_t);
node_t *searchR (node_t *, data_t);
node_t *treeMinI (node_t *);
node_t *treeMinR (node_t *);
node_t *treeMaxI (node_t *);
node_t *treeMaxR (node_t *);
node_t *insert(node_t *, data_t);
node_t *delete(node_t *, data_t);
void writeTree(FILE *, node_t *, int);
void freeTree(node_t *);

// exercise 1a
void countNode (node_t *root, int *array);
// exercisa 1b
void depthtree (node_t *root, int level, int *depth);
void countLevel (node_t * root, int *array, int l);
// exercise 1c
void countPath (node_t * root, int *np, int *length);
// exercise 1d
int visit (node_t *root, int key1, int key2);
node_t * double_searchR (node_t *rp, data_t data1, data_t data2);
int search_countR (node_t *, data_t, int);


#endif

