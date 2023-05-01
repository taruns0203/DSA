#include <iostream>
using namespace std;

void lastOccLTR(string &s, char x, int i, int &ans){
    //base case
    if(i <0){
        return;
    }    
    if(s[i] == x){
        ans = i;
        return;
    }
    lastOccLTR(s,x,i-1,ans);
    
}
int main()
{
    string s;
    cin>>s;
    char x;
    cin>>x;
    int ans = -1;
    lastOccLTR(s,x,s.size() -1,ans);
    cout << ans << endl;

    return 0;
}