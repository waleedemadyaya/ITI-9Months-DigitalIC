#include <stdio.h>
#include <stdlib.h>

int main()
{
    char chart;
    printf("\nEnter an alphabet pleas:\t");
    scanf("%c",&chart);
    switch (chart)
    {
        case 'a'...'z' :
            printf(" Valid character.");
            break;
        case 'A'...'Z' :
            printf("Valid character.");
            break;
        default:
            printf("Not Valid!!!!\a");
    }
    return 0;
}
