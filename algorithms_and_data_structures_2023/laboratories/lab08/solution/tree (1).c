#include "treePrivate.h"

#define FIND 0

static node_t *myAlloc (void);
#if FIND
  static data_t findDeleteMax1 (node_t **);
#endif
#if !FIND
  static node_t *findDeleteMax2 (data_t *, node_t *);
#endif

data_t
getData (
  node_t *node
  )
{
  return (node->val);
}

node_t *
createEmptyTree (
  void
  )
{
  return (NULL);
}

node_t *
treeMinI (
  node_t *rp
  )
{
  if (rp == NULL)
    return (rp);

  while (rp->left != NULL) {
    rp = rp->left;
  }

  return (rp);
}

node_t *
treeMinR (
  node_t *rp
  )
{
  if (rp == NULL || rp->left==NULL)
    return (rp);

  return (treeMinR (rp->left));
}

node_t *
treeMaxI (
  node_t *rp
  )
{
  if (rp == NULL)
    return (rp);

  while (rp->right != NULL) {
    rp = rp->right;
  }

  return (rp);
}

node_t *
treeMaxR (
  node_t *rp
  )
{
  if (rp == NULL || rp->right==NULL)
    return (rp);

  return (treeMaxR (rp->right));
}

node_t *
searchI (
  node_t *rp,
  data_t data
  )
{
  while (rp != NULL) {
    if (compare(rp->val, data) == 0)
      return (rp);

    if (compare(data, rp->val) < 0)
      rp = rp->left;
    else
      rp = rp->right;
  }

  return (NULL);
}

node_t *
searchRT (
  node_t *rp,
  data_t data
  )
{
  if (rp==NULL || compare(rp->val, data)==0)
    return (rp);

  if (compare(data, rp->val) < 0)
    return (searchRT (rp->left, data));
  else
    return (searchRT (rp->right, data));
}

node_t *
insert (
  node_t *rp,
  data_t data
  )
{
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


node_t *
readTree (
  FILE *fp
  )
{
  node_t *rp;
  data_t d;

  rp = createEmptyTree ();

  while (readData (fp, &d) != EOF) {
    rp = insert (rp, d);
  }

  return (rp);
}

void
freeTree (
  node_t *rp
  )
{
  if (rp == NULL) {
    return;
  }

  freeTree (rp->left);
  freeTree (rp->right);
  free (rp);

  return;
}

void
writeTree (
  FILE *fp,
  node_t *rp,
  int modo
)
{
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

void
bst2hash (
  node_t *rp,
  ST st
  )
{
  data_t data;
  Item item;

  if (rp == NULL) {
    return;
  }

  bst2hash (rp->left, st);
  data = rp->val;
  //printf ("--> %s %s %d %d\n",
  //  getField1 (data), getField2 (data), getField3 (data), getField4 (data));
  item = ITEMset (getField1 (data), getField2 (data),
    getField3 (data), getField4 (data));
  STinsert (st, item);
  bst2hash (rp->right, st);

  return;
}

node_t *
delete (
  node_t *rp,
  data_t data
  )
{
  node_t *p;

  /* Empty Tree */
  if (rp == NULL) {
    printf("Error: Unknown Data\n");
    return (rp);
  }

  if (compare (data, rp->val) < 0) {
    /* Delete on the left sub-treee Recursively */
    rp->left = delete (rp->left, data);
    return (rp);
  }

  if (compare(data, rp->val)> 0) {
    /* Delete on the rigth sub-treee Recursively */
    rp->right = delete (rp->right, data);
    return (rp);
  }

  /* Delete Current Note rp */
  p = rp;
  if (rp->right == NULL) {
    /* Empty Right Sub-Tree: Return Left Sub-Tree */
    rp = rp->left;
    free (p);
    return (rp);
  }

  if (rp->left == NULL) {
    /* Empty Left Sub-Tree: Return Right Sub-Tree */
    rp = rp->right;
    free (p);
    return rp;
  }

  /* Find Predecessor and Substitute */
#if FIND
  rp->val = findDeleteMax1 (&(rp->left));
#endif
#if !FIND
  {
    data_t val;

    rp->left = findDeleteMax2 (&val, rp->left);
    rp->val = val;
  }
#endif

  return (rp);
}

static node_t *
myAlloc (
  void
  )
{
  node_t *p;

  p = (node_t *)malloc(sizeof(node_t));
  if (p == NULL) {
    printf ("Allocation Error.\n");
    exit (1);
  }

  return (p);
}

#if FIND
static data_t
findDeleteMax1 (
  node_t **rpp
  )
{
  node_t *p;
  data_t d;

  /* Find The Rigth-Most Node (max value) */
  while ((*rpp)->right != NULL)
    rpp = &((*rpp)->right);

  p = *rpp;
  d = p->val;
  *rpp = (*rpp)->left;
  free (p);

  return (d);
}
#endif

#if !FIND
static node_t *
findDeleteMax2 (
  data_t *d,
  node_t *rp
  )
{
  node_t *tmp;

  if (rp->right == NULL) {
    *d = rp->val;
    tmp = rp->left;
    free (rp);
    return (tmp);
  }

  rp->right = findDeleteMax2 (d, rp->right);
  return (rp);
}
#endif
