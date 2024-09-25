#include <iostream>

using namespace std;

/* We will print a singly-linked-list in reverse order,
 by using recursive function */

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

void reversePrint(Node* &head)
{
    if ( head == NULL )
    {
        return;
    }
    reversePrint(head->next);
    cout<<head->value<<"  ";
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
    reversePrint(head); // 2  5  4  3  2  2  1
    return 0;
}

// Date : 25.09.2024
