#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch_crnt;
    char ch_prv = ' ';
    int word=0;
    int alph=0;
    printf("_________________Assignment2 -- Task 7 _________________\n");
    printf("Enter your sentence: ");
    do{
        ch_crnt = getche();
        if (ch_crnt != ' ' && ch_crnt != '\r')
        {
            alph++;
        }else if (ch_crnt == ' ' && ch_prv != ' ')
        {
            word++;
        }
        ch_prv = ch_crnt;
    }while (ch_crnt != '\r'); ///check for the ASCII code of Enter.
    if (ch_prv != ' ')
    {
        word++;
    }
    printf("\nNumber of words = %d",word);
    printf("\nNumber of alphabet = %d",alph);

    return 0;

    /*int index=0;
    int alph=0;
    int word=0;
    char sentence[5000];
    char cur='\0';

    printf("Enter sentence pleas e.g (Hello world.):   ");
    gets(&sentence);

    cur = sentence[index];
    while (cur != '\0'){
        switch(cur){
        case ' ':{
            word++;
            break;
        }
        default: {
            alph++;
        }
        }
        cur = sentence[++index];
    }
    printf("\nNumber of words = %d",++word);
    printf("\nNumber of alphabet = %d",alph);*/

}
