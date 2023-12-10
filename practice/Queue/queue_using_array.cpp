#include <iostream>
using namespace std;

class Queue
{
public:
    int *queue;
    int size, front, rear;
    Queue(int _size)
    {
        size = _size;
        queue = new int[_size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        return (rear + 1) % size == front;
    }
    void enQueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full, unable to enQueue" << endl;
        }
        else if (isEmpty())
        {
            front++;
            queue[++rear] = val;
        }
        else
        {
            rear = (rear + 1) % size;
            queue[rear] = val;
        }
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty, nothing to dequeue!" << endl;
            return -1;
        }
        else if (front == rear)
        {
            int element = queue[front];
            rear = -1;
            front = -1;
            return element;
        }
        else
        {
            int element = queue[front];
            front = (front + 1) % size;
            return element;
        }
    }
    int showFront()
    {
        return queue[front];
    }
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        do
        {
            cout << queue[i] << ", ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);

        cout << endl;
    }
};

int main()
{
    Queue q(4);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.displayQueue();
    q.deQueue();
    q.displayQueue();
    return 0;
}