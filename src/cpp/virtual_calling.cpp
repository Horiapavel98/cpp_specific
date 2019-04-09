/**
 * Calling virtual functions from a constructor or destructor
 * is considered dangerous most of the times and must be avoided
 * whenever possible.
 * 
 * All the C++ implementations need to call the version of the
 * function defined at the level of the hierarchy in the current 
 * constructor and not further.
 * 
 * You can call a virtual function in a constructor. The Objects
 * are constructed from the base up, "base before derived".
 * 
 * Resource: https://www.geeksforgeeks.org/calling-virtual-methods-in-constructordestructor-in-cpp/
 */

#include <iostream>
using namespace std;

class dog {
public:
    dog() {
        cout << "Constructor called\n";
        bark();
    }

    ~dog() {
        bark();
    }

    virtual void bark(){
        cout << "Virtual method called\n";
    }

    void seeCat() {
        bark();
    }
};

class Yellowdog : public dog {
public:
    Yellowdog() {
        cout << "Derived class: Constructor called\n";
    }
    void bark() {
        cout << "Derived class: Virtual method called\n";
    }
};

/**
 * Although, bark method is virtual method but when it is called inside 
 * constructor it will behave as non-virtual method because
 * by the time constructor of dog(base) class is called as in above code, 
 * Yellowdog(derived) class is not constructed by that time.
*/

int main() {
    Yellowdog d;
    d.seeCat();
    return 0;
}

/**
 *  _________________________________________________________________
 * |Note: It is highly recommended to avoid calling virtual functions|
 * |from constructor / destructor.                                   |
 * |_________________________________________________________________|
 */