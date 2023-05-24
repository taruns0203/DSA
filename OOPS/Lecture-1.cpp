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
    //Object Creation
    
    //static
    Animal ramesh;
    ramesh.age = 12;
    ramesh.name = "Lion";
    
    cout << "Age of ramesh is: " << ramesh.age << endl;
    cout << "Name of ramesh is: " << ramesh.name << endl;
       
    ramesh.eat();
    ramesh.sleep();
    
    //accessing private memeber
    ramesh.setWeight(101);
    cout << "Weight of ramesh is: " << ramesh.getWeight() << endl;
    //Dynamic memory

    return 0;
}
