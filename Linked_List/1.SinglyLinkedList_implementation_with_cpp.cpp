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

void insertAtHead(Node* &head , int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(Node* &head , int value, int k)
{
    if ( k == 0)
    {
        insertAtHead(head , value);
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

void insertAtTail(Node* &head , int value)
{
    Node* newNode = new Node(value);
    Node*temp = head;
    while ( temp->next != NULL)
    {
        temp = temp->next;
    }
    // Now temp is at last position
    temp->next = newNode;
}

void updateAtHead(Node* &head , int value)
{
    head->value = value;
}

void updateAtPosition ( Node* &head , int value , int k)
{
    if ( k == 0)
    {
        updateAtHead(head , value);
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
    while ( temp->next != NULL)
    {
        temp = temp->next;
    }
    // Now temp is at tail
    temp->value = value;
}

void deleteHead(Node* &head)
{
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtPosition(Node* &head , int k)
{
    if ( k == 0)
    {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    Node* toDelete = NULL;
    int position = 0;
    while ( position != k - 1)
    {
        temp = temp->next;
        position++;
    }
    // Now temp is just before the position which we want to delete
    toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void deleteTail(Node* head)
{
    Node* temp = head;
    Node* toDelete = NULL;
    while ( temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // Now temp is just before of the tail
    toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);
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
        cout<<temp->value<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head;
    head = NULL;
    insertAtHead(head , 1);
    display(head); // 1-> NULL
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    display(head); // 1-> 2-> 3-> 4-> 5-> NULL
    insertAtHead(head , 2);
    display(head); // 2-> 1-> 2-> 3-> 4-> 5-> NULL
    updateAtHead(head , 0);
    display(head); // 0-> 1-> 2-> 3-> 4-> 5-> NULL
    insertAtPosition(head , 13 , 3);
    display(head); // 0-> 1-> 2-> 13-> 3-> 4-> 5-> NULL
    updateAtPosition(head , 8 , 4);
    display(head); // 0-> 1-> 2-> 13-> 8-> 4-> 5-> NULL
    updateAtTail(head , 10);
    display(head); // 0-> 1-> 2-> 13-> 5-> 4-> 10-> NULL
    deleteHead(head);
    display(head); // 1-> 2-> 13-> 5-> 4-> 10-> NULL
    deleteAtPosition(head , 3);
    display(head); // 1-> 2-> 13-> 4-> 10-> NULL
    deleteTail(head);
    display(head); // 1-> 2-> 13-> 4-> NULL
    cout<<size(head); // 4
    return 0;
}

// Date : 25.09.2024
