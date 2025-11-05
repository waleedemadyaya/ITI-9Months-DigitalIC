#include <stdio.h>
#include <stdlib.h>

#define Max 100

int main()
{
    int row = 0;
    int col = 0;
    int row_ind, col_ind;
    float Array[Max][Max];
    printf("_________________Assignment3 -- Task 1 _________________");
    printf("\nEnter number of rows please (Maximum size = 100): ");
    scanf("%d",&row);
    printf("\nEnter number of cols please (Maximum size = 100): ");
    scanf("%d",&col);

    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("\nEnter The Element Array[%d][%d]: ",row_ind+1, col_ind+1);
            scanf("%f",&Array[row_ind][col_ind]);
        }
    }
    printf("\nYou have entered the following Array:\n");
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("%0.2f\t",Array[row_ind][col_ind]);
        }
        printf("\n");
    }
    return 0;
}
