#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) {
        if (top != MAX-1) {
            arr[++top] = c;
        }
    }
    char pop() {
        if (top != -1) {
            return arr[top--];
        }
        return '\0';
    }
    bool isEmpty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    char str[MAX];
    cout << "Enter string: ";
    cin >> str;

    Stack s;
    for(int i = 0; str[i] != '\0'; i++) {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    while(!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
    return 0;
}
