#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    char str_in[MAX+1];
    int i = 0 , count = 0;
    char ch;

    printf("Enter your sentence pleas (Max length is 100): ");
    gets(str_in);
    printf("Enter character for which you wanna calculate frequency: ");
    ch = getche();
    while (str_in[i] != '\0'){
        if (ch == str_in[i++])
            count++;
    }

    printf("\nTotal number of '%c' in your sentence is %d....",ch,count);
    return 0;
}
