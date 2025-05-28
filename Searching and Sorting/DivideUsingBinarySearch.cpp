

#include <iostream>
using namespace std;

int solve(int divident, int divisor)
{
    int s = 0;
    int e = abs(divident);
    int ans = 0;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // perfect solution - no decimal
        if (abs(mid * divisor) == abs(divident))
        {
            return mid;
        }

        // not perfect solution
        if (abs(mid * divisor) > abs(divident))
        {
            // left search
            e = mid - 1;
        }
        else
        {
            // ans store
            ans = mid;
            // right store
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    if ((divisor < 0 && divident < 0) || (divisor > 0 && divident > 0))
    {
        return ans;
    }
    else
    {
        return -ans;
    }
}
int main()
{
    int divident = 36;
    int divisor = 9;

    int ans = solve(divident, divisor);
    cout << " Ans is " << ans << endl;

    return 0;
}