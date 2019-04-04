/**
 * Variables of extern storage class have a global scope. 
 * We use extern variables when we want a variable to be visible outside the file in which it is declared. 
 * So, an extern variable can be shared across multiple files. An extern variable remains alive as long as program execution continues. 
 * A static global variable is visible only in the file it is declared 
 * but an extern global variable is visible across all the files of a program.
 * We have used declaring and defining a variable interchangeably but extern storage class adds a distinction.
 *  
 * In simple words :

    extern int count; // declaration of variable ‘count’ |
    |                                                    |
    | <----- Done in separate files ----->               |
    |                                                    |
    int count; // definition of variable ‘count’_________|
 
 */

#include <iostream>
#include "extern_var_util.cpp" // including the contents of a user defined file

extern int count; // declaration

int main() {
   // uses the count variable from the other file
    std::cout << "count : " << count << std::endl;
    count = 1; // goes on with using the actual count variable from this file.
    incrementCount();
    std::cout << "count : " << count << std::endl;
}