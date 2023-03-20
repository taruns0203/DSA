#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define N 3

void transpose(vector<vector<int>> &mat, vector<vector<int>> &transMat)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transMat[i][j] = mat[j][i];
        }
    }
}

int main()
{
    // Write C++ code here
    vector<vector<int>> mat = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    vector<vector<int>> transMat(N, vector<int>(N));
    transpose(mat, transMat);
    cout << "Result matrix is \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << transMat[i][j];
        }

        cout << "\n";
    }

    return 0;
}