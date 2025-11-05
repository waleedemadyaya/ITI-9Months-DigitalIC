#include <stdio.h>
#include <stdlib.h>

int main() {
    int row = 0, col = 0;
    int row_ind, col_ind;

    printf("_________________Assignment7 -- Task 3 _________________\n");
    printf("Enter number of students please : ");
    scanf("%d", &row);

    printf("Enter number of subjects please : ");
    scanf("%d", &col);

    // Dynamic allocations
    float **students = (float**)malloc(row * sizeof(float*));
    float *sum_grades = (float*)malloc(row * sizeof(float));
    float *avg_grades = (float*)malloc(col * sizeof(float));

    for (row_ind = 0; row_ind < row; row_ind++)
        students[row_ind] = (float*)malloc(col * sizeof(float));

    // Get data
    for (row_ind = 0; row_ind < row; row_ind++) {
        for (col_ind = 0; col_ind < col; col_ind++) {
            printf("Enter student[%d], subject[%d] grade: ", row_ind + 1, col_ind + 1);
            scanf("%f", &students[row_ind][col_ind]);
        }
    }

    // Print data
    printf("\nYou have entered the following data:\n");
    for (row_ind = 0; row_ind < row; row_ind++) {
        printf("Student %d:\t", row_ind + 1);
        for (col_ind = 0; col_ind < col; col_ind++)
            printf("%.2f\t", students[row_ind][col_ind]);
        printf("\n");
    }

    // Calculate summation per student
    for (row_ind = 0; row_ind < row; row_ind++) {
        sum_grades[row_ind] = 0;
        for (col_ind = 0; col_ind < col; col_ind++)
            sum_grades[row_ind] += students[row_ind][col_ind];
    }

    // Calculate average per subject
    for (col_ind = 0; col_ind < col; col_ind++) {
        avg_grades[col_ind] = 0;
        for (row_ind = 0; row_ind < row; row_ind++)
            avg_grades[col_ind] += students[row_ind][col_ind];
        avg_grades[col_ind] /= row;
    }

    // Print total per student
    printf("\nSummation of each student�s grades:\n");
    for (row_ind = 0; row_ind < row; row_ind++) {
        printf("Student %d:\t", row_ind + 1);
        for (col_ind = 0; col_ind < col; col_ind++)
            printf("%.2f\t", students[row_ind][col_ind]);
        printf("=> Total = %.2f\n", sum_grades[row_ind]);
    }

    // Print average per subject
    printf("\nAverage grade per subject:\n");
    for (col_ind = 0; col_ind < col; col_ind++)
        printf("Subject %d average = %.2f\n", col_ind + 1, avg_grades[col_ind]);

    // Free memory
    for (row_ind = 0; row_ind < row; row_ind++)
        free(students[row_ind]);
    free(students);
    free(sum_grades);
    free(avg_grades);

    return 0;
}
