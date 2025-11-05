#include <stdio.h>
#include <stdlib.h>

float pow_func (float num , int exp);


int main()
{
    float num, my_num;
    int exp, my_exp;

    printf("\n Enter a number please: ");
    scanf("%f",&num);

    printf("\n Enter a exponent please: ");
    scanf("%d",&exp);

    if (exp < 0){
        my_num = 1.0 / num;
        my_exp = -1 * exp;
    } else {
        my_num = num;
        my_exp = exp;
    }

    printf("\nResults:\n %0.2f ^ %d = %0.8f",num,exp,pow_func (my_num ,my_exp));

    return 0;
}


float pow_func (float num , int exp){
    if (exp == 0){
        return 1;
    }else{
        return num * pow_func (num , exp-1 );
    }
}
