#include <iostream>
using namespace std;

class stack
{
private:
    int top;
    int max_size;
    int* stack_array;

public:
    stack();
    stack(int size);
    ~stack();
    stack (const stack &temp_stack);
    int peak();
    void push(int value);
    int pop();
    int is_empty();
    int is_full();
    stack reverse_stack(); // returns a new reversed stack
    friend void display_stack(stack temp);
};

 main()
{
///************* Copy Ctor Case(1): Pass by value to function ********************
/*
    stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    display_stack(S1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;
*/

///************* Copy Ctor Case(2): Return by value from function ********************
/*
    stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    stack SS = S1.reverse_stack();
    cout << SS.pop() << endl;
*/

///************* Copy Ctor Case(3): Create obj in terms of another obj "Explicitly" ********************

    stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    stack S3 ( S1 );

    for(int i=0; i<10; i++)
        cout << S3.pop() << endl;


    for(int i=0; i<10; i++)
        S3.push(-1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;

}


/*
int main()
{
    cout << "Enter stack size: ";
    int size;
    cin >> size;
    stack my_stack(size);

    int Exit = 0;
    while (!Exit)
    {
        cout << "Select and option with index number:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peak" << endl;
        cout << "4. Reverse Stack" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to push: ";
            int value;
            cin >> value;
            my_stack.push(value);
            break;
        }
        case 2:
        {
            int popped_value = my_stack.pop();
            if (popped_value != -1)
                cout << "Popped value: " << popped_value << endl;
            break;
        }
        case 3:
        {
            int peak_value = my_stack.peak();
            if (peak_value != -1)
                cout << "Peak value: " << peak_value << endl;
            break;
        }
        case 4:
        {
            stack stack_reverse = my_stack.reverse_stack();
            cout << "Reversed stack: ";
            display_stack ( stack_reverse );
            cout << "Original stack: ";
            display_stack ( my_stack );
            break;
        }
        case 5:
        {
            display_stack ( my_stack );
            break;
        }
        case 6:
        {
            Exit = 1;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}
*/

// Constructors & Destructor
stack::stack()
{
    cout << "Parameter less constructor is called!" << endl;
    (this -> max_size) = 10;
    top = -1;
    stack_array = new int[(this -> max_size)];
}

stack::stack(int size)
{
    cout << "Parameterized constructor is called!" << endl;
    (this -> max_size) = size;
    top = -1;
    stack_array = new int[(this -> max_size)];
}

stack::~stack()
{
    cout << " Destructor is called! " << endl;
    for (int i = 0 ; i < (this -> max_size) ; i++)
        this -> stack_array[i] = -1;
    delete[] stack_array;
}

// Operations
int stack::peak()
{
    if (!is_empty())
        return stack_array[top];
    else
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
}

void stack::push(int value)
{
    if (!is_full())
    {
        stack_array[++top] = value;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}

int stack::pop()
{
    if (!is_empty())
    {
        ///cout << stack_array[top] << endl;
        return stack_array[top--];
    }
    else
    {
        ///cout << "Stack is empty" << endl;
        return -1;
    }
}

int stack::is_empty()
{
    return top == -1;
}

int stack::is_full()
{
    return top == (this -> max_size) - 1;
}


stack stack::reverse_stack()
{
    stack reversed((this -> max_size));

    if (this -> is_empty())
        return reversed;

    // Copy and reverse
    for (int i = top; i >= 0; i--)
    {
        reversed.push(stack_array[i]);
    }

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
    {
        cout << temp.stack_array[i] << " ";
    }
    cout << endl;
}


stack::stack(const stack &temp_stack)
{
    cout << "Deep copy constructor is called" << endl;
    this -> top = temp_stack.top;
    this -> max_size = temp_stack.max_size;
    ///this -> temp_stackack_array = temp_stack.temp_stackack_array;   /// not valid memory wize copying
    this -> stack_array = new int[temp_stack.max_size];
    for (int i = 0; i <= top; i++)
    {
        this -> stack_array[i] = temp_stack.stack_array[i];
    }
}

