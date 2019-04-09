#include <iostream>

class Test{
public:
    virtual ~Test()=0; // Test now becomes abstract class.
};

Test::~Test() { }

class Base {
public:
    virtual ~Base()=0; // pure virtual destructor
};

/**
 * It is important to note that a class becomes abstract
 * when it contains a pure virtual destructor.
 */

Base::~Base() {
    std::cout << "Pure virtual destructor is called\n";
}

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "~Derived() is executed\n";
    }
};

int main(void) {

    Base * b = new Derived();

    delete b;

    return 0;
}