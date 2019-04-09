/**
 * Deleting a derived class object using a pointer to a
 * base class that has a non-virtual destructor results in
 * undefined behaviour.
 * 
 * Thus, we make the base class destructor virtual so 
 * that polymorphic objects are being deleted properly
 * in the correct order (i.e. reverse order of their creation).
 * 
 * Source: https://www.geeksforgeeks.org/virtual-destruction-using-shared_ptr/
 */

/**
 * Similar behaviour can also be achieved by using 
 * shared_ptr without having the Base class destructor virtual.
*/

#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
    Base() {
        cout << "Constructing Base\n";
    }
    ~Base() {
        cout << "Destructing Base\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Constructing Derived\n";
    }
    ~Derived() {
        cout << "Destructing Derived\n";
    }
};

int main(void) {
    /* std::shared_ptr<Base> sp { new Derived }; */

    // make_shared can also be used to create sp.
    // std::shared_ptr<Base> sp {std::make_shared<Derived>()};
    // Use sp

    /*
    Base * p = new Derived{};        |
    std::shared_ptr<Base> sp { p };  | <-----|
                                             |
                                             | 
                                             |
                                             |
                                             |
                                             |
        -------------------------------------|
        V 
      Here, if the shared_ptr is initialised from
      
      Base* (here `p`), then this magical behaviour of
      smart destruction will not be achieved as this will
      call Base::~Base() and not Derived::~Derived(). The
      shared_ptr will not be able to find out the exact type
      of the object which is being pointed by
      `p`.

      So in this case the magic doesn't happen.

}

/**
 * Note: use shared_ptr for having|
 * |                              |
 * |   >  SMART DESTRUCTION  <    |
 * |______________________________|
 */