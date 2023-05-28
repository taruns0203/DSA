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

// Brute force using the counting approach
void sortZeroOneTwoBF(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return NULL;
    }

    if (head->next == NULL)
    {
        cout << "LL is single element " << endl;
        return head;
    }

    // Step-1: fint count of 0's , 1' and 2's
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else if (temp->data == 2)
        {
            two++;
        }

        temp = temp->next;
    }

    // step2: , fill 0,1,2 in original LL
    temp = head;
    while (temp != NULL)
    {
        // fill zerores
        while (zero--)
        {
            temp->data = 0;
            temp = temp->next;
        }
        // fill ones
        while (one--)
        {
            temp->data = 1;
            temp = temp->next;
        }

        // fill twos
        while (two--)
        {
            temp->data = 2;
            temp = temp->next;
        }
    }
}

// optimal using pointer conversion
Node *sortZeroOneTwoOPTIMAL(Node *&head)
{

    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return NULL;
    }

    if (head->next == NULL)
    {
        cout << "LL is single element " << endl;
        return head;
    }
    Node *zeroHead = new Node(-101);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-101);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-101);
    Node *twoTail = twoHead;

    // traverse the original LL
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {

            // take out o node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }

        else if (curr->data == 1)
        {
            // take out 1 node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the one node in zeroHead LL
            oneTail->next = temp;
            oneTail = temp;
        }

        else if (curr->data == 2)
        {
            // take out 2 node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the two node in zeroHead LL
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // modify one LL -> remove -1 Node
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // modify two LL -> remove -1 Node
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // here zero, one and two LL is ready

    // join them
    if (oneHead != NULL)
    {
        // one wali list is non empty
        zeroTail->next = oneHead;

        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    {
        // one wali list is empty
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    // remove dummy Node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of the joined LL
    return zeroHead;
}
int main()
{
    Node *head = new Node(2);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(2);
    Node *fifth = new Node(2);
    Node *sixth = new Node(2);
    Node *seventh = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    print(head);

    head = sortZeroOneTwoOPTIMAL(head);
    cout << endl;

    print(head);

    return 0;
}
