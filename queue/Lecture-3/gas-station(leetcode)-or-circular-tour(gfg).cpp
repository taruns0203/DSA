// Link https://leetcode.com/problems/gas-station/
#include <vector>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // kitna petrol kam pad gaya
        int deficit = 0;
        // kitna petrol bacha hua he
        int balance = 0;
        // circuit kaha se start krre ho
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if (balance < 0)
            {
                // yahi pr galti hogi
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if (deficit + balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};