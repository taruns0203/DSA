#include <iostream>
using namespace std;
int main()
{
    int arr[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1};

    int size = 16;

    int numZero = 0;
    int numOne = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            numZero++;
        }

        if (arr[i] == 1)
        {
            numOne++;
        }
    }

    cout << "Number of zeroes " << numZero << endl;
    cout << "Number of ones " << numOne << endl;

    return 0;
}