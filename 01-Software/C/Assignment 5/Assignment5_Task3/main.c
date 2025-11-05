#include <stdio.h>
#include <stdlib.h>
#define MAX_EMP 5

struct Employee
{
    int id;
    char name[50];
    float salary;
    float bonus;
    float deduction;
};

int main()
{
    struct Employee emp[MAX_EMP];
    int i;

    for (i = 0; i < MAX_EMP; i++)
    {
        printf("\nEnter Employee %d ID: ", i + 1);
        scanf("%d", &emp[i].id);

        _flushall();
        printf("Enter Employee %d Name: ", i + 1);
        gets(emp[i].name);

        _flushall();
        printf("Enter Salary, Bonus, and Deduction separated by space: ");
        scanf("%f %f %f", &emp[i].salary, &emp[i].bonus, &emp[i].deduction);
    }

    printf("\n\n--- Employee Information ---\n");
    for (i = 0; i < MAX_EMP; i++)
    {
        float net = emp[i].salary + emp[i].bonus - emp[i].deduction;
        printf("\nID: %d", emp[i].id);
        printf("\nName: %s", emp[i].name);
        printf("\nNet Salary: %.2f\n", net);
    }

    return 0;
}
