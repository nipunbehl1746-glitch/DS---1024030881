#include <iostream>
#include <cstring>
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
    char pop() {
        if (top != -1) { return arr[top--]; }
        return '\0';
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

int prec(char c) {
    if (c == '^') { return 3; }
    else if (c == '*' || c == '/') { return 2; }
    else if (c == '+' || c == '-') { return 1; }
    else { return -1; }
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter infix: ";
    cin >> infix;
    Stack s;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            if (!s.isEmpty()) {
                s.pop(); // pop '('
            }
        } else {
            while (!s.isEmpty() && prec(s.peek()) >= prec(c)) {
                postfix[k++] = s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix[k++] = s.pop();
    }
    postfix[k] = '\0';
    cout << "Postfix: " << postfix << endl;
    return 0;
}
