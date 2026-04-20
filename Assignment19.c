#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    char designation[50];
    char gender;
    char doj[20];
    float salary;
};

int main() {
    struct Employee e[100];
    int n, i;
    int male = 0, female = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i+1);

        printf("Name: ");
        scanf("%s", e[i].name);

        printf("Designation: ");
        scanf("%s", e[i].designation);

        printf("Gender (M/F): ");
        scanf(" %c", &e[i].gender);

        printf("Date of Joining: ");
        scanf("%s", e[i].doj);

        printf("Salary: ");
        scanf("%f", &e[i].salary);
    }

    // a) Total employees
    printf("\nTotal employees = %d\n", n);

    // b) Count male & female
    for(i = 0; i < n; i++) {
        if(e[i].gender == 'M' || e[i].gender == 'm')
            male++;
        else
            female++;
    }

    printf("Male = %d, Female = %d\n", male, female);

    // c) Salary > 10000
    printf("\nEmployees with salary > 10000:\n");
    for(i = 0; i < n; i++) {
        if(e[i].salary > 10000)
            printf("%s\n", e[i].name);
    }

    // d) Asst Manager
    printf("\nEmployees with designation Asst Manager:\n");
    for(i = 0; i < n; i++) {
        if(strcmp(e[i].designation, "Asst") == 0)
            printf("%s\n", e[i].name);
    }

    return 0;
}
