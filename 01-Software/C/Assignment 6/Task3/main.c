#include <stdio.h>
#include <stdlib.h>

void Calculate(float X, float Y, float *SumPtr, float *SubPtr, float *MultipPtr, float *DivPtr)
{
    *SumPtr = X + Y;
    *SubPtr = X - Y;
    *MultipPtr = X * Y;
    if (Y != 0)
        *DivPtr = X / Y;
}

int main()
{
    float x, y;
    float sum, sub, mul, div;

    printf("Enter two integers:\n");
    scanf("%f %f", &x, &y);

    Calculate(x, y, &sum, &sub, &mul, &div);

    printf("\nResults:\n");
    printf("Sum = %0.2f\n", sum);
    printf("Sub = %0.2f\n", sub);
    printf("Mul = %0.2f\n", mul);
    printf("Div = %0.2f\n", div);

    return 0;
}
