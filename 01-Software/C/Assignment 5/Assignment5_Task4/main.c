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

struct Employee AddNewEmployee()
{
    struct Employee emp;

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

    return emp;
}

void DisplayEmployee(struct Employee emp)
{
    float net = emp.salary + emp.bonus - emp.deduction;
    printf("\nEmployee ID: %d", emp.id);
    printf("\nEmployee Name: %s", emp.name);
    printf("\nNet Salary: %.2f\n", net);
}

int main()
{
    struct Employee e = AddNewEmployee();
    DisplayEmployee(e);
    return 0;
}
