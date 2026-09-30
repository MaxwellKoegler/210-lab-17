//Maxwell Koegler | 9/29/26 | Lab 17 | COMSC 210

#include <iostream>
using namespace std;

void addNodeFront(Node *&head);
void addNodeTail(Node *&head);
void deleteNode(Node *&head);
void insertNode(Node *&head);
void deleteList(Node *&head);
void output(Node *head);

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
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

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}


void addNodeFront(Node *&head){
    Node *newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->value;
    newNode->next = head;
    head = newNode;
}
void addNodeTail(Node *&head){
    Node *newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->value;
    newNode->next = nullptr;
    Node *current = head;
    while(current->next) {
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
    for(int i =0; i < e; i++) {
        prev = current;
        current = current->next;
    }

    

}
void deleteList(Node *&head){

}
void output(Node *head){

}
