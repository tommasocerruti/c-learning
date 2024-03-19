#ifndef _TREE_PUBLIC_INCLUDED
#define _TREE_PUBLIC_INCLUDED

#include "data.h"
#include "st.h"
#include "item.h"

#define PREORDER  (-1)
#define INORDER    (0)
#define POSTORDER  (1)

typedef struct node node_t;

node_t *createEmptyTree ();
node_t *readTree(FILE *);
node_t *insert(node_t *, data_t);
void writeTree(FILE *, node_t *, int);
void freeTree(node_t *);

//exercise 1
void bst2hash(node_t *, ST);




#endif

