#include <string.h>
#include <stdio.h>

const int STRLEN=21;
const int LMAX=255;

void format(char nin[],char nout[],int lmax);

int main(void){
    char nin[STRLEN],nout[STRLEN];
    printf("INPUT");
    scanf("%s",nin);
    printf("OUTPUT");
    scanf("%s",nout);
    format(nin,nout,LMAX);
}

void format(char nin[],char nout[],int lmax){
    FILE *fin=fopen(nin,"r");
    FILE *fout=fopen(nout,"w");
    char word[STRLEN], line[LMAX];
    int i,l;
    l=0;
    while (fscanf(fin,"%s", word)==1) {
        if (l+1+strlen(word) <= lmax) {
            // if (l!=0)
                strcat(line," ");
            strcat(line,word);
            l+=1+strlen(word);
        }
        else {
            for (i=0; i<(lmax-l)/2; i++)
                fprintf(fout," ");
            fprintf(fout,"%s\n",line);
            strcpy(line,word);
            l=strlen(word);
        }
        for (i=0; i<(lmax-l)/2; i++)
            fprintf(fout," ");
        fprintf(fout,"%s\n",line);
        strcpy(line,word);
        l=strlen(word);
    }
}