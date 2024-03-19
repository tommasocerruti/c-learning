#ifndef _TREE_PRIVATE_INCLUDED
#define _TREE_PRIVATE_INCLUDED

#include "treePublic.h"

struct node {
  data_t val;
  struct node *left;
  struct node *right;
};

#endif

