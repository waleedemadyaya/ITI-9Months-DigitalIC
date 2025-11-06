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
    int peak();
    void push(int value);
    int pop();
    int is_empty();
    int is_full();
    stack reverse_stack(); // returns a new reversed stack
    void display_stack();
};

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
            stack_reverse.display_stack();
            cout << "Original stack: ";
            my_stack.display_stack();
            break;
        }
        case 5:
        {
            my_stack.display_stack();
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

// Constructors & Destructor
stack::stack()
{
    max_size = 10;
    top = -1;
    stack_array = new int[max_size];
}

stack::stack(int size)
{
    max_size = size;
    top = -1;
    stack_array = new int[max_size];
}

stack::~stack()
{
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
        return stack_array[top--];
    }
    else
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
}

int stack::is_empty()
{
    return top == -1;
}

int stack::is_full()
{
    return top == max_size - 1;
}


stack stack::reverse_stack()
{
    stack reversed(max_size);

    if (is_empty())
        return reversed;

    // Copy and reverse
    for (int i = top; i >= 0; i--)
    {
        reversed.push(stack_array[i]);
    }

    return reversed;
}

void stack::display_stack()
{
    if (is_empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack contents (top to bottom): ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack_array[i] << " ";
    }
    cout << endl;
}
