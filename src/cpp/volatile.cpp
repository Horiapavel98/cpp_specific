/**
 * `volatile` keyword can be used to
 *  prevent the compiler's optimization in a
 *  certain part of the program.
 * 
 * In other words, this is done in situations
 * where optimization is undesirable, because it may be that
 * someone else is changing the value of that variable
 * from outside the program in which the compiler is not aware of,
 * since it cannot see it; but it's how you've designed it.
 * 
 * In that case, compiler's optimization would not produced the
 * desired result.
 */

#include <iostream>

int main() {

    int some_int = 100;

    /*
    while(some_int == 100) {
        // do stuff
    }
    
    This gets optimized in this:

    while(true) {
        // do stuff
    }

    for a faster execution.

    BUT sometimes you just do not want this.

    In that case you are going to use

    volatile int some_int = 100;

    */

    return 0;
}