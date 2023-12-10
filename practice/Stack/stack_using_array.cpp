#include <iostream>
using namespace std;

class Stack
{
public:
    int size, top;
    int *stack;

    Stack(int _size) : size(_size), top(-1), stack(new int[_size]){};

    void push(int val)
    {
        if (top < size)
            stack[++top] = val;
    }
    int pop()
    {
        if (top > -1)
            return stack[top--];
    }
    int topElement()
    {
        return stack[top];
    }
    void printStack()
    {
        if (top > -1)
        {
            cout << "Stack :";
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << ", ";
            }
            cout << endl;
        }
        else
        {
            cout << "stack is empty" << endl;
        }
    }
};

int main()
{
    Stack abc(100);
    abc.push(5); // stack= 5
    abc.push(10);
    abc.push(30);
    abc.push(70);
    abc.printStack();                                     // 5, 10, 30, 70
    cout << "Top Element : " << abc.topElement() << endl; // 70
    abc.pop();                                            // removed 70
    abc.printStack();                                     // 5, 10, 30
    return 0;
}