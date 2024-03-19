#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int **read_sud(FILE *, int *);
int solve_sud(int **, int, int);
int check_sud(int **, int, int, int, int *);
void print_sol(int **, int);
void reset(int *, int);

int main(int argc, char *argv[]){
    int dim;
    int i, j;
    int **mat;
    FILE *fp;
    if (argc!=2){
        fprintf(stderr,"Wrong number of arguments");
        return EXIT_FAILURE;
    }
    if ((fp=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"File opening error");
        return EXIT_FAILURE;
    }
    mat=read_sud(fp,&dim);
    fclose(fp);
    if (solve_sud(mat,dim,0))
        print_sol(mat,dim);
    for (i=0;i<dim;i++)
        free(mat[i]);
    free(mat);
    return EXIT_SUCCESS;
}

int **read_sud(FILE *fp, int *dim){
    int i=0,j;
    char c=' ';
    int **sud;
    while (c!='\n'){
        fscanf(fp,"%c",&c);
        i++;
    }
    rewind(fp);
    (*dim)=i/2;
    sud=malloc((*dim)*sizeof(int *));
    for (i=0;i<(*dim);i++)
        sud[i]=malloc((*dim)*sizeof(int));
    for (i=0;i<(*dim);i++){
        for (j=0;j<(*dim);j++){
            fscanf(fp,"%d%*c",&sud[i][j]);
        }
    }
    return sud;
}

int solve_sud(int **sud, int dim, int lev){
    int i=(lev/dim), j=(lev%dim), k;
    int *vect=calloc(dim, sizeof(int));
    if (lev>=(dim*dim)){
        //solution found
        return 1;
    }
    if (sud[i][j]!=0)
        solve_sud(sud,dim,lev+1);
    for (k=1;k<=dim;k++){
        sud[i][j]=k;
        if (check_sud(sud,dim,i,j,vect)){
            if (solve_sud(sud,dim,lev+1))
                return 1;
        }
    }
    free(vect);
    return 0;
}

int check_sud(int **sud, int dim, int x, int y, int *vect){
    int i;
    // check rows
    for (i=0;i<dim;i++){
        if ((vect[sud[x][i]])!=0){
            return 0;
        }
        vect[sud[x][i]]++;
    }
    reset(vect,dim);
    // check columns
    for (i=0;i<dim;i++){
        if ((vect[sud[i][y]]++)!=0){
            return 0;
        }
    }
    reset(vect,dim);
    return 1;
}

// 1 4 5
// 1 5 7
// 1 4 5

// 7 -> i=1, j=2





void print_sol(int **sud, int dim){
    int i, j;
    for (i=0;i<dim;i++){
        for (j=0;j<dim;j++){
            fprintf(stdout,"%d ",sud[i][j]);
        }
        fprintf(stdout,"\n");
    }
}

void reset(int *vect, int dim){
    int i;
    for (i=0;i<dim;i++)
        vect[i]=0;
}