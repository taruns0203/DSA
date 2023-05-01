#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int majorityElement(vector<int> v)
{
    // size of the given array
    int n = v.size();

    // declaring a map
    map<int, int> map;

    // storing the element with it's occurance
    for (int i = 0; i < n; i++)
    {
        map[v[i]]++;
    }

    // searching for the majority element
    for (auto it : map)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }

    return -1;
}

using namespace std;

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is " << ans << endl;

    return 0;
}