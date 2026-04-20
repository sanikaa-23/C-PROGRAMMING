#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    int i;

    if (n < 0)
        return -1;  // Factorial not defined for negative numbers

    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate power x^y
double power(double x, int y) {
    double result = 1;
    int i;

    for (i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

int main() {
    int choice;
    double num1, num2, result;
    int n;
    long long fact;

    printf("Simple Calculator\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (x^y)\n");
    printf("6. Factorial (x!)\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result = %.2lf\n", result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result = %.2lf\n", result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result = %.2lf\n", result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0)
                printf("Result = %.2lf\n", num1 / num2);
            else
                printf("Error! Division by zero.\n");
            break;

        case 5:
            printf("Enter base (x) and exponent (y): ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, (int)num2);
            printf("Result = %.2lf\n", result);
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%d", &n);
            fact = factorial(n);
            if (fact == -1)
                printf("Factorial not defined for negative numbers.\n");
            else
                printf("Result = %lld\n", fact);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

