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

Node *reverse(Node *head)
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

Node *solve(Node *&head1, Node *&head2)
{
    // step:1 reverse both LL
    head1 = reverse(head1);
    head2 = reverse(head2);

    // step2: Add both LL
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {

        // calculate sum
        int sum = carry + head1->data + head2->data;
        // find digit to create node for
        int digit = sum % 10;
        // calculate carry
        int carry = sum / 10;

        // create a new node for the digit
        Node *newNode = new Node(digit);

        // attach the newNode into the answer linked list
        if (ansHead == NULL)
        {
            // first node insert
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    // if head2 gets null but head1 still has nodes
    while (head1 != NULL)
    {
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }

    // if head1 gets null but head2 still has nodes
    while (head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    // if carry is still not exhausted
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // step3: reverse the ans linked list
    ansHead = reverse(ansHead);
    return ansHead;
}

int main()
{
    Node *head1 = new Node(2);
    Node *second1 = new Node(4);
    head1->next = second1;

    Node *head2 = new Node(2);
    Node *second2 = new Node(3);
    Node *third2 = new Node(4);
    head2->next = second2;
    second2->next = third2;

    Node *ans = solve(head1, head2);
    print(ans);

    return 0;
}
