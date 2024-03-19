#include <stdio.h>

int main() {
    char operation;
    float op1, op2, result;
    FILE *fp_read, *fp_write;

    if ((fp_read = fopen("../Operations.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    if ((fp_write = fopen("../Output.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }

    while (!feof(fp_read)) {
        fscanf(fp_read, "%c %f %f\n", &operation, &op1, &op2);

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
                    return 3;
            }
            fprintf(fp_write,"%c %.2f\n", operation, result);
    }

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}
