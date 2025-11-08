#include <iostream>

using namespace std;

class complex {

public:
    complex(int r , int i);
    complex(int r);
    complex();
    ~complex();
    complex (const complex &complex_temp);
    void setter (int r , int i);
    int getter_real ();
    int getter_imag ();
    complex Add_complex (complex c1);
    complex Sub_complex (complex c1);
    void Display_complex ();

private:
    int real;
    int imag;
};


int main()
{
    complex C1(3,4), C2(5), C3;
	C3 = C1.Add_complex(C2);
    return 0;
}

complex::complex (int r , int i){
        (this -> real) = r;
        (this -> imag) = i;
        cout << "Two parameters constructor called" << endl;
    }

complex::complex(int r){
        (this -> real) = r;
        (this -> imag) = 0;
        cout << "Single Parameter Constructor called" << endl;
    }

complex::complex(){
        (this -> real) = 0;
        (this -> imag) = 0;
        cout << "Default Constructor called" << endl;
    }

complex::~complex(){
        cout << "Destructor called" << endl;
    }

complex::complex (const complex &complex_temp){
    this -> real = complex_temp.real;
    this -> imag = complex_temp.imag;
    cout << "Deep copy constructor is called!" << endl;
}

void complex::setter (int r , int i){
        (this -> real) = r;
        (this -> imag) = i;
    }

int complex::getter_real (){
        return real;
    }

complex complex::Add_complex (complex c1){
    complex ctemp;
    ctemp.real = (this -> real) + c1.real;
    ctemp.imag = (this -> imag) + c1.imag;
    return ctemp;
}

complex complex::Sub_complex (complex c1){
    complex ctemp;
    ctemp.real = (this -> real) - c1.real;
    ctemp.imag = (this -> imag) - c1.imag;
    return ctemp;
}

void complex::Display_complex (){
    cout << "Complex Number is : " << endl;
    if ( (this -> real) != 0 && (this -> imag) > 0)
        cout << (this -> real) << " + " << (this -> imag) << "i" << endl;
    else if (real != 0 && (this -> imag) < 0)
        cout << (this -> real) << " - " << -1 * (this -> imag) << "i" << endl;
    else if ((this -> real) == 0 && (this -> imag) != 0)
        cout <<  (this -> imag) << "i" << endl;
    else if ((this -> real) != 0 && (this -> imag) == 0)
        cout <<  (this -> real) << endl;
    else
        cout << "0" << endl;
}

