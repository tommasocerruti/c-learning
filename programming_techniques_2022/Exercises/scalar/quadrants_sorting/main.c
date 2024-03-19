#include <stdio.h>
#define SIZE 10

void sortPoints(char nin[], char nout[]);
void selectPoints(FILE *fi, FILE *fo, int sx, int sy);

int main() {
    char nin[SIZE], nout[SIZE];
    printf("File input: "); scanf("%s",nin);
    printf("File output: "); scanf("%s",nout);
    sortPoints(nin,nout);
    return 0;
}

void sortPoints (char nin[], char nout[]) {
    //idea: checking four times the file
    FILE *fin, *fout;
    fout = fopen(nout, "w");
    fin = fopen(nin, "r");
    selectPoints(fin,fout,1,1);
    fclose(fin); fin = fopen(nin, "r");
    selectPoints(fin,fout,-1,1);
    fclose(fin); fin = fopen(nin, "r");
    selectPoints(fin,fout,-1,-1);
    fclose(fin); fin = fopen(nin, "r");
    selectPoints(fin,fout,1,-1);
    fclose(fin);
    fclose(fout);
}

void selectPoints (FILE *fi, FILE *fo, int sx, int sy) {
    float x,y;
    int xOK, yOK;
    while (fscanf(fi, "%f%f",&x,&y)==2) {
        xOK = x*sx>0.0 || (x==0.0 && sx>0);
        yOK = y*sy>0.0 || (y==0.0 && sy>0);
        if (xOK && yOK)
            fprintf(fo, "%f %f\n",x,y);
    }
}