#include <iostream>
using namespace std;

class Animal {   
    private:
    int weight;
    
    public:
    //state or Properties
    int age;
    string name;
    
    ~Animal(){
        cout << "Destructure is called " << endl;
    }
};

int main()
{
    Animal tiger;
    Animal * lion = new Animal;
    
    //call destructure for dma Object
    delete lion;
  
    return 0;
}
