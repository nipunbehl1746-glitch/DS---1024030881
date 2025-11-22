#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int val) {
        if (top != MAX-1) { arr[++top] = val; }
    }
    int pop() {
        if (top != -1) { return arr[top--]; }
        return 0;
    }
    bool isEmpty() {
        if (top == -1) { return true; }
        else { return false; }
    }
};

int main() {
    char postfix[MAX];
    cout << "Enter postfix: ";
    cin >> postfix;
    Stack s;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else {
            int b = s.pop();
            int a = s.pop();
            int res;
            if (c == '+') { res = a + b; }
            else if (c == '-') { res = a - b; }
            else if (c == '*') { res = a * b; }
            else if (c == '/') { res = a / b; }
            else { res = 0; }
            s.push(res);
        }
    }
    cout << "Result: " << s.pop() << endl;
    return 0;
}
