#include <iostream>
using namespace std;

/**
 * Overriding a public virtual function as a private function
 * of the derived class.
 */

class Base {
public:
    virtual int fun(int i) { }
};

class Derived : public Base {
private:
    int fun(int x) { }
};

int main() {

    Base * ptr = new Derived;

    ptr->fun(9);

    return 0;
}