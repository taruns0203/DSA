// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;

    while (mid <= hi)
    {
        switch (nums[mid])
        {

        // If element is 0
        case 0:
            swap(nums[lo++], nums[mid++]);
            break;

        // If the element is 1
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(nums[mid], nums[hi--]);
            break;
        }
    }
}

int main()
{
    // Write C++ code here
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    sortColors(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        cout << "\n";
    }

    return 0;
}