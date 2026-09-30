//Maxwell Koegler | 9/29/26 | Lab 17 | COMSC 210
//I chose to pursue the refrence apporach because it made it easier
//to formulate the functions without worrying about return types and
//copied values across different iterations

#include <iostream>
using namespace std;
struct Node { //struct must come before prototypes because they use the struct in the def
    float value;
    Node *next;
};
void addNodeFront(Node *&head); // prototypes
void addNodeTail(Node *&head);
void deleteNode(Node *&head);
void insertNode(Node *&head);
void deleteList(Node *&head);
void output(Node *head);
const int SIZE = 7;
int main() {
    Node *head = nullptr; //creates list
    int choice = 0;
    for (int i = 0; i < SIZE; i++) {
        addNodeFront(head);
    }
    output(head); 
    while(choice != 7){ //option list
        cout << "\n1. Add node to front" << endl;
        cout << "2. Add node to end" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Insert node" << endl;
        cout << "5. Delete entire list" << endl;
        cout << "6. Print list" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        if (choice == 1) { //choice selection
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
            cout << "Exiting." << endl;
        }else{
            cout << "Invalid option";
        }
    }
   
    return 0;
}

void addNodeFront(Node *&head){ //adds random node to front
    Node *newNode = new Node;
    newNode->value = rand() % 100;
    newNode->next = head;
    head = newNode;
}
void addNodeTail(Node *&head) { //adds random node to tails
    Node *newNode = new Node;
    newNode->value = rand() % 100;
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
void deleteNode(Node *&head){ //deletes specified node
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
void insertNode(Node *&head){ //inserts a specified node
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
void deleteList(Node *&head){ //deletes the whole list
    Node *current = head;
    while(current){
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
void output(Node *head){ //outputs the whole list
    int count = 1;
    Node *current = head;

    while(current) {
        cout << "[" << count++ << "]" << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
