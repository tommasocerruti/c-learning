#define MAX 10

#include <stdio.h>

void selectionSort (int A[], int N);

int main(void){
    int A[MAX], N, i;
    printf("Enter N:");
    scanf("%d",&N);
    for (i=0;i<N;i++)
        scanf("%d",&A[i]);
    selectionSort (A, N);
    for (i=0;i<N;i++)
        printf("%d ",A[i]);
}

void selectionSort (int A[], int N) {
    int i, j, imin, temp;
    for (i=0; i<N-1; i++) {
        /*find the index of the min in A[i]..A[N-1]*/
        imin = i;
        for (j = i+1; j < N; j++)
            if (A[j] < A[imin]) imin = j;
        /*swap min with A[i]*/
        temp = A[i];
        A[i] = A[imin];
        A[imin] = temp;
    }
}