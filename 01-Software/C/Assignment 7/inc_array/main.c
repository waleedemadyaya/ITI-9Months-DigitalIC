#include <stdio.h>
#include <stdlib.h>

int* Inc_Array_Fixed (){
    int i;
    int my_arr[5];
    for (i = 0; i < 5 ; i++)
    {
        printf("Enter element number %d:", i+1);
        scanf("%d",&my_arr[i]);
        my_arr[i] += 10;
    }
    return my_arr;
}

int* Inc_Array_Dynam (){
    int i;
    int* ptr = malloc(5*sizeof(int));
    for (i = 0; i < 5 ; i++)
    {
        printf("Enter element number %d:", i+1);
        scanf("%d",&ptr[i]);
        ptr[i] += 10;
    }
    return ptr;
}

int main()
{
    int i;
    printf("\nUsing Fixed Array Size");
    printf("\n=========================\n");
    int* const ptr = Inc_Array_Fixed();
    for (i = 0; i < 5 ; i++)
    {
        printf("\nElement number %d: %d", i+1 , *(ptr+i));
    }

    printf("\n\n\nUsing Dynamic Array Size");
    printf("\n=========================\n");
    int* const ptr_dy = Inc_Array_Dynam();
    for (i = 0; i < 5 ; i++)
    {
        printf("\nElement number %d: %d", i+1 , *(ptr_dy+i));
    }
    free(ptr_dy);
    return 0;
}
