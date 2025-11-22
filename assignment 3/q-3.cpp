#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) {
        if (top != MAX-1) { arr[++top] = c; }
    }
    void pop() {
        if (top != -1) { top--; }
    }
    char peek() {
        if (top != -1) { return arr[top]; }
        return '\0';
    }
    bool isEmpty() {
        if (top == -1) { return true; }
        else { return false; }
    }
};

bool isBalanced(char expr[]) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            s.push(expr[i]);
        }
        else if (expr[i] == ')') {
            if (s.isEmpty()) {
                return false;
            }
            else {
                s.pop();
            }
        }
    }
    return s.isEmpty();
}

int main() {
    char expr[MAX];
    cout << "Enter expression: ";
    cin >> expr;
    if (isBalanced(expr)) {
        cout << "Balanced Parentheses.\n";
    }
    else {
        cout << "Not Balanced Parentheses.\n";
    }
    return 0;
}
