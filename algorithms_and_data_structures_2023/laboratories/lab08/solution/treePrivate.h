#ifndef _TREE_PRIVATE_INCLUDED
#define _TREE_PRIVATEINCLUDED

#include "treePublic.h"

struct node {
  data_t val;
  struct node *left;
  struct node *right;
};

#endif

