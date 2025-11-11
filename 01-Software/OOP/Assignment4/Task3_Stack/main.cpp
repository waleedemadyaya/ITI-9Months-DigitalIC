#include <iostream>
using namespace std;

class stack
{
private:
    int top;
    int max_size;
    int* stack_array;
    static int counter;

public:
    stack();
    stack(int size);
    ~stack();
    stack(const stack& temp_stack);
    int peak();
    void push(int value);
    int pop();
    int is_empty();
    int is_full();
    stack reverse_stack();
    static int getCounter();
    friend void display_stack(stack temp);

    // Added operators
    stack& operator=(stack& rhs);
    stack operator+(const stack& rhs);
    int operator[](int index) const;
    int& operator[](int index);
};

// Initialize static counter
int stack::counter = 0;

// Constructors & Destructor
stack::stack()
{
    cout << "Parameter-less constructor is called!" << endl;
    max_size = 10;
    top = -1;
    stack_array = new int[max_size];
    counter++;
}

stack::stack(int size)
{
    cout << "Parameterized constructor is called!" << endl;
    max_size = size;
    top = -1;
    stack_array = new int[max_size];
    counter++;
}

stack::~stack()
{
    cout << "Destructor is called!" << endl;
    delete[] stack_array;
    counter--;
}

stack::stack(const stack& temp_stack)
{
    cout << "Deep copy constructor is called!" << endl;
    this->top = temp_stack.top;
    this->max_size = temp_stack.max_size;
    this->stack_array = new int[temp_stack.max_size];
    for (int i = 0; i <= top; i++)
        this->stack_array[i] = temp_stack.stack_array[i];
    counter++;
}

// Other member functions
int stack::peak()
{
    if (!is_empty())
        return stack_array[top];
    cout << "Stack is empty" << endl;
    return -1;
}

void stack::push(int value)
{
    if (!is_full())
        stack_array[++top] = value;
    else
        cout << "Stack is full" << endl;
}

int stack::pop()
{
    if (!is_empty())
        return stack_array[top--];
    cout << "Stack is empty" << endl;
    return -1;
}

int stack::is_empty() { return top == -1; }
int stack::is_full() { return top == max_size - 1; }

stack stack::reverse_stack()
{
    stack reversed(max_size);
    for (int i = top; i >= 0; i--)
        reversed.push(stack_array[i]);
    return reversed;
}

void display_stack(stack temp)
{
    if (temp.is_empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack contents (top to bottom): ";
    for (int i = temp.top; i >= 0; i--)
        cout << temp.stack_array[i] << " ";
    cout << endl;
}

int stack::getCounter() { return counter; }

// ====== Added Operators ======
stack& stack::operator=(stack& rhs)
{
    if (this != &rhs)
    {
        delete[] stack_array;
        this->max_size = rhs.max_size;
        this->top = rhs.top;
        this->stack_array = new int[max_size];
        for (int i = 0; i <= top; i++)
            this->stack_array[i] = rhs.stack_array[i];
    }
    cout << "Assignment operator called!" << endl;
    ///cout << "rhs= " << (rhs) <<endl;
    cout << "&rhs= " << (&rhs) << endl;
    ///cout << "*rhs= " << (*rhs) <<endl;
    cout << "this= "<< (this) <<endl;
    ///cout << "&this= "<< (&this) <<endl;
    ///cout << "*this= "<< (*this) <<endl;
    return rhs;
}

stack stack::operator+(const stack& rhs)
{
    stack result(this->max_size + rhs.max_size);
    for (int i = 0; i <= this->top; i++)
        result.push(this->stack_array[i]);
    for (int i = 0; i <= rhs.top; i++)
        result.push(rhs.stack_array[i]);
    cout << "Operator+ called!" << endl;
    return result;
}

int stack::operator[](int index) const
{
    if (index < 0 || index > top)
    {
        cout << "Invalid index access!" << endl;
        return -1;
    }
    return stack_array[index];
}

int& stack::operator[](int index)
{
    if (index < 0 || index > top)
    {
        cout << "Invalid index for assignment!" << endl;
        static int dummy = -1;
        return dummy;
    }
    return stack_array[index];
}

// ============ MAIN TEST ============
int main()
{
    stack s1;
    cout << "s1.push(10)" << endl;
    s1.push(10);
    cout << "s1.push(20)" << endl;
    s1.push(20);
    cout << "s1.push(30)" << endl;
    s1.push(30);

    stack s2;
    cout << "s2.push(100)" << endl;
    s2.push(100);
    cout << "s2.push(200)" << endl;
    s2.push(200);

    cout << "stack s3 = s1 + s2" << endl;
    stack s3 = s1 + s2;

    cout << "Concatenated stack s3 stack: " << endl;
    display_stack(s3);

    cout << "Counter: " << stack::getCounter() << endl;

    cout << "s3[2] = " << s3[2] << endl;

    cout << "s3[1] = 999" << endl;
    s3[1] = 999;
    cout << "\n\ns3 stack: " << endl;
    display_stack(s3);
    cout << endl << endl;


    cout << "\n\ns1 stack: " << endl;
    display_stack(s1);
    cout << endl << endl;
    cout << "\n\ns2 stack: " << endl;
    display_stack(s2);
    cout << endl << endl;
    cout << "\n\ns1 = s2" << endl;
    s1 = s2;
    cout << "\n\ns1.pop()" << endl;
    s1.pop();
    cout << "s1.push(50)" << endl;
    s1.push(50);
    cout << "s1.push(90)" << endl;
    s1.push(90);
    cout << "s1.push(100)" << endl;
    s1.push(100);

    cout << "\n\ns1 stack: " << endl;
    display_stack(s1);
    cout << endl << endl;
    cout << "\n\ns2 stack: " << endl;
    display_stack(s2);
    cout << endl << endl;

    return 0;
}
