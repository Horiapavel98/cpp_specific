#include <iostream>
using namespace std;
// Resources: https://www.geeksforgeeks.org/inline-virtual-function/
class Base{
public:
    virtual void who() {
        cout << "I am base\n";
    }
};

class Derived : public Base {
public:
    void who() {
        cout << "I am derived\n";
    }
};

int main() {
    
    /**
     * Note here the virtual function who() is called
     * through object of the class (it will be resoulved
     * at compile time) so it can be inlined.
     */
    Base b;
    b.who();
    

    /**
     * Here virtual function is called through a pointer,
     * so it cannot be inlined.
     */
    Base * ptr = new Derived();
    ptr->who();

    return 0;
}