#include <iostream>
using namespace std;

bool findKey(int arr[][3], int row, int col, int key)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                return true;
            }
        }
    }

    // value is not returned
    return false;
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

    cout << "Is Key Present : " << findKey(arr, row, col, 3) << endl;
}