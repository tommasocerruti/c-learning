#include <stdio.h>
#include <string.h>
#define maxR 30
#define maxC 30
#define maxL 21


void rotate(int m[maxR][maxC], int r, int c, int ind, int loc, char sel[], char dir[]);

int main() {
    int m[maxR][maxC], r, c, ind, loc, i, j;
    FILE *fp;
    char filename[maxL], sel[8], dir[8];
    //0. open the file
    scanf("%s",filename);
    fp=fopen(filename,"r");
    if (fp==NULL){
        printf("File not found");
        return 1;
    }
    //1. acquire n
    fscanf(fp,"%d%d",&r,&c);
    //2. acquire m and print i
    for (i=0;i<r;i++){
        for (j=0;j<r;j++)
            fscanf(fp,"%d",&m[i][j]);
    }
    for (i=0;i<r;i++){
        for (j=0;j<r;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
    printf("\n");
    //3. acquire repeatedly p
    printf("INPUT <selector> <index> <direction> <locations>\n");
    scanf("%s",sel);
    if (strcmp(sel,"end")!=0)
        scanf("%d%s%d",&ind,dir,&loc);
    while(strcmp(sel,"end")!=0){
        if (strcmp(sel,"row")==0&&(loc>=r))
            loc=loc%r;
        else if (strcmp(sel,"column")==0&&(loc>=c))
            loc=loc%c;
        while (ind<0 || (strcmp(sel,"column")==0&&(ind>c)) || (strcmp(sel,"row")==0&&(ind>r))){
            printf("Enter valid index");
            scanf("%d",&ind);
        }
        ind-=1;
        rotate(m, r, c, ind, loc, sel, dir);
        for (i=0;i<r;i++){
            for (j=0;j<r;j++)
                printf("%d ",m[i][j]);
            printf("\n");
            }
            printf("\n");
        scanf("%s",sel);
        if (strcmp(sel,"end")!=0)
            scanf("%d%s%d",&ind,dir,&loc);
    }
    return 0;
}

void rotate(int m[maxR][maxC], int r, int c, int ind, int loc, char sel[], char dir[]){
    int i,j,z=0,prev_m[maxR][maxC],dir_int;
    // copy the matrix
    for (i=0;i<r;i++){
        for (j=0;j<c;j++)
            prev_m[i][j]=m[i][j];
    }
    if (strcmp(sel,"row")==0){
        if (strcmp(dir,"right")==0)
            dir_int=-1;
        else if (strcmp(dir,"left")==0)
            dir_int=1;
        if (dir_int==-1){
            for (i=r-loc;i<r;i++){
                m[ind][z]=prev_m[ind][i];
                z++;
            }
            for (i=0;i<r-loc;i++){
                m[ind][z]=prev_m[ind][i];
                z++;
            }
        }
        else if (dir_int==1){
            for (i=loc;i<r;i++){
                m[ind][z]=prev_m[ind][i];
                z++;
            }
            for (i=0;i<r;i++){
                m[ind][z]=prev_m[ind][i];
                z++;
            }
        }
    }
    else if (strcmp(sel,"column")==0){
        if (strcmp(dir,"down")==0)
            dir_int=-1;
        else if (strcmp(dir,"up")==0)
            dir_int=1;
        if (dir_int==-1){
            for (i=c-loc;i<c;i++){
                m[z][ind]=prev_m[i][ind];
                z++;
            }
            for (i=0;i<c-loc;i++){
                m[z][ind]=prev_m[i][ind];
                z++;
            }
        }
        else if (dir_int==1){
            for (i=loc;i<c;i++){
                m[z][ind]=prev_m[i][ind];
                z++;
            }
            for (i=0;i<c;i++){
                m[z][ind]=prev_m[i][ind];
                z++;
            }
        }
    }
    else
        printf("Wrong command\n");
}