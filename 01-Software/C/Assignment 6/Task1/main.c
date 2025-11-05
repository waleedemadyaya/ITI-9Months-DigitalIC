#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    ///int temp = *a;
    ///*a = *b;
    ///*b = temp;

    ///swapping without temp variable
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int x, y;
    printf("Enter two integers:\n");
    scanf("%d %d", &x, &y);

    printf("\nBefore Swap: x = %d , y = %d\n", x, y);
    Swap(&x, &y);
    printf("After  Swap: x = %d , y = %d\n", x, y);

    return 0;
}
