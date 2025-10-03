//COMSC-210 | Lab 17 | Kristofer King
//IDE Used: VSC
#include <iostream>
using namespace std;

//declaring and initializing a maximum size for the linked list
const int SIZE = 7;  

//declaring and initializing the node structure that we will be modifying and adding to the linked list
struct Node {
    float value;
    Node *next;
};

//prototype functions for the appropriate gathering, modifying, and displaying the values of the linked list
void output(Node *);
void addToHead(int val, Node *&);
void addToTail(int val, Node *&);
void insertNode(Node *);
void deleteNode(Node *);
void deleteList(Node *);

int main() {
    //declaring and initializing the head variable for the linked list and the count of the variables within the linked list 
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) 
    {
        //declares the temp value as a random numer between 0 and 99
        int tmp_val = rand() % 100;
        char insertion;
        //asks the user whether they would like to insert the previously obtained random value at the head or the tail end of the linked list
        cout << "Where would you like to insert this value? (h for Head & t for tail)\n";
        cin >> insertion;
        cin.ignore();
        //determines, which function will be called to either add the value found to the front or back of the linked list respectively
        if(insertion == 'h' || insertion =='H')
            addToHead(tmp_val, head);
        else if(insertion == 't' || insertion =='T')
            addToTail(tmp_val, head);
    }
    //displays the current linked list by calling the ouput() function
    output(head);

    //calls the deleteNode() function, which allows users to choose which element they would like to remove from the linked list
    deleteNode(head);
    output(head);

    //calls the insertNode() function, which allows users to choose at which position they would like to insert our predetermined value
    insertNode(head);
    output(head);

    //calls the deleteList() function, which deletes the linked list all together
    deleteList(head);

    return 0;
}

//output function that will display the values of the linked list as long as it is not empty
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

//function that adds the designated value to the front of the linked list
void addToHead(int val, Node *&hd)
{
    Node *newVal = new Node;
        
    // if this is the first node, it's the new head
        if (!hd) { 
            hd = newVal;
            newVal->next = nullptr;
            newVal->value = val;
        }
        // if its a second or subsequent node; place at the head
        else {
            newVal->next = hd;
            newVal->value = val;
            hd = newVal;
        }
}

//function that adds the designated value to the back of the linked list
void addToTail(int val, Node *&hd)
{
   Node *newVal = new Node;
    // adds node at head if list is empty, as that position would also technically be the tail end
    if (hd == nullptr) 
    {
        hd = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    //iff the list is not empty, the function will traverse the array until it reaches the last value, at which point it will add the designated value to the end of the list
    else if (hd != nullptr)
    {
        Node *current = hd;
        while(current->next != nullptr)
            {
            current = current->next;
            }
        current->next = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
}

//function that allows the user to insert our predetermined value to whichever position they desire on the linkedlist
void insertNode(Node *hd)
{
    Node *current = hd;
    //displays the current values on the linked list and asks the user at which position they would like to insert our new value
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

//function that allows the user to delete an element of the linked list at whichever designated position they choose
void deleteNode(Node *hd)
{
    //requests the user to input which node they wish to delete
    Node * current = hd;
    cout << "Which node to delete? " << endl;
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverses the linked list that many times and deletes that node
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
    // checks for current to be valid before deleting the node
    if (current) {
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

//function that traverses the linked list and deletes each node individually until the entirety of the linked list is deleted
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