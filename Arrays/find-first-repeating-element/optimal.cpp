#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {

        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (hash[arr[i]] > 1)
            {
                return i + 1;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
