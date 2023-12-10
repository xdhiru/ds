// LL, insertToFront to LL front
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr){}
};
class LL{
    public:
    Node* head;
    LL():head(nullptr){}

    void insertToFront(int value){
        Node* temp=new Node(value);
        if (head==nullptr){
            head=temp;
        }else{
            temp->next=head;
            head=temp;
        }
    }
    void showLL(){
        Node *current=head;
        while(current!=nullptr){
            cout<<current->data<<"->";
            current=current->next;
        }
        cout<<endl;
    }
};
int main(){
    LL hey;
    hey.insertToFront(300);
    hey.insertToFront(50);
    hey.insertToFront(140);
    hey.showLL();
    return 0;
}