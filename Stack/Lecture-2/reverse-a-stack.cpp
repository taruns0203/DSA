#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target)
{

    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();

    // rec call
    insertAtBottom(s, target);

    // BT
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{
    // base ccase
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);
    // insert at bottom target
    insertAtBottom(s, target);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    cout << "Printing After insert at bottom " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    reverseStack(s);

    return 0;
}