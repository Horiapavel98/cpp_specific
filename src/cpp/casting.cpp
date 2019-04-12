#include <iostream>
#include <typeinfo>
using namespace std;

/**
 * Implicit conversions with classes
 * 
 * In the world of classes, implicit conversions
 * can be controlled by means of three member functions:
 * 
 *      Single-argument constructors: allow implicit conversion from
 *      a particular type to initialize an object.
 * 
 *      Assignment operator: allow implicit conversion from a particular type
 *      on assignments.
 *  
 *      Type-cast operator: allow implicit conversion to a particular type.
 * 
 * Source: http://www.cplusplus.com/doc/tutorial/typecasting/
 */

/* Implicit conversions of classess */
// class A{};

// class B{
// public:
//     // conversion from A (constructor)
//     B (const A& x) {}
//     // conversion from A (assignment)
//     B& operator= (const A & x) { return *this; }
//     // conversion to A (type-cast operator)
//     operator A() { return A(); }
//     /**
//      * The type-cast operator uses a particular syntax: 
//      * it uses the operator keyword followed by the destination 
//      * type and an empty set of parentheses. Notice that the return 
//      * type is the destination type and thus is not specified before 
//      * the operator keyword.
//      */
// };

/* Keyword explicit */

// class A{};

// class B {
// public:
//     explicit B (const A & x) {}
//     /**
//      * Additionally, constructors marked with explicit cannot be called with the 
//      * assignment-like syntax;
//      */
//     B& operator= (const A & x) {return *this;}
//     operator A() {return A();}
//     /**
//      * Type-cast member functions (those described in the previous section) can also be 
//      * specified as explicit. This prevents implicit conversions in the same way as 
//      * explicit-specified constructors do for the destination type.
//      */
// };

// void fn (B x) {}

/* Type casting */

/**
 * C++ is a strong-typed language. Many conversions, specially those that 
 * imply a different interpretation of the value, require an explicit conversion, 
 * known in C++ as type-casting. There exist two main syntaxes for generic type-casting: 
 * functional and c-like:
 * 
 *      double x = 10.3;
 *      int y;
 *      y = int (x);    // functional notation
 *      y = (int) x;    // c-like cast notation
 */

class Dummy {
    double i,j;
};

class Addition {
    int x, y;
    public:
        Addition (int a, int b) { x = a; y = b; }
        int result() { return x + y; }
};

// int main(void){
    
//     Dummy d;
//     Addition * padd;
//     padd = (Addition * ) &d;
//     /**
//      * Unrestricted explicit type-casting to convert any pointer into any other
//      * pointer type, independently of the types they point to. The subsequent call
//      * to member result will produce either a run-time error or some other undexpected
//      * results.
//      */
//     cout << padd->result() << "\n";
//     return 0;
// }

/**
 * In order to control these types of conversions between classes, we have four specific
 * casting operators:
 *  
 *      - dynamic_cast
 *      - reinterpret_cast
 *      - static_cast
 *      - const_cast
 * 
 * Their format is to follow the new type enclosed between angle-brackets (<>) and immediately
 * after, the expression to be converted between parantheses.
 */

/* Casting: dynamic_cast */

/**
 * dynamic_cast can only be used with pointers and references to classes (or with void*).
 * It's purpose is to ensure that the result of the type conversion points to a valid complete
 * object of the destination pointer type.
 * 
 * This naturally includes pointer upcast (converting from pointer-to-derived to pointer-to-base),
 * int the same way as allowed as an implicit conversion.
 * 
 * dynamic_cast can also downcast (convert from pointer-to-base to pointer-to-derived) polymorphic
 * classes (those with virtual members) if - and only if - the pointed object is a valid complete
 * object of the target type.
 * 
 * For example:
 */

// class Base {
//     virtual void dummy() {}
// };

// class Derived : public Base { int a; };

// int main(void) {
//     try{
//         Base * pba = new Derived;
//         Base * pbb = new Base;

//         Derived *pd;

//         pd = dynamic_cast<Derived*>(pba);
//         if(pd == 0) cout << "Null pointer on first type-cast.\n";

//         pd = dynamic_cast<Derived*>(pbb);
//         if(pd == 0) cout << "Null pointer on second type-cast.\n";
    
//     }catch (exception & e) {
//         cout << "Exception: " << e.what();
//     }
//     return 0;
// }

