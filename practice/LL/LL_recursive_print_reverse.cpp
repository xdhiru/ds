#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val1) : data(val1), next(nullptr){};
};

class LL
{
public:
    Node *head = nullptr;

    void insertToFront(int val)
    {
        Node *temp = new Node(val);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void printRecursive(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }
        cout << current->data << "->";
        printRecursive(current->next);
    }

    void reversePrintRecursive(Node *front_)
    {
        if (front_ == nullptr)
        {
            return;
        }
        reversePrintRecursive(front_->next);
        cout << front_->data << "->";
    }

    Node *reverseRecursive(Node *front_)
    {
        if (front_->next == nullptr)
        {
            return front_; //last element is already in reversed form, nothing to reverse
        }
        Node *reversed = reverseRecursive(front_->next);
        front_->next->next = front_;
        front_->next = nullptr;
        return reversed;
    }
};

int main()
{
    LL hey;
    hey.insertToFront(300);
    hey.insertToFront(50);
    hey.insertToFront(140);
    cout<<"initial list: ";
    hey.printRecursive(hey.head); // 140,50,300
    cout <<"\nprinting reverse: ";
    hey.reversePrintRecursive(hey.head); // 300,50,140
    cout <<"\nreversing and storing and then printing: ";
    LL reversed_ll;
    reversed_ll.head = hey.reverseRecursive(hey.head); // 300,50,140
    reversed_ll.printRecursive(reversed_ll.head);
    return 0;
}