#include <iostream>
using namespace std;

/**
 * In contrast to public inheritance, compilers will generally
 * not convert a derived class object into a base class object
 * if the inheritance relationship between the classes is private.
 * 
 * With public inheritance, the public methods of the base class
 * become public methods of the derived class. In other words,
 * the derived class inherits the base-class interface (the interface
 * is still visible to outside and anyone can use it). This is the is-a
 * relationship. 
 * 
 * But with the private inheritance, the public methods of the
 * base class become private methods of the derived class, even if they were
 * protected of public in the base class. So, the derived class does not
 * inherit the base-class interface.
 * 
 * Private inheritance defines a has-a relationship.
 * 
 * Resources: https://bogotobogo.com/cplusplus/private_inheritance.php
 */

class Engine {
public:
    Engine(int nc) {
        cylinder = nc;
    }

    void start() {
        cout << getCylinder() << " cylinder engine started\n";
    }

    int getCylinder() {
        return cylinder;
    }

private:
    int cylinder;
};

class Car : private Engine {
    // Car has-a engine
public:

    using Engine::start;
    using Engine::getCylinder;

    Car(int nc = 4) : Engine(nc) { }
    void start() {
        cout << "car with " << Engine::getCylinder() <<
            " cylinder engine started" << endl;
        Engine::start();
    }
};

/**
 * In short, private inheritance does acquire the implementation, 
 * but does not acquire interface.
 */

/**
 * Private inheritance is a variant of composition, aggregation,
 * or containment. So, the has-a relationship can be achieved using composition
 * as in the example below.
 */

class CarWithComposition {
    // Car has-a engine
public:
    CarWithComposition(int n = 4) : eng(n) { }
    void start() {
        cout << "car with " << eng.getCylinder() <<
            " cylinder engine started" << endl;
        eng.start();
    }
private:
    Engine eng;
};

int main() {
    Car c(8);

    c.start();

    return 0;
}

/**
 * Conclusions:
 * Use compostion over private inheritance because
 * inheritance produces a more tightly coupled design.
 */