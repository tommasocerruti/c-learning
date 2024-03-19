#include "treePrivate.h"

#define FIND 0

static node_t *myAlloc (void);

node_t *createEmptyTree (void){
  return (NULL);
}

static node_t *myAlloc (void){
    node_t *p;
    p = (node_t *)malloc(sizeof(node_t));
    if (p == NULL) {
        printf ("Allocation Error.\n");
        exit (1);
    }
    return (p);
}

node_t *insert (node_t *rp,data_t data){
  node_t *p;
  /* Empty Tree: Found Position */
  if (rp == NULL) {
    p = myAlloc();
    p->val = data;
    p->left = p->right = NULL;
    return (p);
  }
  /* Duplicated Element */
  if (compare(data, rp->val) == 0) {
    return (rp);
  }
  if (compare(data, rp->val) < 0) {
    /* Insert on the left */
    rp->left = insert (rp->left, data);
  } else {
    /* Insert on the right */
    rp->right = insert (rp->right, data);
  }
  return (rp);
}


node_t * readTree (FILE *fp){
  node_t *rp;
  data_t d;
  rp = createEmptyTree ();
  while (readData (fp, &d) != EOF) {
    rp = insert (rp, d);
  }
  return (rp);
}

void freeTree (node_t *rp){
  if (rp == NULL) {
    return;
  }
  freeTree (rp->left);
  freeTree (rp->right);
  free (rp);
  return;
}

void writeTree (FILE *fp, node_t *rp, int modo){
  if (rp == NULL) {
    return;
  }
  if (modo == PREORDER) {
    writeData (fp, rp->val);
  }
  writeTree (fp, rp->left, modo);
  if (modo == INORDER) {
    writeData(fp, rp->val);
  }
  writeTree (fp, rp->right, modo);
  if (modo == POSTORDER) {
    writeData(fp, rp->val);
  }
  return;
}

void bst2hash (node_t *root, ST st){
    data_t data;
    Item item;
    if (root == NULL) {
        return;
    }
    bst2hash (root->left, st);
    data = root->val;
    item = ITEMset (getField1 (data), getField2 (data),getField3 (data), getField4 (data));
    STinsert (st, item);
    bst2hash (root->right, st);

    return;
}