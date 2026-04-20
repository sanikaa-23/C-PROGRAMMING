#include <stdio.h>

#define MAX 100

// Structure definition
struct Student {
    char name[50];
    int roll;
    float marks[3];
    float total;
    float percentage;
    char result[10];
};

int main() {
    struct Student s[MAX];
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for(i = 0; i < n; i++) {
        printf("\n Enter details for student %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        s[i].total = 0;

        for(j = 0; j < 3; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3;

        // Result calculation
        if(s[i].percentage >= 40)
            sprintf(s[i].result, "Pass");
        else
            sprintf(s[i].result, "Fail");
    }

    // Display student results
    printf("\n--- Student Results ---\n");

    for(i = 0; i < n; i++) {
        printf("\n Student %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Roll Number: %d\n", s[i].roll);
        printf("Total Marks: %.2f\n", s[i].total);
        printf("Percentage: %.2f\n", s[i].percentage);
        printf("Result: %s\n", s[i].result);
    }

    return 0;
}
