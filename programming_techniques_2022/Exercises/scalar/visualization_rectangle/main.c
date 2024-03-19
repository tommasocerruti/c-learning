#include <stdio.h>

void rectangle(int b, int h){
    int i,j;
    for (i=0; i<h; i++) { // iterating on rows (i.e. height)
        for (j=0; j<b; j++) { // iterating on columns (i.e. base)
            if (i!=0 && i!=h-1 && j!=0 && j!=b-1)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}