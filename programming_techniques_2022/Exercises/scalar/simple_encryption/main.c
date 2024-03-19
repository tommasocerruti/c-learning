#include <stdio.h>
#define MAXR 30

int main() {
    FILE *fin, *fout;
    char c, filename[MAXR+1];
    printf("INPUT FILE:");
    scanf("%s",&filename);
    if ((fin=fopen(filename,"r"))==NULL){
        printf("ERROR OPENING INPUT");
        return 1;
    }
    fin=fopen(filename,"r");
    printf("OUTPUT FILE:");
    scanf("%s",&filename);
    if ((fout=(filename,'w'))==NULL){
        printf("ERROR OPENING OUTPUT");
        return 2;
    }
    fout=fopen(filename,"w");
    while (!feof(fin)){
        fscanf(fin,"%c",&c);
        if (c>='0'&&c<='9')
            c='9'-c;
        else if (c>='A'&&c<='Z')
            c=('a'-'A')+('z'-c);
        else if (c>='a'&&c<='z')
            c=('A'-'a')+('Z'-c);
        fprintf(fout,"%c",c);
    }
    fclose(fin);fclose(fout);
    return 0;
}

