// User function template for C++

class Solution
{
public:
    int isPossibleSolution(vector<int> &arr, int n, int k, int mid)
    {
        int timeSum = 0;
        int c = 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
            {
                return false;
            }

            if (arr[i] + timeSum > mid)
            {
                c++;
                timeSum = arr[i];
                if (c > k)
                    return false;
            }
            else
            {
                timeSum += arr[i];
            }
        }

        return true;
    }
    int minTime(vector<int> &arr, int k)
    {
        // code here
        int start = 0;
        int end = 0;

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            end += arr[i];
        }

        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
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
        // return minimum time
    }
};