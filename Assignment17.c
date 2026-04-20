#include <stdio.h>

int main() {
    int n, i, j;
    float x, sum = 0, term;

    printf("Enter value of x (in radians): ");
    scanf("%f", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        term = 1;

        // Calculate x^(2i-1)
        for(j = 1; j <= (2*i - 1); j++) {
            term = term * x;
        }

        // Calculate factorial (2i-1)!
        for(j = 1; j <= (2*i - 1); j++) {
            term = term / j;
        }

        // Add or subtract term
        if(i % 2 == 0)
            sum = sum - term;
        else
            sum = sum + term;
    }

    printf("Sum of sine series = %f", sum);

    return 0;
}
