#include <iostream>
using namespace std;
class Param {
    public:
        int val;
        void operator+(Param& obj2){
            int value1  = this->val;
            int value2 = obj2.val;
            cout << (value2 - value1) << endl;
        }
        
};
int main()
{
    Param obj1,obj2;
    obj1.val = 7;
    obj2.val = 2;
    //here we will find the difference between obj1 and obj2
    //compiler will get confuse about how to use '+' for two object, and it will 
    //try to find implementation in Param class
    obj1+obj2;

    return 0;
}
