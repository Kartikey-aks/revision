#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << endl
             << "memory free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{ // if linkded list is empty
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else // some node's are present in the linked list
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{ // empty linked list
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else // some node's are present in the linked list
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtLocation(Node *&head, Node *&tail, int data, int loc)
{
    if (loc == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    // traversing to the provided loc
    Node *temp = head;
    if (temp == NULL) // if the linked list is empty and the loc is greater than 1
    {
        cout << "linked list is empty , so please add the node at the 1'st position" << endl;
        return;
    }
    int i = 1;
    while (i < loc - 1)
    {
        temp = temp->next;
        i++;
        if (temp == NULL && i <= loc)
        {
            cout << "location of node is invalid i.e. larger than the length of the linked list ." << endl;
            return;
        }
    }
    // checking if temp is at tail
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    // creating a new node
    Node *addNode = new Node(data);
    // inserting the new node
    addNode->next = temp->next;
    temp->next->prev = addNode;
    temp->next = addNode;
    addNode->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int loc)
{
    if (loc == 1) // deleting the first node
    {
        Node *temp = head;
        // only 1 node is present in the linked list
        if (head->next == NULL)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            temp->next->prev = NULL;
            temp->next = NULL;
        }
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < loc)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            if (curr == NULL && cnt <= loc)
            {
                cout << "location of node is invalid i.e. larger than the length of the linked list ." << endl;
                return;
            }
        }
        // deleting the last node
        if (curr->next == NULL)
        {
            tail = prev;
            prev->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
        else
        { // deleting the node in somewhere middle of the linked list
            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
    }
}

void printLinkedList(Node *head, Node *tail)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "empty linked list" << endl;
        return;
    }
    cout << "printing the linked list : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "head at " << head->data << " , tail at " << tail->data << endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{ // creating 1 node in the starting
    // Node *node1 = new Node(1);
    // Node *head = node1;
    // Node *tail = node1;

    // starting with empty linked list
    Node *head = NULL;
    Node *tail = NULL;
    printLinkedList(head, tail);
    int length = getLength(head);
    cout << "length = " << length << endl;
    insertAtHead(head, tail, 2);
    printLinkedList(head, tail);
    deleteNode(head, tail, 1);
    insertAtTail(head, tail, 3);
    printLinkedList(head, tail);
    deleteNode(head, tail, 1);
    insertAtLocation(head, tail, 4, 2);
    printLinkedList(head, tail);
}