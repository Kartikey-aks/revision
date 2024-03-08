#include <iostream>
#include <map>
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

bool circlePresent(Node *head)
{
    if (head == NULL)
        return false;
    // creating map
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "loop in linked list starts at node " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    // creating object in heap
    // creating the new node i.e. first node in the starting

    // Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointed to node1

    // Node *head = node1;
    // Node *tail = node1;

    // starting with empty linked list
    Node *head = NULL;
    Node *tail = NULL;
    // printLinkedList(head, tail);
    insertAtHead(head, tail, 12);
    // printLinkedList(head, tail);
    insertAtHead(head, tail, 15);
    // printLinkedList(head, tail);
    insertAtTail(head, tail, 8);
    // printLinkedList(head, tail);
    //  deleteNode(head, tail, 3);
    // printLinkedList(head, tail);
    //  deleteNode(head, tail, 1);
    // printLinkedList(head, tail);
    //  deleteNode(head, tail, 1);
    // printLinkedList(head, tail);
    insertAtLocation(head, tail, 100, 4);
    // printLinkedList(head, tail);
    tail->next = head->next->next;
    if (circlePresent(head))
    {
        cout << "loop is present in the linked list";
    }
    else
        cout << "loop is not present in the linked list";
    return 0;
}