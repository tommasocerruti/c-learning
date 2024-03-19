#include "treePublic.h"

#define N 100

int main(int argc, char *argv[]){
    FILE *fpr,*fpw;
    if ((fpr=fopen(argv[1],"r"))==NULL)
        return 1;
    if ((fpw=fopen(argv[2],"w"))==NULL)
        return 2;
    node_t *root;
    ST st;
    root=createEmptyTree();
    root=readTree(fpr);
    st=STinit(N);
    STdisplay(st,fpw);
    freeTree(root);
    fclose(fpr);
    fclose(fpw);
    return 0;
}