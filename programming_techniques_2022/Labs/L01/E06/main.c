#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write;
    float op1,op2,result;
    char op;
    if ((fp_read=fopen("../Operations.txt", "r"))==NULL) {
        printf("Error opening input file\n");
        return 3;
    }
    if ((fp_write=fopen("../Results.txt", "w"))==NULL) {
        printf("Error opening output file\n");
        return 4;
    }
    while (!feof(fp_read)) {
        fscanf(fp_read, "%c %f %f\n", &op, &op1, &op2);
        if (op == '+')
            result=op1+op2;
        else if (op == '-')
            result=op1-op2;
        else if (op == '*')
            result=op1*op2;
        else if (op == '/') {
            if (op2==0) {
                printf("ERROR: op2 must be different from zero for divisions");
                return 1;
            }
            else
                result=op1/op2;
        }
        else {
            printf("ERROR: op must be a valid operation");
            return 2;
        }
        fprintf(fp_write, "%c %.2f\n", op, result);
    }
    fclose(fp_read);
    fclose(fp_write);
    return 0;
}