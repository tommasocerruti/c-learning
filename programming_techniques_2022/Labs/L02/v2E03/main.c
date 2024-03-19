#include <stdio.h>
#include <string.h>
#define MAXL 100

int compressing(FILE *fin, FILE *fout);

int main() {
    FILE *fin, *fout;
    if ((fin=fopen("../source.txt","r"))==NULL)
        return 0;
    if ((fout=fopen("../output.txt","w"))==NULL)
        return 0;
    return compressing(fin, fout);
}

int compressing(FILE *fin, FILE *fout){
    int num=0,i;
    char line[MAXL];
    while (fgets(line, MAXL, fin)==1){
        i=0;
        while(i<strlen(line)){
            if (line[i]!=line[i+1])
                printf()
            i++;
        }
    }
}