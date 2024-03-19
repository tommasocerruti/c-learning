#include <stdio.h>
#define INPUT_FILE "../numbers.txt"
int verification(int x_2,int x_1,int x);
void outcome(int max, int min, int i);
int main() {
    FILE *f_point;
    char cx_2=' ', cx_1=' ', cx=' ';
    int x_2, x_1, x, i=0, max, min;
    if ((f_point= fopen(INPUT_FILE, "r"))==NULL){
        printf("ERROR WITH INPUT_FILE");
        return 1;
    }
    while (cx_2==' ' || cx_2=='\n'){
        fscanf(f_point,"%c",&cx_2);
        if (cx_2=='-'){
            fscanf(f_point,"%c",&cx_2);
            x_2=(cx_2-'0')*(-1);
        }
        else x_2=cx_2-'0';
    }
    while (cx_1==' ' || cx_1=='\n'){
        fscanf(f_point,"%c",&cx_1);
        if (cx_1=='-'){
            fscanf(f_point,"%c",&cx_1);
            x_1=(cx_1-'0')*(-1);
        }
        else x_1=cx_1-'0';
    }
    if (x_2>=x_1){
        max=x_2;
        min=x_1;
    }
    else {
        max=x_1;
        min=x_2;
    }
    while (!feof(f_point)){
        while ((cx==' ' || cx=='\n') && !feof(f_point)){
            fscanf(f_point,"%c",&cx);
            if (cx=='-'){
                fscanf(f_point,"%c",&cx);
                x=(cx-'0')*(-1);
            }
            else x=cx-'0';
            if ((cx!=' ' && cx!='\n') && !verification(x_2,x_1,x)){
                cx=' ';
                i+=1;
            }
        }
        if (!feof(f_point)){
            if (x>max)
                max=x;
            else if (min>x)
                min=x;
        }
        x_2=x_1;
        x_1=x;
        cx=' ';
    }
    fclose(f_point);
    outcome(max, min, i);
    return 0;
}

int verification(int x_2,int x_1, int x){
    if (x==x_2+x_1)
        return 1;
    else if ((x==x_2-x_1) || (x==x_1-x_2)) //not commutative
        return 1;
    else if (x==x_2*x_1)
        return 1;
    else if ((x_1!=0 && x==x_2/x_1) || (x_2!=0 && x==x_1/x_2)) //not commutative + "zero check"
        return 1;
    else
        return 0;
}
void outcome(int max, int min, int i){
    printf("# of discarded values: %d\n",i);
    printf("Maximum value: %d\n",max);
    printf("Minimum value: %d",min);
}
//{}
