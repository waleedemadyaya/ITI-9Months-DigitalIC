#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    char str1[MAX];
    char str2[MAX];
    int i = 0;

    printf("Enter your sentence please:\n");
    gets(str1);

    while(str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    printf("\n You have entered the following array: %s",str2);
    return 0;
}
