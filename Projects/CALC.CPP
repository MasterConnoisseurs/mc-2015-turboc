#include <stdio.h>
#include <conio.h>

int main() {
    float num1, num2, result;
    char op;

    clrscr();
    printf("Simple Calculator\n");
    printf("-----------------\n");

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2f", result);
            } else {
                printf("Error: Cannot divide by zero.");
            }
            break;
        default:
            printf("Invalid operator.");
    }

    getch();
    return 0;
}
