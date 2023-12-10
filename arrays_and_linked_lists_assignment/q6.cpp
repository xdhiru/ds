#include <iostream>
using namespace std;

// Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Function to check if an array of integers is a palindrome
bool isPalindromeArray(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        if (arr[i] != arr[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Function to check if a linked list of integers is a palindrome
bool isPalindromeLinkedList(Node* head, int length) {
    int arr[1000]; // Assuming a maximum of 1000 elements in the linked list
    int i = 0;

    // Traverse the linked list and store elements in the array
    while (head != nullptr && i < length) {
        arr[i++] = head->data;
        head = head->next;
    }

    // Check if the array is a palindrome
    return isPalindromeArray(arr, length);
}

int main() {
    // Input for array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[1000]; // Assuming a maximum of 1000 elements in the array

    cout << "Enter " << n << " elements for the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isPalindromeArray(arr, n)) {
        cout << "The array is a palindrome." << endl;
    } else {
        cout << "The array is not a palindrome." << endl;
    }

    // Input for linked list
    int m;
    cout << "Enter the number of elements in the linked list: ";
    cin >> m;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter " << m << " elements for the linked list: ";
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (isPalindromeLinkedList(head, m)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}