#include "treePrivate.h"

#define FIND 0

static node_t *myAlloc (void);
static node_t *findDeleteMax(data_t *, node_t *);

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
searchR (
  node_t *rp,
  data_t data
  )
{
  if (rp==NULL || compare(rp->val, data)==0)
    return (rp);

  if (compare(data, rp->val) < 0)
    return (searchR (rp->left, data));
  else
    return (searchR (rp->right, data));
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
  {
    data_t val;

    rp->left = findDeleteMax(&val, rp->left);
    rp->val = val;
  }

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


static node_t *
findDeleteMax(
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

  rp->right = findDeleteMax(d, rp->right);
  return (rp);
}


// exercise 1a
void countNode (node_t *root, int *array){
    if (root==NULL)
        return;
    int c=0;
    if (root->left!=NULL){
        countNode(root->left,array);
        c++;
    }
    if (root->right!=NULL){
        countNode(root->right,array);
        c++;
    }
    array[c]++;
}

// exercise 1b
void depthtree (node_t *root, int level, int *depth){
    if (root==NULL)
        return;
    if (root->left!=NULL)
        depthtree(root->left,level+1, depth);
    if (root->right!=NULL)
        depthtree(root->right,level+1, depth);
    if (level>(*depth))
        (*depth)=level;
}
void countLevel (node_t * root, int *array, int l){
    if (root==NULL)
        return;
    if (root->left!=NULL)
        countLevel(root->left,array,l+1);
    if (root->right!=NULL)
        countLevel(root->right,array, l+1);
    array[l]++;
}

//exercise 1c
void countPath (node_t * root, int *np, int *length){
    if (root==NULL)
        return;
    if (root->left!=NULL){
        (*length)++;
        countPath(root->left,np,length);
    }
    if (root->right!=NULL){
        (*length)++;
        countPath(root->right,np,length);
    }
    if ((root->left)==NULL && (root->right)==NULL){
        (*np)++;
    }
}

//exercise 1d
int visit (node_t *root, int key1, int key2){
    node_t *start;
    start=double_searchR(root,key1,key2);
    return search_countR(start,key1,0)+search_countR(start,key2,0);
}
node_t * double_searchR (node_t *rp, data_t data1, data_t data2){
    if ((compare(rp->val, data1)==0)||(compare(rp->val, data2)==0))
        return rp;
    if ((compare(data1, rp->val) < 0)&&(compare(data2, rp->val) < 0))
        return (double_searchR (rp->left, data1, data2));
    if ((compare(data1, rp->val) > 0)&&(compare(data2, rp->val) > 0))
        return (double_searchR (rp->right, data1, data2));
    else
        return rp;
}
int search_countR (node_t *rp, data_t data, int level){
    if (compare(rp->val,data)==0)
        return level;
    if (compare(rp->val,data)<0)
        return search_countR(rp->left,data,level+1);
    else
        return search_countR(rp->right,data,level+1);
}