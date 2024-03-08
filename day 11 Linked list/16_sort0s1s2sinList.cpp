#include "01_singleLinkedListImplymentation.cpp"

void sort(Node *&head, Node *&tail)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // traversing through the list
    // filling the node's in the above 3 list's
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insertAtTail(zeroHead, zeroTail, temp->data);
        }
        else if (temp->data == 1)
        {
            insertAtTail(oneHead, oneTail, temp->data);
        }
        else if (temp->data == 2)
        {
            insertAtTail(twoHead, twoTail, temp->data);
        }
        temp = temp->next;
    }
    // linking the 3 list's into 1 list
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    // twoTail->next = NULL;  //because we have function insert at tail which is directly maintaining the null
    tail = twoTail;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    delete zeroTail;
    delete oneTail;
    delete twoTail;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    printLinkedList(head, tail);
    sort(head, tail);
    printLinkedList(head, tail);
    return 0;
}
