#include <stdio.h>
void binary(int dec);
int main(void) {
    int n;
    printf("DECIMAL-BINARY converter\nInput decimal number:");
    scanf("%d",&n);
    printf("Binary conversion: ");
    binary(n);
    return 0;
}

void binary(int dec) {
    int i;
    for (i=1;(dec>=2*i);i*=2);
    while (i>0) {
        if (dec>i) {
            printf("1");
            dec-=i;
        }
        else
            printf("0");
        i/=2;

    }
}
