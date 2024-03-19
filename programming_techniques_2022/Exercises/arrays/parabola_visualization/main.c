#include <stdio.h>
#include <math.h>
const int NR=20, NC=80;
int main(void) {
    float a, b, c, x, y, stepX, stepY,
            xmin, xmax, ymin, ymax;
    int i, j;
    char page[NR][NC];
    FILE *fpout = fopen("out.txt","w");
    printf("Coefficients (a b c): ");
    scanf("%f%f%f",&a,&b,&c);
    printf("X axis range (xmin xmax): ");
    scanf("%f%f",&xmin,&xmax);
    printf("Y axis range (ymin ymax): ");
    scanf("%f%f",&ymin,&ymax);
    /* matrix initialization*/
    for (i=0; i<NR; i++)
        for (j=0; j<NC; j++)
            page[i][j] = ' ';
    stepX = (xmax-xmin)/(NC-1);
    stepY = (ymax-ymin)/(NR-1);
    /* compute parabola points */
    for (j=0; j<NC; j++) {
        x = xmin + j*stepX;
        y = a*x*x + b*x + c;
        if (y>=ymin && y<=ymax) {
            i = (y-ymin)/stepY;
            page[i][j] = '*';
        }
    }
    /* print matrix row by row:
    the minimum value of y (first row) needs to be printed last */
    for (i=NR-1; i>=0; i--) { // per each value of y
        for (j=0; j<NC; j++) // per each value of x
            fprintf(fpout,"%c",page[i][j]);
        fprintf(fpout,"\n");
    }
    fclose(fpout);
}