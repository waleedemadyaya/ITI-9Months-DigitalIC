#include <iostream>
using namespace std;

class A {
private:
    int X;
protected:
    int Y;
public:
    int Z;

    void MyFunc ()
    {
        cout << Y << Z;
    }
};


/// 
class B : protected A
{
    private:
        int L;
    protected:
        int M;
    public:
        int N;
}


/*
/// inherite methods and attributes in the public and protected sections
/// but in private section
class B : private A
{
    private:
        int L;
    protected:
        int M;
    public:
        int N;
}
*/

/*
/// if you didn't write the public key word it's a prblem
class B : public A  ///public inheritance get all attributes and method in public 
                    /// and protected section
{
    private:
        int L;
    protected:
        int M;
    public:
        int N;
}
*/
class C : public B
{
    private:
        int O;
}

int main(){

    A a;
    ///cout << a.X;
    ///cout << b.Y;
    cout << a.Z;

    B b;
    ///cout << b.X;
    ///cout << b.Y;
    cout << b.Z;
    ///cout << b.L;
    ///cout << b.M;
    ///cout << b.N;

    C c;
    ///cout << c.X;
    ///cout << c.Y;
    cout << c.Z;
    ///cout << c.L;
    ///cout << c.M;
    cout << c.N;
    ///cout << c.O;

    return 0;
}