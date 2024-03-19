/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void matrix_max(int **mat, int r, int c);

#define R 3
#define C 4

int main()
{
    int **mat;
    int i, j;
    mat=malloc(R*sizeof(int *));
    for (i=0;i<R;i++){
        mat[i]=malloc(C*sizeof(int));
        for (j=0;j<C;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    matrix_max(mat,3,4);
    return 0;
}

#define N 8
void matrix_max(int **mat, int r, int c){
    int di[N]={-1,-1,-1,0,0,1,1,1};
    int dj[N]={-1,0,1,-1,1,-1,0,1};
    int i, j, n, flag;
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            flag=0;
            for (n=0;n<N && !flag;n++){
                if ((i+di[n])>=0&&(i+di[n])<N&&(j+dj[n])>=0&&(j+dj[n])<N){
                    if (mat[i+di[n]][j+dj[n]]>=mat[i][j])
                        flag=1;
                }
            }
            if (!flag)
                fprintf(stdout,"%d %d\n",i,j);
        }
    }
    return;
}