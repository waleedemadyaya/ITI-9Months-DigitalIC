#include <iostream>

using namespace std;

struct Complex_Nums {
public:
    void set_real(int rea){
        real = rea;
    }
    void set_img (int imag){
        img = imag;
    }

    int get_real (){
        return real;
    }

    int get_img () {
        return img;
    }
private:
    int real;
    int img ;

};

void print_complex (Complex_Nums Cp){

    cout << "Complex Number is : " << endl;
    if (Cp.get_real() != 0 && Cp.get_img() > 0)
        cout << Cp.get_real() << " + " << Cp.get_img() << "i" << endl;
    else if (Cp.get_real() != 0 && Cp.get_img() < 0)
        cout << Cp.get_real() << " - " << -1 * Cp.get_img() << "i" << endl;
    else if (Cp.get_real() == 0 && Cp.get_img() != 0)
        cout <<  Cp.get_img() << "i" << endl;
    else if (Cp.get_real() != 0 && Cp.get_img() == 0)
        cout <<  Cp.get_real() << endl;
    else
        cout << "0" << endl;
}

int main()
{
    Complex_Nums C1;
    C1.set_real(5);
    C1.set_img(3);
    print_complex(C1);

    C1.set_real(5);
    C1.set_img(-3);
    print_complex(C1);

    C1.set_real(-5);
    C1.set_img(3);
    print_complex(C1);

    C1.set_real(0);
    C1.set_img(3);
    print_complex(C1);

    C1.set_real(5);
    C1.set_img(0);
    print_complex(C1);

    C1.set_real(0);
    C1.set_img(0);
    print_complex(C1);

    return 0;
}
