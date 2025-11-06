#include <iostream>
using namespace std;

class queue
{
private:
    int head, tail, max_size, count;
    int* queue_array;

public:
    queue();
    queue(int size);
    ~queue();
    void enqueue(int value);
    int dequeue();
    int is_empty();
    int is_full();
    int front();
    void display_queue();
};

// ======================= MAIN FUNCTION =======================

int main()
{
    cout << "Enter queue size: ";
    int size;
    cin >> size;
    queue my_queue(size);

    int Exit = 0;
    while (!Exit)
    {
        cout << "\nSelect an option by index number:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to enqueue: ";
            int value;
            cin >> value;
            my_queue.enqueue(value);
            break;
        }
        case 2:
        {
            int dequeued_value = my_queue.dequeue();
            if (dequeued_value != -1)
                cout << "Dequeued value: " << dequeued_value << endl;
            break;
        }
        case 3:
        {
            int front_value = my_queue.front();
            if (front_value != -1)
                cout << "Front value: " << front_value << endl;
            break;
        }
        case 4:
        {
            my_queue.display_queue();
            break;
        }
        case 5:
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

// ======================= CLASS IMPLEMENTATION =======================

queue::queue()
{
    max_size = 10;
    head = 0;
    tail = -1;
    count = 0;
    queue_array = new int[max_size];
}

queue::queue(int size)
{
    max_size = size;
    head = 0;
    tail = -1;
    count = 0;
    queue_array = new int[max_size];
}

queue::~queue()
{
    delete[] queue_array;
}

void queue::enqueue(int value)
{
    if (!is_full())
    {
        tail++;
        queue_array[tail] = value;
        count++;
    }
    else
    {
        cout << "Queue is full" << endl;
    }
}

int queue::dequeue()
{
    if (!is_empty())
    {
        int value = queue_array[head];

        // Shift all elements one step toward the front
        for (int i = 0; i < tail; i++)
        {
            queue_array[i] = queue_array[i + 1];
        }

        tail--;
        count--;

        return value;
    }
    else
    {
        cout << "Queue is empty" << endl;
        return -1; // Indicating queue is empty
    }
}

int queue::is_empty()
{
    return (count == 0);
}

int queue::is_full()
{
    return (count == max_size);
}

int queue::front()
{
    if (!is_empty())
        return queue_array[head];
    else
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
}

void queue::display_queue()
{
    if (is_empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue contents (front to rear): ";
    for (int i = 0; i <= tail; i++)
    {
        cout << queue_array[i] << " ";
    }
    cout << endl;
}
