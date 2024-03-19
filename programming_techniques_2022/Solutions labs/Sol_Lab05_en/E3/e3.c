#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 30
#define LEN 21

typedef struct {
	int r, c;
} matmaxN;

matmaxN readMatrix(char *file, int mat[][maxN]);
void rotateArray1(int V[maxN], int dir, int N, int P);
void rotateArray2(int V[maxN], int dir, int N, int P);
void rotateArray3(int V[maxN], int dir, int N, int P);
void rotateArray4(int V[maxN], int dir, int N, int P);
void rotateMatrix(int mat[][maxN], char r_o_c, int index, int maxN1, int maxN2, int P, char direction[maxN], int strategy);
void printMatrix(FILE *out, int mat[][maxN], int nr, int nc);

int main(int argc, char **argv) {
	matmaxN mmaxN;
	int mat[maxN][maxN], r, c, keep_on = 1, index = 0, locations = 1, strategy = 1;
	char cmd[256], selector[LEN], filename[LEN], direction[LEN], r_o_c;

	if (argc>1) {
		strategy = atoi(argv[1]);
		if (strategy<1 || strategy>4)
			strategy = 1;
	}

	printf("Insert filename: ");
	scanf("%s", filename);

	mmaxN = readMatrix(filename, mat);
	r = mmaxN.r;
	c = mmaxN.c;

	do {
		printMatrix(stdout, mat, r, c);
		printf("Command > ");
		fgets(cmd, 255, stdin);
		sscanf(cmd, "%s %d %s %d", selector, &index, direction, &locations);

		if (locations > 0) {
			if (strcmp(selector,"row")==0) {
				if (index <= 0 || index > r) {
					printf("Error selecting row\n");
					return 1;
				}
				r_o_c = 'r';
				rotateMatrix(mat, r_o_c, index, r, c, locations, direction, strategy);
			} else if (strcmp(selector,"column")==0) {
				if (index <= 0 || index > c) {
					printf("Error selecting column\n");
					return 1;
				}
				r_o_c = 'c';
				rotateMatrix(mat, r_o_c, index, r, c, locations, direction, strategy);
			} else if (strcmp(selector,"end")==0) {
				keep_on=0;
			} else {
				printf("row|column|end [index] [direction] [locations]\n");
			}
		}
	} while (keep_on);
	return 0;
}

void rotateMatrix(int mat[][maxN], char r_o_c, int index, int maxN1, int maxN2, int P, char direction[], int strategy) {
	int vet[maxN], i, dir = 0;
	if ((strcmp(direction, "right")== 0) || (strcmp(direction, "up")== 0))
		dir = -1;
	else if ((strcmp(direction, "left")== 0) || (strcmp(direction, "down")== 0))
		dir = 1;
	if ((dir !=1) && (dir !=-1)){
		printf("error direction\n");
		return;
	}
	if (r_o_c == 'r')
		switch (strategy) {
			//NOTE the index-1, since the user input is handled with ordering starting from 1
			case 1:
				rotateArray1(mat[index - 1], dir, maxN2, P);
				break;
			case 2:
				rotateArray2(mat[index - 1], dir, maxN2, P);
				break;
			case 3:
				rotateArray3(mat[index - 1], dir, maxN2, P);
				break;
			case 4:
				rotateArray4(mat[index - 1], dir, maxN2, P);
				break;
			default:
				printf("error: wrong strategy\n");
		}
	else if (r_o_c == 'c') {
		// in order to perform barrel shift on a column, we can copy the column to a temporary array, perform the rotation, and then put the array back in the matrix
		for (i=0; i<maxN1; i++)
			vet[i] = mat[i][index-1];//Copy elements of a column to an ancilla array. NOTE the index-1, since the user input is handled with ordering starting from 1

		switch (strategy) {
			case 1: rotateArray1(vet, -dir, maxN1, P);
				break;
			case 2: rotateArray2(vet, -dir, maxN1, P);
				break;
			case 3: rotateArray3(vet, -dir, maxN1, P);
				break;
			case 4: rotateArray4(vet, -dir, maxN1, P);
				break;
			default: printf("error: wrong strategy\n");
		}

		//copy back the array in the matrix
		for (i=0; i<maxN1; i++)
			mat[i][index-1] = vet[i];
	}
}

