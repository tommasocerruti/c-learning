##include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MAXR 40
#define MAXC 40

int cmpHor(char A[][MAXC], int r, int c, char str[], int l) {
    int k;
    for (k=0; k<l; k++) {
        if (str[k] != A[r][c+k])
            return 0; // not equal;
    }
    return 1; // equal
}

int cmpVert(char A[][MAXC], int r, int c, char str[], int l) {
    int k;
    for (k=0; k<l; k++) {
        if (str[k] != A[r+k][c])
            return 0; // not equal;
    }
    return 1; // equal
}

int count (char A[][MAXC], int n, int m, char str[]) {
    int r, c, k, len = strlen(str), cnt = 0;
    // Horizontal
    for(r=0;r<n;r++) {
        for(c=0;c<=m-len;c++) {
            if (cmpHor(A,r,c,str,len))
                cnt++;
        }
    }
    // Vertical
    for(r=0;r<=n-len;r++) {
        for(c=0;c<m;c++) {
            if (cmpVert(A,r,c,str,len))
                cnt++;
        }
    }
    return cnt;
}

/* Not required: just to call the function and see if it works */
int main(void) {
    char M[MAXR][MAXC] = {
        "xceca",
        "waecq",
        "dtpaz",
        "pcatf"
    };
    
    printf("Num of matches for %s = %d\n", "cat", count(M, 4, 5, "cat"));
    return 0;
}

