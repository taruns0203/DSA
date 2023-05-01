#include <iostream>
using namespace std;
int fib(int n){
    //base case
    if(n==1){
        //fist term
        return 0;
    }
    
    if(n==2){
        //second term
        return 1;
    }
    
    //RR
    return fib(n-1) + fib(n-2);

}

int main()
{
    int n;
    cout << "Enter the term you want to see "<<endl;
    cin >> n;
    
    int ans = fib(n);
    cout << "The fibonacci term is "<< ans << endl;

    return 0;
}
