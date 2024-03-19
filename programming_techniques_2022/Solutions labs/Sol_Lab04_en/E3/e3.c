#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define R 20
#define C 20
#define LEN 21

int matrixSumPrint(int mat[R][C], int nr, int nc, int D, int r0, int c0) {
	int r, c, sum = 0;
	for(r=r0; r<r0+D; r++) {
		for(c=c0; c<c0+D; c++) {
			/* print */
			printf("%d ", mat[r][c]);
			sum += mat[r][c];
		}
		printf("\n");
	}
	return sum;
}

void matDxD(int mat[R][C], int nr, int nc, int D) {
	int i, j, sum, maxsum, max_i0=-1, max_j0=-1;
	if (D <= 0 || D > nr || D > nc)
		return;
	printf("Matrices of dimension %dx%d\n", D, D);
	/* For all points [i,j] where a DxD square matrix can begin */
	for(i=0; i<=nr-D; i++) {
		for(j=0; j<=nc-D; j++) {
			sum = matrixSumPrint(mat,nr,nc,D,i,j);
			/* For all the cells of such sub-matrix */
			if (((max_i0 == -1)&&(max_j0 == -1)) || maxsum < sum) {
				maxsum = sum;
				max_i0 = i;
				max_j0 = j;
			}
		}
	}

	printf("Matrix of dimension %dx%d with maximum sum\n", D, D);
	sum = matrixSumPrint(mat,nr,nc,D,max_i0,max_j0);

}

int main(int argc, char **argv) {

	FILE *in = NULL;
	int i, j, nr, nc, dim, mat[R][C];
	char filename[LEN];

	printf("Insert filename: ");
	scanf("%s", filename);
	in = fopen(filename, "r");
	if (in == NULL)
		return 0;

	fscanf(in, "%d %d", &nr, &nc);
	for(i=0;i<nr;i++) {
		for(j=0;j<nc;j++) {
			fscanf(in, "%d", &mat[i][j]);
		}
	}

	do {
		printf("Dimension: ");
		if (scanf("%d", &dim) !=1)
			return 1;
		matDxD(mat, nr, nc, dim);

	} while (dim > 0 && dim <= nr && dim <= nc);

	return 0;
}
