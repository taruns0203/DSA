#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:

    int mincostTickets_helper(vector<int>& days, vector<int> & costs,int i){
        //base case
        if(i >= days.size()) return 0;

        //sol for 1case
        //1 days pass taken
        int cost2 = costs[0] + mincostTickets_helper(days,costs,i+1);

        //7 Days pass taken
        int passEndDay = days[i] +7 -1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost7 = costs[1] + mincostTickets_helper(days,costs,j);

        //30 Days pass taken
        passEndDay = days[i] +30 -1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + mincostTickets_helper(days,costs,j);

        return min(cost2, min(cost7,cost30));

    }
 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       return mincostTickets_helper(days, costs,0);

    }
};