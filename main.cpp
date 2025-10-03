// Refactored addFront into a function and added stubs for deleteAt, insertAt, deleteList


#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// ---------- Function Prototypes ----------
Node* addFront(Node* head, int value);
Node* deleteAt(Node* head, int entry);             // stub
Node* insertAt(Node* head, int entry, int value);  // stub
void deleteList(Node*& head);                      // stub
void output(Node* head);

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addFront(head, tmp_val);   // ✅ refactored
    }

    cout << "Initial list:\n";
    output(head);

    // still inline code for delete/insert/cleanup (will refactor later)

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    if (current) {  
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
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

// ---------- Function Definitions ----------

// Add node at the head
Node* addFront(Node* head, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

// Stub functions (to be implemented later)
Node* deleteAt(Node* head, int entry) {
    return head;
}

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
