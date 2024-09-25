#include <iostream>
using namespace std;

//We will reverse a Singly-linked-list

class Node
{
    public:
    int value;
    Node* next;

    // Constructor
    Node (int value)
    {
        this->value = value;
        next = NULL;
    }
};

void insertAtHead(Node* &head , int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head , int value)
{
    Node* newNode = new Node(value);
    Node*temp = head;
    while ( temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* reverseLinkedList(Node* &head)
{
    Node* prevptr = NULL;
    Node* currentptr = head;
    Node* nextptr = NULL;
    while ( currentptr != NULL)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;
    }
    return prevptr;
}

void display(Node* &head)
{
    Node*temp = head;
    while ( temp != NULL)
    {
        cout<<temp->value<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head = NULL;
    insertAtHead(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 2);
    display(head); // 1-> 2-> 2-> 3-> 4-> 5-> 2-> NULL
    head = reverseLinkedList(head);
    display(head); // 2-> 5-> 4-> 3-> 2-> 2-> 1-> NULL , reversed
    return 0;
}

// Date : 25.09.2024
