#include <stdio.h>
#define FILENAME "../sort.txt"
#define MAXLEN 100

void SelectionSort(int A[], int N);
void InsertionSort(int A[], int N);
void ShellSort(int A[], int N);


int main() {
    int S, i1, i2, A1[MAXLEN], A2[MAXLEN], A3[MAXLEN], N;
    FILE *fp;
    if ((fp=fopen(FILENAME,"r"))==NULL)
        return 1;
    fscanf(fp,"%d",&S);
    printf("TypeSort: #swaps #iterations_outerloop #iterations_innerloop #iterations_total\n\n");
    for (i1=0;i1<S;i1++){
        fscanf(fp,"%d",&N);
        printf("Sequence #%d: ",i1+1);
        for (i2=0;i2<N;i2++){
            fscanf(fp,"%d",&A1[i2]);
            A2[i2]=A1[i2];
            A3[i2]=A1[i2];
            printf("%d ",A1[i2]);
        }
        printf("\n");
        SelectionSort(A1,N);
        InsertionSort(A2,N);
        ShellSort(A3,N);
    }
    return 0;
}


void SelectionSort(int A[], int N){
    int swaps=0;
    int i, j, l=0, r=N-1, min;
    int temp;
    for (i = l; i < r; i++) {
        min = i;
        for (j = i+1; j <= r; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            swaps+=1;
        }
    }
    printf("SelectionSort: %d %d %d %d\n",swaps,i,j,i*j);
}
void InsertionSort(int A[], int N){
    int swaps=0;
    int i, j, l=0, r=N-1, x;
    for (i = l+1; i <= r; i++) {
        x = A[i];
        j = i - 1;
        while (j >= l && x < A[j]){
            A[j+1] = A[j];
            j--;
            swaps+=1;
        }
        A[j+1] = x;
    }
    printf("SelectionSort: %d %d %d %d\n",swaps,i,i-1,i*(i-1));
}
void ShellSort(int A[], int N){
    int swaps=0;
    int i, j, x, l=0, r=N-1, h=1;
    while (h < N/3)
        h = 3*h+1;
    while(h >= 1) {
        for (i = l + h; i <= r; i++) {
            j = i;
            x = A[i];
            while(j >= l + h && x < A[j-h]) {
                A[j] = A[j-h];
                swaps+=1;
                j -=h;
            }
            A[j] = x;
        }
        h = h/3;
    }
    printf("SelectionSort: %d %d %d %d\n\n",swaps,i,i-l-h,i*(i-l-h));
}