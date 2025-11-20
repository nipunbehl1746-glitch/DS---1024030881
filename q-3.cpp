#include <iostream>
using namespace std ;
int size() {
    int count = 0;
    DNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

/*int size() {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
// Usage: cout << "Size: " << clist.size() << endl; */ 

