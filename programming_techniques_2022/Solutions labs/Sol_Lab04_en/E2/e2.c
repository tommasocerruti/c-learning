#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define maxN 30
#define maxS 100


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
		/* move V starting from the position P by P positions to the left */
		for (i=0; i<N-P; i++) {
			V[i] = V[i+P];
		}
		/* copy the data stored in tmpArray in the remaining positions of V */
		for (i=0; i<P; i++) {
			V[N-P+i] = tmpArray[i];
		}
	} else {  /* direction RIGHT */
		/* dual: save the last P cells of V in tmpArray */
		for (i=0; i<P; i++) {
			tmpArray[i] = V[N-P+i];
		}
		/* move V starting from the position N-P-1 by P positions to the right */
		for (i=N-1; i>=P; i--) {
			V[i] = V[i-P];
		}
		/* copy the data saved in tmpArray in the remaining positions of V */
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
	else { /* direction  RIGHT */
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
	/* move stuff by P positions to the LEFT */
	for (i=0; i<N-P; i++) {
		V[i] = V[i+P];
	}
	/* copy stuff starting from N-P+i the interval stored in the temporary array */
	for (i=0; i<P; i++) {
		V[N-P+i] = tmpArray[i];
	}
}

void printArray(int V[maxN], int N) {
	int i;
	for (i=0;i<N;i++)
		printf("%d ", V[i]);
	printf("\n");
}

int main(int argc, char *argv[]) {
	int N, i, P, dir, fine=0, arr[maxN] = {0,1,2,3,4,5,6,7,8,9};
	int selector = 1;

	if (argc>1) {
		selector = atoi(argv[1]);
		if (selector<1 || selector>4)
			selector = 1;
	}

	printf("Insert number of elements (interval 1..%d)\n", maxN);
	printf("(Outside of interval to accept pre-set values): ");
	scanf("%d", &N);
	printf("Insert array of numers: ");
	if (N > 0 && N <= maxN) {
		for(i=0; i<N; i++)
			scanf("%d", &arr[i]);
	}
	else {
		N = 10;
	}

	printArray(arr, N);

	do {
		printf("Command (P dir) (0 dir to terminate)> ");
		fine = scanf(" %d %d", &P, &dir) != 2;
		if (P<=0)
			fine = 1;
		P = P%N; /* if P>N, the number of rotations is still P%N */
		if (!fine && (dir == 1 || dir == -1)) {
			switch (selector) {
				case 1: rotateArray1(arr, dir, N, P);
					break;
				case 2: rotateArray2(arr, dir, N, P);
					break;
				case 3: rotateArray3(arr, dir, N, P);
					break;
				case 4: rotateArray4(arr, dir, N, P);
					break;
				default: printf("Error: invalid selector\n");
			}
			printArray(arr, N);
		}
	} while (!fine);

	return 0;
