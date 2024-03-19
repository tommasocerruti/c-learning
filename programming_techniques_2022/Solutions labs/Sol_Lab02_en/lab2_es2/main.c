#include <stdio.h>

int main() {
    unsigned int x0=0, x1=1;
    int N, i;
    unsigned int x2;
    printf("Insert number:");
    scanf("%d", &N);

    printf("Fibonacci: %d %d ", x0, x1);
    for(i=0;i<N-2;i++){
        x2 = x0 + x1;
        x0 = x1;
        x1 = x2;
        printf("%d ", x2);
    }
    x0 = 1;
    x1 = 2;
    printf("\nSeries: %d %d ", x0, x1);
// unsigned int 4.294.967.295
// signed int 2.147.483.647
    for(i=0;i<N-2;i++){
        x2 = x0 * x1;
        x0 = x1;
        x1 = x2;
        printf("%d ", x2);
    }

    return 0;
}
