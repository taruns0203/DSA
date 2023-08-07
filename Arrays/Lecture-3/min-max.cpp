#include <iostream>
#include <limits.h>
using namespace std;

int getMax(int arr[][3], int row, int cols)
{
    int maxi = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > maxi)
            {
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
}

int getMin(int arr[][3], int row, int cols)
{
    int mini = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] < mini)
            {
                mini = arr[i][j];
            }
        }
    }
    return mini;
}

int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Maximum Element is : " << getMax(arr, row, col) << endl;
    cout << "Minimum Element is : " << getMin(arr, row, col) << endl;
}