#include <stdio.h>
void conversion(int n, int b);
int main(void) {
    int b0, b1, n, p, digit, end=0;
    char c;
    printf("b0 (2..9):"); scanf("%d",&b0);
    printf("b1 (2..9):"); scanf("%d\n",&b1);
    n = 0;
    while (!end) {
        scanf("%c",&c);
        if (c== ' ' || c== '\n') {
            conversion(n,b1); n=0; printf("\n");
        }
        else {
            digit = c - '0'; // converts char to number
            if (digit>=0 && digit<b0)
                n = b0*n + digit;
            else
                end=1;
        }
    }
}

void conversion(int n, int b) {
    int p;
    for (p=1; b*p<=n; p=p*b); // same as binary, but with b instead of 2
    while (p>0) {
        if (p<=n) {
            printf("%d",n/p); n=n%p;
        }
        else printf("0");
        p = p/b;
    }
}
