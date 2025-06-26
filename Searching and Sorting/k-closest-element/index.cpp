class Solution
{
public:
    int lowerBound(vector<int> &arr, int x)
    {
        int start = 0, end = arr.size() - 1;
        int ans = end;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (x > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }

    vector<int> bs_method(vector<int> &arr, int k, int x)
    {
        // lower bound
        int h = lowerBound(arr, x);
        int l = h - 1;
        while (k--)
        {

            if (l < 0)
            {
                h++; // if high is on first element then lower will go out of
                     // bound since h=0, l = h-1 = -1, hence we will keep doing
                     // h++
            }
            else if (h >= arr.size())
            {
                l--; // if high is on last element, lower will be backward only
                     // and we cant do h++
            }
            else if (x - arr[l] > arr[h] - x)
            {
                h++;
            }
            else
            {
                l--;
            }
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }

    vector<int> twoPtrMethod(vector<int> &arr, int k, int x)
    {
        // TC - O(n-k)
        // SC - O(K) if we use the for loop
        int l = 0, h = arr.size() - 1;
        while (h - l >= k)
        {
            if (x - arr[l] > arr[h] - x)
            {
                l++;
            }
            else
            {
                h--;
            }
        }

        // vector<int> ans;
        // for(int i=l; i <=h; i++){
        //     ans.push_back(arr[i]);
        // }

        return vector<int>(arr.begin() + l, arr.begin() + h + 1);
    }
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // return twoPtrMethod(arr,k,x);
        return bs_method(arr, k, x);
    }
};