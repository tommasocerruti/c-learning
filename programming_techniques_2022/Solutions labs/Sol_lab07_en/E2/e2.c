#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define filein "./sort1.txt"
#define maxN 100

void selectionSort(int A[], int N)
{
    int i, j, l = 0, r = N - 1, min, tmp;
    int cnti = 0, cntj = 0, cntswap = 0, cntt = 0;

    for (i = l; i < r; i++)
    {
        cnti++;
        printf("Outer loop id = %d ", cnti);
        min = i;
        for (j = i + 1, cntj = 0; j <= r; j++)
        {
            cntj++;
            if (A[j] < A[min])
                min = j;
        }
        printf("Inner loop count = %d\n", cntj);
        if (min != i)
        {
            tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
            cntswap++;
        }
        cntt += cntj;
    }
    printf("Total loop count = %d, Outer loop count: %d, Assignments = %d\n", cntt + cnti, cnti, cntswap);
}

void insertionSort(int A[], int N)
{
    int i, j, l = 0, r = N - 1, x;
    int cnti = 0, cntj = 0, cntt = 0, cntswap = 0;

    for (i = l + 1; i <= r; i++)
    {
        cnti++;
        printf("Outer loop id = %d ", cnti);
        x = A[i];
        j = i - 1;
        cntj = 0;
        while (j >= l && x < A[j])
        {
            cntj++;
            A[j + 1] = A[j];
            cntswap++;
            j--;
        }
        printf("Inner loop count = %d\n", cntj);
        A[j + 1] = x;
        cntt += cntj;
    }
    printf("Total loop count = %d, Outer loop count: %d, Assignments = %d\n", cntt + cnti, cnti, cntswap);
}

void shellSort(int A[], int N)
{
    int i, j, h = 1, l = 0, r = N - 1, tmp;
    int cnth = 0, cnti = 0, cntj = 0, cntt = 0, cnto = 0, cntswap = 0;

    while (h < N / 3)
        h = 3 * h + 1;

    while (h >= 1)
    {
        cnth++;
        printf("Outer h loop id = %d \n", cnth);

        for (i = l + h; i <= r; i++)
        {
            cnti++;
            printf("    Outer loop id = %d ", cnti);
            tmp = A[i];
            j = i;
            cntj = 0;
            while (j >= l + h && tmp < A[j - h])
            {
                A[j] = A[j - h];
                j -= h;
                cntj++;
                cntswap++;
            }
            printf("Inner loop count = %d\n", cntj);
            A[j] = tmp;
            cntt += cntj;
        }
        h = h / 3;
        cntt += cnti;
        cnto += cnti;
        cnti = 0;
    }
    printf("Total loop count = %d, Outer loops count: %d, Assignments = %d\n", cntt + cnth, cnto + cnth, cntswap);
}

void printArray(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int A[maxN] = {0}, i, j, s, N;

    /* InsertionSort */
    FILE *fp = fopen(filein, "r");
    fscanf(fp, "%d", &s);
    printf("InsertionSort\n");
    for (i = 0; i < s; i++)
    {
        fscanf(fp, "%d", &N);
        for (j = 0; j < N; j++)
            fscanf(fp, "%d", &A[j]);
        insertionSort(A, N);
    }
    fclose(fp);
    printf("\n");

    /* SelectionSort */
    fp = fopen(filein, "r");
    fscanf(fp, "%d", &s);
    printf("SelectionSort\n");
    for (i = 0; i < s; i++)
    {
        fscanf(fp, "%d", &N);
        for (j = 0; j < N; j++)
            fscanf(fp, "%d", &A[j]);
        selectionSort(A, N);
    }
    fclose(fp);
    printf("\n");

    /* ShellSort */
    fp = fopen(filein, "r");
    fscanf(fp, "%d", &s);
    printf("ShellSort\n");
    for (i = 0; i < s; i++)
    {
        fscanf(fp, "%d", &N);
        for (j = 0; j < N; j++)
            fscanf(fp, "%d", &A[j]);
        shellSort(A, N);
    }
    fclose(fp);
    printf("\n");

    return 0;
}
