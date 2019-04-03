#include <iostream>
using namespace std;

class base {
protected:
    int y;
public:
    int x;
    base () : x(2), y(3), z(4) {}
private:
    int z;
};

class publicDerived : public base {
    /**
     * publicDerived inherits variables x and y as public and protected.
     * z is not inherited as it is a private member variable of base.
    */
   public:

    void outputX() {
        cout << x << endl;
    }

    void outputY() {
        cout << y << endl;
    }
};

class protectedDerived : protected base {
    /**
     * protectedDerived inherits variables x and y. Both variables become protected. z is not inherited
     * If we derive a class derivedFromProtectedDerived from protectedDerived, variables x and y are also inherited to the derived class.
    */

    public:
    void outputX() {
        cout << x << endl;
    }

    void outputY() {
        cout << y << endl;
    }
};
/**
 * Access modifier of the inheritance changes the way the variables
 * can be accessed from the subclass.
 * If this access modifier changes to 'private' the variables x & y
 * wouldn't be available in the 'derivedFromDerivedFromProtectedDerived'.
 * -----------------------------------V                       */
class derivedFromProtectedDerived : protected protectedDerived {
    public:

    void outputX() {
        cout << x << endl;
    }

    void outputY() {
        cout << y << endl;
    }
};

class derivedFromDerivedFromProtectedDerived : public derivedFromProtectedDerived {
    public:

    void outputX() {
        cout << x << endl;
    }

    void outputY() {
        cout << y << endl;
    }
};

class privateDerived : private base {
    /**
     * privateDerived inherits variables x and y. Both variables become private. z is not inherited
     * If we derive a class derivedFromPrivateDerived from privateDerived, variables x and y are not inherited because they are private variables of privateDerived.
    */

    public:

    void outputX() {
        cout << x << endl;
    }

    void outputY() {
        cout << y << endl;
    }
};

/**
 * Doesn't work as privateDerived class
 * has x and y as private variables.
 * */ /* <--------------------> /*
class derivedFromPrivateDerived : public privateDerived {
    public:
    void outputX() {
        cout << x << endl;
    }

    void outputY() {
        cout << y << endl;
    }
};
*/
void output() {
    derivedFromDerivedFromProtectedDerived p;
    p.outputX();
    p.outputY();
}

