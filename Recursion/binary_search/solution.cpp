
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int s, int e, int key){
    //base case
    //key not found
    if(s > e)
        return -1;
        
    int mid = (s+e)/2;
        
    //case 2 -> key found
    if(arr[mid] == key)
        return mid;
        
    // arr[mid] < key - right me search
    if(arr[mid] < key){
        return binarySearch(arr, mid+1, e, key);
        
    }else{
        //arr[mid] > key -> left me search
        return binarySearch(arr,s, mid-1, key);
    }
    
}

int main()
{
    vector<int> v {10,20,5,50,60};
    int n = v.size();
    int target = 50;
    int s = 0;
    int e = n-1;
    int ans = binarySearch(v,s,e,target);
    
    cout << "Answer is " << ans << endl;

    return 0;
}
