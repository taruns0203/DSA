#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];
        while (s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans2 = prevSmaller(v);

    cout << "printing prev smaller " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    cout << endl;
    return 0;
}
