#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val1) : data(val1), next(nullptr) {}
};

class LinkedList {
public:
    Node* head = nullptr;

    void insertToFront(int val) {
        Node* temp = new Node(val);
        if (head == nullptr) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void printRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }
        cout << current->data << "->";
        printRecursive(current->next);
    }

    void reversePrintRecursive(Node* front_) {
        if (front_ == nullptr) {
            return;
        }
        reversePrintRecursive(front_->next);
        cout << front_->data << "->";
    }

    Node* reverseRecursive(Node* front_) {
        if (front_->next == nullptr) {
            return front_;
        }
        Node* reversed = reverseRecursive(front_->next);
        front_->next->next = front_;
        front_->next = nullptr;
        return reversed;
    }
};

int main() {
    LinkedList myList;
    myList.insertToFront(300);
    myList.insertToFront(50);
    myList.insertToFront(140);

    cout << "Original List: ";
    myList.printRecursive(myList.head);
    cout << endl;

    cout << "Reverse Printed List: ";
    myList.reversePrintRecursive(myList.head);
    cout << endl;

    LinkedList reversedList;
    reversedList.head = myList.reverseRecursive(myList.head);

    cout << "Reversed List: ";
    reversedList.printRecursive(reversedList.head);

    return 0;
}
