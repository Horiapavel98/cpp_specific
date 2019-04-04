#include "../include/default_headers.hpp"

// define a class 'X' (user-defined data type)
class X {
public:
    X (int a, int b) {
        m = a;
        n = b;
    }
    // data members
    int m;
    mutable int n;
};

int main() {
    // declare a const variable 'obj' of type 'X'
    const X obj(5, 2); // m = 5, n = 2;
    cout << "m : " << obj.m << "  n : " << obj.n << endl;
    // obj.m = 7; // Illegal since 'obj' is constant.
    obj.n = 8; // legal since 'n' is mutable
    cout << "m : " << obj.m << "  n : " << obj.n << endl;
    return 0;
}