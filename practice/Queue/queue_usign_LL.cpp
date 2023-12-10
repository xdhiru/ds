#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to free allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue (add) an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.enqueue(40);
    myQueue.enqueue(50);

    myQueue.display();

    return 0;
}
