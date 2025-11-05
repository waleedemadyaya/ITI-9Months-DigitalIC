#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LINE_MAX_LENGTH 100
#define X_COLUMN 15
#define Y_ROW    1
#define UP  72
#define DOWN  80
#define RIGHT   77
#define LEFT   75
#define HOME 71
#define END 79
#define PGUP 73
#define PGDN 81
#define ENTER 13
#define ESC 27
#define BACK 8
#define DELETE 83
#define INSERT 82

/***************************** FUNCTION DECLARATIONS ****************************/
void print_boxed_line(char** lines, int line_num, int x_column, int y_row);
void print_line(char* line, int x_column, int y_row);
void detect_pressed_button(char* ch_in);
void check_char(char* ch_in, int* curr_row, int line_num, int* curr_col, int* max_col, char** lines, int* insert, int line_length , int* esc);
void check_nor(char* ch_in, int* curr_row, int line_num, int* curr_col, int* max_col, char** lines, int* insert, int line_length , int* esc);
void check_ext(char* ch_in, int* curr_row, int line_num, int* curr_col, int* max_col, char** lines, int* insert, int line_length);
void gotoxy(int x, int y);
void clrscr(void);
void textattr(int ForgC);
void SetColor(int ForgC);
void end_prog(char** lines, int line_num);


int max_row = 0;
/***************************** MAIN ****************************/
int main()
{
    int i;

    int line_num;
    printf("Enter number of lines:\n");
    scanf("%d", &line_num);

    int line_length;
    printf("Enter line length:\n");
    scanf("%d", &line_length);

    char** lines = (char**) malloc(line_num * sizeof(char*));
    for(i = 0; i < line_num; i++) {
        lines[i] = (char*) malloc((line_length + 1) * sizeof(char));
        memset(lines[i], ' ', line_length);
        lines[i][line_length] = '\0';
    }

    char ch_in;
    int* curr_col = (int*) calloc(line_num, sizeof(int));
    int* max_col = (int*) calloc(line_num, sizeof(int));
    int curr_row = 0;
    int insert = 0;
    int esc = 0;

    while (esc != 1) {
        print_boxed_line(lines, line_num, X_COLUMN, Y_ROW);
        gotoxy(X_COLUMN + curr_col[curr_row], Y_ROW + curr_row);
        detect_pressed_button(&ch_in);
        check_char(&ch_in, &curr_row, line_num, curr_col, max_col, lines, &insert, line_length , &esc);
    }
    end_prog (lines , line_num);
    for(i = 0; i < line_num; i++)
        free(lines[i]);
    free(lines);

    return 0;
}

/***************************** PRINT FUNCTIONS ****************************/
void print_boxed_line(char** lines, int line_num, int x_column, int y_row)
{
    int i;
    clrscr();
    for(i = 0; i < line_num; i++)
        print_line(lines[i], x_column, y_row + i);
}

void print_line(char* line, int x_column, int y_row)
{
    textattr(0x60);
    gotoxy(x_column, y_row);
    printf("%s", line);
    textattr(0x07);
}

/***************************** INPUT DETECTION ****************************/
void detect_pressed_button(char* ch_in)
{
    *ch_in = getch();
}

/***************************** CHARACTER CHECK ****************************/
void check_char(char* ch_in, int* curr_row, int line_num, int* curr_col, int* max_col, char** lines, int* insert, int line_length , int* esc)
{
    switch (*ch_in) {
        case 0:
        case -32:
        case 224:
            check_ext(ch_in, curr_row, line_num, curr_col, max_col, lines, insert, line_length);
            break;
        default:
            check_nor(ch_in, curr_row, line_num, curr_col, max_col, lines, insert, line_length , esc);
            break;
    }
}

