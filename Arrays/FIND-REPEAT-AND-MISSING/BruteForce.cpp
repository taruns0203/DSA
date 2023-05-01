#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> find_missing_repeating(vector<int> array)
{
    int n = array.size() + 1;

    vector<int> substitute(n, 0);
    vector<int> ans;

    for (int i = 0; i < array.size(); i++)
    {
        substitute[array[i]]++;
    }

    for (int i = 1; i <= array.size(); i++)
    {
        if (substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};

    vector<int> ans = find_missing_repeating(arr);
    cout << "Repeating ele is " << ans[0] << " Missing ele is  " << ans[1] << endl;
    return 0;
}
