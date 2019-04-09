#include <iostream>
using namespace std;

class Base{
public:
    virtual void show() {
        cout << "In Base n\n";
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "In Derived n\n";
    }
};

int main(void) {
    Base * bp = new Derived;

    bp->Base::show(); // Note the use of scope resolution here
    return 0;
}