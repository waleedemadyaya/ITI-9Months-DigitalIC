#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define UP  72
#define DOWN  80
#define RIGHT   77
#define LEFT   75
#define HOME 71
#define END 79
#define TAB 9
#define ENTER 13
#define ESC 27



void gotoxy(int x, int y);
void clrscr();
void textattr(int ForgC);
void SetColor(int ForgC);
void print_menu ();

char menu [3][8] = {"New" , "Display" , "Exit"};
int curr = 0;
char ch = '\0';

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

void print_menu ()
{
    clrscr();
    int i;
    printf("\t\t\t\t\t\t\t Main Menu \t\t\t\t\t\t\t");
    for (i = 0 ; i < 3 ; i++)
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
        curr = 2;
    else if (curr>2)
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
            curr = 2;
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
        case 0:
            clrscr();
            printf("This is new screen...\nPress any button to go home.\n");
            getch();
        break;
        case 1:
            clrscr();
            printf("This is display screen...\nPress any button to go home.\n");
            getch();
        break;
        case 2:
            exit(0);
        break;
    }

}


