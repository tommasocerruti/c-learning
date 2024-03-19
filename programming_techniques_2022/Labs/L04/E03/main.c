#include <stdio.h>
#define max_n 20


int main() {
    char filename[max_n];
    int dim=1, nr, nc, i, j, min, upr, upc, sum, max, max_ind_i, max_ind_j;
    int m[max_n][max_n];
    FILE *fp;
    printf("Filename:");
    scanf("%s",filename);// ../matrix.txt
    if ((fp=fopen(filename,"r"))==NULL)
        return 1;
    fscanf(fp,"%d %d",&nr,&nc);
    for (i=0;i<nr;i++){
        for (j=0;j<nc;j++){
            fscanf(fp,"%d",&m[i][j]);
        }
    }
    printf("\nThe full matrix is\n");
    for (i=0;i<nr;i++){
        for (j=0;j<nc;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    if (nr>=nc)
        min=nc;
    if (nc>nr)
        min=nr;
    printf("Dimension:");
    scanf("%d",&dim);
    while(dim>=1 && dim<=min){
        printf("The square sub-matrices of dimension %d are:\n\n",dim);
        upr=0;upc=0;i=0;j=0;max=0;
        while (i+upr<=nr){
            while (i+upc<=nc){
                sum=0;
                for (i=0;i<dim;i++) {
                    for (j = 0; j<dim; j++){
                        printf("%d ", m[i+upr][j+upc]);
                        sum+=m[i+upr][j+upc];
                    }
                    printf("\n");
                }
                if (sum>max){
                    max_ind_i=i-dim+upr;
                    max_ind_j=j-dim+upc;
                    max=sum;
                }
                upc+=1;
                printf("\n");
            }
            upr+=1;
            upc=0;
        }
        printf("The submatrix with maximum sum of elements (%d) is\n\n",max);
        for (i=max_ind_i;i<dim+max_ind_i;i++) {
            for (j=max_ind_j;j<dim+max_ind_j;j++)
                printf("%d ", m[i][j]);
            printf("\n");
        }
        printf("\nDimension:");
        scanf("%d",&dim);
    }
    printf("\nDimension inconsistent with the size of the matrix\n");
    return 0;
}
