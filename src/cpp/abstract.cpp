/**
 * An abstract class is a class that has at least one pure
 * virtual function. Pure virtual functions are written with " = 0"
 * after their declaration. They do not have any implementation.
 * 
 * Source: https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
 */

/** 
 * A pure virtual function is implemented by classes which are derived
 * from an Abstract class. 
 */

#include <iostream>
using namespace std;

// class Base {
//     int x;
// public:
//     virtual void fun() = 0;
//     int getX() { return x; }
// };

// class Derived : public Base {
//     int y;
// public:
//     void fun() { cout << "fun() is called\n"; }
// };

// int main(void) {
//     Base b; // Compiler error
//     return 0;
// }

/**
 * We can have pointers and references of abstract class type
 */

// class Base {
// public:
//     virtual void show() = 0;
// };

// If we do not override the pure virual function in the derived class
// this also becomes abstract
// class Derived: public Base {
// public:
//     void show() {
//         cout << "In Derived\n";
//     }
// };

// int main(void) {
//     Base * bp = new Derived();
//     bp->show();
//     return 0;
// }

/**
 * An abstract class can have constructors
 */

class Base {
protected:
    int x;
public:
    virtual void fun() = 0;
    Base(int i) { x = i; }
};

class Derived: public Base {
    int y;
public:
    Derived(int i, int j) : Base(i) { y = j; }
    void fun() {
        cout << "x = "<< x << ", y = "<< y << endl;
    }
};

int main(void){
    Derived d(4,5);
    d.fun();
    return 0;
}