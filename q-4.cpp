#include <iostream>
using namespace std;

struct DNode {
    char data;
    DNode* prev;
    DNode* next;
};

class DoublyList {
    DNode* head;
public:
    DoublyList() { head = NULL; }

    void insertLast(char val) {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next != NULL) { temp = temp->next; }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    bool isPalindrome() {
        if (head == NULL) { return true; }
        DNode* left = head;
        DNode* right = head;
        while (right->next != NULL) { right = right->next; }
        while (left != right && left->prev != right) {
            if (left->data != right->data) { return false; }
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList dlist;
    string word;
    cout << "Enter characters string: ";
    cin >> word;
    for (size_t i = 0; i < word.size(); i++) {
        dlist.insertLast(word[i]);
    }
    if (dlist.isPalindrome()) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}
