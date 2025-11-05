#include <iostream>

using namespace std;

void swap_values_by_values  (int  x , int  y);
void swap_values_by_address (int* x , int* y);
void swap_values_by_refrence(int& x , int& y);

int main()
{
    int A, B;
    cout << "Enter First Value pleas: " << endl;
    cin  >> A;
    cout << "Enter second Value pleas: " << endl;
    cin  >> B;


    swap_values_by_values  (A , B);
    cout << "Swapped values by value are : " << endl;
    cout << "A= " << A << "\tB= " << B << endl;

    swap_values_by_address (&A , &B);
    cout << "Swapped values by address are : " << endl;
    cout << "A= " << A << "\tB= " << B << endl;
    swap_values_by_address (&A , &B);

    swap_values_by_refrence(A , B);
    cout << "Swapped values by reference are : " << endl;
    cout << "A= " << A << "\tB= " << B << endl;
    swap_values_by_refrence(A , B);

    return 0;
}

void swap_values_by_values  (int  x , int  y){
    int temp = x ;
    x = y;
    y = temp;
}

void swap_values_by_address (int* x , int* y){
    int temp = *(x);
    (*x) = (*y);
    (*y) = temp;
}

void swap_values_by_refrence(int& x , int& y){
    int temp = x;
    x = y;
    y = temp;
}
