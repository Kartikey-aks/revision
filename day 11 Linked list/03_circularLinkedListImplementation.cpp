#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory free for node with data " << value << endl;
    }
};

void printLinkedList(Node *tail)
{
    if (tail == NULL)
    {
        cout << "linked list is empty" << endl;
        return;
    }
    Node *temp = tail;
    cout << "printing the linked list : ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << " tail at " << tail->data << endl;
}

void insertNode(Node *&tail, int element, int data)
{
    // linked list is empty
    if (tail == NULL)
    {
        cout << "linked list was empty so element was added as first Node " << endl;
        Node *temp = new Node(data);
        tail = temp;
        temp->next = tail;
    }
    else // there are some elements in the linked list
    {
        // traversing the linked list to find the provided element
        Node *curr = tail;
        while (curr->data != element)
        {
            // provided element not present in the linked list
            if (curr->next == tail && curr->data != element)
            {
                cout << "provided elment is not present in the linked list" << endl;
                return;
            }
            curr = curr->next;
        }
        // curr is representing the provided element (provided element is present in the linked list)
        Node *addNode = new Node(data);
        addNode->next = curr->next;
        curr->next = addNode;
    }
}

void deleteNode(Node *&tail, int element)
{
    // linked list is empty
    if (tail == NULL)
    {
        cout << "linked list is empty";
        return;
    }
    // some elements are present in the linked list
    // traversing the linked list
    Node *prev = tail;
    Node *curr = tail->next;
    while (curr->data != element)
    {
        // element to be deleted is not present in the linked list
        if (curr == tail && curr->data != element)
        {
            cout << "the element is not present in the linked list";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    // element found in the linked list
    // only 1 element is present in the linked list
    if (curr == prev)
    {
        tail = NULL;
    }
    // curr is representing the element to be deleted
    // prev is representing the element just before the element to be deleted

    // checking if the element to be deleted is at tail
    else if (curr == tail)
    {
        tail = curr->next; // updating the tail
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{
    // Node *node1 = new Node(10);
    Node *tail = NULL;
    insertNode(tail, 2, 1);
    printLinkedList(tail);
    // deleteNode(tail, 1);
    // printLinkedList(tail);
    insertNode(tail, 1, 2);
    printLinkedList(tail);
    insertNode(tail, 2, 5);
    printLinkedList(tail);
    insertNode(tail, 2, 4);
    printLinkedList(tail);
    deleteNode(tail, 1);
    printLinkedList(tail);
    insertNode(tail, 2, 3);
    printLinkedList(tail);
}
