#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //create vector
    vector<int> arr;
    vector<int> brr(10); //size of 10 vector is created and. by default all values are initialized with 0 
    vector<int> crr(10,-1); //size of 10 vector is created and all values are initialized with -1
    vector<int> drr{10,20,30,50}; //creating vector with elements
    vector<int> err;
    
    int ans = (sizeof(arr)/sizeof(int));
    cout << ans << endl;
    cout << arr.size() <<endl;
    cout << arr.capacity() <<endl;
    
    //insert 
    arr.push_back(5);
    arr.push_back(6);
    
    //print
    for(int i=0; i <arr.size() ;i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    //remove
    arr.pop_back();
    
    cout << "Size of b is : "  << brr.size() <<endl;
    cout << "capacity of b is : "  << brr.capacity() <<endl;
    
    //print
    for(int i=0; i <brr.size() ;i++){
        cout << brr[i] << " ";
    }
    cout << endl;

    cout << "Printing DRR : "<<endl;
    //print
    for(int i=0; i <drr.size() ;i++){
        cout << drr[i] << " ";
    }
    
    cout << endl;
    //checking if vector is empty or not
    cout << "Vector ERR is empty or not : "<< err.empty() << endl;
    cout << "Vector DRR is empty or not : "<< drr.empty() << endl;
    return 0;
}
