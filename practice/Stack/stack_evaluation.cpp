#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(char value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            return '\0';
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(const char* expression) {
    Stack stack;
    int length = strlen(expression);

    for (int i = 0; i < length; ++i) {
        if (isdigit(expression[i])) {
            stack.push(expression[i] - '0');
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (expression[i]) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return stack.pop();
}

int evaluatePrefix(const char* expression) {
    Stack stack;
    int length = strlen(expression);

    for (int i = length - 1; i >= 0; --i) {
        if (isdigit(expression[i])) {
            stack.push(expression[i] - '0');
        } else {
            int operand1 = stack.pop();
            int operand2 = stack.pop();

            switch (expression[i]) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return stack.pop();
}

int main() {
    const char* postfixExpression = "23*5+";
    const char* prefixExpression = "+*235";

    cout << "Postfix Evaluation: " << evaluatePostfix(postfixExpression) << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefixExpression) << endl;

    return 0;
}
