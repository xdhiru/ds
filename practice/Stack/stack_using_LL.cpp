#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
    Node(int _val):data(_val),link(nullptr){};
};

class Stack{
    public:
    Node* top;
    
    Stack(){
        top=nullptr;
    }
    void push(int val){
        Node* temp=new Node(val);
        if (top==nullptr){
            top=temp;
        }else{
            temp->link=top;
            top=temp;
        }
    }

    void pop(){
        if (top==nullptr){
            cout<<"NOTHING TO POP! Stack is empty"<<endl;
        }else{
            Node* temp=top;
            top=top->link;
            delete temp;
        }
    }
    void displayStack(){
        Node* temp=top;
        cout<<"Stack : ";
        while(temp!=nullptr){
            cout<<temp->data<<", ";
            temp=temp->link;
        }
        cout<<endl;
    }
};

int main(){
    Stack s;
    s.push(5);              // 5
    s.displayStack();
    s.push(30);             // 5 30
    s.push(50);             // 5 30 50
    s.displayStack();
    s.pop();                // 5 30
    s.displayStack();       
    s.push(90);             // 5 30 90    
    s.displayStack();
    s.pop();                // 5 30
    s.pop();                // 5     
    s.pop();                // EMPTY
    s.displayStack();
    s.pop();
    return 0;
}