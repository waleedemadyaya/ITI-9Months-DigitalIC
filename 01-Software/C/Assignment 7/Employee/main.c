#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define TAB 9
#define RIGHT 77
#define LEFT 75
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27

#define MENU_ELEMENTS 8
#define New 0
#define New_Index 1
#define Display_Index 2
#define Display 3
#define Display_All 4
#define Delete 5
#define Delete_All 6
#define Exit 7

// Function declarations
void gotoxy(int x, int y);
void clrscr();
void textattr(int ForgC);
void print_menu();
void getcharacter();
void check_char();
void check_ext();
void check_nor();
void check_curr();
void view_details();
void end_prog();

struct Employee AddNewEmployee();
void DisplayEmployee(struct Employee emp);
int check_emp_ind();
int check_added_emp_ind();
void Display_All_Employee();
void DeleteEmployee(int ind);
void DeleteAllEmployees();
int check_index();

char menu[MENU_ELEMENTS][100] = {
    "New", "New Index", "Display Index", "Display",
    "Display All", "Delete", "Delete All", "Exit"
};

int curr = 0;
char ch = '\0';
int emp_ind = 0;
int disp_ind = 0, del_ind = 0, new_ind = 0;
int EMP_SIZE = 0;  // dynamic size

struct Employee {
    int id;
    char name[50];
    float salary;
    float bonus;
    float deduction;
    int isFilled;
};

struct Employee* emp = NULL;
int* Employee_IDs = NULL;

/***************************************************************************************************************************************/
int main() {
    int i;
    printf("Enter the number of employees to allocate: ");
    scanf("%d", &EMP_SIZE);

    emp = (struct Employee*) malloc(EMP_SIZE * sizeof(struct Employee));
    Employee_IDs = (int*) malloc(EMP_SIZE * sizeof(int));

    if (emp == NULL || Employee_IDs == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < EMP_SIZE; i++) {
        emp[i].isFilled = 0;
        Employee_IDs[i] = 0;
    }

    while (1) {
        print_menu();
        getcharacter();
        check_char();
    }

    free(emp);
    free(Employee_IDs);
    return 0;
}

/***************************************************************************************************************************************/
void gotoxy(int x, int y) {
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void clrscr() {
    system("cls");
    textattr(0x07);
}

void textattr(int ForgC) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ForgC);
}

/***************************************************************************************************************************************/
void print_menu() {
    clrscr();
    int i;
    printf("\t\t\t\t Main Menu \t\t\t\t\n\n");
    for (i = 0; i < MENU_ELEMENTS; i++) {
        if (i == curr)
            textattr(0x30);
        else
            textattr(0x07);
        gotoxy(3, 3 + (i * 2));
        printf("%s", menu[i]);
    }
    textattr(0x07);
}

/***************************************************************************************************************************************/
void getcharacter() {
    ch = getch();
}

void check_char() {
    switch (ch) {
        case 0:
        case -32:
        case 224:
            check_ext();
            break;
        default:
            check_nor();
            break;
    }
}

void check_curr() {
    if (curr < 0)
        curr = MENU_ELEMENTS - 1;
    else if (curr > MENU_ELEMENTS - 1)
        curr = 0;
}

void check_ext() {
    getcharacter();
    switch (ch) {
        case UP:
        case LEFT:
            curr--;
            check_curr();
            break;
        case DOWN:
        case RIGHT:
            curr++;
            check_curr();
            break;
        case HOME:
            curr = 0;
            break;
        case END:
            end_prog();
            break;
    }
}

void end_prog() {
    free(emp);
    free(Employee_IDs);
    exit(0);
}

void check_nor() {
    switch (ch) {
        case ESC:
            curr = MENU_ELEMENTS - 1;
            break;
        case TAB:
            curr++;
            check_curr();
            break;
        case ENTER:
            view_details();
            break;
    }
}

