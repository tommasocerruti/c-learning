#include "treePublic.h"

#define OK 1
#define KO 0

int main (void){
  node_t *root, *tmp;
  data_t d;
  int retValue, end = 0;
  int *arr, i, depth=0, np=0, length=0, key1, key2;
  char row[MAXC];
  FILE *fp = NULL;

  root = NULL;
  root = createEmptyTree();

  while (!end) {

    fprintf (stdout, "User selection\n");
    fprintf (stdout, "\t1) Insert one single node\n\t2) Cancel one single node\n\t3) Search a node\n");
    fprintf (stdout, "\t4) Print BST on stdout\n\t5) Write BST on file\n\t6) Read BST from file\n");
    fprintf (stdout, "\t7) Compute min and max\n\t8) End\n");
    fprintf (stdout, "\t9) EX1A \n\t10) EX1B \n\t11) EX1C \n\t12) EX1D\n\t>");
    scanf ("%2s", row);

    switch (atoi(row)) {

      case 1:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input erro.\n");
          exit (0);
        }
	root = insert (root, d);
	break;

      case 2:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input erro.\n");
          exit (0);
        }
	root = delete (root, d);
	break;

      case 3:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input error.\n");
          exit (0);
        }

	tmp = searchI (root, d);
	if (tmp != NULL) {
	  fprintf (stdout, "Iterative Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Iterative Search: Not Found\n");
        }
	tmp = searchR (root, d);
	if (tmp  != NULL) {
	  fprintf (stdout, "Recursive Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Recursive Search: Not Found\n");
        }
	break;

      case 4:
	writeTree (stdout, root, INORDER);
	break;

      case 5:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

        if (strcmp (row, "stdout") == 0) {
          fp = stdout;
        } else {
   	  fp = fopen (row, "w");
        }

        if (fp == NULL) {
         fprintf (stderr, "Error Opening File %s\n", row);
         break;
	}

	writeTree (fp, root, PREORDER);

        if (strcmp (row, "stdout") != 0) {
	  fclose(fp);
	}
	break;

      case 6:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

	fp = fopen (row, "r");
	if (fp == NULL) {
	  fprintf (stderr, "Error Opening File %s\n", row);
	} else {
	  freeTree (root);
	  root = readTree (fp);
	}
	break;

      case 7:
        fprintf (stdout, "Tree minimum iterative: "); 
        tmp = treeMinI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree minimum recursive: "); 
        tmp = treeMinR (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum iterative: ");
        tmp = treeMaxI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum recursive: "); 
        tmp = treeMaxR (root);
        writeData (stdout, getData(tmp));
	break;

      case 8:
	end = 1;
	break;

      case 9:
          arr=calloc(3,sizeof(int));
          if (arr==NULL){
              fprintf(stderr,"Memory allocation error");
              end=1;
              break;
          }
          countNode(root,arr);
          fprintf(stdout,"Nodes with no child: %d\n",arr[0]);
          fprintf(stdout,"Nodes with one child: %d\n",arr[1]);
          fprintf(stdout,"Nodes with two children: %d\n",arr[2]);
          free(arr);
    break;

      case 10:
          depthtree(root,0,&depth);
          fprintf(stdout,"The height of the tree is %d\n",depth);
          arr=calloc(depth,sizeof(int));
          if (arr==NULL){
              fprintf(stderr,"Memory allocation error");
              end=1;
              break;
          }
          countLevel(root,arr,0);
          for (i=0;i<=depth;i++)
              fprintf(stdout,"At depth %d there are %d nodes\n",i,arr[i]);
          free(arr);

    break;

      case 11:
          countPath(root,&np,&length);
          fprintf(stdout,"The number of leaves are %d passing by %d edges\n",np,length);
    break;

        case 12:
            fprintf(stdout,"Input the two keys to find",np,length);
            fprintf(stdout,"\nkey 1:");
            fscanf(stdin,"%d",&key1);
            tmp = searchR (root, key1);
            if (tmp==NULL){
                fprintf (stdout, "Key 1 value not found in the tree\n");
                break;
            }
            fprintf(stdout,"\nkey 2:");
            fscanf(stdin,"%d",&key2);
            tmp = searchR (root, key2);
            if (tmp==NULL){
                fprintf (stdout, "Key 2 value not found in the tree\n");
                break;
            }
            if (key1==key2){
                fprintf (stdout, "It's the same node!\n");
                break;
            }
            fprintf(stdout,"\nThe distance between the two nodes is %d\n",visit(root,key1,key2));
    break;

        default:
	fprintf (stderr, "Unknown Option.\n");
	break;
    }
  }

  freeTree(root);

  return (OK);
}