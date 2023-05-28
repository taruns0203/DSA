#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        cout << "Node with value " << this->data << "deleted " << endl;
    }
};

void print(Node *&head)
{ // T.C = O(n), S.C = O(n)
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *head)
{ // T.C = O(n), S.C = O(n)
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{ // T.C. - O(n) ,
    if (head == NULL)
    {
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is non-empty
        // Step:1 create a new Node
        Node *newNode = new Node(data);

        // Step2:
        newNode->next = head;

        // Step3:
        head->prev = newNode;

        // step4:
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is non-empty
        // Step:1 create a new Node
        Node *newNode = new Node(data);

        // Step2:
        tail->next = newNode;

        // Step3:
        newNode->prev = tail;

        // step4:
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }

        int len = getLength(head);
        if (position > len)
        {
            insertAtTail(head, tail, data);
            return;
        }

        // insertion in middle
        // Step1: find prev && curr
        int i = 1;
        Node *prevNode = head;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }

        Node *curr = prevNode->next;

        // Step2: create a new Node
        Node *newNode = new Node(data);

        // step:3
        prevNode->next = newNode;
        newNode->prev = prevNode;
        curr->prev = newNode;
        newNode->next = curr;
    }
}

void deleteFromPos(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Linked List is empty";
        return;
    }

    if (head->next == NULL)
    {
        // single Node
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);

    if (position > len)
    {
        cout << "Please enter a valid position " << endl;
        return;
    }

    if (position == 1)
    {
        // want to delete the first Node
        Node *temp = head;

        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (position == len)
    {
        // delete last Node
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    // delete from middle of the Linked List
    // step1: find left , curr, right
    int i = 1;
    Node *left = head;
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }

    Node *curr = left->next;
    Node *right = curr->next;

    // Step2: Put next of left on right
    left->next = right;

    // Step3: Put prev of right on left
    right->prev = left;

    // step4:
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

Node *reverse(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        // LL revese ho chuki he
        return prev;
    }

    // 1 case solve then recursion will take care
    Node *forward = curr->next;
    curr->next = prev;
    reverse(curr, forward);
}

Node *reverseUsingLoop(Node *head)
{
    Node *prev = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node *reverseUsingRecursion(Node *prev, Node *curr)
{
    // base case
    if (curr == NULL)
    {
        // LL revese ho chuki he
        return prev;
    }

    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    // recursion
    return reverseUsingRecursion(prev, curr);
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    Node *head = first;
    Node *tail = third;

    cout << endl;
    print(first);
    cout << endl;
    insertAtHead(head, tail, 101);
    print(head);

    cout << endl;

    insertAtTail(head, tail, 501);
    print(head);

    cout << endl;

    insertAtPosition(head, tail, 401, 5);
    print(head);

    cout << "Delete operations starts here " << endl;
    deleteFromPos(head, tail, 10);

    cout << endl;
    print(head);

    Node *prev = NULL;
    Node *curr = head;
    head = reverse(prev, curr);
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}