/***************************** NORMAL CHAR CHECK ****************************/
void check_nor(char* ch_in, int* curr_row, int line_num, int* curr_col, int* max_col, char** lines, int* insert, int line_length, int* esc)
{
    int i;

    switch (*ch_in) {
        case ENTER:
            if ((*curr_row) < line_num - 1 && max_row < line_num - 1) {
                if ((*curr_row) == max_row)
                {
                    max_row++;
                }
                (*curr_row)++;
                for (i = line_num - 1; i > *curr_row; i--)
                {
                    strcpy(lines[i], lines[i - 1]);
                    max_col[i] = max_col[i - 1];
                    curr_col[i] = curr_col[i - 1];
                }
                memset(lines[*curr_row], ' ', line_length);
                max_col[*curr_row] = 0;
                curr_col[*curr_row] = 0;

            }
            break;

        case ESC:
            *esc = 1;
            break;

        case BACK:
            if (curr_col[*curr_row] ==  0) {
                if ((*curr_row) == max_row)
                    max_row--;
                (*curr_row)--;
                curr_col[*curr_row] = max_col[*curr_row];
            } else if (curr_col[*curr_row] > 0) {
                if (curr_col[*curr_row] == max_col[*curr_row]) {
                    lines[*curr_row][curr_col[*curr_row] - 1] = ' ';
                    curr_col[*curr_row]--;
                    max_col[*curr_row]--;
                } else {
                    for (i = curr_col[*curr_row] - 1; i < max_col[*curr_row]; i++)
                        lines[*curr_row][i] = lines[*curr_row][i + 1];
                    lines[*curr_row][max_col[*curr_row] - 1] = ' ';
                    curr_col[*curr_row]--;
                    max_col[*curr_row]--;
                }
            }
            break;

        default:
            if (curr_col[*curr_row] > line_length - 1 && (*curr_row) < line_num - 1) {
                if ((*curr_row) == max_row)
                    max_row++;
                (*curr_row)++;
                curr_col[*curr_row] = 0;
                gotoxy(X_COLUMN + curr_col[*curr_row], Y_ROW + *curr_row);
            }
            if (*insert && curr_col[*curr_row] < line_length - 1 && max_col[*curr_row] < line_length) {
                for (i = max_col[*curr_row]; i > curr_col[*curr_row]; i--)
                    lines[*curr_row][i] = lines[*curr_row][i - 1];
                lines[*curr_row][curr_col[*curr_row]] = *ch_in;
                curr_col[*curr_row]++;
                max_col[*curr_row]++;
            } else if (curr_col[*curr_row] < line_length) {
                lines[*curr_row][curr_col[*curr_row]] = *ch_in;
                curr_col[*curr_row]++;
                if (curr_col[*curr_row] > max_col[*curr_row])
                    max_col[*curr_row] = curr_col[*curr_row];
            }
            break;
    }
}

/***************************** EXTENDED KEYS ****************************/
void check_ext(char* ch_in, int* curr_row, int line_num, int* curr_col, int* max_col, char** lines, int* insert, int line_length)
{
    char ch = getch();
    switch (ch) {
        case LEFT:
            if (curr_col[*curr_row] > 0)
                curr_col[*curr_row]--;
            else{
                (*curr_row)--;
                curr_col[*curr_row] = max_col[*curr_row];
            }
            break;
        case RIGHT:
            if (curr_col[*curr_row] < max_col[*curr_row])
                curr_col[*curr_row]++;
            else{
                (*curr_row)++;
                curr_col[*curr_row] = 0;
            }
            break;
        case UP:
            if (*curr_row > 0)
                (*curr_row)--;
            if (max_col[*curr_row] > curr_col [(*curr_row) + 1])
                curr_col[*curr_row] = curr_col [(*curr_row)+1];
            else
                curr_col[*curr_row] = max_col [*curr_row];
            break;
        case DOWN:
            if (*curr_row < line_num - 1)
                (*curr_row)++;
            if (max_col[*curr_row] > curr_col [(*curr_row) - 1])
                curr_col[*curr_row] = curr_col [(*curr_row)-1];
            else
                curr_col[*curr_row] = max_col [*curr_row];
            break;
        case HOME:
            curr_col[*curr_row] = 0;
            break;
        case END:
            curr_col[*curr_row] = max_col[*curr_row];
            break;
        case DELETE:
            if (curr_col[*curr_row] < max_col[*curr_row]) {
                int i;
                for (i = curr_col[*curr_row]; i < max_col[*curr_row]; i++)
                    lines[*curr_row][i] = lines[*curr_row][i + 1];
                lines[*curr_row][max_col[*curr_row] - 1] = ' ';
                max_col[*curr_row]--;
            }
            break;
        case INSERT:
            *insert ^= 1;
            break;
        case PGUP:
            *curr_row = 0;
            curr_col[*curr_row] = 0;
            break;
        case PGDN:
            *curr_row = max_row;
            curr_col[*curr_row] = max_col[*curr_row];
            break;
    }
}

/***************************** UTILITY FUNCTIONS ****************************/
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void clrscr(void)
{
    system("cls");
    textattr(0x07);
}

void textattr(int ForgC)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ForgC);
}

void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void end_prog(char** lines, int line_num)
{
    print_boxed_line_final(lines, line_num, X_COLUMN, Y_ROW);
    exit(0);
}

/***************************** PRINT FUNCTIONS ****************************/
void print_boxed_line_final(char** lines, int line_num, int x_column, int y_row)
{
    int i;
    clrscr();
    for(i = 0; i < line_num; i++)
        print_line_final(lines[i], x_column, y_row + i);
}

void print_line_final(char* line, int x_column, int y_row)
{
    textattr(0x07);
    gotoxy(x_column, y_row);
    printf("%s", line);
    textattr(0x07);
}
