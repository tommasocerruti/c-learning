#include "treePublic.h"

#define OK   1
#define KO   0
#define N  100

int main (int argc, char *argv[]) {
  node_t *root;
  int i;
  FILE *fpR, *fpW;
  ST st;

  for (i=0; i<argc; i++)
     printf ("%s ", argv[i]);
  printf ("\n");

  fpR = fopen (argv[1], "r");
  fpW = fopen (argv[2], "w");
  if (fpR==NULL || fpW==NULL) {
    fprintf (stderr, "Error openeing file.\n");
    exit (KO);
  }

  fprintf (stdout, "Reading BST ...\n");
  root = NULL;
  root = createEmptyTree();
  root = readTree (fpR);
  fprintf (stdout, "Writing BST:\n");
  writeTree (stdout, root, INORDER);

  st = STinit (N);
  bst2hash (root, st);
  STdisplay(st, fpW);

  freeTree(root);
  fclose (fpW);
  fclose (fpR);

  return (OK);
}


