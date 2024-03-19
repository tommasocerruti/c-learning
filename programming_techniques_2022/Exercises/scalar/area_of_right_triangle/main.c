#include <stdio.h>

int main() {
    int a,b,c; //sides
    float area;
    printf("Insert the value of the sides a b c: ");
    scanf("%d %d %d",&a,&b,&c);
    if (a>b) {
        if (a>c) //hypothenuse is a
            area=b*c/2.0; //at least one variable needs to be float
        else // hypothenuse is c
            area=a*b/2;
    }
    else if (a<b) {
        if (b>c) //hypothenuse is b
            area=a*c/2;
        else // hypothenuse is c
            area=a*b/2;
    }
    printf("The area is %f", area);
    return 0;
}

// or could have used
/*
 #include <math.h>
#include <stdio.h>
int main(void) {
int a,b,c;
float area;
printf("Sides of triangle (a b c): ");
scanf("%d%d%d",&a,&b,&c);
if (a>b && a>c) {
printf("Hypotenuse is a\n");
area = b*c/2.0;
 else if (b>a && b>c) {
printf("Hypotenuse is b\n");
area = a*c/2.0;
}
else if (c>a && c>b) {
printf("Hypotenuse is c\n");
area = a*b/2.0;
}
printf("Area is %f\n", area);
}
}

 */