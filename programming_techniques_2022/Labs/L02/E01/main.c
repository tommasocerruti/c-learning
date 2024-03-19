#include <stdio.h>

int main() {
    int a,b,end_flag,gcf;
    printf("Input the two numbers a b:");
    scanf("%d %d",&a,&b);
    end_flag=0;
    while (!end_flag){
        if (a>b){
            a=a%b;
            if (a==0){
                gcf=b;
                end_flag=1;
            }
        }
        else if (a<=b){
            b=b%a;
            if (b==0){
                gcf=a;
                end_flag=1;
            }
        }
    }
    printf("The gfc is %d",gcf);
    return 0;
}
