#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int SumArray(int *arr, int size)
{
    int sum = 0;
    int *ptr = arr; // pointer to first element
    int i;

    printf("\nArray Elements:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(ptr + i)); // pointer notation for printing
        sum += *(ptr + i);
    }
    printf("\n");

    return sum;
}

int main()
{
    int arr[MAX];
    int n, i;
    int* ptr;

    ptr = &arr;

    printf("Enter number of elements (Max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) // array notation for input
    {
        scanf("%d", &ptr[i]);
    }

    int total = SumArray(arr, n);
    printf("\nSum of array elements = %d\n", total);

    return 0;
}

