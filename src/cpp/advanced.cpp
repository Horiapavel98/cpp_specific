#include <iostream>

/**
 * In practical scenarios we would need to create a 
 * derived class object in a class hierarchy based on
 * some input. 
 * 
 * Putting in other words, object creation
 * and object type are tightly coupled which forces
 * modifications to extended. The objective of virtual 
 * constructor is to decouple object creation from it’s 
 * type.
 */

//// LIBRARY START

class Base {
public:

    // The "Virtual Constructor"
    static Base * Create(int id);
    
    Base() { }

    virtual // Ensures to invoke actual object destructor
    ~Base() { }

    // An interface
    virtual void DisplayAction() = 0;
};

class Derived1 : public Base {
public:
    Derived1() {
        std::cout << "Derived1 created\n";
    }

    ~Derived1() {
        std::cout << "Derived1 destroyed\n";
    }

    void DisplayAction() {
        std::cout << "Action from Derived1\n";
    }
};

class Derived2 : public Base {
public:
    Derived2() {
        std::cout << "Derived2 created\n";
    }

    ~Derived2() {
        std::cout << "Derived2 destroyed\n";
    }

    void DisplayAction() {
        std::cout << "Action from Derived2\n";
    }
};

class Derived3 : public Base {
public:
    Derived3() {
        std::cout << "Derived3 created\n";
    }

    ~Derived3() {
        std::cout << "Derived3 destroyed\n";
    }

    void DisplayAction() {
        std::cout << "Action from Derived3\n";
    }
};

Base * Base::Create(int id) {
    if (id == 1) {
        return new Derived1;
    }else if (id == 2) {
        return new Derived2;
    }else {
        return new Derived3;
    }
}

//// LIBRARY END

//// UTILITY START

/*
class User {
public:

    // Creates Drived1
    User() : pBase(0) {
        // What if Derived2 is required? - Add an if-else ladder (see next example)
        pBase = new Derived1();
    }

    ~User() {
        if( pBase ) {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action() {
        pBase->DisplayAction();
    }

private:
    Base * pBase;
};
*/

/**
 * What if the User class (constumer) needs Derived2 functionality?
 * It needs to create a 'new Derived2()' and it forces recompilation.
 * 
 * Recompiling is a bad way of design, so we can opt for the following approach.
 * 
 * Before going into details, let us answer, who will dictate to 
 * create either of Derived1 or Derived2 object? -> User (consumer)
 * 
 */

/* Redefinition of class: User */
/*
class User {
public:

    // Creates Drived1
    User() : pBase(0) {
        int input;

        std::cout << "Enter ID (1 or 2): ";
        std::cin >> input;

        if(input == 1) {
            pBase = new Derived1;
        }else {
            pBase = new Derived2;
        }

        // What if Derived3 is being added to the class hierarchy?
    }

    ~User() {
        if( pBase ) {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action() {
        pBase->DisplayAction();
    }

private:
    Base * pBase;
};
*/

/* Redefinition of class: User */
/*
class User {
public:

    // Creates Drived1
    User() : pBase(0) {
        int input;

        std::cout << "Enter ID (1 or 2): ";
        std::cin >> input;

        if(input == 1) {
            pBase = new Derived1;
        }else if(input == 2) {
            pBase = new Derived2;
        }else {
            pBase = new Derived3;
        }

        // What if Derived3 is being added to the class hierarchy?
    }

    ~User() {
        if( pBase ) {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action() {
        pBase->DisplayAction();
    }

private:
    Base * pBase;
};
*/

/* Redefinition of class: User (final) */

class User {
public:

    // Creates Drived1
    User() : pBase(0) {
        int input;

        std::cout << "Enter ID (1, 2 or 3): ";
        std::cin >> input;

        while ((input != 1) && (input != 2) && (input != 3)) {
            std::cout << "Enter ID (1, 2 or 3): ";
            std::cin >> input;
        }

        pBase = Base::Create(input);
    }

    ~User() {
        if( pBase ) {
            delete pBase;
            pBase = 0;
        }
    }

    // Delegates to actual object
    void Action() {
        pBase->DisplayAction();
    }

private:
    Base * pBase;
};

//// UTILITY END

int main() {

    User * user = new User();

    // Need Derived1 functionality only
    user->Action();

    delete user;

    return 0;
}