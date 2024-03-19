#include<stdlib.h>
#include<stdio.h>

#define R 50
#define C 50

void readMatrix(int mat[][C], int *nr, int *nc);
void printMatrix(int mat[][C], int nr, int nc);
int detectRegion(int mat[][C], int nr, int nc, int r, int c, int *b, int *h);

int main(int argc, char **argv) {
	int M[R][C], nr, nc, i, j, b, h;
	int rectHx = -1, rectHy = -1, rectAx = -1, rectAy = -1, rectBx = -1, rectBy = -1;
	int rectHb = 0, rectHh = 0, rectAb = 0, rectAh = 0, rectBb = 0, rectBh = 0;;

	readMatrix(M, &nr, &nc);
	printMatrix(M, nr, nc);

	for (i=0; i<nr; i++) {
		for(j=0;j<nc;j++) {
			b = 0;
			h = 0;
			if (detectRegion(M, nr, nc, i, j, &b, &h)) {
				/* update (if needed) the "best" regions to be printed at the end of the scan */
				if (rectBx == -1 || rectBb < b) {
					rectBx = i;
					rectBy = j;
					rectBb = b;
					rectBh = h;
				}
				if (rectAx == -1 || rectAb*rectAh < b*h) {
					rectAx = i;
					rectAy = j;
					rectAb = b;
					rectAh = h;
				}
				if (rectHx == -1 || rectHb < h) {
					rectHx = i;
					rectHy = j;
					rectHb = b;
					rectHh = h;
				}
			}
		}
	}
	printf("Max Width: upper left corner = <%d,%d> b=%d, h=%d, Area=%d\n", rectBx, rectBy, rectBb, rectBh, rectBb*rectBh);
	printf("Max Area: upper left corner = <%d,%d> b=%d, h=%d, Area=%d\n", rectAx, rectAy, rectAb, rectAh, rectAb*rectAh);
	printf("Max Height: upper left corner = <%d,%d> b=%d, h=%d, Area=%d\n", rectHx, rectHy, rectHb, rectHh, rectHb*rectHh);

	return 0;
}

void readMatrix(int mat[][C], int *nrp, int *ncp) {
	int i, j;
	FILE *in = fopen("mat.txt", "r");
	if (in == NULL)
		exit(-1);
	fscanf(in, "%d %d", nrp, ncp);
	for (i=0; i<*nrp; i++)
		for (j=0; j<*ncp; j++)
			fscanf(in, "%d", &mat[i][j]);
	fclose(in);
	return;
}

void printMatrix(int mat[][C], int nr, int nc) {
	int i, j;
	for (i=0; i<nr; i++) {
		for (j=0; j<nc; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return;
}

int detectRegion(int mat[][C], int nr, int nc, int r, int c, int *pb, int *ph) {
	int x, y, b, h;
	if (mat[r][c] != 1)
		return 0;
	x = r;
	y = c;
	while (y<nc && mat[x][y] == 1)
		y++;
	b = y - c;
	y = c;
	while (x<nr && mat[x][y] == 1)
		x++;
	h = x - r;
	for (x=0; x<h; x++)
		for (y=0; y<b; y++)
			mat[r+x][c+y] = 2;
	*pb = b;
	*ph = h;
	return 1;
}
