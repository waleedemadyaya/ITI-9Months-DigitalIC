#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice = 0;
    printf("Choose on of the following choices pleas using index (1, 2, or 3):");
    printf("\n1. play\n2. study\n3. pray\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("Your choice is \"play\"");
            break;
        case 2:
            printf("Your choice is \"study\"");
            break;
        case 3:
            printf("Your choice is \"pray\"");
            break;
        default:
            printf("Your choice is not available!!\a");
            break;
    }
    return 0;
}
