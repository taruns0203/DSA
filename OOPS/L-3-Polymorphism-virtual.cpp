#include <iostream>
using namespace std;
class Animal{
    public:
        virtual void speak(){
            cout << "Speaking " << endl;
        }
};
class Dog:public Animal{
     public:
        //override
        void speak(){
            cout << "Barking " << endl;
        }
};
int main()
{

    //Upcasting
    Animal *a = new Dog();
    a->speak();
    return 0;
}
