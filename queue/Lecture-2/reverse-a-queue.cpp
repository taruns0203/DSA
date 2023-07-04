#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseUsingStack(queue<int> &q)
{
    stack<int> s;

    // put elements od q into stack
    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        s.push(element);
    }

    // step2: put all element from stack into q
    while (!s.empty())
    {
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void recursiveQueueRecursion(queue<int> &q)
{
    // Base case
    if (q.empty())
    {
        return;
    }

    // step A
    int temp = q.front();
    q.pop();

    // step B
    recursiveQueueRecursion(q);

    // step c
    q.push(temp);
}

int main()
{

    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseUsingStack(q);

    cout << "Printing the queue " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
