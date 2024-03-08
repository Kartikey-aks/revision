#include "01_singleLinkedListImplymentation.cpp"

void mergeList(Node *&head1, Node *&head2, Node *&tail1, Node *&tail2)
{
    // if one of the list is empty.
    if (head1 == NULL)
    {
        head1 = head2;
        tail1 = tail2;
        return;
    }
    if (head2 == NULL)
    {
        // head2 = head1;  // considering that the merged list head is head1 and tail is tail1
        // tail2 = tail1;
        return;
    }
    // if both the list's are non-empty.
    // placing the head1 at the list with starting node with minimum value
    if (head1->data >= head2->data)
    {
        Node *temp = head1;
        head1 = head2;
        head2 = temp;
    }
    Node *curr1 = head1, *next1 = head1->next, *curr2 = head2, *next2 = head2->next;
    cout << curr1->data << endl
         << next1->data << endl
         << curr2->data << endl
         << next2->data << endl;
    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            cout << "hi" << endl;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
            next2 = next2->next;
        }
        else
        {
            cout << "bye" << endl;
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                tail1 = tail2;
                break;
            }
        }
    }
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    insertAtHead(head1, tail1, 6);
    insertAtHead(head1, tail1, 3);
    insertAtHead(head1, tail1, 1);
    insertAtHead(head2, tail2, 5);
    insertAtHead(head2, tail2, 4);
    insertAtHead(head2, tail2, 2);
    mergeList(head1, head2, tail1, tail2);
    printLinkedList(head1, tail1);
    return 0;
}