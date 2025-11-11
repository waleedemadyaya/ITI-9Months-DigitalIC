#include <iostream>

using namespace std;

int Add (int a = 0 , int b = 0 , int c = 0 ){
    return (a + b + c);
}


int main()
{
    cout << "Add three numbers: " << endl;
    cout << Add(1, 2, 3) << endl;

    cout << "Add two numbers: " << endl;
    cout << Add(1, 2) << endl;

    cout << "Add one number: " << endl;
    cout << Add(1) << endl;

    cout << "Add no numbers: " << endl;
    cout << Add() << endl;
    return 0;
}

