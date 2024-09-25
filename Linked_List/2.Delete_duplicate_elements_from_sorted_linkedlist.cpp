#include <iostream>
using namespace std;

/* Given the head of a sorted linked list, we need to delete all duplicates,
 such that each element appears only once. We will return the new linked list too.*/

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

Node* deleteDuplicates(Node* &head)
{
    Node* temp = head;
    Node* toDelete = NULL;
    while(temp->next != NULL)
    {
        while(temp->value == temp->next->value)
        {
            toDelete = temp->next;
            temp->next = temp->next->next;
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
    insertAtTail(head , 3);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 5);
    insertAtTail(head , 6);
    display(head); //1-> 2-> 2-> 3-> 3-> 3-> 4-> 5-> 5-> 6-> NULL
    head = deleteDuplicates(head);
    display(head); // 1-> 2-> 3-> 4-> 5-> 6-> NULL
    return 0;
}

// Date : 25.09.2024
