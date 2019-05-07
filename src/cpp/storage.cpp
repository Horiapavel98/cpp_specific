#include <iostream>
using namespace std;

void func() {
    static int count = 0;
    /**
     * The value will persist between function calls.
     */
    ++count;
    cout << "Function is called " << count << " times " << endl;
}

int main() {
    cout << "Calling function :- " << endl;
    func();
    cout << "Calling function :- " << endl;
    func();
    cout << "Calling function :- " << endl;
    func();
    return 0;
}