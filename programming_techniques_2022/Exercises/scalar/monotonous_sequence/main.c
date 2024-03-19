#include <stdio.h>
#define N 5

int main(void) {// N = #values
    int monotone=0,i,x,X;
    printf("x0:");
    scanf("%d",&x);
    for (i=1;i<N;i++){
        printf("x%d:",i);
        scanf("%d",&X);
        if (x>X)
            monotone=1;
        x=X;
    }
    return monotone;
}