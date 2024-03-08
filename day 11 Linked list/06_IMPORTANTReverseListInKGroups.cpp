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

Node *reverseLinkedListIn_Kgroup(Node *&head, Node *&tail, int k)
{
    // base case
    if (head == NULL || k <= 1)
    {
        return head;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = curr;
    int cnt = 1;
    while (curr != NULL && cnt <= k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if (curr == NULL)
        tail = head;
    // Node *chotaHead = reverseLinkedListIn_Kgroup(curr, tail, k);
    // cout << "head befor " << head->data << " ";
    // head->next = chotaHead;
    head->next = reverseLinkedListIn_Kgroup(curr, tail, k);
    head = prev;
    // cout << " and after " << head->data << endl;
    return head;
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
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 0);
    printLinkedList(head, tail);

    reverseLinkedListIn_Kgroup(head, tail, 2);
    printLinkedList(head, tail);
    return 0;
}