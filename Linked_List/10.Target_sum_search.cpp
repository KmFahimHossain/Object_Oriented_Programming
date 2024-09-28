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

void targetSum(Node* &head , Node* &tail , int sum)
{
    Node* temp1 = head;
    Node* temp2 = head->next;
    while(temp1 !=NULL)
    {
        while(temp2 != NULL)
        {
            if ( temp1->value + temp2->value == sum)
            {
                cout<<"Found"<<"  "<<temp1->value<<"  "<<temp2->value<<endl;
                return;
            }
            else
            {
                temp2 = temp2->next;
            }
        }

        temp1 = temp1->next;
        if ( temp1 == NULL)
        {
            cout<<sum<<"  Not Found"<<endl;
            return;
        }
        temp2 = temp1->next;
    }
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
    insertAtTail(head ,tail, 3);
    insertAtTail(head ,tail, 4);
    insertAtTail(head ,tail, 5);
    insertAtTail(head ,tail, 6);
    insertAtTail(head ,tail, 1);
    insertAtTail(head ,tail, 12);
    insertAtTail(head ,tail, 11);
    display(head); // 1  2  3  4  5  6  1  12  11
    targetSum(head ,tail, 12); // Found  1  11
    targetSum(head ,tail, 11); // Found  5  6
    targetSum(head ,tail, 50); // 50  Not Found
    targetSum(head ,tail, 23); // Found  12  11
}

// Date : 27.09.2024
