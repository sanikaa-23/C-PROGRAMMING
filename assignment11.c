#include <stdio.h>
#include <math.h>

// Function to check prime
int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to calculate factorial
long long factorial(int n) {
    if (n < 0)
        return -1;

    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    long long fact;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Square root
    if (num >= 0)
        printf("Square root = %.2f\n", sqrt(num));
    else
        printf("Square root not defined for negative numbers.\n");

    // Square
    printf("Square = %d\n", num * num);

    // Cube
    printf("Cube = %d\n", num * num * num);

    // Prime check
    if (isPrime(num))
        printf("%d is a Prime number.\n", num);
    else
        printf("%d is not a Prime number.\n", num);

    // Factorial
    fact = factorial(num);
    if (fact == -1)
        printf("Factorial not defined for negative numbers.\n");
    else
        printf("Factorial = %lld\n", fact);

    // Prime factors
    printf("Prime factors: ");
    int n = num;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    if (num <= 1)
        printf("None");
    printf("\n");

    return 0;
}

