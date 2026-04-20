#include <stdio.h>

int main() {
    float marks[5];
    float total = 0, percentage;
    int i, pass = 1;

    // Input marks
    printf("Enter marks for 5 courses:\n");
    for(i = 0; i < 5; i++) {
        printf("Course %d: ", i + 1);
        scanf("%f", &marks[i]);

        if(marks[i] < 40) {
            pass = 0;   // Student fails if any mark is below 40
        }

        total += marks[i];
    }

    // Calculate percentage
    percentage = total / 5;

    // Display result
    if(pass == 0) {
        printf("\nResult: Fail\n");
    } else {
        printf("\nResult: Pass\n");
        printf("Aggregate Percentage: %.2f%%\n", percentage);

        if(percentage > 75) {
            printf("Grade: Distinction\n");
        }
        else if(percentage >= 60 && percentage < 75) {
            printf("Grade: First Division\n");
        }
        else if(percentage >= 50 && percentage < 60) {
            printf("Grade: Second Division\n");
        }
        else if(percentage >= 40 && percentage < 50) {
            printf("Grade: Third Division\n");
        }
    }

    return 0;
}
