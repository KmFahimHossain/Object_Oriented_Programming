#include <iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node* prev;
    Node* next;

    // Constructor
    Node ()
    {
        value = 0;
        prev = NULL;
        next = NULL;
    }

    Node (int value)
    {
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int value)
{
    Node* newNode = new Node(value);
    if ( head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head , Node* &tail, int value)
{
    Node* newNode = new Node(value);
    if ( tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = NULL;
    tail = newNode;
}

void reverseLinkedList(Node* &head , Node* &tail)
{
    Node* currentptr = head;
    Node* nextptr = NULL;
    while(currentptr != NULL)
    {
        nextptr = currentptr->next;
        currentptr->next = currentptr->prev;
        currentptr->prev = nextptr;
        currentptr = nextptr;
    }
    Node* temp;
    temp = tail;
    tail = head;
    head = temp;
}

int size(Node* &head)
{
    int size = 0;
    Node* temp = head;
    while ( temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

void display(Node* &head)
{
    Node*temp = head;
    while ( temp != NULL)
    {
        cout<<temp->value<<"  ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head ,tail, 1);
    insertAtTail(head ,tail, 2);
    insertAtTail(head ,tail, 3);
    insertAtTail(head ,tail, 4);
    insertAtTail(head ,tail, 6);
    display(head); // 1  2  3  4  6  NULL
    reverseLinkedList(head,tail);
    display(head); // 6  4  3  2  1  NULL
    cout<<size(head); // 5
    return 0;
}

// Date : 26.09.2024
