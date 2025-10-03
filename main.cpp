//added insertAt, deleteList, and addTail functions and finalized the code
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

//Function Prototypes
Node* addFront(Node* head, int value);
Node* addTail(Node* head, int value);
Node* deleteAt(Node* head, int entry);
Node* insertAt(Node* head, int entry, int value);
void deleteList(Node*& head);
void output(Node* head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addFront(head, tmp_val);   // adds node at head
    }
    output(head);

    //deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteAt(head, entry);
    output(head);

    //insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head = insertAt(head, entry, 10000);
    output(head);

    //deleting the linked list
    deleteList(head);
    output(head);

    //add node at the tail
    head = addTail(head, 200);
    output(head);

    return 0;
}

//adds node at head
Node* addFront(Node* head, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

//adds node at tail
Node* addTail(Node* head, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if (!head) return newNode;

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

//deleting a node
Node* deleteAt(Node* head, int entry) {
    if (!head) return nullptr;

    Node* current = head;
    Node* prev = nullptr;

    for (int i = 1; i < entry && current; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) return head;

    if (!prev) {
        head = current->next;
        delete current;
    } else {
        prev->next = current->next;
        delete current;
    }
    return head;
}

//insert a node
Node* insertAt(Node* head, int entry, int value) {
    if (!head) return nullptr;

    Node* current = head;
    for (int i = 1; i < entry && current; i++) {
        current = current->next;
    }

    if (!current) return head;

    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

//deleting the linked list
void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

//output the list
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
