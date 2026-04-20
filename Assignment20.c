#include <stdio.h>

// Without pointers (call by value)
void swapValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Inside swapValue: a=%d b=%d\n", a, b);
}

// With pointers (call by reference)
void swapPointer(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    printf("Before swap: x=%d y=%d\n", x, y);

    // Call by value
    swapValue(x, y);
    printf("After swapValue: x=%d y=%d\n", x, y);

    // Call by reference
    swapPointer(&x, &y);
    printf("After swapPointer: x=%d y=%d\n", x, y);

    return 0;
}
