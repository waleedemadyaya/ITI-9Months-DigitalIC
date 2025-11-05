#include <stdio.h>
#include <stdlib.h>

#define Max 100

int main()
{
    int row = 0;
    int col = 0;
    int row_ind, col_ind;
    float Array[Max][Max];
    float sum = 0;
    float avg_grad [Max] = {0};
    printf("_________________Assignment3 -- Task 4 _________________");
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
    printf("_____________________________________________________________________________");
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

    /// Calculate the Average
    for (col_ind = 0; col_ind<col; col_ind++)
    {
        sum = 0.0;
        for (row_ind = 0; row_ind <row; row_ind++)
        {
            sum += Array[row_ind][col_ind];
        }
        avg_grad[col_ind] = sum / (float)row;
    }

    /// Print Entered Data;
    printf("_____________________________________________________________________________");
    printf("\nThe average of each subject is  :\n");
    for (row_ind = 0; row_ind <row; row_ind++)
    {
        printf("Student %d : \t", row_ind+1);
        for (col_ind = 0; col_ind<col; col_ind++)
        {
            printf("%0.2f\t",Array[row_ind][col_ind]);
        }
        printf("\n");
    }

    printf("Average    : \t");

    for (col_ind = 0; col_ind < col ; col_ind++)
    {
        printf("%0.2f\t",avg_grad[col_ind]);
    }




    return 0;
}
