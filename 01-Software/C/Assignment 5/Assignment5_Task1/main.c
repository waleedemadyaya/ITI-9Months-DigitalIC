#include <stdio.h>
#include <stdlib.h>

float max_3num(float n1, float n2, float n3)
{
    float max = n1;

    if (n2 > max)
        max = n2;
    if (n3 > max)
        max = n3;

    return max;
}

int main()
{
    float a, b, c;

    printf("Enter 3 numbers separated by space: ");
    scanf("%f %f %f", &a, &b, &c);

    printf("\nThe largest number is: %0.2f\n", max_3num(a, b, c));

    return 0;
}
