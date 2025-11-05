#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define UP  72
#define DOWN  80
#define TAB 9
#define RIGHT   77
#define LEFT   75

#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27

#define MENU_ELEMENTS 8
#define MAX_EMP 50
#define New 0
#define New_Index 1
#define Display_Index 2
#define Display 3
#define Display_All 4
#define Delete 5
#define Delete_All 6
#define Exit 7


void gotoxy(int x, int y);
void clrscr();
void textattr(int ForgC);
void SetColor(int ForgC);
void print_menu ();
struct Employee AddNewEmployee();
void DisplayEmployee(struct Employee emp);

char menu [MENU_ELEMENTS][100] = {"New" , "New Index" , "Display Index" , "Display" , "Display All" , "Delete" , "Delete All" , "Exit"};
int curr = 0;
char ch = '\0';
int emp_ind = 0;
int disp_ind, del_ind = 0;
int new_ind = 0;

struct Employee
{
    int id;
    char name[50];
    float salary;
    float bonus;
    float deduction;
};

struct Employee emp[MAX_EMP];
int Employee_IDs[MAX_EMP];
int Employee_INDEX[MAX_EMP];

int main()
{
    while(1)
    {
        print_menu();
        getcharacter();
        check_char();
    }

    return 0;
}

/***************************************************************************************************************************************/
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void clrscr()
{
    system("cls");
    textattr(0x07);
}

void textattr(int ForgC)
{
    //system("COLOR ForgC"); //system("COLOR FC");
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ForgC);
}

void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
/***************************************************************************************************************************************/
void print_menu ()
{
    clrscr();
    int i;
    printf("\t\t\t\t\t\t\t Main Menu \t\t\t\t\t\t\t");
    for (i = 0 ; i < MENU_ELEMENTS ; i++)
    {
        if (i == curr){
            textattr(0x30);
        }else{
            textattr(0x07);
        }
        gotoxy(3,3+(i*3));
        printf("%s",menu[i]);
    }
    textattr(0x07);
}
/***************************************************************************************************************************************/
void getcharacter()
{
    ch = getch();
}

void check_char()
{
    switch (ch){
        case  0 :
        case -32:
        case 224:
            check_ext();
        break;
        default:
            check_nor();
        break;
    }

}

void check_curr()
{
    if (curr<0)
        curr = MENU_ELEMENTS - 1;
    else if (curr > MENU_ELEMENTS - 1)
        curr = 0;
}

void check_ext()
{
    getcharacter();
        switch(ch){
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

void end_prog()
{
    exit(0);
}

void check_nor()
{
    switch(ch){
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

void view_details()
{
    switch(curr){
        case New:
            clrscr();
            emp[emp_ind] = AddNewEmployee();
            Employee_IDs[emp_ind] = emp[emp_ind].id;
            emp_ind++;
            printf("\n\nPress any button to go home.\n\n");
            getch();
        break;
        case New_Index:
            clrscr();
            new_ind = check_index();
            printf("\n\nPress any button to go home.\n\n");
            getch();
        break;
        case Display_Index:
            break;
        case Display:
            clrscr();
            disp_ind = check_emp_ind();
            if (disp_ind != -1){
             DisplayEmployee(emp[disp_ind]);
            }
            printf("\n\nPress any button to go home.\n");
            getch();
        break;
        case Display_All:
            clrscr();
            Display_All_Employee();
            printf("\n\nPress any button to go home.\n");
            getch();
        break;
        case Delete:
            clrscr();
            del_ind = check_emp_ind();
            DeleteEmployee(del_ind);
            printf("\n\nPress any button to go home.\n");
            getch();
        break;
        case Delete_All:
            clrscr();
            DeleteAllEmployees( );
            printf("\n\nPress any button to go home.\n");
            getch();
        break;
        case Exit:
            exit(0);
        break;
    }

}

struct Employee AddNewEmployee()
{
    struct Employee emp;

    emp.id = check_added_emp_ind ();

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

int check_emp_ind()
{

    int ind = 0;
    int emp_id = -1;
    printf("\nEnter a valid employee ID pleas: ");
    _flushall();
    scanf("%d",&emp_id);

    for(ind=0; ind<emp_ind ; ind++)
    {
        if (Employee_IDs[ind] == emp_id){
            return ind;
        }
    }
    printf("\nInvalid employee ID.");
    return -1;
}


int check_added_emp_ind()
{

    int ind = 0;
    int emp_id = -1;
    int valid = 0;
    while(!valid)
    {
        printf("\nEnter a valid employee ID pleas: ");
        _flushall();
        scanf("%d",&emp_id);

        valid = 1;
        for(ind=0; ind<emp_ind ; ind++)
        {
            if (Employee_IDs[ind] == emp_id){
                printf("\nInvalid employee ID.\n");
                valid = 0;
                break;
            }
        }
    }
    return emp_id;

}

void Display_All_Employee()
{
    int i = 0;
    for (i=0;i<emp_ind;i++)
    {
        DisplayEmployee(emp[i]);
        printf("\n_______________________________________________________________\n\n");
    }
}

void DeleteEmployee(int ind)
{
    int i = 0;
    for (i = ind ; i < emp_ind ; i++)
    {
        emp[i] = emp [i+1];
        Employee_IDs[i] = Employee_IDs[i+1];
    }
    emp_ind--;
}

void DeleteAllEmployees( )
{
    emp_ind = 0;
}

int check_index(){
    int ind = 0;
    int in_emp_ind = -1;
    do{
        printf("\nEnter a valid employee INDEX pleas: ");
        _flushall();
        scanf("%d",&in_emp_ind);

        if (in_emp_ind < emp_ind){
            printf("\nInvalid employee ID.");
        } else {
            emp[in_emp_ind] = AddNewEmployee();
        }

    }while (in_emp_ind != -1);

}
