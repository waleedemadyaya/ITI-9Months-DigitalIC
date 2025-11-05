#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    char Fname [MAX+1];
    char Lname [MAX+1];
    char FullName [2*(MAX+1)];

    printf("Enter Your First Name (Max length 100 characters): ");
    gets(Fname);

    printf("Enter Your Last Name (Max length 100 characters): ");
    gets(Lname);

    strcpy(FullName,Fname);
    strcat(FullName," ");
    strcat(FullName,Lname);

    printf("\nYour full name is %s",FullName);
    return 0;
}
