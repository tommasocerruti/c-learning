#include <stdio.h>
#include <stdlib.h>

int power(int *arr, int n);
int comb(int *arr, int *sol, int k, int n, int start, int pos, int count);

int main(void){
    int n, *arr, i, count;
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    if (arr==NULL)
        return 1;
    for (i=0;i<n;i++)
        scanf("%d",&arr[i]);
    count=power(arr,n);
    free(arr);
    return count;
}

int power(int *arr, int n){
    int i,count=0, *sol, *mark;
    sol=malloc(n*sizeof(int));
    if (sol==NULL)
        return 1;
    for (i=0;i<=n;i++)
        count+=comb(arr,sol,i,n,0,0,0);
    free(sol);
    return count;
}

int comb(int *arr, int *sol, int k, int n, int start, int pos, int count){
    int i;
    if (pos>=k){
        printf("Partition %d {",count);
        for (i=0;i<k;i++)
            printf("%d",sol[i]);
        printf(", ",count);
        printf("\n");
        return count+1;
    }
    for (i=start;i<n;i++){
        sol[pos]=arr[i];
        count=comb(arr,sol,k,n,i+1,pos+1,count);
    }
    return count;
}


//unordered, k=1ton, no rep
//simple combinations with k from 1 to n

//using powerset, and setting to 1 so