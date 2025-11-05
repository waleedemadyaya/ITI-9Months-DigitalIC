#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    char str1[MAX+1];
    char str2[MAX+1];
    int i = 0;
    int i_str_2 = 0;
    printf("Enter your sentence please (MAX SIZE IS 100]:\n");
    gets(str1);

    while(str1[i] != '\0')
    {
        if ( ('a' <= str1[i] && str1[i] <= 'z') || ('A' <= str1[i] && str1[i] <= 'Z') )
        {
             str2[i_str_2] = str1[i];
             i_str_2++;
        }
        i++;
    }
    str2[i_str_2] = '\0';
    printf("\n You have entered the following alphabet in order:\n\n\t %s",str2);
    return 0;
}
