#include <iostream>
#include <queue>
using namespace std;

class CirQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    CirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        // Queue full

        // single element case -> first element

        // circular nature

        // normal flow

        // (front == 0 && rear == size - 1) || (rear == front-1) - we can use this condition or a single condition as - rear = (front-1) % (size-1)
        if (rear = (front - 1) % (size - 1))
        {
            cout << "Q is full , cannot insert " << endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        // empty check

        // single element

        // circular nature

        // normal flow

        if (front == -1)
        {
            cout << "Q is empty , can't pop" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Q is empty " << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return rear - front;
    }
};
int main()
{

    CirQueue q(10);

    return 0;
}
