#include <stdio.h>
#include <stdlib.h>

int main() {
    int row = 0;
    int row_ind, col_ind;

    printf("_________________Assignment7 -- Task 3 _________________\n");
    printf("Enter number of students please : ");
    scanf("%d", &row);

    int* col = (int*)malloc(row * sizeof(int));
    for (row_ind = 0; row_ind < row; row_ind++) {
        printf("Enter number of subjects for student %d please : ", row_ind + 1);
        scanf("%d", &col[row_ind]);
    }

    // Dynamic allocations
    float **students = (float**)malloc(row * sizeof(float*));
    float *sum_grades = (float*)malloc(row * sizeof(float));

    for (row_ind = 0; row_ind < row; row_ind++)
        students[row_ind] = (float*)malloc(col[row_ind] * sizeof(float));

    // Get data
    for (row_ind = 0; row_ind < row; row_ind++) {
        for (col_ind = 0; col_ind < col[row_ind]; col_ind++) {
            printf("Enter student[%d], subject[%d] grade: ", row_ind + 1, col_ind + 1);
            scanf("%f", &students[row_ind][col_ind]);
        }
    }

    // Print data
    printf("\nYou have entered the following data:\n");
    for (row_ind = 0; row_ind < row; row_ind++) {
        printf("Student %d:\t", row_ind + 1);
        for (col_ind = 0; col_ind < col[row_ind]; col_ind++)
            printf("%.2f\t", students[row_ind][col_ind]);
        printf("\n");
    }

    // Calculate summation per student
    for (row_ind = 0; row_ind < row; row_ind++) {
        sum_grades[row_ind] = 0;
        for (col_ind = 0; col_ind < col[row_ind]; col_ind++)
            sum_grades[row_ind] += students[row_ind][col_ind];
    }

    // Print total per student
    printf("\nSummation of each student's grades:\n");
    for (row_ind = 0; row_ind < row; row_ind++) {
        printf("Student %d:\t", row_ind + 1);
        for (col_ind = 0; col_ind < col[row_ind]; col_ind++)
            printf("%.2f\t", students[row_ind][col_ind]);
        printf("=> Total = %.2f\n", sum_grades[row_ind]);
    }

    // -------- Average per subject (dynamic subjects count) --------
    // Find max number of subjects among all students
    int max_subjects = 0;
    for (row_ind = 0; row_ind < row; row_ind++)
        if (col[row_ind] > max_subjects)
            max_subjects = col[row_ind];

    float *avg_grades = (float*)malloc(max_subjects * sizeof(float));

    for (col_ind = 0; col_ind < max_subjects; col_ind++) {
        float sum = 0;
        int count = 0;
        for (row_ind = 0; row_ind < row; row_ind++) {
            if (col_ind < col[row_ind]) {  // subject exists for this student
                sum += students[row_ind][col_ind];
                count++;
            }
        }
        avg_grades[col_ind] = (count > 0) ? (sum / count) : 0;
    }

    // Print average per subject
    printf("\nAverage grade per subject:\n");
    for (col_ind = 0; col_ind < max_subjects; col_ind++)
        printf("Subject %d average = %.2f\n", col_ind + 1, avg_grades[col_ind]);

    // Free memory
    for (row_ind = 0; row_ind < row; row_ind++)
        free(students[row_ind]);
    free(students);
    free(sum_grades);
    free(avg_grades);
    free(col);

    return 0;
}
