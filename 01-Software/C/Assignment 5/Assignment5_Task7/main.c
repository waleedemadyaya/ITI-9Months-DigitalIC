#include <stdio.h>
#include <stdlib.h>
#define MAX_EMP 3

struct Employee
{
    int ID;
    char Name[50];
    float Salary;
    float Bonus;
    float Deduction;
};

struct Department
{
    int Dept_ID;
    char Dept_Name[50];
    struct Employee EmpList[MAX_EMP];
};

int main()
{
    struct Department dept;
    int i;
    float NetSalary;

    printf("Enter Department ID: ");
    _flushall();
    scanf("%d", &dept.Dept_ID);

    printf("Enter Department Name: ");
    _flushall();
    gets (dept.Dept_Name);

    printf("\nEnter data of %d Employees for Department %s:\n", MAX_EMP, dept.Dept_Name);

    for (i = 0; i < MAX_EMP; i++)
    {
        printf("\nEmployee #%d\n", i + 1);

        printf("Enter Employee ID: ");
        _flushall();
        scanf("%d", &dept.EmpList[i].ID);

        printf("Enter Employee Name: ");
        _flushall();
        gets (dept.EmpList[i].Name);

        printf("Enter Salary: ");
        _flushall();
        scanf("%f", &dept.EmpList[i].Salary);

        printf("Enter Bonus: ");
        _flushall();
        scanf("%f", &dept.EmpList[i].Bonus);

        printf("Enter Deduction: ");
        _flushall();
        scanf("%f", &dept.EmpList[i].Deduction);
    }

    printf("\n\n==================== Department Summary ====================\n");
    printf("Department ID: %d\nDepartment Name: %s\n", dept.Dept_ID, dept.Dept_Name);
    printf("------------------------------------------------------------\n");

    for (i = 0; i < MAX_EMP; i++)
    {
        NetSalary = dept.EmpList[i].Salary + dept.EmpList[i].Bonus - dept.EmpList[i].Deduction;
        printf("Emp ID: %d\tName: %s\tNet Salary: %.2f\n",
               dept.EmpList[i].ID, dept.EmpList[i].Name, NetSalary);
    }

    printf("============================================================\n");

    return 0;
}
