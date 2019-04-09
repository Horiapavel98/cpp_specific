#include <iostream>
using namespace std;

/**
 * Properties:
 *  1. Return values are the same for the same arguments
 *  2. It's evaluation has no side effects.
 * 
 * Resource: https://en.wikipedia.org/wiki/Pure_function
 */

[[gnu::pure]] int square(int val) {
    return val*val;
}

int main(const int argc, const char *[]){
    
    cout << square(6) + square(6);
    
    return 0;
}