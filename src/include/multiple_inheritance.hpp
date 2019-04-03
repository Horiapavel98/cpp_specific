#include "default_headers.hpp"

class Mammal {
public:
    Mammal() {
        cout << "Mammals can give direct birth." << endl;
    }
};

class WingedAnimal {
public:
    WingedAnimal() {
        cout << "Winged animal can flab." << endl;
    }
};

class Bat: public Mammal, public WingedAnimal {

};

class MultipleInheritance {
public:
    static void output() {
        Bat b1;
    }
};