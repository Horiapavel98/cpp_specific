/**
 * C++ has no built-in concepts of interfaces. You can implement it
 * using abstract classes which contains only pure virtual functions.
 * 
 * Since it allows multiple inheritance, you can inherit this class to
 * create another class which will then contain this interface in it 
 * (object interface).
 * 
 * "Interface are nothing but a pure abstract class in C++. 
 *  Ideally this interface class should contain only pure virtual public
 *  methods and static const data."
 */

#include <iostream>

class Interface {
public:
    Interface() { std::cout << "Interface created ...\n"; }
    virtual ~Interface(){ std::cout << "Interface deleted ...\n"; }
    virtual void method1() = 0;

    virtual void method2() = 0;
};

class Concrete: public Interface {
private:
    int myMember;

public:
    Concrete(){ std::cout << "Concrete created ...\n"; }
    ~Concrete(){ std::cout << "Concrete deleted ...\n"; }
    void method1();
    void method2();
};

// Provide implementation for the first method
void Concrete::method1() {
    std::cout << "method1() called ...\n";
}

void Concrete::method2() {
    std::cout << "method2() called ...\n";
}

int main(void) {
    Interface * f = new Concrete();

    f->method1();
    f->method2();

    delete f;

    return 0;
}