#include <stdio.h>

void count_per_tens(int data[], int n) {
    int count[11], i, d;
    for (i=0;i<=10;i++)
        count[i]=0;
    for (i=0;i<n;i++){
        d=data[i]/10;
        count[d]+=1;
    }
    for (i=0;i<=10;i++){
        printf("GROUP %d: %d numbers",i+1,count[i]);
    }
}
