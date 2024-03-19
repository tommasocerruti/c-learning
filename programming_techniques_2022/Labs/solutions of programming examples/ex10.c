#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define NNUM 14
#define NR 3
#define NC 5
#define MAXR 10
#define MAXC 10

int buildMatrix(int V[], int N, int M[MAXR][MAXC], int nr, int nc) {
    int i, j, k, x, y;
    k=0; // Counter of the decoded values
    for(i=0;i<N;i=i+2) {
        int val = V[i]; // Value
        int rip = V[i+1];  // Number of repetitions
        for(j=0;j<rip;j++) {  // Per each repetition
            x = k / nc;  // Row-index
            y = k % nc;  // Column-index
            M[x][y] = val;  // Insert value in the matrix
            k++;            // Increment counter
        }
    }
    return k==nr*nc;    // Counter should be equal to number of cells of the matrix
}

int main(void) {
    
    int i, j, M[MAXR][MAXC], V[NNUM] = {1, 2, 17, 2, 3, 1, 8, 4, 6, 1, 7, 3, 5, 2};
    
    if (buildMatrix(V, NNUM, M, NR, NC))
    {
        for (i = 0; i < NR; i++) {
            for (j = 0; j < NC; j++) {
                printf("%3d ", M[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
