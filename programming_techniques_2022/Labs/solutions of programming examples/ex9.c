#include <stdio.h>
#include <math.h>

#define MAXN 20
#define MAXM 20

void displRanking(int C[MAXN][MAXM], int n, int m);
int searchMax(int v[], int n);

// Not required: just to check if the function works!
int main()
{
    int mat[MAXN][MAXM] = {{3,1,0},{0,1,1},{1,1,1},{1,1,3}};
    displRanking(mat, 4, 3);
}


void displRanking(int C[MAXN][MAXM], int n, int m) {
    int i, j, points[MAXN] = {0};
    
    printf("The leading team for each of the %d days is: ",m);
    /* for each day of championship*/
    for(j=0;j<m;j++) {
        /* for each team */
        for(i=0;i<n;i++)
            points[i] += C[i][j];
        // points now contains the current scores of the different teams in the given day
        printf("%d ",searchMax(points, n));  // find the currently leading team
    }
    return;
}


int searchMax(int v[], int n) {
    int max = -1, i, maxi = -1;
    for(i=0;i<n;i++) {
        if (max < v[i]) {
            max = v[i];
            maxi = i;
        }
    }
    return maxi;
}
