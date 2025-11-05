#include <stdio.h>
#include <stdlib.h>

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
    struct Employee emp;
    float net;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    _flushall();
    printf("Enter Employee Name: ");
    gets(emp.name);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    printf("Enter Bonus: ");
    scanf("%f", &emp.bonus);

    printf("Enter Deduction: ");
    scanf("%f", &emp.deduction);

    net = emp.salary + emp.bonus - emp.deduction;

    printf("\nEmployee ID: %d", emp.id);
    printf("\nEmployee Name: %s", emp.name);
    printf("\nNet Salary: %.2f\n", net);

    return 0;
}
