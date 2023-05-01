#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findDuplicate(vector <int> &arr){
    int n = arr.size();
    int freq[n+1] = {0};
    
    for(int i=0; i< n ;i++){
        if(freq[arr[i]] == 0){
            freq[arr[i]] +=1;
            
        }else{
            return arr[i];
        }
    }
    
    return 0;
} 

int main()
{
    vector <int> arr;
    arr = {1,3,4,2,2};
    
    cout << "Duplicate Element is "<< findDuplicate(arr) << endl;
    return 0;

}