#include <iostream>
using namespace std;

class Animal {          
    private:
         int age; 
};

class Dog:protected Animal{ //DOG class inheriting properties of Animal
    public:
        void print(){
            //will throw error
            cout << this->age; // BCAM is private and MOI is protected so, DM of parent class can't be accessed inside of clild class(Dog) ,
        }
};

int main()
{
    Dog d1;
    //d1.age; can't access -> BCAM is private and MOI is protected so, DM of parent class can't be accessed outside of clild class(Dog)
    d1.print(); //can access
    return 0;
}
