#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define UP  72
#define DOWN  80
#define RIGHT   77
#define LEFT   75
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27
#define Row_START 10
#define COL_START 10
#define MAX_SIZE 100
#define Min_LOC 0
#define Max_LOC 99


int main()
{
    char line[MAX_SIZE+1];
    memset(line, 'a', MAX_SIZE);
    line[MAX_SIZE] = '\0';

    int curr_loc = Min_LOC;

    print_line(&line);
    gotoxy(COL_START, Row_START);
    check_char(&curr_loc);
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

void print_line(char* line)
{
    gotoxy(COL_START , Row_START);
    textattr(0x70);
    printf("%s", line);
    textattr(0x07);
}

void getcharacter(char* ch)
{
    *ch = getch();
}


void check_char(int* curr_loc)
{
    char ch;
    getcharacter(&ch);
    switch (ch){
        case  0 :
        case -32:
        case 224:
            check_ext(curr_loc);
        break;
        default:
            check_nor(curr_loc);
        break;
    }

}


void check_ext(int* curr_loc)
{
    char ch;
    getcharacter(&ch);
        switch(ch){
            case UP:
            case LEFT:
                if (*curr_loc > Min_LOC)
                {*curr_loc--;}
            break;
            case DOWN:
            case RIGHT:
                if (*curr_loc < Max_LOC)
                {*curr_loc++;}
            break;
            case HOME:
                *curr_loc = 0;
            break;
            case END:
                end_prog();
            break;
        }

}


void check_nor(int* curr_loc , char* line)
{
    char ch;
    getcharacter(&ch);
    switch(ch){
        case ENTER:
        case ESC:
            gotoxy(COL_START , Row_START+2);
            printf("%s", line);
        break;
        default:
            line[*curr_loc] = ch;
        break;
    }
}

void end_prog()
{
    exit(0);
}
