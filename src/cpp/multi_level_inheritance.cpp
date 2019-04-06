#include "default_headers.hpp"

class A {
public:
    void display() {
        cout << "Base class content printed now!" << endl;
    }
};

class B : public A {
public:
    void display() {
        cout << "B.class content printed now!" << endl;
    }
};

class C : public B {
public:
    void display() {
        cout << "C.class content is printed now!" << endl;
    }
};

class Wrapper {
public:
    static void output() {
        C obj;
        obj.display();
    }
};