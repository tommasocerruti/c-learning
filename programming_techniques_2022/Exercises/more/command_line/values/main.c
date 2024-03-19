#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int N, D, i;
    if (argc!=3)
        return 2;
    N=atoi(argv[1]);
    D=atof(argv[2]);
    for (i=0;i<=N;i++){
        if (i%D==0)
            printf("%d ",i);
    }
    return 0;
}
