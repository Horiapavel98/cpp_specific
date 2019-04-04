#include "../include/all_custom_headers.hpp"

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