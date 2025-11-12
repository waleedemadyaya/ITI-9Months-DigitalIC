#include <iostream>

using namespace std;


class Complex {

public:
    // Existing constructors and destructor
    Complex(int r , int i);
    Complex(int r);
    Complex();
    ~Complex();
    Complex (const Complex &Complex_temp);  /// deep copy constructor

    // Existing member functions
    void set_Complex (int r , int i);
    int get_real ();
    int get_imag ();
    Complex Add_Complex (Complex c1);
    Complex Sub_Complex (Complex c1);
    void Display_Complex ();

    // ===== Operator Overloads =====
    Complex operator - (const Complex &c1);     // C3 = C1 - C2
    Complex operator - (int val);               // C3 = C1 - 7
    friend Complex operator - (int val, const Complex &c1);  // C3 = 7 - C2
    Complex& operator -= (const Complex &c1);   // C1 -= C2

    Complex& operator -- ();     // Pre-decrement (--C1)
    Complex operator -- (int);   // Post-decrement (C1--)

    bool operator == (const Complex &c1);  // C1 == C2
    bool operator != (const Complex &c1);  // C1 != C2

    bool operator >  (const Complex &c1);
    bool operator >= (const Complex &c1);
    bool operator <  (const Complex &c1);
    bool operator <= (const Complex &c1);

    operator int();              // (int)C1
    int operator [] (char ch);   // C1['R']

    // ===== Stream Operators =====
    friend ostream& operator << (ostream &out, const Complex &c);
    friend istream& operator >> (istream &in, Complex &c);

private:
    int real;
    int imag;
};

/// template functions ( generic functions )
template <typename any_type_name>
void Swap (any_type_name& x , any_type_name& y)
{
    any_type_name temp = x;
    x = y;
    y = temp;
}

template < typename T >
class Stack{
private:
    int top;
    int max_size;
    T* Stack_array;
    static int counter;

public:
    Stack();
    Stack(int size);
    ~Stack();
    Stack(const Stack& temp_Stack);
    T peak();
    void push(T value);
    T pop();
    int is_empty();
    int is_full();
    Stack reverse_Stack();
    static int getCounter();
    friend void display_Stack(Stack temp);

    // Added operators
    Stack& operator=(Stack& rhs);
    Stack operator+(const Stack& rhs);
    T operator[](int index) const;
    T& operator[](int index);
};



// ============ MAIN TEST ============
int main()
{
    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    cout<<"\nComplex1 After Swap: "<<endl;
    C1.Display_Complex();
    cout << endl;
    cout<<"\nComplex2 After Swap: "<<endl;
    C2.Display_Complex();
    cout << endl;

    Stack<int> S;
    S.push(10);
    S.push(20);
    cout<< S.pop();
    cout << endl;

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout<< S2.pop();
    cout << endl;

    Stack<Complex> S3(4);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.pop();
    cout << endl;
    C.Display_Complex();
    cout << endl;

    return 0;
}



// ======================= Implementations of the Complex class methods =========================

Complex::Complex (int r , int i){
    (this -> real) = r;
    (this -> imag) = i;
    cout << "Complex Two parameters constructor called" << endl;
}

Complex::Complex(int r){
    (this -> real) = r;
    (this -> imag) = 0;
    cout << "Complex Single Parameter Constructor called" << endl;
}

Complex::Complex(){
    (this -> real) = 0;
    (this -> imag) = 0;
    cout << "Complex Default Constructor called" << endl;
}

Complex::~Complex(){
    cout << "Complex Destructor called" << endl;
}

Complex::Complex (const Complex &Complex_temp){
    this -> real = Complex_temp.real;
    this -> imag = Complex_temp.imag;
    cout << "Complex Deep copy constructor is called!" << endl;
}

void Complex::set_Complex (int r , int i){
    (this -> real) = r;
    (this -> imag) = i;
}

int Complex::get_real (){
    return real;
}

int Complex::get_imag (){
    return imag;
}

Complex Complex::Add_Complex (Complex c1){
    Complex ctemp;
    ctemp.real = (this -> real) + c1.real;
    ctemp.imag = (this -> imag) + c1.imag;
    return ctemp;
}

Complex Complex::Sub_Complex (Complex c1){
    Complex ctemp;
    ctemp.real = (this -> real) - c1.real;
    ctemp.imag = (this -> imag) - c1.imag;
    return ctemp;
}

