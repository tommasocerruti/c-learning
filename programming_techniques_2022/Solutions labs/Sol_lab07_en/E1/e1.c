#include<stdlib.h>
#include<stdio.h>

#define R 50
#define C 50

typedef struct {int r; int c;} dim;
typedef struct {int b; int h; int x; int y; } rect;


dim readMatrix(int mat[][C]);
void printMatrix(int mat[][C], dim dimensions);
rect detectRegion(int mat[][C], dim dimensions, int r, int c);

int main(int argc, char **argv) {
  int M[R][C], i, j;
  dim dimensions;
  rect rectangle, rectH, rectB, rectA;
  rectH.x = rectH.y = rectA.x = rectA.y = rectB.x = rectB.y = -1;

  dimensions = readMatrix(M);
  printMatrix(M, dimensions);

  for (i=0; i<dimensions.r; i++) {
    for(j=0;j<dimensions.c;j++) {
      rectangle.b = 0;
      rectangle.h = 0;
      rectangle = detectRegion(M, dimensions, i, j);
      if (rectangle.b!=0 && rectangle.h!=0) {
        /* update (if needed) the "best" regions to be printed at the end of the scan */
        if (rectB.x == -1 || rectB.b < rectangle.b) rectB = rectangle;
        if (rectA.x == -1 || (rectA.b * rectA.h) < (rectangle.b * rectangle.h)) rectA = rectangle;
        if (rectH.x == -1 || rectH.h < rectangle.h) rectH = rectangle;
      }
    }
  }
  printf("Max Width: upper left corner = <%d,%d> b=%d, h=%d, Area=%d\n", rectB.x, rectB.y, rectB.b, rectB.h, rectB.b*rectB.h);
  printf("Max Area: upper left corner = <%d,%d> b=%d, h=%d, Area=%d\n", rectA.x, rectA.y, rectA.b, rectA.h, rectA.b*rectA.h);
  printf("Max Height: upper left corner = <%d,%d> b=%d, h=%d, Area=%d\n", rectH.x, rectH.y, rectH.b, rectH.h, rectH.b*rectH.h);

  return 0;
}

dim readMatrix(int mat[][C]) {
  int i, j, nr, nc;
  dim dimensions;
  FILE *in = fopen("map.txt", "r");
  if (in == NULL)
    exit(-1);

  fscanf(in, "%d %d", &nr, &nc);
  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
      fscanf(in, "%d", &mat[i][j]);
  dimensions.r = nr;
  dimensions.c = nc;
  fclose(in);
  return dimensions;
}

void printMatrix(int mat[][C], dim dimensions) {
  int i, j;
  for (i=0; i<dimensions.r; i++) {
    for (j=0; j<dimensions.c; j++)
      printf("%d ", mat[i][j]);
	printf("\n");
  }
  return;
}

rect detectRegion(int mat[][C], dim dimensions, int r, int c) {
  int x, y, b=0, h=0;
  rect rectangle;

  if (mat[r][c] != 1 || (r>0 && (mat[r-1][c] == 1)) || (c>0 && (mat[r][c-1] == 1))) {
    rectangle.b = b;
    rectangle.h = h;
    return rectangle;
  }
  /* if it is a rectangle on the upper left */
  x = r;
  y = c;
  while (y<dimensions.c && mat[x][y] == 1)
    y++;
  b = y - c;
  y = c;
  while (x<dimensions.r && mat[x][y] == 1)
    x++;
  h = x - r;

  rectangle.b = b;
  rectangle.h = h;
  rectangle.x = r;
  rectangle.y = c;

  return rectangle;
}
