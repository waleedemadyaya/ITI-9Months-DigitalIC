#include <iostream>

using namespace std;

class complex {
public:
    complex(int r , int i){
        real = r;
        imag = i;
        cout << "Constructor called" << endl;
    }

    complex(int r){
        real = r;
        imag = 0;
        cout << "Single Parameter Constructor called" << endl;
    }

    complex(){
        real = 0;
        imag = 0;
        cout << "Default Constructor called" << endl;
    }

    ~complex(){
        cout << "Destructor called" << endl;
    }

    void setter (int r , int i){
        real = r;
        imag = i;
    }

    int getter_real (){
        return real;
    }

    int getter_imag (){
        return imag;
    }

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


complex complex::Add_complex (complex c1){
    complex ctemp;
    ctemp.real = real + c1.real;
    ctemp.imag = imag + c1.imag;
    return ctemp;
}

complex complex::Sub_complex (complex c1){
    complex ctemp;
    ctemp.real = real - c1.real;
    ctemp.imag = imag - c1.imag;
    return ctemp;
}

void complex::Display_complex (){
    cout << "Complex Number is : " << endl;
    if (real != 0 && imag > 0)
        cout << real << " + " << imag << "i" << endl;
    else if (real != 0 && imag < 0)
        cout << real << " - " << -1 * imag << "i" << endl;
    else if (real == 0 && imag != 0)
        cout <<  imag << "i" << endl;
    else if (real != 0 && imag == 0)
        cout <<  real << endl;
    else
        cout << "0" << endl;
}
