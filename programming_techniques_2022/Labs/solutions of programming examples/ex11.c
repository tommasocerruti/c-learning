#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define NMAX 100

int areaTot(FILE *fp);

// Not required: just to check if it works!
int main()
{
    FILE* fp = fopen("rect.txt","r");
    
    int area = areaTot(fp);
    
    printf("The area is %d",area);
    
    fclose(fp);
    
}

int areaTot(FILE *fp){
    
    int mat[NMAX][NMAX] = {0};  // Region: 100x100 matrix of 0 elements
    int x1,y1,x2,y2,i1,i2,j1,j2,i,j;
    int area = 0;
    
    // Per each rectangle in the file
    while(fscanf(fp,"%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
    {
        // Convert cartesian coordinates to row-column indexes
        i1 = NMAX-y1-1; // row-index of lower-left corner
        j1 = x1;        // column-index of lower-left corner
        i2 = NMAX-y2;   // row index of upper-right corner
        j2 = x2-1;      // column index of upper-right corner
        // Per all elements of a rectangle
        for (i=i2;i<=i1;i++)
            for (j=j1;j<=j2;j++)
                if (mat[i][j]==0)  // Check if the element is "free"
                {
                    mat[i][j]++;   // If so, fill it with a 1
                    area++;        // ... and increment the area
                }
    }
    return area;
}
