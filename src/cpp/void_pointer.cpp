/**
 *                           ________________________
 *                          |                        |
 *                          |      RAW POINTER       |
 *                          |________________________|
 * 
 * A void* does not mean anything. It is a pointer that doesn't have a type.
 * It can basically point to anything in the memory.
 * 
 * A function that returns a void* generally is doing one of the follwing:
 * 
 * - Dealing with unformatted memory. This is what operator new and malloc return
 * Since the memory does not have a type -> it is void.
 * 
 * - It is an opaque handle; it references a created object without naming
 * a specific type. Sign of poorly formed code.
 * 
 * - It return a pointer to storage that contains an object of a known type.
 * However, the exact type that a particular call returns cannot be known at compile time.
 * Therefore, there will be some documentation explaining when it stores which kinds of objects,
 * and therefore which type can be safely cast to.
 * 
 * It can be pointer at objects of any data type!
 * 
 * A void pointer is declared like a normal pointer, using the void keyword as
 * the pointer's type:
 *  
 *      void* pointer_variable;
 * 
 *      void *pVoid;
 */

#include <iostream>
using namespace std;

// int nValue;
// float flValue;

// struct Something
// {
//     /* data */
//     int nValue;
//     float flValue;
// };

// int main(void) {


//     Something soValue;

//     void *pVoid;
//     pVoid = &nValue;
//     pVoid = &flValue;
//     pVoid = &soValue;

// }

int main(void) {
    int nValue = 5;
    void *pVoid = &nValue;

    // can not dereference pVoid because it is a void pointer

    //cout << *pVoid << "\n"; // Invalid: pointer to an incomplete object type

    int *pInt = static_cast<int*>(pVoid);

    cout << *pInt << "\n";

    return 0;
}

