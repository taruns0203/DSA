#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int recSolve(int n)
    {
        // base case
        if (n == 1 || n == 0)
        {
            return n;
        }

        int ans = recSolve(n - 1) + recSolve(n - 2);
        return ans;
    }

    int topDownSolve(int n, vector<int> &dp)
    {
        // base case
        if (n == 1 || n == 0)
        {
            return n;
        }

        // step-3: check if ANSWER already exist
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // step-2: replace ans with dp[n]
        dp[n] = recSolve(n - 1) + recSolve(n - 2);
        return dp[n];
    }

    int BottomUpSolve(int n)
    {
        // step-1: create dp array
        vector<int> dp(n + 1, -1);
        // step-2: observe base case in above solution
        dp[0] = 0;
        if (n == 0)
        {
            return dp[0];
        }
        dp[1] = 1;
        if (n == 1)
        {
            return dp[1];
        }
        // step-3: ruuning iteration
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int spaceOptSolve(int n)
    {
        // step:2 - base case
        int prev2 = 0;
        int prev1 = 1;

        if (n == 0)
        {
            return prev2;
        }

        if (n == 1)
        {
            return prev1;
        }
        int curr;
        // step-3: top down approach me n kese traverse karta h
        for (int i = 2; i <= n; i++)
        {
            curr = prev2 + prev1;
            // shifting
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }

    int fib(int n)
    {
        // int ans = recSolve(n);
        // return ans;

        // step-1: create dp array
        vector<int> dp(n + 1, -1);
        int ans = BottomUpSolve(n);
        return ans;
    }
};