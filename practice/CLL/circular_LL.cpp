#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // Add a new node to the circular linked list
    void addNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == nullptr) {
            // If the list is empty, make the new node the head and point it to itself
            head = newNode;
            newNode->next = head;
        } else {
            // Traverse the list to find the last node and insert the new node at the end
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Display the circular linked list
    void display() {
        Node* temp = head;
        if (head != nullptr) {
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
        }
        cout << endl;
    }

    // Delete a node with the specified key from the circular linked list
    void deleteNode(int key) {
        if (head == nullptr) {
            return;  // If the list is empty, nothing to delete
        }

        Node* curr = head;
        Node* prev = nullptr;

        while (curr->data != key) {
            if (curr->next == head) {
                break;  // If the end of the list is reached without finding the key, break
            }
            prev = curr;
            curr = curr->next;
        }

        // Handle different cases for deleting nodes
        if (curr->next == head && curr->data != key) {
            cout << "Key not found" << endl;
            return;
        }

        if (curr == head && curr->next == head) {
            // If there's only one node, delete it and set head to nullptr
            head = nullptr;
            delete curr;
            return;
        }

        if (curr == head) {
            // If the first node is to be deleted, update head and delete the node
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = curr->next;
            prev->next = head;
            delete curr;
        } else if (curr->next == head) {
            // If the last node is to be deleted, update prev's next and delete the node
            prev->next = head;
            delete curr;
        } else {
            // If a node in between is to be deleted, update prev's next and delete the node
            prev->next = curr->next;
            delete curr;
        }
    }

    // Search for a node with the specified key and return its address
    Node* search(int key) {
        Node* temp = head;
        if (head != nullptr) {
            do {
                if (temp->data == key) {
                    return temp;
                }
                temp = temp->next;
            } while (temp != head);
        }
        return nullptr;  // Return nullptr if the key is not found
    }
};

int main() {
    CircularLinkedList cl;

    // Add nodes, display, delete a node, and search in the circular linked list
    cl.addNode(1);
    cl.addNode(2);
    cl.addNode(3);
    cl.addNode(4);
    cl.addNode(5);

    cout << "Circular Linked List: ";
    cl.display();

    cout << "Deleting 3 from the list" << endl;
    cl.deleteNode(3);
    cout << "Circular Linked List: ";
    cl.display();

    cout << "Searching for 4 in the list" << endl;
    Node* result = cl.search(4);
    if (result != nullptr) {
        cout << "Element found at address " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
