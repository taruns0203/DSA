
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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool checkPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return true;
    }

    if (head->next == NULL)
    {
        // only 1 Node
        return true;
    }

    // greater than 1 Node

    // Step1: find the middle Node
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // slow pointer pointing to the middle Node

    // Step2: reverse LL after the middle Node
    Node *reverseLLHead = reverse(slow->next);

    // Step3: put slow->next to reverseLLHead(join reverse LL into the  left part)
    slow->next = reverseLLHead;

    // Step4: start comparison
    Node *temp1 = head;
    Node *temp2 = reverseLLHead;

    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            // not a Palindrome
            return false;
        }
        else
        {
            // if data is equal, move forward
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(20);
    Node *fifth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    bool isPalindrome = checkPalindrome(head);

    if (isPalindrome)
    {
        cout << "LL is a valid a Palindrome" << endl;
    }
    else
    {
        cout << "LL is not a valid Palindrome" << endl;
    }

    return 0;
}
