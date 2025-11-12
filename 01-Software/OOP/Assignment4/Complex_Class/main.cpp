#include <iostream>
using namespace std;

class complex {

public:
    // Existing constructors and destructor
    complex(int r , int i);
    complex(int r);
    complex();
    ~complex();
    complex (const complex &complex_temp);  /// deep copy constructor

    // Existing member functions
    void set_complex (int r , int i);
    int get_real ();
    int get_imag ();
    complex Add_complex (complex c1);
    complex Sub_complex (complex c1);
    void Display_complex ();

    // ===== Operator Overloads =====
    complex operator - (const complex &c1);     // C3 = C1 - C2
    complex operator - (int val);               // C3 = C1 - 7
    friend complex operator - (int val, const complex &c1);  // C3 = 7 - C2
    complex& operator -= (const complex &c1);   // C1 -= C2

    complex& operator -- ();     // Pre-decrement (--C1)
    complex operator -- (int);   // Post-decrement (C1--)

    bool operator == (const complex &c1);  // C1 == C2
    bool operator != (const complex &c1);  // C1 != C2

    bool operator >  (const complex &c1);
    bool operator >= (const complex &c1);
    bool operator <  (const complex &c1);
    bool operator <= (const complex &c1);

    operator int();              // (int)C1
    int operator [] (char ch);   // C1['R']

    // ===== Stream Operators =====
    friend ostream& operator << (ostream &out, const complex &c);
    friend istream& operator >> (istream &in, complex &c);

private:
    int real;
    int imag;
};

// ======================= Main Function ==========================
int main()
{
    complex C1(3,4), C2(5), C3;

    C3 = C1 - C2;
    cout << "C1 - C2" << endl;
    C3.Display_complex();

    C3 = 7 - C2;
    cout << "7 - C2" << endl;
    C3.Display_complex();

    C3 = C2 - 7;
    cout << "C2 - 7" << endl;
    C3.Display_complex();

    C1 -= C2;
    cout << "C1 -= C2" << endl;
    C1.Display_complex();

    C2 = --C1;
    cout << "--C1" << endl;
    C2.Display_complex();

    C2 = C1--;
    cout << "C1--" << endl;
    C2.Display_complex();

    
    cout << "C1 == C2" << endl;
    if (C1 == C2)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    cout << "C1 > C2" << endl;
    if (C1 > C2)
        cout << "C1 is greater" << endl;
    else
        cout << "C2 is greater or equal" << endl;

    cout << "(int)C1" << endl;
    int value = (int)C1;
    cout << "Integer value of C1: " << value << endl;

    cout << "C1['R']" << endl;
    cout << "Real part using operator[]: " << C1['R'] << endl;
    cout << "C1['I']" << endl;
    cout << "Imag part using operator[]: " << C1['I'] << endl;

    cout << "Enter a complex number (real imag): ";
    cin >> C3;

    cout << "You entered: " << C3 << endl;

    cout << "C1 = " << C1 << endl;
    cout << "C2 = " << C2 << endl;
    cout << "C3 = " << C3 << endl;

    return 0;
}

// ======================= Implementations of complex methods =========================

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

void complex::set_complex (int r , int i){
    (this -> real) = r;
    (this -> imag) = i;
}

int complex::get_real (){
    return real;
}

int complex::get_imag (){
    return imag;
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
    cout << "Complex Number is : ";
    if ((this -> real) != 0 && (this -> imag) > 0)
        cout << (this -> real) << " + " << (this -> imag) << "i" << endl;
    else if ((this -> real) != 0 && (this -> imag) < 0)
        cout << (this -> real) << " - " << -1 * (this -> imag) << "i" << endl;
    else if ((this -> real) == 0 && (this -> imag) != 0)
        cout << (this -> imag) << "i" << endl;
    else if ((this -> real) != 0 && (this -> imag) == 0)
        cout << (this -> real) << endl;
    else
        cout << "0" << endl;
}

// =================== Operator Overloads ===================

// C3 = C1 - C2
complex complex::operator - (const complex &c2){
    complex ctemp;
    ctemp.real = (this -> real) - c2.real;
    ctemp.imag = (this -> imag) - c2.imag;
    return ctemp;
}

// C3 = C1 - 7
complex complex::operator - (int val){
    complex ctemp;
    ctemp.real = (this -> real) - val;
    ctemp.imag = (this -> imag);
    return ctemp;
}

// C3 = 7 - C2
complex operator - (int val, const complex &c1){
    complex ctemp;
    ctemp.real = val - c1.real;
    ctemp.imag = -c1.imag;
    return ctemp;
}

// C1 -= C2
complex& complex::operator -= (const complex &c1){
    (this -> real) -= c1.real;
    (this -> imag) -= c1.imag;
    return *this;
}

// Pre-decrement (--C1)
complex& complex::operator -- (){
    --(this -> real);
    --(this -> imag);
    return *this;
}

// Post-decrement (C1--)
complex complex::operator -- (int){
    complex temp = *this;
    (this -> real)--;
    (this -> imag)--;
    return temp;
}

// Comparison operators
bool complex::operator == (const complex &c1){
    return ((this -> real) == c1.real && (this -> imag) == c1.imag);
}

bool complex::operator != (const complex &c1){
    return ( (this -> real != c1.real) || (this -> imag != c1.imag) );
}

bool complex::operator > (const complex &c1){
    return (( (this -> real*this -> real) + (this -> imag*this -> imag) ) >
            ( (c1.real*c1.real) + (c1.imag*c1.imag) ));
}

bool complex::operator >= (const complex &c1){
    return (*this > c1) || (*this == c1);
}

bool complex::operator < (const complex &c1){
    return !(*this >= c1);
}

bool complex::operator <= (const complex &c1){
    return !(*this > c1);
}

// (int)C1 → returns the magnitude squared
complex::operator int(){
    return (this -> real * this -> real) + (this -> imag * this -> imag);
}

// C1['R'] or C1['I']
int complex::operator [] (char ch){
    if (ch == 'R' || ch == 'r')
        return (this -> real);
    else if (ch == 'I' || ch == 'i')
        return (this -> imag);
    else {
        cout << "Invalid index, returning 0" << endl;
        return 0;
    }
}

// =================== Stream Operators ===================

// cout << c1;
ostream& operator << (ostream &out, const complex &c){
    if (c.real != 0 && c.imag > 0)
        out << c.real << " + " << c.imag << "i";
    else if (c.real != 0 && c.imag < 0)
        out << c.real << " - " << -1 * c.imag << "i";
    else if (c.real == 0 && c.imag != 0)
        out << c.imag << "i";
    else if (c.real != 0 && c.imag == 0)
        out << c.real;
    else
        out << "0";
    return out;
}

// cin >> c1;
istream& operator >> (istream &in, complex &c){
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}
