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

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // creating new node
    Node *temp = new Node(data);
    // empty linkded list
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else // some node's are present in the linked list
    {
        tail->next = temp;
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
    if (temp == NULL) // if linked list is empty and loc is greater than 1
    {
        cout << "linked list is empty , so please add the node at the 1's position" << endl;
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
    temp->next = addNode;
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
            delete curr;
        }
        else
        { // deleting the node in somewhere middle of the linked list
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
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
    cout << "printing the list : " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << " head at " << head->data << " , tail at " << tail->data << endl;
}

void removeDublicate(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;
    Node *temp = head;
    int cnt = 2;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            deleteNode(head, tail, cnt);
            // temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
            cnt++;
        }
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 5);
    insertAtTail(head, tail, 8);
    insertAtHead(head, tail, 1);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 6);
    insertAtHead(head, tail, 1);
    insertAtLocation(head, tail, 100, 4);
    insertAtLocation(head, tail, 100, 4);
    printLinkedList(head, tail);
    removeDublicate(head, tail);
    printLinkedList(head, tail);
}