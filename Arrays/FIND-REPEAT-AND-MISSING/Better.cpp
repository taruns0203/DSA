#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> find_missing_repeating(vector<int> &A)
{
    long long int len = A.size();

    long long int S = (len * (len + 1)) / 2;
    long long int P = (len * (len + 1) * (2 * len + 1)) / 6;
    long long int missingNumber = 0, repeating = 0;

    for (int i = 0; i < A.size(); i++)
    {
        S -= (long long int)A[i];
        P -= (long long int)A[i] * (long long int)A[i];
    }

    missingNumber = (S + P / S) / 2;

    repeating = missingNumber - S;

    vector<int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

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
