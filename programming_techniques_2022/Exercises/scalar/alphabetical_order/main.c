#include <stdio.h>
#include <string.h>
#define MAX_LINE 50
int main() { //verify order
    FILE * fp;
    fp=fopen("../names.txt","r");
    char line0[MAX_LINE], line1[MAX_LINE];
    int order=0;
    fgets(line0,MAX_LINE,fp); //first line
    while (fgets(line1,MAX_LINE,fp)!=NULL){
        if (strcmp(line1,line0)<0) // line 1 proceeding line 0
            order=1;
        strcpy(line0,line1); // copies line 1 in line 0
    }
    return order;
}