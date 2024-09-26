#include <iostream>
using namespace std;

// Given a doubly linked list, we will find it"s palindrome or not

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

string checkPalindrome ( Node* &head , Node* &tail)
{
    Node* temp1 = head;
    Node* temp2 = tail;
    while ( temp1->next != temp2->next && temp1->prev != temp2)
    {
        if ( temp1->value == temp2->value)
        {
            temp1 = temp1->next;
            temp2 = temp2->prev;
        }
        else
        {
            return "Not Palindrome";
        }
    }
    return "Palindrome";
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
    display(head); // 1  2  3
    cout<<checkPalindrome(head , tail)<<endl; // Not Palindrome
    insertAtTail(head ,tail, 2);
    display(head); // 1  2  3  2
    cout<<checkPalindrome(head , tail)<<endl; // Not Palindrome
    insertAtTail(head ,tail, 1);
    display(head); // 1  2  3  2  1
    cout<<checkPalindrome(head , tail)<<endl; // Palindrome
    insertAtTail(head ,tail, 1);
    insertAtTail(head ,tail, 2);
    insertAtTail(head ,tail, 3);
    insertAtTail(head ,tail, 2);
    insertAtTail(head ,tail, 1);
    display(head); // 1  2  3  2  1  1  2  3  2  1
    cout<<checkPalindrome(head , tail)<<endl; // Palindrome
    return 0;
}

// Date : 26.09.2024
