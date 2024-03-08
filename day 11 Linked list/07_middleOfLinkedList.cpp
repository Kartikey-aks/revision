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
        if (this->next == NULL) // if (this->next != NULL)
        {
            // cout << "hi" << endl;
            delete next;
            this->next = NULL;
        }
        cout << "memory free for node with data = " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // create new node
    Node *temp = new Node(data);
    // empty linked list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else // some node's are present
    {
        temp->next = head;
        head = temp;
    }
}

// traversing linked list
void printLinkedList(Node *head, Node *tail)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "empty linked list" << endl;
        return;
    }
    cout << "printing the linked list : " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << " head at " << head->data << " , tail at " << tail->data << endl;
}

void middleElementLinkedList(Node *head, Node *tail)
{
    // empty linked list or 1 element in linked list
    if (head == NULL || head->next == NULL)
    {
        cout << head->data << endl;
        return;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << "middle element of the linked list is = " << slow->data << endl;
}

int main()
{
    // starting with empty linked list
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    // insertAtHead(head, tail, 1);
    printLinkedList(head, tail);

    // find the middle element of the linked list
    //  case - even no. of elements -> middle or n/2
    //  case - odd no. of elements  -> farther from head or n/2 + 1
    middleElementLinkedList(head, tail);
    return 0;
}