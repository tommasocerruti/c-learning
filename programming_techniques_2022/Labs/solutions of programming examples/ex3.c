#include <stdio.h>

void prodCartFilt(int *v1, int d1, int *v2, int d2);

// Not required: just to check if the function works!
int main(){
    int v1[] = {1,2,3};
    int v2[] = {3,4,5,6};
    prodCartFilt(v1, 3, v2, 4);
}

void prodCartFilt(int *v1, int d1, int *v2, int d2)
{
    int i,j,prod;
    
    // Per each element of the first set
    for (i=0;i<d1;i++)
    {
        // Per each element of the second set
        for(j=0;j<d2;j++){
            prod = v1[i]*v2[j];
            // Check validity of the cartesian product
            if (v1[i] != v2[j] && v1[i]-v2[j] != 1 && v1[i]-v2[j] != -1)
                printf("(%d,%d) ",v1[i],v2[j]); // Print only if valid
        }
    }
    return;
}
