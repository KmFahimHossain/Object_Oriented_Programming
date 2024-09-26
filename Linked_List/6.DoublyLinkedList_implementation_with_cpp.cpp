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

class DoublyLinkedList
{
    public:
    Node* head;
    Node* tail;

    // Constructor
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Functions
    void insertAtHead(int value)
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

    void insertAtPosition(int value, int k)
    {
        if (k == 0)
        {
            insertAtHead(value);
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
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertAtTail(int value)
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

    void updateAtHead(int value)
    {
        head->value = value;
    }

    void updateAtPosition (int value , int k)
    {
        if ( k == 0)
        {
            updateAtHead( value);
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

    void updateAtTail(int value)
    {
        tail->value = value;
    }

    void deleteHead()
    {
        Node* toDelete = head;
        head = head->next;
        head->prev = NULL;
        free(toDelete);
    }

    void deleteAtPosition( int k)
    {
        if ( k == 0)
        {
            deleteHead();
            return;
        }

        Node* temp = head;
        Node* toDelete = NULL;
        int position = 0;
        while ( position != k )
        {
            temp = temp->next;
            position++;
        }

        // Now temp is at the position which we want to delete
        toDelete = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(toDelete);
    }

    void deleteTail()
    {
        Node* toDelete = tail;
        tail = tail->prev;
        free(toDelete);
        tail->next = NULL;

    }

    int size()
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

    void display()
    {
        Node*temp = head;
        while ( temp != NULL)
        {
            cout<<temp->value<<"  ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void reverseDisplay()
    {
        Node* temp = tail;
        while ( temp != NULL)
        {
            cout<<temp->value<<"  ";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }
};


int main()
{
    DoublyLinkedList list;
    list.insertAtHead(1);
    list.display(); // 1  NULL
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.display(); // 1  2  3  4  5  NULL
    list.reverseDisplay(); // 5  4  3  2  1  NULL
    list.insertAtHead(2);
    list.display(); // 2  1  2  3  4  5  NULL
    list.updateAtHead(0);
    list.display(); // 0  1  2  3  4  5  NULL
    list.insertAtPosition(13, 3);
    list.display(); // 0  1  2  13  3  4  5  NULL
    list.updateAtPosition(8 , 4);
    list.display(); // 0  1  2  13  8  4  5  NULL
    list.updateAtTail(10);
    list.display(); // 0  1  2  13  8  4  10  NULL
    list.deleteHead();
    list.display(); // 1  2  13  8  4  10  NULL
    list.deleteAtPosition(3);
    list.display(); // 1  2  13  4  10  NULL
    list.deleteTail();
    list.display(); // 1  2  13  4  NULL
    list.reverseDisplay(); // 4  13  2  1  NULL
    cout<<list.size(); // 4
    return 0;
}

// Date : 26.09.2024
