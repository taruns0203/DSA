#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

Node *getMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty ";
    }

    if (head->next == NULL)
    {
        // only 1 node in LL
        return head;
    }

    // LL has multiple nodes
    Node *slow = head;
    // for even off if u need n/2+1 middle node
    Node *fast = head;

    // for even off if u need n/2 middle node
    // Node* fast = head->next;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

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

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);
    cout << endl;
    cout << "Middle node is " << getMiddle(head)->data << endl;

    return 0;

    return 0;
}
