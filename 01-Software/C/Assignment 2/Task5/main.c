#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,max,i;
    printf("\nPrint the multiplication table for number: \t");
    scanf("%d",&num);
    printf("\nStop at number :\t");
    scanf("%d",&max);

    for(i=0;i<=max;i++)
    {
        printf("\n %d * %d = %d",i,num,i*num);
    }
    return 0;
}
