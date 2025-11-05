#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    char str_in[MAX+1];
    int i = 0;
    char ch;

    printf("Enter your sentence pleas (Max length is 100): ");
    do {
        ch = getche();
        if(ch != '\r')
        {
            str_in[i++] = ch;
        }else
        {
            str_in[i++] = '\0';
        }
    }while (ch != '\r');

    printf("\nYour sentence is :\n%s",str_in);
    return 0;
}
