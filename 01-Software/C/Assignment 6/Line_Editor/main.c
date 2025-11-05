#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define LINE_MAX_LENGTH 100
#define X_COLUMN 15
#define Y_ROW    15
#define UP  72
#define DOWN  80
#define RIGHT   77
#define LEFT   75
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27
#define BACK 8
#define DELETE 83

int main()
{
    char line[LINE_MAX_LENGTH];
    memset(line, ' ', LINE_MAX_LENGTH);
    line[LINE_MAX_LENGTH] = '\0';
    char ch_in;
    int curr_loc , min_loc , max_loc;
    curr_loc = 0;
    min_loc = 0;
    max_loc = 0;

    while(ch_in != '\r' && ch_in != ESC && max_loc < LINE_MAX_LENGTH){
        print_line(&line, X_COLUMN, Y_ROW);
        printf("\n\n%d",max_loc);
        printf("\n\n%d",curr_loc);
        gotoxy(X_COLUMN + curr_loc, Y_ROW);
        detect_pressed_button(&ch_in);
        check_char(&ch_in , &line , &curr_loc , &max_loc , min_loc);
    }

    clrscr();
    gotoxy(X_COLUMN, Y_ROW+1);
    printf("%s\n\n\n\n", line);

    return 0;
}

/*****************************____PRINT_LINE_FUNCTIONS____****************************/

void print_line(char* line, int x_column, int y_row)
{
    clrscr();
    textattr(0x60);
    gotoxy(x_column, y_row);
    printf("%s", line);
    textattr(0x07);
}

/************************____DETECT_PRESSED_BUTTON_FUNCTIONS____**********************/

void detect_pressed_button(char* ch_in)
{
       *ch_in = getche();
}

/*************************____CHECK_PRESSED_BUTTON_FUNCTIONS____**********************/

void check_char (char* ch_in , char* line , int* curr_loc , int* max_loc , int min_loc)
{
    switch (*ch_in){
        case  0 :
        case -32:
        case 224:
            check_ext (ch_in , line , curr_loc , max_loc , min_loc);
        break;
        default:
            check_nor(ch_in , line , curr_loc , max_loc);
        break;
    }

}

void check_nor(char* ch_in , char* line , int* curr_loc , int* max_loc)
{
    int i;
    switch (*ch_in){
        case ENTER:
        case ESC:
            (*curr_loc) = LINE_MAX_LENGTH; // to end the program
            (*max_loc)  = LINE_MAX_LENGTH; // to end the program
        break;
        case BACK:
            if (*curr_loc >0){
                if (*curr_loc == *max_loc){
                    line[*curr_loc-1] = ' ';
                    (*curr_loc)--;
                    (*max_loc)--;
                }
                else if (*curr_loc < *max_loc){
                    for (i = *curr_loc -1 ; i < *max_loc ; i++){
                        line[i] = line[i+1];
                    }
                    line[*max_loc -1] = ' ';
                    (*max_loc)--;
                    (*curr_loc)--;
                }
            }
        break;
        default:
            line[*curr_loc] = *ch_in;
            (*curr_loc)++;
            (*max_loc)++;
        break;
    }
}

void check_ext (char* ch_in , char* line , int* curr_loc , int* max_loc , int min_loc)
{
    char ch;
    ch = getch();
    switch(ch){
        case LEFT:
            if (*curr_loc > min_loc)
            {(*curr_loc)--;}
        break;
        case RIGHT:
            if ((*curr_loc) < (*max_loc))
            {(*curr_loc)++;}
        break;
        case HOME:
            (*curr_loc) = 0;
        break;
        case END:
            (*curr_loc) = *max_loc;
        break;
        case DELETE:
            if (*curr_loc < *max_loc){
                int i;
                for (i = *curr_loc ; i < *max_loc ; i++){
                    line[i] = line[i+1];
                }
                line[*max_loc -1] = ' ';
                (*max_loc)--;
            }
        break;
    }

}

/********************************____EXTRA_FUNCTIONS____******************************/

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

void end_prog()
{
    exit(0);
}
