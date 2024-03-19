//PROPOSED SOLUTION EX1

#include <stdio.h>
#include <string.h>
#define MAXNAME 30
#define MAXTEAMS 18
struct team{
    char name[MAXNAME];
    int pts, diff;
};

int main() {
    struct team teams[MAXTEAMS];
    int n=0,w,d,l,gd,gr;
    int i,j,left=0,right,temp;
    char name[MAXNAME];
    FILE *fpr,*fpw;
    if ((fpr=fopen("../results.txt","r"))==NULL)
        return 1;
    if ((fpw=fopen("../rank.txt","w"))==NULL)
        return 2;
    while (!feof(fpr)){
        fscanf(fpr,"%s %d %d %d %d %d",teams[n].name,&w,&d,&l,&gd,&gr);
        teams[n].pts=w*3+d*1;
        teams[n].diff=gd-gr;
        n++;
    }
    right=n-1;
    for (i=left;i<right;i++){
        for (j=left;j<right-i+left;j++)
            if ((teams[j].pts>teams[j+1].pts)||(teams[j].pts==teams[j+1].pts && teams[j].diff>teams[j+1].diff)){
                temp=teams[j].pts; teams[j].pts=teams[j+1].pts; teams[j+1].pts=temp;
                temp=teams[j].diff; teams[j].diff=teams[j+1].diff; teams[j+1].diff=temp;
                strcpy(name,teams[j].name); strcpy(teams[j].name,teams[j+1].name); strcpy(teams[j+1].name,name);
            }
    }
    for (i=n-1;i>=0;i--)
        fprintf(fpw,"%s %dpts\n",teams[i].name,teams[i].pts);
    fclose(fpr);
    fclose(fpw);
    return 0;
}