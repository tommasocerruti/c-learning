#include <stdio.h>
#define maxN 30

void rotate(int v[maxN], int n, int p, int dir);

int main() {
    int v[maxN], n, p, dir;
    int i;
    //1. acquire n
    printf("Input n (n<=30)\n");
    scanf("%d",&n);
    //2. acquire v
    printf("Input the %d values of the array\n",n);
    for (i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    //3. acquire repeatedly p
    while(p!=0){
        printf("Input the number of positions to be rotated "
               "(p<n, p=0 to terminate the program)\n");
        scanf("%d",&p);
        if (p!=0){
            printf("Input the direction of the rotation "
                   "(dir=-1 for right, dir=1 for left)\n");
            scanf("%d",&dir);
            rotate(v, n, p, dir);
            for (i=0;i<n;i++){
                printf("%d ",v[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

void rotate(int v[maxN], int n, int p, int dir){
    int i,z=0,prev_v[n];
    for (i=0;i<n;i++)
        prev_v[i]=v[i];
    if (dir==-1){
        for (i=n-p;i<n;i++){
            v[z]=prev_v[i];
            z++;
        }
        for (i=0;i<n-p;i++){
            v[z]=prev_v[i];
            z++;
        }
    }
    else if (dir==1){
        for (i=p;i<n;i++){
            v[z]=prev_v[i];
            z++;
        }
        for (i=0;i<p;i++){
            v[z]=prev_v[i];
            z++;
        }
    }
}