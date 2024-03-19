#include <stdio.h>
#include <math.h>

#define MAXN 10


int sumFrames(int mat[MAXN][MAXN], int N, int vet[]);

// Not required: just to check if the function works!
int main()
{
    int mat[MAXN][MAXN] = {{1,2,3,4,5},{6,7,8,9,0},{1,2,3,4,5},{6,7,8,9,0},{1,1,1,1,1}};
    int v[MAXN/2+1], i, n;
    
    n = sumFrames(mat,5,v);
    
    for (i=0;i<n;i++)
        printf("%d ",v[i]);
}

int sumFrames(int mat[MAXN][MAXN], int N, int vet[])
{
    int nf,i,j;
    
    // Total number of frames in a NxN matrix is ceil(N/2.0)
    
    // Per each frame (0 is the most external)
    for (nf = 0; nf<(int)ceil(N/2.0);nf++)
    {
        // Counter of nf-th frame initialized to 0
        vet[nf]=0;
        // Indexes of a frame go from nf to N-nf
        for (i=nf;i<N-nf;i++)
            for (j=nf;j<N-nf;j++)
                // Elements of a frame have either nf or N-nf-1 as i,j index
                if (i==nf || j==nf || i==N-nf-1 || j==N-nf-1)
                    vet[nf]+=mat[i][j];
    }
    return nf;
}
