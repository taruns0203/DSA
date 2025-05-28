#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;
    while (start <= end)
    {
        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        else if (target < element)
        {
            // search in left
            end = mid + 1;
        }
        else
        {
            // search in right
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 16};
    cout << "Hello ";

    int size = 7;
    int target = 2;

    int indexOfTarget = binarySearch(arr, size, target);

    if (indexOfTarget == -1)
    {
        cout << "target not found" << endl;
    }
    else
    {
        cout << "Target found ait " << indexOfTarget << " index " << endl;
    }

    return 0;
}
