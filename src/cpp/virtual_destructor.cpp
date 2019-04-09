#define _CRTDBG_MAP_ALLOC

#include <iostream>
using namespace std;

class base {
public:
    
    base() {
        cout << "Constructing base\n";
    }
    /**
     * In case if the destructor is not virtual
     * the deletion process will use the base class
     * destructor.
     */
    virtual ~base() {
        cout << "Destructing base\n";
    }
};

class derived : public base {
public:
    
    derived() {
        cout << "Constructing derived\n";
    }

    ~derived() {
        cout << "Destructing derived\n";
    }
};

int main(void) {

    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    derived *d = new derived();   
    base *b = d; 
    delete b;
    return 0; 
}