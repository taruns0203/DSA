#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool solveUsingRecursion(int index, vector<int> &nums, int target)
    {
        // base case
        int n = nums.size();
        if (index >= n)
        {
            return 0;
        }

        if (target < 0)
        {
            return 0;
        }

        if (target == 0)
        {
            return 1;
        }

        bool include = solveUsingRecursion(index + 1, nums, target - nums[index]);
        bool exclude = solveUsingRecursion(index + 1, nums, target);

        return (include || exclude);
    }

    bool solveUsingMemo(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        // base case
        int n = nums.size();
        if (index >= n)
        {
            return 0;
        }

        if (target < 0)
        {
            return 0;
        }

        if (target == 0)
        {
            return 1;
        }

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        bool include = solveUsingMemo(index + 1, nums, target - nums[index], dp);
        bool exclude = solveUsingMemo(index + 1, nums, target, dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool solveUsingTabulation(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));

        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = 0;
                if (t - nums[index] >= 0)
                {
                    include = dp[index + 1][t - nums[index]];
                }

                bool exclude = dp[index + 1][t];

                dp[index][t] = (include || exclude);
            }
        }

        return dp[0][target];
    }

    bool solveUsingSO(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[0] = 1;
        next[0] = 1;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = 0;
                if (t - nums[index] >= 0)
                {
                    include = next[t - nums[index]];
                }

                bool exclude = next[t];

                curr[t] = (include || exclude);
            }

            // shift
            next = curr;
        }

        return next[target];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        // if sum is odd return false
        // yha bhi galti hogi
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        int index = 0;
        // bool ans = solveUsingRecursion(index, nums, target);

        // vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
        // bool ans = solveUsingMemo(index, nums, target, dp);

        bool ans = solveUsingSO(nums, target);
        return ans;
    }
};