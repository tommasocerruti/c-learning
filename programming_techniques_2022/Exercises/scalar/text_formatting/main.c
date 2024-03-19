#include <stdio.h>
#include <string.h>

void formatting(char nin[], char nout[], int lmax) {
    const int STRLEN=21;
    FILE *fin=fopen(nin,"r"); //input file (argument 1)
    FILE *fout=fopen(nin,"w"); //output file (argument 2)
    char word[STRLEN]; //reading word
    int l=0; //current length of line
    while (fscanf(fin, "%s", &word)==1){ //until EOF reading a word
        if (l+1+strlen(word)>lmax){ //cannot fit in the line
            fprintf(fout,"\n%s",word);
            l=strlen(word);
        }
        else{ //can fit in the line
            if (l!=0) {//avoiding a space for first word
                fprintf(fout," ");
                l+=1;
            }
            fprintf(fout,"%s",word);
            l+=strlen(word);
        }
    }
    fclose(fin);
    fclose(fout);
}
