#include <stdio.h>

int main()
{
    int a, b, i;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // finding smallest common divisor
    for(i = 2; i <= a && i <= b; i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            printf("Smallest Common Divisor = %d\n", i);
            break;
        }
    }

    // finding GCD
    for(i = a; i >= 1; i--)
    {
        if(a % i == 0 && b % i == 0)
        {
            printf("GCD = %d", i);
            break;
        }
    }

    return 0;
}
