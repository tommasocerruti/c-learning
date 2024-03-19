#include <stdio.h>
#define P 3.14

int main(void) {
    char figure, dimension;
    int length;
    float area;

    printf("Insert area request: ");
    scanf("%c %c%d", &figure, &dimension, &length);

    if (figure == 'Q') {
        if (dimension == 'D') {
            area = length * length / 2.0;
        }
        else if (dimension == 'L') {
            area = (float)(length * length);
        }
        else {
            printf("Error!");
            return 1;
        }
        printf("Square Area = %.1f", area);
    }
    else if (figure == 'C') {
        if (dimension == 'D') {
            area = P * length * length / 4.0;
        }
        else if (dimension == 'R') {
            area = P * length * length;
        }
        else {
            printf("Error!");
            return 1;
        }
        printf("Circle Area = %.1f", area);
    }
    else {
        printf("Error");
    }
    return 0;
}
