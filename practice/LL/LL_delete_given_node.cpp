// LL, insertToFront to LL front, insert to nth position
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
    void insertToPos(int value, int pos){
        Node *current=head;
        Node* temp=new Node(value);
        if (head==nullptr || pos==1){
            temp->next=head;
            head=temp;
        }else{
            for (int i=1;i<pos-1;i++){
                current=current->next;
            }
            temp->next=current->next;
            current->next=temp;
        }
    }
    void deleteNode(int pos){
        Node* predecessor_of_toDelete=head;
        if (pos==1){
            head=head->next;
            delete predecessor_of_toDelete;
        }else{
            for (int i=1;i<pos-1;i++){
                predecessor_of_toDelete=predecessor_of_toDelete->next;
            }
            Node* toDelete=predecessor_of_toDelete->next;
            predecessor_of_toDelete->next=toDelete->next;
            delete toDelete;
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
    hey.insertToFront(300); // LL : 300
    hey.insertToFront(50); // 50 300
    hey.insertToFront(140); // 140 50 300
    hey.insertToPos(990,1); // 990 140 50 300
    hey.insertToPos(2,1); // 2 990 140 50 300
    hey.insertToPos(3,2); // 2 3 990 140 50 300
    hey.insertToPos(4,1); // 4 2 3 990 140 50 300
    hey.insertToPos(5,2); // 4 5 2 3 990 140 50 300
    hey.showLL();
    hey.deleteNode(3); // 4 5 3 990 140 50 300
    hey.showLL();
    return 0;
}