/**
 * Compatibility mode:
 * This type of dynamic_cast requires Run-Time Type Information (RTTI) to keep track of dynamic
 * types. Some compilers support this feature as an option which is disabled by default. This needs
 * to be enabled for runtime type checking using dynamic_cast properly with these types.
 */

/**
 * When dynamic_cast cannot cat a pointer because it is not a complete object of the required class - as in the second
 * conversion of the previous example - it returns a null pointer to indicate the failure. Exception of bad_cast is thrown
 * if dynamic_cast is used to convert a reference type and the conversion is not possible.
 */

/* Casting: static_cast */

/**
 * static_cast can perform conversions between pointers to related classes, not only upcasts, but also downcasts.
 * No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination
 * type. Therefore, it is up to the programmer to ensure that the conversion is safe.
 * 
 * On the other side, it does not incur the overhead of the type-safety checks of dynamic cast.
 * 
 * EFFICIENT THAN: dynamic_cast.
 */

// class Base {};

// class Derived : public Base {};

// int main(void) {
//     Base * a = new Base;
//     Derived * b = static_cast<Derived*>(a);
//     return 0;
//     /**
//      * This would be valid code, although b would point to an INCOMPLETE object.
//      * 
//      * Therefore, static_cast is able to perform with pointers to classes not only the conversions allowed implicitly,
//      * but also their opposite conversions.
//      */
// }

/**
 * static_cast is also able to perform all conversions allowed implicitly (not only those with pointers to classes), and is
 * also able to perform the opposite of these. It can:
 * 
 *      - Convert from void* to any pointer type. In this case, it guarantees that if the void* value was obtained by
 *        converting from the same pointer type, the resulting pointer value is the same.
 * 
 *      - Convert integers, floating-point values and enum types to enum types.
 */

/**
 * Additionally, static_cast can also perform the following:
 *  
 *  - Explicitly call a single-argument constructor or a conversion operator.
 *  - Convert to rvalue reference
 *  - Convert enum class values to integers or floating-point values.
 *  - Convert any type to void, evaluating and discarding the value.
 */

/* Casting: reinterpret_cast */

/**
 * reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes.
 * The operation results in a simple binary copy of the value from one pointer to the other. All pointer
 * conversions are allowed:  neither the content pointed to nor the pointer type itself is checked.
 * 
 * It can also cast pointers to or from integer types. The format in which this integer value represents a pointer
 * is platform-specific. The only guarantee it shat a pointer cast to an integer type large enough to fully contain
 * it (such as intptr_t), is guaranteed to be able to be cast back to a valid pointer.
 * 
 * The conversion that can be performed by reinterpret_cast but not by static cast are low-level operations based on
 * reinterpreting the binary representations of the types, which on most cases results in code which is system-specific,
 * and thus non-portable/ For example:
 */

// class A { };
// class B { };

// int main(void) {
    
//     A * a = new A;

//     B * b = reinterpret_cast<B*>(a);

//     return 0;
// }

/* Casting: const_cast */

/**
 * This type of casting manipulates the constness of the object pointed by a pointer, either to be set or to be removed.
 * For example, in order to pass a const pointer to a function that expects a non-const argument:
 */

// void print (char * str) {
//     cout << str << '\n';
// }

// int main(void) {
//     const char * c = "sample text";
//     print(const_cast<char*>(c));
//     return 0;
// }

/* Casting: typeid */

/**
 * typeid allows to check the type of an expression:
 * 
 * This operator returns a reference to a constant object of type type_info that is defined in the standard header
 * <typeinfo>. A value returned by typeid can be compared with another value returned by type id using operators ==
 * and != or can serve to obtain a null-terminated character sequence representing the data type or class name by using
 * its name() member.
 */

// #include <typeinfo>

// int main(void) {
//     int * a, b;

//     a = 0; b = 0;

//     if(typeid(a) != typeid(b)) {

//         cout << "a and b are of different types:\n";
//         cout << "a is: " << typeid(a).name() << '\n';
//         cout << "b is: " << typeid(b).name() << '\n';
    
//     }

//     return 0;
// }

/**
 * When typeid is applied to classes, typeid uses the RTTI to keep track of the type of dynamic objects. When typeid is
 * applied to an expression whose type is a polymorphic class, the result is the type of the most derived complete object:
 */

#include <typeinfo>
#include <exception>

class Base { virtual void f(){} };
class Derived : public Base {};

int main () {
  try {
    Base* a = new Base;
    Base* b = new Derived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
  return 0;
}