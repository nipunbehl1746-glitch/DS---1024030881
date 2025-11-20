#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyList {
    DNode* head;
public:
    DoublyList() { head = NULL; }

    void insertFirst(int val) {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted as first node.\n";
    }

    void insertLast(int val) {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted as last node.\n";
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                DNode* newNode = new DNode;
                newNode->data = val;
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                cout << "Inserted after " << key << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found.\n";
    }

    void deleteNode(int key) {
        DNode* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                cout << "Deleted node " << key << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found.\n";
    }

    void search(int key) {
        DNode* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found.\n";
    }

    void display() {
        DNode* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
        } else {
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    DoublyList dlist;
    int choice, val, key;
    while (true) {
        cout << "\n1.Insert First \n2.Insert Last \n3.Insert After \n4.Delete Node \n5.Search Node \n6.Display \n7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Value: "; cin >> val;
            dlist.insertFirst(val);
        } else if (choice == 2) {
            cout << "Value: "; cin >> val;
            dlist.insertLast(val);
        } else if (choice == 3) {
            cout << "After data: "; cin >> key;
            cout << "Value: "; cin >> val;
            dlist.insertAfter(key, val);
        } else if (choice == 4) {
            cout << "Delete data: "; cin >> key;
            dlist.deleteNode(key);
        } else if (choice == 5) {
            cout << "Search data: "; cin >> key;
            dlist.search(key);
        } else if (choice == 6) {
            dlist.display();
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
