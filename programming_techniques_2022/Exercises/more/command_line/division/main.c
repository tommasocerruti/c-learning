#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]) {
    float a, b, div;
    if (arg!=3)
        return 1;
    a=atof(argv[1]);
    b=atof(argv[2]);
    div=a/b;
    printf("%d/%d=%f",argv[1],argv[2],div);
    return 0;
}
