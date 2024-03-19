#include <stdio.h>
#define MAXL 30

int subSequences(int v[], int n);
int AllSubSequences(int v[], int n, int ind[]);

int main() {
    int i=0, v[MAXL];
    printf("Input the elements (type end to finish the input)\n");
    while (scanf("%d",&v[i])==1 && i<=MAXL)
        i++;
    subSequences(v, i);
    return 0;
}

int subSequences(int v[], int n){
    int ind[MAXL], i=0, j, z, length, max_length=0;
    j = AllSubSequences(v, n, ind);
    // we need to identify all the longest
    while (i<j){
        length=ind[i+1]-ind[i];
        if (length>max_length)
            max_length=length;
        i+=2;
    }
    i=0;
    while (i<j){
        length=ind[i+1]-ind[i];
        if (length==max_length){
            printf("[");
            for (z=ind[i];z<=ind[i+1];z++){
                if (z<ind[i+1])
                    printf("%d ",v[z]);
                else
                    printf("%d",v[z]);
            }
            printf("] ");
        }
        i+=2;
    }
}

int AllSubSequences(int v[], int n, int ind[]){
    int i, j=0, first=0, dec=0, inc=0;
    for (i=0;i<n;i++){
        if (v[i]==0 && first){ // 1
            if (i-j>0){ // more than one element
                ind[j]=i-1; j++;
            }
            else // it was not a valid sequence
                j--;
            first=0; inc=0; dec=0;
        }
        if (v[i]!=0 && first && !dec && !inc){ // 2
            if (v[i]<v[i-1])
                dec=1;
            else if (v[i]>v[i-1])
                inc=1;
            // equal --> check the next
        }
        if (v[i]!=0 && first && (dec || inc)){ // 3
            if (dec){
                if (v[i]>v[i-1]){ // a1
                    ind[j]=i-1;
                    j++;
                    ind[j]=i-1;
                    j++;
                    dec=0;
                }
            }
            if (inc){
                if (v[i]<v[i-1]){ // a2
                    ind[j]=i-1;
                    j++;
                    ind[j]=i-1;
                    j++;
                    inc=0;
                }
            }
        }
        if (v[i]!=0 && !first){
            ind[j]=i;
            first=1; j++;
        }
    }
    if (first){ //condition was still valid
        ind[j]=i-1;
    }
    return j;
}