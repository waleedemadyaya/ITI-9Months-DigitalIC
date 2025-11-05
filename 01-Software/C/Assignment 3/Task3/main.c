#include <stdio.h>
#include <stdlib.h>

#define Max 100

int main()
{
    int row = 0;
    int col = 0;
    int row_ind, col_ind;
    float Array[Max][Max];
    float Sum_grad [Max] = {0};
    printf("_________________Assignment3 -- Task 3 _________________");
    printf("\nEnter number of students please (Maximum size = 100): ");
    scanf("%d",&row);
    printf("\nEnter number of subjects please (Maximum size = 100): ");
    scanf("%d",&col);

    /// Get Data
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("\nEnter The student[%d], subject[%d] grade: ",row_ind+1, col_ind+1);
            scanf("%f",&Array[row_ind][col_ind]);
        }
    }

    /// Print Entered Data;
    printf("\nYou have entered the following Data :\n");
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        printf("Student %d : \t", row_ind+1);
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("%0.2f\t",Array[row_ind][col_ind]);
        }
        printf("\n");
    }

    /// Calculate the summation
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            Sum_grad[row_ind] += Array[row_ind][col_ind];
        }
    }


    /// Print the data and summation
    /// Print Entered Data
    printf("\nThe summation of each student grades:\n");
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        printf("Student %d : \t", row_ind+1);
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("%0.2f\t",Array[row_ind][col_ind]);
        }
        printf("\t Summation of student grades = %0.2f",Sum_grad[row_ind]);
        printf("\n");
    }

    return 0;
}
