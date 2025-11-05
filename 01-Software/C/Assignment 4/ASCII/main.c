#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch,chext;
    do{
        printf("Enter a character pleas (Press End to end your program) : ");
        ch = getche();
        switch(ch)
        {
            case -32:
            case  0 :
                chext = getche();
                printf("\n\nYou have entered an extended key with ASCII code %d\n",chext);
            break;

            default:
                switch(ch)
                {
                    case '\r':
                        printf("\n\nASCII code of <_| is %d\n",ch);
                    break;
                    default:
                        printf("\n\nASCII code of %c is %d\n",ch,ch);
                    break;
                }

            break;
        }
        printf("________________________________________________________________________________________\n");
    } while (chext != 79);

    return 0;
}
