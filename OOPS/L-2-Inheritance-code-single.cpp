#include <iostream>

using namespace std;

class Car {
    public:
    string name;
    int weight;
    int age;
    
    void speedUp(){
        cout << "Speeding up" <<endl;
        
    }
    void putBreak(){
        cout << "Put Break " <<endl;
    }
};

class Mahindra:public Car{
    
};

int main()
{
    Mahindra Scorpio;
    Scorpio.speedUp();

    return 0;
}
