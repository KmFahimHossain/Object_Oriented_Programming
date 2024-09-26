#include <iostream>
using namespace std;

/* Given a sorted doubly-linked-list, we need to delete all duplicates,
 such that each element appears only once. We will return the new linked list too.*/

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

Node* deleteDuplicates(Node* &head , Node* tail)
{
    Node* temp = head;
    Node* toDelete = NULL;
    while(temp->next != NULL)
    {
        while(temp->value == temp->next->value)
        {
            toDelete = temp->next;
            temp->next = temp->next->next;
            temp->next->next->prev = temp;
            free(toDelete);
            if (temp->next == NULL)
            {
                return head;
            }
        }
        temp = temp -> next;
    }
    return head;
}

void display(Node* &head)
{
    Node*temp = head;
    while ( temp != NULL)
    {
        cout<<temp->value<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head ,tail, 1);
    insertAtTail(head ,tail, 2);
    insertAtTail(head ,tail, 2);
    insertAtTail(head ,tail, 2);
    insertAtTail(head ,tail, 3);
    insertAtTail(head ,tail, 4);
    insertAtTail(head ,tail, 4);
    insertAtTail(head ,tail, 5);
    insertAtTail(head ,tail, 1);
    display(head); // 1  2  2  2  3  4  4  5  1
    deleteDuplicates(head , tail);
    display(head); // 1  2  3  2  1  1  2  3  2  1
    return 0;
}

// Date : 26.09.2024
