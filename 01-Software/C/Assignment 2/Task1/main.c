#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    int input = 0;
    while (sum <= 100){
        printf("Enter number please : ");
        scanf("%d",&input);
        sum += input;
    }
    return 0;
}
