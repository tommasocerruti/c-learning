#include <stdio.h>

int main() {
    char operation;
    float op1, op2, result;

    printf("Insert operation:");
    operation = getchar();
    printf("Insert number one:");
    scanf("%f", &op1);
    printf("Insert number two:");
    scanf("%f", &op2);

    switch (operation) {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        default:
            printf("Wrong choice\n");
            return 1;
    }
    printf("result: %c %.2f", operation, result);

    return 0;
}
