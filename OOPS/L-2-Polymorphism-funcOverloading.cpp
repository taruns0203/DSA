#include <iostream>
using namespace std;class Maths{
    public:
        int sum(int a, int b){
            cout << "I am in first signature" << endl;
            return a+b;
        }  
        int sum(int a,int b,int c){
             cout << "I am in second signature" << endl;
            return a+b+c;
        }
        int sum(int a, double b){
             cout << "I am in third signature" << endl;
            return a+b;
        }
};
int main()
{
    Maths obj;
    cout << obj.sum(2,5) << endl;
    cout << obj.sum(2,5,10) << endl;
    cout << obj.sum(2,5.4) << endl;

    return 0;

}