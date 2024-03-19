#include <stdio.h>
#define MAX 30

void subSequences(int v[], int n);

int main() {
    printf("Hello, World!\n");
    return 0;
}

void subSequences(int v[], int n){
    int i, j=0, subs[MAX], first=1;
    while(i<n){
        if (first){
            subs[j]=v[i];
            j++;
        }
        while (i<n && subs[j-1]<)
    }
}