#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        this->head = nullptr;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void reorderOddEven()
    {
        Node *oddHead = nullptr;
        Node *oddTail = nullptr;
        Node *evenHead = nullptr;
        Node *evenTail = nullptr;

        Node *current = head;
        while (current != nullptr)
        {
            if (current->data % 2 == 1)
            {
                if (oddHead == nullptr)
                {
                    oddHead = current;
                    oddTail = current;
                }
                else
                {
                    oddTail->next = current;
                    oddTail = current;
                }
            }
            else
            {
                if (evenHead == nullptr)
                {
                    evenHead = current;
                    evenTail = current;
                }
                else
                {
                    evenTail->next = current;
                    evenTail = current;
                }
            }
            current = current->next;
        }

        if (oddHead != nullptr)
        {
            oddTail->next = evenHead;
        }
        else
        {
            head = evenHead;
        }

        if (evenTail != nullptr)
        {
            evenTail->next = nullptr;
        }
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList llist;
    int arr[] = {1,5,6,6,7,3,4,2};
    for(int i:arr){
        llist.insertAtEnd(i);
    }
    cout << "Original list:" << endl;
    llist.print();

    llist.reorderOddEven();

    cout << "Reordered list:" << endl;
    llist.print();

    return 0;
}