#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // move slow ptr by one step and fast by 2 step
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // move fast pointer to first Element
    fast = nums[0];

    // moce slow and faster by one step
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};

    cout << "Duplicate Element is " << findDuplicate(arr) << endl;
    return 0;
}