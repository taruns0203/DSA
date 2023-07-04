#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];
        // apka answer mill chuka he
        while (s.top() >= curr)
        {
            s.pop();
        }
        // chota element mill chuka he -> ans store
        ans[i] = s.top();

        // push krdo curr element ko
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

    vector<int> ans1 = nextSmaller(v);

    cout << "printing Next smaller " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
    return 0;
}
