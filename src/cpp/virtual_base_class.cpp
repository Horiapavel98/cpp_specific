#include <iostream>
using namespace std;
/**
 * How to solve this issue?
 * 
 * Declare the inheritance as virtual in the class headers.
 * 'virtual' can be written before or after the public keyword.
 * Now only one copy of data/function member will be copied to class C
 * and class B and class A becomes: the VIRTUAL BASE CLASS.
 * 
 * When a base class is specified as a virtual base, it can act as an 
 * indirect base more than once without duplication of its data members. 
 * A single copy of its data members is shared by all the base classes that use virtual base.
 * 
 * Resource: https://www.geeksforgeeks.org/virtual-base-class-in-c/
 * 
 */
class A {
public:
    int a;
    A() {
        a = 10;
    }
    void show() {
        cout << "Hello from A \n";
    }
};

class B : public virtual A {
public:
    B() {
        a = 15;
    }
};

class C : public  virtual A {
public:
    C() {
        a = 20;
    }
};

class D : public B, public C {
};

int main() {
    D object; // object creation of class d
    cout << "a = " << object.a << endl;
}