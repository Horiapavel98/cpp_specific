#include <iostream>
using namespace std;

/**
 * Working of virtual functions(concept of VTABLE and VPTR)
 * 
 * As discussed here , If a class contains a virtual function then compiler itself does two things:
 * 
 * If object of that class is created then a virtual pointer(VPTR) is inserted as a data member of 
 * the class to point to VTABLE of that class. 
 * For each new object created, a new virtual pointer is inserted as a data member of that class.
 * 
 * Irrespective of object is created or not, a static array of function pointer called VTABLE where
 * each cell contains the address of each virtual function contained in that class.
 * 
 */

class base {
    public:
        void fun_1() { cout << "base-1\n"; }
        virtual void fun_2() { cout << "base-2\n"; }
        virtual void fun_3() { cout << "base-3\n"; }
        virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base {
    public:
        void fun_1() { cout << "derived-1\n"; }
        void fun_2() { cout << "derived-2\n"; }
        void fun_4(int x) { cout << "derived-4\n"; }
};

int main() {
    
    base* p;

    derived obj1;

    p = &obj1;

    // Early binding because fun1() is non-virtual in  base
    p->fun_1();

    // Late binding (RTP)
    p->fun_2();

    // Late binding (RTP)
    p->fun_3();

    // Late binding (RTP)
    p->fun_4();

    /** Early binding but this function call is
     * illegal(produces error) because pointer is
     * of base type and function is of
     * derived class.
     */
    // p->fun_4(5);

    return 0;
}