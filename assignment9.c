#include <stdio.h>

int main() {
    int num, originalNum, remainder;
    int result = 0;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    originalNum = num;

    // Calculate sum of cubes of digits
    while (num != 0) {
        remainder = num % 10;
        result += remainder * remainder * remainder;
        num /= 10;
    }

    // Check Armstrong condition
    if (result == originalNum)
        printf("%d is an Armstrong number.\n", originalNum);
    else
        printf("%d is not an Armstrong number.\n", originalNum);

    return 0;
}
