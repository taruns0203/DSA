class Solution
{
public:
    void countArrangeMentHelper(vector<int> &v, int &n, int &ans, int currNum)
    {
        // base
        if (currNum == n + 1)
        {
            for (int i = 1; i <= n; i++)
            {
            }
            ++ans;
            return;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
            {
                v[i] = currNum;
                countArrangeMentHelper(v, n, ans, currNum + 1);
                v[i] = 0; // backtracking
            }
        }
    }
    int countArrangement(int n)
    {
        vector<int> v(n + 1);
        int ans = 0;
        countArrangeMentHelper(v, n, ans, 1);
        return ans;
    }
};