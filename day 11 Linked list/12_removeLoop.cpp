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

Node *FlaudcirclePresent(Node *head)
{
    if (head == NULL) // depends upon constriaints
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
        {
            cout << endl
                 << "loop is present in the linked list and the node in the loop is " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *startingNodeFlaydAlgo(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *intersectionNode = FlaudcirclePresent(head);
    if (intersectionNode == NULL)
        return NULL;
    while (slow != intersectionNode)
    {
        slow = slow->next;
        intersectionNode = intersectionNode->next;
    }
    return slow;
}

void removeLoop(Node *head)
{
    if (head == NULL)
        return; // return NULL
    Node *loopStart = startingNodeFlaydAlgo(head);
    if (loopStart == NULL)
        return; // return head
    Node *temp = loopStart;
    while (temp->next != loopStart)
        temp = temp->next;
    temp->next = NULL;
    // return head
}

int main()
{

    // starting with empty linked list
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 15);
    insertAtTail(head, tail, 8);
    insertAtLocation(head, tail, 100, 4);
    printLinkedList(head, tail);

    tail->next = head->next;

    if (FlaudcirclePresent(head))
    {
        cout << "loop is present in the linked list" << endl;
        cout << "loop start at node = " << startingNodeFlaydAlgo(head)->data;
        cout << "after removing the loop ";
        removeLoop(head);
        cout << endl;
        printLinkedList(head, tail);
    }
    else
        cout << "loop is not present in the linked list";

    return 0;
}