#include <iostream>
using namespace std;

class Animal {   
    private: //ALL DATA memebers are private - so we have achieved the perfect encapsulation
         int age;
         int weight;
    
    public:
        //behaviour
        void eat(){ cout << "Eating" << endl; }
        
        int getAge(){
            return this->age;
        }
        
        void setAge(int age){
            this->age = age;
        }
    
};

int main()
{
    Animal tiger;
    return 0;
}
