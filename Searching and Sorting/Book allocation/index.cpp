class Solution
{
public:
    bool isPossibleSolution(vector<int> &arr, int n, int m, int sol)
    {
        int pageSum = 0;
        int c = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > sol)
            {
                return false;
            }

            if (pageSum + arr[i] > sol)
            {
                c++;
                pageSum = arr[i];

                if (c > m)
                {
                    return false;
                }
            }
            else
            {
                pageSum += arr[i];
            }
        }

        return true;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size(); // no of books
        if (k > n)
        {
            return -1;
        }

        int start = 0;
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (start <= end)
        {
            int mid = (start + end) >> 1;
            if (isPossibleSolution(arr, n, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};