/***************************************************************************************************************************************/
void view_details() {
    switch (curr) {
        case New:
            clrscr();
            if (emp_ind < EMP_SIZE) {
                emp[emp_ind] = AddNewEmployee();
                Employee_IDs[emp_ind] = emp[emp_ind].id;
                emp[emp_ind].isFilled = 1;
                printf("\nEmployee added successfully!\n");
                printf("\n---------------------------------\n");
                printf("Added Employee Details:\n");
                DisplayEmployee(emp[emp_ind]);
                printf("---------------------------------\n");
                emp_ind++;
            } else {
                printf("\nNo more space to add employees!\n");
            }
            printf("\nPress any key to return to menu...");
            getch();
            break;

        case New_Index:
            clrscr();
            check_index();
            printf("\nPress any key to return to menu...");
            getch();
            break;

        case Display:
            clrscr();
            disp_ind = check_emp_ind();
            if (disp_ind != -1)
                DisplayEmployee(emp[disp_ind]);
            printf("\nPress any key to return...");
            getch();
            break;

        case Display_All:
            clrscr();
            Display_All_Employee();
            printf("\nPress any key to return...");
            getch();
            break;

        case Delete:
            clrscr();
            del_ind = check_emp_ind();
            if (del_ind != -1)
                DeleteEmployee(del_ind);
            printf("\nPress any key to return...");
            getch();
            break;

        case Delete_All:
            clrscr();
            DeleteAllEmployees();
            printf("\nAll employees deleted.\n");
            printf("\nPress any key to return...");
            getch();
            break;

        case Exit:
            end_prog();
            break;
    }
}

/***************************************************************************************************************************************/
struct Employee AddNewEmployee() {
    struct Employee emp1;
    emp1.id = check_added_emp_ind();

    printf("Enter Employee Name: ");
    fflush(stdin);
    fgets(emp1.name, sizeof(emp1.name), stdin);
    emp1.name[strcspn(emp1.name, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp1.salary);

    printf("Enter Bonus: ");
    scanf("%f", &emp1.bonus);

    printf("Enter Deduction: ");
    scanf("%f", &emp1.deduction);

    emp1.isFilled = 1;
    return emp1;
}

/***************************************************************************************************************************************/
void DisplayEmployee(struct Employee emp) {
    float net = emp.salary + emp.bonus - emp.deduction;
    printf("\nEmployee ID: %d", emp.id);
    printf("\nEmployee Name: %s", emp.name);
    printf("\nNet Salary: %.2f\n", net);
}

/***************************************************************************************************************************************/
int check_emp_ind() {
    int emp_id = -1;
    printf("Enter Employee ID: ");
    scanf("%d", &emp_id);
    int i;

    for (i = 0; i < emp_ind; i++) {
        if (Employee_IDs[i] == emp_id && emp[i].isFilled)
            return i;
    }

    printf("\nEmployee not found!\n");
    return -1;
}

/***************************************************************************************************************************************/
int check_added_emp_ind() {
    int emp_id = -1, valid = 0;
    int i;

    while (!valid) {
        printf("Enter Employee ID: ");
        scanf("%d", &emp_id);
        valid = 1;
        for (i = 0; i < emp_ind; i++) {
            if (Employee_IDs[i] == emp_id && emp[i].isFilled) {
                printf("ID already exists! Try again.\n");
                valid = 0;
                break;
            }
        }
    }
    return emp_id;
}

/***************************************************************************************************************************************/
void Display_All_Employee() {
    int count = 0;
    int i;

    printf("Displaying All Added Employees:\n");
    printf("=================================\n");

    for (i = 0; i < EMP_SIZE; i++) {
        if (emp[i].isFilled) {
            printf("\n[Index %d] --------------------\n", i);
            DisplayEmployee(emp[i]);
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo employees have been added yet.\n");
    }
}

/***************************************************************************************************************************************/
void DeleteEmployee(int ind) {
    if (ind < 0 || ind >= EMP_SIZE) return;


    emp[ind].isFilled = 0;
    Employee_IDs[ind] = 0;
    printf("\nEmployee deleted successfully!\n");
}

void DeleteAllEmployees() {
    int i;
    for (i = 0; i < EMP_SIZE; i++) {
        emp[i].isFilled = 0;
        Employee_IDs[i] = 0;
    }
    emp_ind = 0;
}

/***************************************************************************************************************************************/
int check_index() {
    int in_emp_ind = 0;

    while (1) {
        printf("\nEnter Employee INDEX to input (-1 to stop): ");
        scanf("%d", &in_emp_ind);

        if (in_emp_ind == -1)
            break;

        if (in_emp_ind < 0 || in_emp_ind >= EMP_SIZE) {
            printf("Invalid index!\n");
            continue;
        }

        if (emp[in_emp_ind].isFilled) {
            printf("This location (%d) already has an employee!\n", in_emp_ind);
        } else {
            emp[in_emp_ind] = AddNewEmployee();
            emp[in_emp_ind].isFilled = 1;
            Employee_IDs[in_emp_ind] = emp[in_emp_ind].id;
            if (in_emp_ind >= emp_ind)
                emp_ind = in_emp_ind + 1;
            printf("Employee added successfully at index %d!\n", in_emp_ind);
            printf("\n---------------------------------\n");
            printf("Added Employee Details:\n");
            DisplayEmployee(emp[in_emp_ind]);
            printf("---------------------------------\n");
        }
    }
    return 0;
}
