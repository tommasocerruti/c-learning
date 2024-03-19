#include <stdio.h>
#define PI 3.145

int main() {
    char shape, measure;
    int length;
    float area;
    printf("Shapes s: Square (S) Circle (S). \n");
    printf("Measures m: [Side (S) Diagonal (D)] or [Radius (R) Diameter (D)]. \n");
    printf("Length l. \n");
    printf("Enter the information as s ml:\n");
    scanf("%c %c%d",&shape,&measure,&length);
    if (shape=='S') {
        if (measure=='S')
            area = (float)(length*length);
        else if (measure=='D')
            area = (float)(length*length)/2;
        else{
            printf("Invalid measure");
            return 1;
        }
    }
    else if (shape=='C') {
        if (measure=='R')
            area = (float)(length*length)*PI;
        else if (measure=='D')
            area = (float)(length*length)*PI/4;
        else {
            printf("Invalid measure");
            return 1;
        }
    }
    else {
        printf("Invalid shape");
        return 2;
    }
    printf("The area is %f", area);
    return 0;
}