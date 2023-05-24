#include <iostream>
using namespace std;

class Animal {   
    private:
    int weight;
    
    public:
    //state or Properties
    int age;
    string name;
    
    //behaviour
    void eat(){ cout << "Eating" << endl; }
    
    void sleep(){ cout << "Sleeping" << endl; }
    
    //to access private memeber we will use getter and setter methods
    int getWeight(){ return weight; }
    
    int setWeight(int w){ weight = w; }
};

int main()
{
    //Dynamic memory
    Animal * suresh = new Animal;
    // (*suresh).age = 15;
    // (*suresh).type = 'Billi';   
    //Altername way 
    suresh->age = 17;
    suresh->name = 'Kutta';
    
    suresh->eat();
    suresh-> sleep();
    return 0;
}
