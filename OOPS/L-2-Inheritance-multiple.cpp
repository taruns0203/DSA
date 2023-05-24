#include <iostream>
using namespace std;
class A {
    public:
    int physics;
    int English;
};
class B {
    public:
    int chemistry;
    int English;
};
class C: public A , public B {
    public:
    int maths;
};
int main()
{
    C obj;
    //cout << obj.physics << " " << obj.chemistry << " " << obj.maths << endl;
    cout << obj.A::English << " " << obj.B::English << " " << obj.maths << endl; //scope resolution
    return 0;

}



