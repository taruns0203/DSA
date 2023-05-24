#include <iostream>
using namespace std;

class Animal {   
    private:
    int weight;
    
    public:
    //state or Properties
    int age;
    string name;
    
    // default constructor
    Animal(){
        this->weight = 0;
        this->age =0;
        this->name = "";
        cout << "constructor called" << endl;
    }
    
    //parametrized constructor withe one parameter
    Animal(int age){ 
        this->age = age;
        cout << "Parametrised Constructor  with one parameter  called "<< endl;
    }
    
    //parametrized constructor with two parameter
    Animal(int age, string name){ 
        this->age = age;
        this->name = name;
        cout << "Parametrised Constructor  with two parameter  called "<< endl;
    }
    
    //copy constructor
    Animal(Animal &obj){
        this->age = obj.age;
        this->weight = obj.weight;
        this->name = obj.name;
        cout << "I am inside copy constructor "<< endl;
    }
    
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
    
    
    //Dynamic memory

    //calling default constructor
    Animal tiger;
    Animal * lion = new Animal;
    
    //calling Parametrised constructor with one parameter
    Animal Chettah(12);
    Animal * Leopard = new Animal(20);
    
    //calling Parametrised constructor with two parameter
    Animal Cat(12, "Alex");
    Animal * SnowLeopard = new Animal(20, "Mishi");
    
    //object copy - copy constructor is called
    Animal b = Cat; //one way
    Animal c(b); // Another way

    return 0;
}
