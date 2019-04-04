#include <unordered_set>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

/* <----- Friend classes -----> */

/**
 * Friendships are not symmetric – if class A is a friend of class B, class B is not automatically a friend of class A.
 * Friendships are not transitive – if class A is a friend of class B, and class B is a friend of class C, 
 * class A is not automatically a friend of class C.
 * Friendships are not inherited – if class Base is a friend of class X, subclass Derived is not automatically
 *  a friend of class X; and if class X is a friend of class Base, class X is not automatically a friend of subclass Derived.
 * 
 * More details: https://en.wikipedia.org/wiki/Friend_class
 */

class Graph;

class Vertex {
private:
    // Vertex gives access-rights to Graph.
    friend class Graph;

    unordered_set<Vertex*> _edges;
    string _name;

public:
    // 'explicit' keyword
    /**
     * in C++, if a class has a constructor which can be called with a single argument, 
     * then this constructor becomes conversion constructor because such a constructor 
     * allows conversion of the single argument to the class being constructed.
     * 
     * More info: https://www.geeksforgeeks.org/g-fact-93/
     */
    explicit Vertex(string name)
    : _edges()
    , _name(move(name)) {}

    auto begin() const { return _edges.cbegin(); }
    auto end() const { return _edges.cend(); }

    const auto& name() const {
        return _name;
    }
};

class Graph {
public:
    ~Graph() {
        while(!_vertices.empty()) {
            auto vertex = _vertices.begin();
            removeVertex(*vertex);
        }
    }

    auto addVertex(const string & name) -> Vertex* {
        auto vertex = make_unique<Vertex>(name);
        auto iter = _vertices.insert(vertex.get());
        return vertex.release();
    }

    void removeVertex(Vertex* vertex) {
        _vertices.erase(vertex);
        delete vertex;
    }

    auto addEdge(Vertex* from, Vertex* to) {
        /**
         * Graph can acces Vertex's private
         * fields because Vertex declared Graph as
         * a friend.
         */
        from -> _edges.insert(to);
    }

private:
    unordered_set<Vertex*> _vertices;
};

/* <----- End of: Friend classes -----> */

/* <----- Friend functions -----> */

/**
 * In object-oriented programming, a friend function, that is a "friend" of a given class, 
 * is a function that is given the same access as methods to private and protected data.
 * 
 * This approach may be used in friendly function when a function needs to access private 
 * data in objects from two different classes. 
 * 
 * This may be accomplished in two similar ways:
 * 
 *    a function of global or namespace scope may be declared as friend of both classes
 *    a member function of one class may be declared as friend of another one.
 * 
 * More details: https://en.wikipedia.org/wiki/Friend_function
 */

class Foo;

class Bar {
private:
    int a;
public:
    Bar() : a(0) {}
    void show(Bar& x, Foo& y);
    friend void show(Bar& x, Foo& y); // declaration of global friend
};

class Foo {
private:
    int b;
public:
    Foo() : b(6) {}
    friend void show(Bar& x, Foo& y); // declaration of global friend
    friend void Bar::show(Bar& x, Foo& y); // declaration of friend from other class
};

// Definition of member function of Bar; this member function is a friend of Foo
void Bar::show(Bar& x, Foo& y) {
    cout << "Show via function member of Bar" << endl;
    cout << "Bar::a = " << x.a << endl;
    cout << "Foo::b = " << y.b << endl;
}

// Friend for Bar and Foo, definition of global function.
void show(Bar& x, Foo& y) {
    cout << "Show via global function" << endl;
    cout << "Bar::a = " << x.a << endl;
    cout << "Foo::b = " << y.b << endl;
}

/* <----- End of: Friend functions -----> */

int main() {

    Bar a;
    Foo b;

    show(a,b);

    a.show(a,b);

    return 0;
}