void Complex::Display_Complex (){
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
Complex Complex::operator - (const Complex &c2){
    Complex ctemp;
    ctemp.real = (this -> real) - c2.real;
    ctemp.imag = (this -> imag) - c2.imag;
    return ctemp;
}

// C3 = C1 - 7
Complex Complex::operator - (int val){
    Complex ctemp;
    ctemp.real = (this -> real) - val;
    ctemp.imag = (this -> imag);
    return ctemp;
}

// C3 = 7 - C2
Complex operator - (int val, const Complex &c1){
    Complex ctemp;
    ctemp.real = val - c1.real;
    ctemp.imag = -c1.imag;
    return ctemp;
}

// C1 -= C2
Complex& Complex::operator -= (const Complex &c1){
    (this -> real) -= c1.real;
    (this -> imag) -= c1.imag;
    return *this;
}

// Pre-decrement (--C1)
Complex& Complex::operator -- (){
    --(this -> real);
    --(this -> imag);
    return *this;
}

// Post-decrement (C1--)
Complex Complex::operator -- (int){
    Complex temp = *this;
    (this -> real)--;
    (this -> imag)--;
    return temp;
}

// Comparison operators
bool Complex::operator == (const Complex &c1){
    return ((this -> real) == c1.real && (this -> imag) == c1.imag);
}

bool Complex::operator != (const Complex &c1){
    return ( (this -> real != c1.real) || (this -> imag != c1.imag) );
}

bool Complex::operator > (const Complex &c1){
    return (( (this -> real*this -> real) + (this -> imag*this -> imag) ) >
            ( (c1.real*c1.real) + (c1.imag*c1.imag) ));
}

bool Complex::operator >= (const Complex &c1){
    return (*this > c1) || (*this == c1);
}

bool Complex::operator < (const Complex &c1){
    return !(*this >= c1);
}

bool Complex::operator <= (const Complex &c1){
    return !(*this > c1);
}

// (int)C1 → returns the magnitude squared
Complex::operator int(){
    return (this -> real * this -> real) + (this -> imag * this -> imag);
}

// C1['R'] or C1['I']
int Complex::operator [] (char ch){
    if (ch == 'R' || ch == 'r')
        return (this -> real);
    else if (ch == 'I' || ch == 'i')
        return (this -> imag);
    else {
        cout << "Complex Invalid index, returning 0" << endl;
        return 0;
    }
}

// =================== Stream Operators ===================

// cout << c1;
ostream& operator << (ostream &out, const Complex &c){
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
istream& operator >> (istream &in, Complex &c){
    cout << "Complex Enter real part: ";
    in >> c.real;
    cout << "Complex Enter imaginary part: ";
    in >> c.imag;
    return in;
}




// ======================= Implementations of the stack class methods =========================
// Initialize static counter
template < typename T >
int Stack<T>::counter = 0;

// Constructors & Destructor
template < typename T >
Stack<T>::Stack()
{
    cout << "Stack Parameter-less constructor is called!" << endl;
    max_size = 10;
    top = -1;
    Stack_array = new T[max_size];
    counter++;
}

template < typename T >
Stack<T>::Stack(int size)
{
    cout << "Stack Parameterized constructor is called!" << endl;
    max_size = size;
    top = -1;
    Stack_array = new T[max_size];
    counter++;
}

template < typename T >
Stack<T>::~Stack()
{
    cout << "Stack Destructor is called!" << endl;
    delete[] Stack_array;
    counter--;
}

template < typename T >
Stack<T>::Stack(const Stack& temp_Stack)
{
    cout << "Stack Deep copy constructor is called!" << endl;
    this->top = temp_Stack.top;
    this->max_size = temp_Stack.max_size;
    this->Stack_array = new T[temp_Stack.max_size];
    for (int i = 0; i <= top; i++)
        this->Stack_array[i] = temp_Stack.Stack_array[i];
    counter++;
}

// Other member functions
template < typename T >
T Stack<T>::peak()
{
    if (!is_empty())
        return Stack_array[top];
    cout << "Stack is empty" << endl;
    return -1;
}

template < typename T >
void Stack<T>::push(T value)
{
    if (!is_full())
        Stack_array[++top] = value;
    else
        cout << "Stack is full" << endl;
}

template < typename T >
T Stack<T>::pop()
{
    if (!is_empty())
        return Stack_array[top--];
    else
        cout << "Stack is empty" << endl;
    return -1;
}

template < typename T >
int Stack<T>::is_empty() { return top == -1; }
template < typename T >
int Stack<T>::is_full() { return top == max_size - 1; }

template < typename T >
Stack<T> Stack<T>::reverse_Stack()
{
    Stack reversed(max_size);
    for (int i = top; i >= 0; i--)
        reversed.push(Stack_array[i]);
    return reversed;
}

template < typename T >
void display_Stack(Stack<T> temp)
{
    if (temp.is_empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack contents (top to bottom): ";
    for (int i = temp.top; i >= 0; i--)
        cout << temp.Stack_array[i] << " ";
    cout << endl;
}

template < typename T >
int Stack<T>::getCounter() { return counter; }

// ====== Added Operators ======
template < typename T >
Stack<T>& Stack<T>::operator=(Stack& rhs)
{
    if (this != &rhs)
    {
        delete[] Stack_array;
        this->max_size = rhs.max_size;
        this->top = rhs.top;
        this->Stack_array = new T[max_size];
        for (int i = 0; i <= top; i++)
            this->Stack_array[i] = rhs.Stack_array[i];
    }
    cout << "Stack Assignment operator called!" << endl;
    ///cout << "rhs= " << (rhs) <<endl;
    cout << "&rhs= " << (&rhs) << endl;
    ///cout << "*rhs= " << (*rhs) <<endl;
    cout << "this= "<< (this) <<endl;
    ///cout << "&this= "<< (&this) <<endl;
    ///cout << "*this= "<< (*this) <<endl;
    return rhs;
}

template < typename T >
Stack<T> Stack<T>::operator+(const Stack& rhs)
{
    Stack result(this->max_size + rhs.max_size);
    for (int i = 0; i <= this->top; i++)
        result.push(this->Stack_array[i]);
    for (int i = 0; i <= rhs.top; i++)
        result.push(rhs.Stack_array[i]);
    cout << "Stack Operator+ called!" << endl;
    return result;
}

template < typename T >
T Stack<T>::operator[](int index) const
{
    if (index < 0 || index > top)
    {
        cout << "Stack Invalid index access!" << endl;
        return -1;
    }
    return Stack_array[index];
}

template < typename T >
T& Stack<T>::operator[](int index)
{
    if (index < 0 || index > top)
    {
        cout << "Stack Invalid index for assignment!" << endl;
        static int dummy = -1;
        return dummy;
    }
    return Stack_array[index];
}
