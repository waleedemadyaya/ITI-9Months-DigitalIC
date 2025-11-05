#include <stdio.h>
#include <stdlib.h>

#define Max 100

int main()
{
    int row = 0;
    int col = 0;
    int row_ind, col_ind;
    float Array[Max][Max];
    float min_val , max_val;
    min_val = 0.0;
    max_val = 0.0;

    printf("_________________Assignment3 -- Task 2 _________________");

    printf("\nEnter number of rows please (Maximum size = 100): ");
    scanf("%d",&row);
    printf("\nEnter number of cols please (Maximum size = 100): ");
    scanf("%d",&col);

    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("\nEnter The Element Array[%d][%d]: ",row_ind, col_ind);
            scanf("%f",&Array[row_ind][col_ind]);
        }
    }

    min_val = Array[0][0];
    max_val = Array[0][0];

    printf("\nYou have entered the following Array:\n");
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("%0.2f\t",Array[row_ind][col_ind]);
        }
        printf("\n");
    }

    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            if (Array[row_ind][col_ind] > max_val)
            {
                max_val = Array[row_ind][col_ind];
            }
            if (Array[row_ind][col_ind] < min_val)
            {
                min_val = Array[row_ind][col_ind];
            }
    }
    }

    printf("\nThe minimum value in your array is : %0.2f",min_val);
    printf("\nThe maximum value in your array is : %0.2f",max_val);


    return 0;
}
