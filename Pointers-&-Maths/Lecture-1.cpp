#include <iostream>
using namespace std;

int main()
{
    // int a = 5;
    // int b = 5;
    // int *ptr = &a;

    // cout << "Pointer is " << ptr << endl;
    // cout << "Pointer Derefrence is " << *ptr << endl;
    // cout << "Pointer Address is " << &ptr << endl;
    // cout << a << endl;

    // cout << &a <<endl;
    // cout << &b <<endl;

    int abc = 10;
    int *p = &abc;

    int *q = p;
    int *r = q;

    cout << "Starts are " << endl;
    cout << abc << endl;                 // 10
    cout << &abc << endl;                // address of abc
    cout << p << endl;                   // address of abc
    cout << &p << endl;                  // address of p
    cout << *p << endl;                  // value of abc
    cout << q << endl;                   // address of abc
    cout << &q << endl;                  // address of q
    cout << *q << endl;                  // value of abc
    cout << r << endl;                   // address of abc
    cout << &r << endl;                  // address of r
    cout << *r << endl;                  // value of abc
    cout << (*p + *q + *r) << endl;      // 30
    cout << (*p) * 2 + (*r) * 3 << endl; // 50
    cout << (*p / 2) - (*q) / 2 << endl; // 0

    return 0;
}