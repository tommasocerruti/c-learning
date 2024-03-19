// 2nd degree equation

/* version 1: non-nested if */
#include <math.h>
#include <stdio.h>
int main(void) {
    float a,b,c,delta,x0,x1,re,im;
    printf("Insert coefficients (a b c): ");
    scanf("%f%f%f",&a,&b,&c);
    if (a==0 && b==0 && c==0)
        printf("Indetermined equation\n");
    if (a==0 && b==0 && c!=0)
        printf("Impossible equation\n");
    if (a==0 && b!= 0) {
        printf("I degree equation\n »");
        printf("Solution: %f\n", -c/b);
        if (a!=0) {
            delta = b*b-4*a*c;
            if (delta==0) {
                x0 = (-b)/(2*a); x1 = (-b)/(2*a);
                printf("2 real coincident solutions: ");
                printf("%f %f\n",x0,x1);
            }
            if (delta > 0) {
                x0 = (-b-sqrt(delta))/(2*a);
                x1 = (-b+sqrt(delta))/(2*a);
                printf("2 real distinct solutions: ");
                printf("%f %f\n",x0,x1);
            }
            if (delta < 0){
                re = -b/(2*a);
                im = sqrt(-delta)/(2*a);
                printf("2 compl. Conjugate sol.: ");
                printf("x0=%f-i*%f ",re, im);
                printf("x1=%f+i*%f\n", re, im); }
        }
    }
}

/* version 2: nested if
#include <math.h>
#include <stdio.h>
int main(void) {
    float a,b,c,delta,x0,x1,re,im;
    printf("Insert coefficients (a b c): ");
    scanf("%f%f%f",&a,&b,&c);
    if (a==0) {
        if (b==0) {
            if (c==0)
                printf("Indetermined equation\n");
            else
                printf("Impossible equation\n");
        }
        else {
            printf("I degree equation\n");
            printf("Solution: %f\n", -c/b);
        }
    }
    else {
        delta = pow(b,2)-4*a*c;
        if (delta==0) {
            x0 = (-b)/(2*a);
            x1 = x0;
            printf("2 real coincident solutions: %f %f\n",x0,x1);
        }
        else {
            if (delta > 0) {
                x0 = (-b-sqrt(delta))/(2*a);
                x1 = (-b+sqrt(delta))/(2*a);
                printf("2 real distinct solutions: %f %f\n",x0,x1);
            }
            else {
                re = -b/(2*a);
                im = sqrt(-delta)/(2*a);
                printf("2 complex conjugate solutions: ");
                printf("x0=%f-i%f x1=%f+i%f",re,im,re,im);
            }
        }
    }
    return 0;
}
*/
