#include <stdio.h>
#include <math.h>

int main() {
    FILE *fp_out;
    float a,b,c,x,step,x0,xn,y,ymin,ymax;
    int i,j,n;
    if (fopen("../out.txt","w")==NULL)
        return 1;
    fp_out=fopen("../out.txt","w");
    printf("Coefficients (a b c): ");
    scanf("%f%f%f",&a,&b,&c);
    printf("Number of intervals: ");
    scanf("%d",&n);
    printf("Interval for x-axis: ");
    scanf("%f%f",&x0,&xn);
    printf("Interval for y-axis: ");
    scanf("%f%f",&ymin,&ymax);
    step=(xn-x0)/n;
    for (i=0;i<=n;i++){
        x=x0+i*step;
        y=a*x*x+b*x+c;
        if (y>=ymin && y<=ymax){
            for (j=round(y-ymin);j>0;j--){
                fprintf(fp_out," ");
            }
            fprintf(fp_out,"*");
        }
        fprintf(fp_out,"\n");
    }
    fclose(fp_out);
    return 0;
}
