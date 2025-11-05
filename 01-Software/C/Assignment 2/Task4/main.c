#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[2];
    int max = 0;
    printf("Enter the first  number pleas:    ");
    scanf("%d",&num[0]);
    printf("\nEnter the second number pleas:    ");
    scanf("%d",&num[1]);
    printf("\nEnter the third  number pleas:    ");
    scanf("%d",&num[3]);

    int i;
    for (i = 0 ; i < 3 ; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    printf("\nThe max number you entered is :\t%d", max);
    return 0;
}
