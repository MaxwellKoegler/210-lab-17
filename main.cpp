//Maxwell Koegler | 9/29/26 | Lab 17 | COMSC 210

#include <iostream>
using namespace std;

struct Node {
    float value;
    Node *next;
};

void addNodeFront(Node *&head);
void addNodeTail(Node *&head);
void deleteNode(Node *&head);
void insertNode(Node *&head);
void deleteList(Node *&head);
void output(Node *head);
const int SIZE = 7;

int main() {
    Node *head = nullptr;
    int choice = 0;
    for (int i = 0; i < SIZE; i++) {
        addNodeFront(head);
    }
    output(head);
    while(choice != 7){
        cout << "\n1. Add node to front" << endl;
        cout << "2. Add node to end" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Insert node" << endl;
        cout << "5. Delete entire list" << endl;
        cout << "6. Print list" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice --> ";
        cin >> choice;
        if (choice == 1) {
            addNodeFront(head);
        }else if (choice == 2) {
            addNodeTail(head);
        }else if (choice == 3) {
            deleteNode(head);
        }else if (choice == 4) {
            insertNode(head);
        }else if (choice == 5) {
            deleteList(head);
        }else if (choice == 6) {
            output(head);
        }else if (choice == 7) {
            cout << "Exiting..." << endl;
        }else{
            cout << "Invalid option";
        }
        return 0;
    }

    // create a linked list of size SIZE with random numbers 0-99
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);
    return 0;
}

void addNodeFront(Node *&head){
    Node *newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->value;
    newNode->next = head;
    head = newNode;
}
void addNodeTail(Node *&head) {
    Node *newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}
void deleteNode(Node *&head){
    int entry;
    cout << "Which node to delete? ";
    cin >> entry;
    Node *current = head;
    Node *prev = nullptr;
    for(int i = 0; i < entry - 1; i++){
        prev = current;
        current = current->next;
    }
    if(current){
        if(prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }
}
void insertNode(Node *&head){
    int e;
    cout << "which node to insert after? ";
    cin >> e;
    Node *current = head;
    Node *prev = nullptr;
    for(int i = 0; i < e; i++) {
        prev = current;
        current = current->next;
    }
    Node *newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->value;
    newNode->next = current;
    if(prev == nullptr){
        head = newNode;
    }else {
        prev->next = newNode;
    }
}
void deleteList(Node *&head){
    Node *current = head;
    while(current){
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
void output(Node *head){
    int count = 1;
    Node *current = head;

    while(current) {
        cout << "[" << count++ << "]" << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
