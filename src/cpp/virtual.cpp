#include <iostream>
using namespace std;

/**
 * Resources: https://www.geeksforgeeks.org/virtual-function-cpp/
 */

class base {
    public:
        virtual void print() {
            cout << "print base class" << endl;
        }

        void show() {
            cout << "show base class" << endl;
        }
};

class derived : public base {
    public:
        void print() {
            cout << "print derived class" << endl;
        }

        void show() {
            cout << "show derived class" << endl;
        }
};

/**
 * NOTE: If we have created virtual function in base class and it is being overrided in derived 
 * class then we don’t need virtual keyword in derived class, 
 * functions are automatically considered as virtual functions in derived class.
 */

int main () {
    base* bptr;

    derived d;

    bptr = &d;

    // virtual function binded at runtime
    bptr->print();

    // non-virtual function binded at compile time;
    bptr->show();
    
    return 0;
}