/*****************************************************************************/
///My Documentation for the second assignment in C during 9 month DIC in ITI///
///_____________________________Magic Box Assignment________________________///
/// Date: 26/10/2025
/// Time: 4:57 PM
/// Location: ITI main branch Smart Village.
/*****************************************************************************/

/*****************************************************************************/
///Preprocessor (Linking) Part
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*****************************************************************************/

/*****************************************************************************/
/// Definitions

/*****************************************************************************/

/*****************************************************************************/
///Global Declaration and functions
int size = 3;
int line_number = 1;

int scan_odd_number ( );
int check_scanned_number ( );
int delay_seconds (float seconds);
void gotoxy(int x, int y);
int generate_magicbox (int size);

/*****************************************************************************/

/*****************************************************************************/
///Main program

int main()
{
    scan_odd_number ( );
    generate_magicbox(size);
    return 0;
}
/*****************************************************************************/

/*****************************************************************************/
///Subprograms

int scan_odd_number ( )
{
    printf("Please enter odd number (1,3,5,..): ");
    line_number++;
    scanf("%d",&size);
    check_scanned_number();
    return 0;
}

int check_scanned_number ( )
{
    if ( (size % 2) == 0)
    {
        scan_odd_number( );
    }
    return 0;
}

int delay_seconds (float seconds)
{
    Sleep(seconds * 1000); //converting seconds into milliseconds
}

void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x*5;
    coordinate.Y = y*3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

int generate_magicbox (int size)
{
    int row, col;
    int i;
    row = 1;
    col = (size / 2) + 1;

    for (i = 1 ; i <= size*size ; i++)
    {
        delay_seconds (0.5);
        if (i == 1){
            gotoxy(col, row);
            printf("%d",i);
        } else if ((i-1) % size == 0){
            row++;
            while (row<=0){
                row+=size;
            }
            while (row>size){
                row-=size;
            }
            gotoxy(col, row);
            printf("%d",i);
        } else{
            row--;
            col--;
            while (row<=0){
                row+=size;
            }
            while (col<=0){
                col+=size;
            }
            while (row>size){
                row-=size;
            }
            while (col>size){
                col-=size;
            }
            gotoxy(col, row);
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}
/*****************************************************************************/
