#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define R 20
#define C 20
#define LEN 50

void turns(int mat[R][C], int n, int m);
int searchMax(int points[R], int n);

int main(int argc, char **argv) {

  FILE *in = NULL;
  int i, j, n, m, dim, mat[R][C];
  char filename[LEN];

  printf("Write input filename: ");
  scanf("%s", filename);
  in = fopen(filename, "r");
  if (in == NULL)
    return;

  fscanf(in, "%d %d", &n, &m);
  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
      fscanf(in, "%d", &mat[i][j]);
    }
  }

  turns(mat, n, m);

  return 0;
}

void turns(int mat[R][C], int n, int m) {
  int i, j, points[R] = {0};
  /* for each turn */
  for(i=0;i<m;i++) {
	/* for all teams */
	for(j=0;j<n;j++) {
        // shouldn't we save the points for each team (save by row)
	  points[j] += mat[j][i];
    }
	printf("The leading team is [%d]\n", searchMax(points, n));
  }
  return;
}

int searchMax(int points[R], int n) {
  int max = -1, i, maxi = -1;
  for(i=0;i<n;i++) {
    if (max < points[i]) {
	  max = points[i];
      maxi = i;
    }
  }
  return maxi;
}
