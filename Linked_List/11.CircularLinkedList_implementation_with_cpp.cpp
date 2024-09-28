#include <iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node* next;

    // Constructor
    Node ()
    {
        value = 0;
        next = NULL;
    }

    Node (int value)
    {
        this->value = value;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int value)
{
    Node* newNode = new Node(value);
    if ( head == NULL)
    {
        newNode->next = newNode;;
        head = newNode;
        return;
    }

    Node* temp = head;
    while ( temp->next != head)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(Node* &head , int value, int k)
{
    if ( k == 0)
    {
        insertAtHead(head, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    int position = 0;
    while ( position != k - 1)
    {
        temp = temp->next;
        position++;
    }
    // Now temp is just before where to insert
    newNode->next=temp->next;
    temp->next = newNode;
}

void insertAtTail(Node* &head, int value)
{
    Node* newNode = new Node(value);
    if ( head == NULL)
    {
        newNode->next = newNode;;
        head = newNode;
        return;
    }

    Node* temp = head;
    while ( temp->next != head)
    {
        temp=temp->next;
    }
    // Now temp is at tail position
    temp->next = newNode;
    newNode->next = head;
}

void updateAtHead(Node* &head , int value)
{
    head->value = value;
}

void updateAtPosition ( Node* &head , int value , int k)
{
    if ( k == 0)
    {
        updateAtHead(head, value);
        return;
    }

    Node* temp = head;
    int position = 0;
    while ( position != k)
    {
        temp = temp->next;
        position++;
    }
    // Now temp is at position which we want to update
    temp->value = value;
}

void updateAtTail(Node* &head , int value)
{
    Node*temp = head;
    while ( temp->next != head)
    {
        temp = temp->next;
    }
    // Now temp is at tail
    temp->value = value;
}

void deleteHead(Node* &head)
{
    if ( head->next == head)
    {
        free(head);
    }

    Node* toDelete = head;
    Node* temp = head;
    while ( temp->next != head)
    {
        temp = temp->next;
    }
    // Now temp is at tail
    temp->next = head->next;
    free(toDelete);
    head = temp->next; // New head needed
}

void deleteAtPosition(Node* &head , int k)
{
    if ( k == 0)
    {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    int position = 0;
    while ( position != k - 1)
    {
        temp = temp->next;
        position++;
    }
    // Now temp is just before where to delete
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void deleteTail(Node* &head)
{
    if ( head->next == head)
    {
        free(head);
    }

    Node* temp = head;
    while ( temp->next->next != head)
    {
        temp = temp->next;
    }
    // Now temp is just before tail
    Node* toDelete = temp->next;
    temp->next = head;
    free(toDelete);
}

void display(Node* &head)
{
    Node* temp = head;
    cout<<temp->value<<"  ";
    while ( temp->next != head)
    {
        temp = temp->next;
        cout<<temp->value<<"  ";
    }
    cout<<endl;
}

void circularDisplay(Node* &head)
{
    Node* temp = head;
    for (int i = 0 ; i < 10 ; i++)
    {
        cout<<temp->value<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

int size(Node* &head)
{
    int size = 0;
    if ( head == NULL)
    {
        return 0;
    }

    Node* temp = head;
    while ( temp->next != head)
    {
        temp = temp->next;
        size++;
    }
    size++;
    return size;
}


int main()
{
    Node* head;
    head = NULL;
    insertAtHead(head , 1);
    display(head); // 1
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    display(head); // 1  2  3  4  5
    insertAtHead(head , 2);
    display(head); // 2  1  2  3  4  5
    updateAtHead(head , 0);
    display(head); // 0  1  2  3  4  5
    insertAtPosition(head , 13 , 3);
    display(head); // 0  1  2  13  3  4  5
    updateAtPosition(head , 8 , 4);
    display(head); // 0  1  2  13  8  4  5
    updateAtTail(head , 10);
    display(head); // 0  1  2  13  8  4  10
    deleteHead(head);
    display(head); // 1  2  13  8  4  10
    deleteAtPosition(head , 3);
    display(head); // 1  2  13  4  10
    deleteTail(head);
    display(head); // 1  2  13  4
    circularDisplay(head); // 1  2  13  4  1  2  13  4  1  2
    cout<<size(head)<<endl; // 4
    return 0;
}

// Date : 28.09.2024
