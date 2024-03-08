#include <iostream>
#include "01_singleLinkedListImplymentation.cpp"
using namespace std;

Node *findMidNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *mergeList(Node *&leftHead, Node *&rightHead, Node *&tail)
{
    // cout << "merge sort called " << endl;
    if (leftHead == NULL)
        return rightHead;
    if (rightHead == NULL)
        return leftHead;
    Node *tempHead = new Node(-1);
    Node *temp = tempHead;
    while (leftHead != NULL && rightHead != NULL)
    {
        if (leftHead->data < rightHead->data)
        {
            temp->next = leftHead;
            temp = leftHead;
            leftHead = leftHead->next;
        }
        else
        {
            temp->next = rightHead;
            temp = rightHead;
            rightHead = rightHead->next;
        }
    }
    while (leftHead != NULL)
    {
        temp->next = leftHead;
        tail = leftHead;
        temp = leftHead;
        leftHead = leftHead->next;
    }
    while (rightHead != NULL)
    {
        temp->next = rightHead;
        tail = rightHead;
        temp = rightHead;
        rightHead = rightHead->next;
    }
    tempHead = tempHead->next;
    return tempHead;
}

void mergeSort(Node *&head, Node *&tail)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        tail = head;
        return;
    }
    Node *midNode = findMidNode(head);
    // cout << "midNode is " << midNode->data << endl;
    Node *leftHead = head;
    Node *rightHead = midNode->next;
    midNode->next = NULL;
    mergeSort(leftHead, tail);
    mergeSort(rightHead, tail);
    leftHead = mergeList(leftHead, rightHead, tail);
    // cout << "after merge" << endl;
    head = leftHead;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    printLinkedList(head, tail);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 8);
    printLinkedList(head, tail);
    mergeSort(head, tail);
    cout << "after merge sort ." << endl;
    printLinkedList(head, tail);
    return 0;
}