#include <stdio.h>
#include <string.h>

void maxOdd(int v[], int N);

// Not required: just to check if the function works!
int main(void) {
    int vect[10] = {1,3,7,1,0,1,9,3,1,0};
    maxOdd(vect,10);
    
    return 0;
}

void maxOdd (int v[], int n) {
    int l, j, k, h;
    int toPrint, found;
    
    found = 0;
    
    for(l=n; !found && l>0; l--) { /* for every length of sub-arrays not less than the current maximum one*/
        
        for(j=0; j<=n-l; j++) { /* for each possible starting index of sub-arrays */
            toPrint = 1;
            for(k=j; toPrint && k<j+l; k++) { /* check validity of sub-array */
                if (v[k]%2 == 0)
                    toPrint = 0; /* sub-array not valid */
                
            }
            if (toPrint) {
                found = 1; /* set flag to prevent iteration on a shorted length */
                printf("Maximum subsequence: ");
                for (h=j; h<j+l; h++)
                    printf("%d ",v[h]);
                printf("\n");
                j = k; /* let us skip the sub-interval we just checked */
            }
        }
    }
}



