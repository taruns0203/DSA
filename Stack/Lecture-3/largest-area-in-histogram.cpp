// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> prevSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}
vector<int> nextSmaller(vector<int> &v)
{
    stack<int> s;

    s.push(-1);

    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int getrectangularAreaHistogram(vector<int> &height)
{
    // step1: prevSmaller outpur

    vector<int> prev = prevSmaller(height);

    // step2: nextSmaller output
    vector<int> next = nextSmaller(height);

    int maxArea = INT_MIN;
    int size = height.size();

    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];

        if (next[i] == -1)
        {
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;
        int area = length * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout << "Ans is: " << getrectangularAreaHistogram(v) << endl;

    cout << endl;
    return 0;
}
