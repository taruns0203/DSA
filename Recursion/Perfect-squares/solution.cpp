//LOVE BABBAR

#include <limits.h>
#include <cmath>
using namespace std;
class Solution
{
public:

    int numSquareHelper(int n){
          //base 
        if(n == 0) return 1;

        if(n<0) return 0;

        int i =1;
        int ans = INT_MAX;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i*i;
            int noOfPerfectSquare = 1 + numSquareHelper(n - perfectSquare);
            if(noOfPerfectSquare < ans){
                ans = noOfPerfectSquare;
            }
            i++;
        }
        
        return ans;
    }
    int numSquares(int n) {
        
        return numSquareHelper(n) -1;
    }
};