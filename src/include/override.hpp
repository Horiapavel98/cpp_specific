#include "default_headers.hpp"

class Point2D {
protected:
    int x;
    int y;
public:
    Point2D(int xIn, int yIn) 
        : x(xIn), y(yIn) { }

    void printData() {
        std::cout << "X coordinate is: " << x << std::endl;
        std::cout << "Y coordinate is: " << y << std::endl;
    }
};

/**
 * To access the overridden function of the base class from the derived class, 
 * scope resolution operator :: is used. For example,     Point2D::printData();
 */
class Point3D : public Point2D {
protected:
    int z;
public:
    Point3D(int xIn, int yIn, int zIn) :
        Point2D(xIn,yIn), z(zIn) {}

    void printData() {
        Point2D::printData();
        std::cout << "Z coordinate is: " << z << std::endl;
    }
};

class Override {
public:
    static void output() {
        Point3D p3d(3,6,8);
        p3d.printData();

        Point2D p2d(1,2);
        p2d.printData();

        Point3D p3d2(10,10,100);
        p3d2.printData();
    }
};