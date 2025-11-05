#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    char str1[MAX];
    int i = 0;

    printf("Enter your sentence please:\n");
    gets(str1);

    while(str1[i] != '\0')
    {
        i++;
    }
    printf("\n You have entered an array with length: %d",i);
    return 0;
}
