// implemented deleteAt function and also updated main tp be able to use it 

#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function Prototypes
Node* addFront(Node* head, int value);
Node* deleteAt(Node* head, int entry);             
Node* insertAt(Node* head, int entry, int value);  // stub
void deleteList(Node*& head);                      // stub
void output(Node* head);

int main() {
    Node *head = nullptr;

    // makes a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addFront(head, tmp_val);
    }

    cout << "Initial list:\n";
    output(head);

    // using deleteAt()
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteAt(head, entry);
    cout << "List after deletion:\n";
    output(head);

    // insert a node "inline"
    Node * current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list (still inline for now)
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

// Function Definitions

// Add node at the head
Node* addFront(Node* head, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

// implemented deleteAt
Node* deleteAt(Node* head, int entry) {
    if (!head) return nullptr;

    Node* current = head;
    Node* prev = nullptr;

    // move to nth node
    for (int i = 1; i < entry && current; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) return head; // invalid entry

    if (!prev) { // delete head
        head = current->next;
        delete current;
    } else {
        prev->next = current->next;
        delete current;
    }
    return head;
}

// Stub functions 
Node* insertAt(Node* head, int entry, int value) {
    return head;
}

void deleteList(Node*& head) {
    head = nullptr;
}

// Print linked list
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

