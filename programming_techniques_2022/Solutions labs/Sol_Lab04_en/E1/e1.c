#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MAXN 30


void printArrayInterval(int v[MAXN], int r, int l) {
	int i;
	for(i=r; i<=l; i++) printf("%d ", v[i]);
	printf("\n");
}

int subSequences1(int v[MAXN], int n) {
	int length, j, k;
	int toPrint, found;

	found = 0;
	for(length=n; !found && length>0; length--) { /* for every length of sub-arrays not less than the current maximum one*/
		for(j=0; j<=n-length; j++) { /* for each possible starting index of sub-arrays */
			toPrint = 1;
			for(k=j; toPrint && k<j+length; k++) { /* check validity of sub-array */
				if (v[k] == 0) {
					toPrint = 0; /* sub-array not valid */
				}
			}
			if (toPrint) {
				found = 1; /* set flag to prevent iteration on a shorter length */
				printf("Maximum subsequence: ");
				printArrayInterval(v,j,j+length-1);
				j = k+1; /* let us skip the sub-interval just checked */
			}
		}
	}
	return 0;
}

int subSequences2(int v[MAXN], int n) {
	int maxl=0, i, i0=-1;

	/* find sub-arrays of maximum length */
	for(i=0; i<=n; i++) {
		if (i<n && v[i]!=0 && (i==0 || v[i-1]==0)) {
			/* starting index of sub-array */
			i0 = i;
		}
		else if (i>0 && (i==n || v[i]==0) && v[i-1]!=0) {
			/* sub-array terminated, let us compute its length and compare it against the maximum, updating it accordingly */
			if (i-i0 > maxl) {
				maxl = i-i0;
			}
		}
	}
	/* knowing the maximum length, print correspondent sub-arrays (maybe more than one) */
	for(i=0; i<=n; i++) {
		if (i<n && v[i]!=0 && (i==0 || v[i-1]==0)) {
			/* starting index of sub-array */
			i0 = i;
		}
		else if (i>0 && (i==n || v[i]==0) && v[i-1]!=0) {
			/* sub-array terminated. If of maximum length, let us print it */
			if (i-i0 == maxl) {
				printf("Maximum subsequence: ");
				printArrayInterval(v,i0,i0+maxl-1);
			}
		}
	}

	return 0;
}

int subSequences3(int v[MAXN], int n) {
	int maxl=0, nmax=0, i, i0=-1;
	int maximums_i0[MAXN];

	/* find sub-arrays of maximum length */
	for(i=0; i<=n; i++) {
		if (i<n && v[i]!=0 && (i==0 || v[i-1]==0)) {
			/* starting index of sub-array */
			i0 = i;
		}
		else if (i>0 && (i==n || v[i]==0) && v[i-1]!=0) {
			/* sub-array terminated. Let us compute its length and compare it against the current maximum, updating, if needed: maximum, array of maximums (maximums_i0) and the its index (nmax) */
			if (i-i0 > maxl) {
				maxl = i-i0;
				maximums_i0[0] = i0;
				nmax=1;
			}
			else if (i-i0 == maxl) {
				/* the sub-array found is of maximum length. Let us insert in maximums_i0 its starting index */
				maximums_i0[nmax++] = i0;
			}
		}
	}
	/* print bus-arrays of maximum length (maybe more than one) */
	for(i=0; i<nmax; i++) {
		printf("Maximum subsequence: ");
		printArrayInterval(v,maximums_i0[i],maximums_i0[i]+maxl-1);
	}

	return 0;
}

int main(int argc, char *argv[]) {
	int vett[MAXN] = {0,0,3,4,5,0,0,1,3,4,0,1,0,9,4,2,0};
	int i, n, selettore = 1;

	if (argc>1) {
		selettore = atoi(argv[1]);
		if (selettore<1 || selettore>3) selettore = 1;
	}

	printf("Insert number of elements (interval 1..%d)\n", MAXN);
	printf("(Outside of interval to accept pre-set values): ");
	scanf("%d", &n);
	printf("Insert numbers\n");
	if (n>0 && n<=MAXN) {
		for(i=0; i<n; i++) scanf("%d", &vett[i]);
	}
	else {
		n = 17;
	}

	printf("The array is:\n");
	printArrayInterval(vett,0,n-1);

	switch (selettore) {
		case 1: subSequences1(vett, n);
			break;
		case 2: subSequences2(vett, n);
			break;
		case 3: subSequences3(vett, n);
			break;
		default: printf("Error: invalid selector\n");
	}

	return 0;
}
