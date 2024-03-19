#include <stdio.h>

int main() {
    float op1,op2,result;
    char op;
    printf("Input the op:");
    op=getchar();
    printf("Input the operands op1 op2:");
    scanf("%f %f", &op1, &op2);
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
    printf("%c %.2f", op, result);
    return 0;
}
