#include <stdio.h>
#include <stdlib.h>

#define Max 100

int main()
{
    int row = 0;
    int col = 0;
    int row_ind, col_ind;
    float Array1[Max][Max];
    float Array2[Max][Max];
    float Array3[Max][Max];
    printf("_________________Assignment3 -- Task 5 _________________");

    printf("\nEnter number of rows please (Maximum size = 100): ");
    scanf("%d",&row);
    printf("\nEnter number of cols please (Maximum size = 100): ");
    scanf("%d",&col);

    ///Scan the first array
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("\nEnter The Element Array1[%d][%d]: ",row_ind, col_ind);
            scanf("%f",&Array1[row_ind][col_ind]);
        }
    }
    ///Scan the second array
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("\nEnter The Element Array2[%d][%d]: ",row_ind, col_ind);
            scanf("%f",&Array2[row_ind][col_ind]);
        }
    }
    ///calculated the third array
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            Array3[row_ind][col_ind] = Array1[row_ind][col_ind] + Array2[row_ind][col_ind];
        }
    }

    ///print the summation array
    printf("\nThe summation of the two arrays is:\n");
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("%0.2f\t",Array3[row_ind][col_ind]);
        }
        printf("\n");
    }


    return 0;
}