matmaxN readMatrix(char *file, int mat[][maxN]) {
	int i, j;
	matmaxN md;
	FILE *in = fopen(file, "r");
	if (in == NULL)
		exit(-1);
	fscanf(in, "%d %d", &md.r, &md.c);
	for(i=0; i<md.r; i++)
		for(j=0;j<md.c;j++)
			fscanf(in, "%d", &mat[i][j]);
	fclose(in);
	return md;
}

void printMatrix(FILE *out, int mat[][maxN], int nr, int nc) {
	int i, j;
	for (i=0; i<nr; i++) {
		for(j=0; j<nc; j++)
			fprintf(out, "%d ", mat[i][j]);
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	return;
}

void rotateArray1(int V[maxN], int dir, int N, int P) {
	int tmp, i, j;

	if (dir == 1) { /* direction  LEFT */
		for (i=0; i<P; i++) {
			tmp = V[0];
			for (j=0; j<N-1; j++)
				V[j] = V[(j+1)];
			V[N-1] = tmp;
		}
	} else {  /* direction RIGHT */
		for(i=0; i<P; i++) {
			tmp = V[N-1];
			for(j=N-1; j>0; j--)
				V[j] = V[j-1];
			V[0] = tmp;
		}
	}
}

void rotateArray2(int V[maxN], int dir, int N, int P) {
	int tmpArray[maxN], i;

	if (dir == 1) { /* direction  LEFT */
		/* save the P starting cells of V in tmpArray */
		for (i=0; i<P; i++) {
			tmpArray[i] = V[i];
		}
		/* move V starting from the locationsition P by P locationsitions to the left */
		for (i=0; i<N-P; i++) {
			V[i] = V[i+P];
		}
		/* copy the data stored in tmpArray in the remaining locationsitions of V */
		for (i=0; i<P; i++) {
			V[N-P+i] = tmpArray[i];
		}
	} else {  /* direction RIGHT */
		/* dual: save the last P cells of V in tmpArray */
		for (i=0; i<P; i++) {
			tmpArray[i] = V[N-P+i];
		}
		/* move V starting from the locationsition N-P-1 by P locationsitions to the right */
		for (i=N-1; i>=P; i--) {
			V[i] = V[i-P];
		}
		/* copy the data saved in tmpArray in the remaining locationsitions of V */
		for (i=0; i<P; i++) {
			V[i] = tmpArray[i];
		}
	}
}

void rotateArray3(int V[maxN], int dir, int N, int P) {
	int tmpArray[maxN], i, t0, t1, dest, src;

	if (dir == 1) { /* direction  LEFT */
		t0 = 0; t1 = N-P; /* the interval of V to be saved starts at t0 and will be saved starting from t1 */
		dest = 0; /* when we move, we start from here */
	}
	else {
		t0 = N-P; t1 = 0; /* the interval of V to be saved starts at t0 and will be saved starting from t1 */
		dest = N-1; /* when we move, we start from here */
	}
	/* save interval on temporary array */
	for (i=0; i<P; i++) {
		tmpArray[i] = V[t0+i];
	}
	/* let us move stuff */

	for (i=0; i<N-P; i++) {
		src = dest+P*dir;
		V[dest] = V[src];
		dest = dest + dir;
	}

	/* copy stuff starting from t1 the interval stored in the temporary array */
	for (i=0; i<P; i++) {
		V[t1+i] = tmpArray[i];
	}
}

void rotateArray4(int V[maxN], int dir, int N, int P) {
	int tmpArray[maxN], i;

	if (dir == -1) {
		/* change direction: P movements to the RIGHT are equivalent to N-P to the LEFT */
		P = N-P;
	}
	/* save the first P elements of V in the temporary array */
	for (i=0; i<P; i++) {
		tmpArray[i] = V[i];
	}
	/* move stuff by P locationsitions to the LEFT */
	for (i=0; i<N-P; i++) {
		V[i] = V[i+P];
	}
	/* copy stuff starting from N-P+i the interval stored in the temporary array */
	for (i=0; i<P; i++) {
		V[N-P+i] = tmpArray[i];
	}
}
