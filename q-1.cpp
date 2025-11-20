#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
    Node* head;
public:
    CircularList() { head = NULL; }

    void insertFirst(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted as first node.\n";
    }

    void insertLast(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted as last node.\n";
    }

    void insertAfter(int key, int val) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node;
                newNode->data = val;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        do {
            if (curr->data == key) {
                if (prev != NULL) { // Not first node
                    prev->next = curr->next;
                    if (curr == head) { head = curr->next; }
                } else { // First node
                    if (curr->next == head) { // only one node
                        delete curr;
                        head = NULL;
                        cout << "Deleted node " << key << ".\n";
                        return;
                    }
                    Node* tail = head;
                    while (tail->next != head) { tail = tail->next; }
                    head = curr->next;
                    tail->next = head;
                }
                delete curr;
                cout << "Deleted node " << key << ".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node not found.\n";
    }

    void search(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << " (head repeated)\n";
    }
};

int main() {
    CircularList clist;
    int choice, val, key;
    while (true) {
        cout << "\n1.Insert First \n2.Insert Last \n3.Insert After \n4.Delete Node \n5.Search Node \n6.Display \n7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Value: "; cin >> val;
            clist.insertFirst(val);
        } else if (choice == 2) {
            cout << "Value: "; cin >> val;
            clist.insertLast(val);
        } else if (choice == 3) {
            cout << "After data: "; cin >> key;
            cout << "Value: "; cin >> val;
            clist.insertAfter(key, val);
        } else if (choice == 4) {
            cout << "Delete data: "; cin >> key;
            clist.deleteNode(key);
        } else if (choice == 5) {
            cout << "Search data: "; cin >> key;
            clist.search(key);
        } else if (choice == 6) {
            clist.display();
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
