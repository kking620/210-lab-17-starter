#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addToHead(int val, Node *&);
void addToTail(int val, Node *&);
void insertNode(Node *);
void deleteNode(Node *);
void deleteList(Node *);

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        //calls the function to add this value to the head of a linked list
        char insertion;
        cout << "Where would you like to insert this value? (h for Head & t for tail)\n";
        cin >> insertion;
        cin.ignore();
        if(insertion == 'h' || insertion =='H')
            addToHead(tmp_val, head);
        else if(insertion == 't' || insertion =='T')
            addToTail(tmp_val, head);
    }
    output(head);

    deleteNode(head);
    output(head);

    insertNode(head);
    output(head);

    deleteList(head);

    return 0;
}

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

void addToHead(int val, Node *&hd)
{
    Node *newVal = new Node;
        
        // adds node at head
        if (!hd) { // if this is the first node, it's the new head
            hd = newVal;
            newVal->next = nullptr;
            newVal->value = val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = hd;
            newVal->value = val;
            hd = newVal;
        }
}

void addToTail(int val, Node *&hd)
{
   Node *newVal = new Node;
        // adds node at head if list is empty
        if (!hd) 
        { // if this is the first node, it's the new head
            hd = newVal;
            newVal->next = nullptr;
            newVal->value = val;
        }
        else
        {
            while(newVal->next != nullptr)
            {
               newVal = newVal->next;
            }
            newVal->value = val;

        }        
}

void insertNode(Node *hd)
{
    Node *current = hd;
    int entry;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = hd;
    Node *prev = hd;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
}

void deleteNode(Node *hd)
{
     Node * current = hd;
    cout << "Which node to delete? " << endl;
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = hd;
    Node *prev = hd;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void deleteList(Node *hd)
{
    // deleting the linked list
    Node *current = hd;
    while (current) {
        hd = current->next;
        delete current;
        current = hd;
    }
    hd = nullptr;
}