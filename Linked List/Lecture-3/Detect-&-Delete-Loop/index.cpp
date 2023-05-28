#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // TODO:- write a destructor to delete the Node
    ~Node()
    {
        // write your code here
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// Problem Variation -1 :  Detect a Loop in LL
bool checkForLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            // loop present
            return true;
        }
    }
    // fast NULL i.e no loop present
    return false;
}

// Problem variation -2 : Find the starting point of the Loop
Node *startingPointLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            // loop present - put slow on head
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Problem variation -3 : Remove the Loop
Node *removeLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            // loop present - put slow on head
            slow = head;
            break;
        }
    }

    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL;

    return slow;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    // For Loop
    ninth->next = fifth;

    // for no Loop
    // ninth -> next = NULL;

    cout << "Loop is present or not " << checkForLoop(head);
    cout << "Starting point of Loop is " << startingPointLoop(head)->data << endl;

    removeLoop(head);
    print(head);
    cout << "Loop is present or not " << checkForLoop(head) << endl;

    return 0;
}
