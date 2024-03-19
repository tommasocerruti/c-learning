#include <stdio.h>

void swapInt(int *x, int *y);

int main() {
    int a, b;
    scanf("%d %d",&a,&b);
    swapInt(&a,&b);
    return 0;
}

void swapInt(int *x, int *y){
    int temp=*x; *x=*y; *y=temp;
}