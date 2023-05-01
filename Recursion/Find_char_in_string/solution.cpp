#include <iostream>
#include<limits.h>
using namespace std;

int checkKey(string& str, int i, int& n, char& key){
    if(i >= n){
        return -1;
    }
    
    if(str[i] == key){
        
        //If you want to print the location of all the letter dound
        //cout << "Found at : " << i << endl;
        return i;
    }
    
    int ans = checkKey(str, i+1, n , key);
    return ans;
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();
    
    char key = 'r';
    
    int i = 0;
    int ans = checkKey(str, i , n , key);
    
    cout << "Answer is : " << ans << endl;

    return 0;
}
