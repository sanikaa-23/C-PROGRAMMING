#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], rev[100];
    int i, len;

    printf("Enter a string: ");
    gets(str1);

    // i. Length
    len = strlen(str1);
    printf("Length = %d\n", len);

    // ii. Reverse
    for(i = 0; i < len; i++) {
        rev[i] = str1[len - i - 1];
    }
    rev[i] = '\0';
    printf("Reversed string = %s\n", rev);

    // iii. Equality check
    printf("Enter another string: ");
    gets(str2);

    if(strcmp(str1, str2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    // iv. Palindrome
    if(strcmp(str1, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    // v. Substring
    if(strstr(str1, str2) != NULL)
        printf("Substring found\n");
    else
        printf("Substring not found\n");

    return 0;
}
