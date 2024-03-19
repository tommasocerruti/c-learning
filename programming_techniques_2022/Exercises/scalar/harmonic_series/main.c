#include <stdio.h>

int main() {
    int n,i;
    float sum;
    printf("Any value less or equal than zero will terminate the program\n");
    printf("Enter the value of n:");
    scanf("%d",&n);
    while (n>0) {
        sum = 0.0;
        printf("The n-th harmonic series of order %d is\n",n);
        for (i=1;i<=n;i++){
            sum += 1.0/i;
            printf("%f\n",sum);
        };
        printf("Enter the value of n:");
        scanf("%d",&n);
    }
    return 0;
}
