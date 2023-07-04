#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseK(queue<int> &q, int k)
{
    // StepA: queue -> k elements -> stack

    stack<int> s;
    int count = 0;
    int n = q.size();

    if (k == 0 || k > n)
    {
        return;
    }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if (count == k)
        {
            break;
        }
    }

    // StepB: stack - q me wapas
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // step C: push n-k elements from q front to back
    count = 0;
    while (!q.empty() && n - k != 0)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if (count == n - k)
        {
            break;
        }
    }
}
int main()
{

    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // recursiveQueueRecursion(q);

    reverseK(q, 5);

    cout << "Printing the queue " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
