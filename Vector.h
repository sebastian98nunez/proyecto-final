#ifndef Vector_h
#define Vector_h
#include<Point.h>
#include <iostream>
using namespace std;

using namespace std;

class Vector
{
    private:
        Point inicio;
        Point fin;
    public:
        Vector();
        Vector(Point , Point);
        void PrintVector();
        int distancia();

};
#endif
