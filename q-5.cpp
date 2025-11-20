#include <iostream>
using namespace std ;
bool isCircular() {
    if (head == NULL) { return false; }
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    if (temp == head) {
        return true;
    } else {
        return false;
    }
}
cout << (clist.isCircular() ? "Circular" : "Not circular") << endl;
