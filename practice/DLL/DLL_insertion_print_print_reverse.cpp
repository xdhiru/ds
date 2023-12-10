#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val):data(val),next(nullptr),prev(nullptr){};
};

class DLL{
    public:
    Node* head=nullptr;

    void insertToFront(int val){
        Node* temp=new Node(val);
        if (head==nullptr){
            head=temp;
        }else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }

    void printDLL(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }

    void printReversedDLL(){
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->prev;
        }
        cout<<endl;
    }
};

int main(){
    DLL nice;
    nice.insertToFront(5); // 5
    nice.insertToFront(30); // 30 5
    nice.insertToFront(99); // 99 30 5
    nice.printDLL();                // 99, 30, 5
    nice.printReversedDLL();        // 5, 30, 99
    return 0;
}