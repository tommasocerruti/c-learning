#include <stdio.h>
#define n 20
#define m 20

int main() {
    int table[n][m], ranking[n], row, col, i, j, leader=0;
    FILE *fp;
    char filename[n];
    printf("FILENAME:");
    scanf("%s",&filename);
    fp=fopen(filename,"r");
    if (fp==NULL)
        return 2;
    fscanf(fp,"%d%d",&row,&col);
    for (i=0;i<row;i++){
        for (j=0;j<col;j++)
            fscanf(fp,"%d",&table[i][j]);
    }
    for (i=0;i<row;i++){
        ranking[i]=0;
    }
    for (j=0;j<col;j++){
        for (i=0;i<row;i++)
            ranking[i]+=table[i][j];
        for (i=0;i<row;i++){
            if (ranking[i]>ranking[leader])
                leader=i;
        }
        printf("DAY %d - LEADER TEAM %d\n", j+1, leader+1);
    }
    return 0;
}