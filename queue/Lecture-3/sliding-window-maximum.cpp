// link -https://leetcode.com/problems/sliding-window-maximum/submissions/966059989/
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // first window
        for (int i = 0; i < k; i++)
        {
            // chota element remove krdo
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index, so that we can checkout of window element
            dq.push_back(i);
        }

        // store answer for first window
        ans.push_back(nums[dq.front()]);

        // remaining window ko process
        for (int i = k; i < nums.size(); i++)
        {
            // out of window element ko remove krdia
            if (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            // ab firse current element k liy chote element ko remove krna he
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index, so that we can checkout of window element
            dq.push_back(i);

            // current window ka answer store krna he
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};