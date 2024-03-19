#include <stdio.h>
#define FILE_INPUT "../numbers.txt"

int main() {
    FILE *fp_in;
    int num1, num2, num3, counter=0, num_min, num_max, flag=0;

    if ((fp_in = fopen(FILE_INPUT, "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(fp_in, "%d", &num1);
    fscanf(fp_in, "%d", &num2);

    if (num1 < num2){
        num_min = num1;
        num_max = num2;
    } 
    else {
        num_max = num1;
        num_min = num2;
    }

    while(!feof(fp_in)){
        flag = 0;
        fscanf(fp_in, "%d", &num3);
        if (num2 == 0){
            if (num3 == num1-num2 || num3 == num1+num2 || num3 == num1*num2 ){
                flag = 1;
            }
        }
        else {
            if (num3 == num1-num2 || num3 == num1+num2 || num3 == num1*num2 || num3 == num1/num2){
                flag = 1;
            }
        }
        if (flag == 1){
            if (num3 < num_min)
                num_min = num3;
            if (num3 > num_max)
                num_max = num3;
            num1 = num2;
            num2 = num3;
        }
        else{
            counter++;
        }
    }

    printf("Max number: %d\n", num_max);
    printf("Min number: %d\n", num_min);
    printf("Discarded number: %d\n", counter);

	fclose(fp_in);
    return 0;
}
