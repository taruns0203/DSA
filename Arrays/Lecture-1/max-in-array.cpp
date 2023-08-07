#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int arr[] = {2, 4, 6, 1, 3, 7, 9, 12, 56, 43, 21};
    int size = 11;
    int maxi = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxi)
        {
            // found a number greater than maxi, update maxi
            maxi = arr[i];
        }
    }

    cout << " Maximum number is : " << maxi << endl;

    return 0;
}
