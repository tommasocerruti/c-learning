#include <stdio.h>

int main() {
    int n,i,x_i1,x_i2,x_i;
    printf("Insert the number N (N>=2):");
    scanf("%d",&n);

    x_i2=0;
    x_i1=1;
    printf("%d %d",x_i2,x_i1);
    for (i=1;i<=n;i++){
        x_i=x_i1+x_i2;
        printf(" %d",x_i);
        x_i2=x_i1;
        x_i1=x_i;
    }
    return 0;
}
