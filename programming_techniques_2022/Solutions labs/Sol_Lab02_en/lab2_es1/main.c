#include <stdio.h>

int main() {
    int num1, num2;
    int result = -1;

    printf("Insert two numbers:");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0 || num2 < 0) {
        printf("Error negative number %%");
        return 1;
    }

    while(result != 0){
        result = num1 % num2;
        num1 = num2;
        num2 = result;
    }
    printf("Result MCD: %d", num1);

    return 0;
}
