#include <stdio.h>
#define D 100
// Cartesian product data-type
typedef struct{
    int a;
    int b;
} prod;

void prodCartOrd(int *v1, int d1, int *v2, int d2);
void sortProduct(prod p[], int n);

// Not required: just to check if it works!
int main(){
    int v1[] = {2,1,3};
    int v2[] = {4,5,3,6};
    prodCartOrd(v1, 3, v2, 4);
}

void prodCartOrd(int *v1, int d1, int *v2, int d2)
{
    prod pv[D]; // Vector of cartesian products
    int n = 0;
    int i,j;
    
    // Compute cartesian products of elements pointed by v1 and v2
    for (i=0;i<d1;i++)
    {
        for(j=0;j<d2;j++){
            pv[n].a = v1[i];
            pv[n].b = v2[j];
            n++;
        }
    }
    
    // Selection sort
    sortProduct(pv, n);
    
    // Print sorted elements
    for (i=0;i<n;i++)
        printf("(%d-%d)\n",pv[i].a,pv[i].b);
}


// Selection sort
void sortProduct(prod p[], int n)
{
    int i,j,imin;
    prod tmp;
    for (i=0;i<n-1;i++)
    {
        imin = i;
        for (j=i+1;j<n;j++)
        {
            // Sorting key is the sum of a and b (or a alone, if sum is the same)
            if ((p[j].a+p[j].b < p[imin].a+p[imin].b) || ((p[j].a+p[j].b == p[imin].a+p[imin].b) && (p[j].a < p[imin].a)) )
                imin = j;
        }
        tmp = p[i];
        p[i] = p[imin];
        p[imin]=tmp;
        
    }
}