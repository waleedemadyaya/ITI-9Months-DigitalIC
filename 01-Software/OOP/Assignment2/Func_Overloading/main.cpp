#include <iostream>

using namespace std;

class myTestClass
{
public:
	int  Add(int, int);
	int  Add(int, int, int);
    void Add(char c1, char c2, char ch);
	void Add(char* str1, char* str2);
};

int main()
{
    myTestClass obj;

    cout << "First function call using two integers: " << endl;
    int a = obj.Add(5, 10);
    cout << a << endl << endl;
    cout << "Second function call using three integers: " << endl;
    a = obj.Add(5, 10, 15);
    cout << a << endl << endl;
    cout << "Third function call using three characters: " << endl;
    obj.Add('A', 'B', 'C');
    cout << "Fourth function call using two strings: " << endl;
    obj.Add("Waleed", "Emad");
    return 0;
}

int myTestClass :: Add (int a , int b)
{
    return (a+b);
}

int myTestClass :: Add (int a , int b , int c)
{
    return (a+b+c);
}

void myTestClass :: Add (char c1 , char c2 , char ch)
{
    cout << "Characters are : " << c1 << " " << c2 << " " << ch << endl << endl;
}

void myTestClass :: Add (char* str1 , char* str2)
{
    cout << "Strings are : " << str1 << " " << str2 << endl << endl;
}
