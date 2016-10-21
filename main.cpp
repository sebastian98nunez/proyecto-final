#include <iostream>
#include <Point.h>
#include <Vector.h>

using namespace std;


int main()
{
    int x;
    Vector Vector1;
    Point Point2;
    Point Point3;
    Point Point1(3,4);
    Point1.PrintPoint();
    Point2=Point(Point1);
    Point3.SetX(5);
    Point3.SetY(6);
    Point3.GetX();
    Point3.GetY();
    Point2.PrintPoint();
    Vector1=Vector(Point1,Point3);
    Vector1.PrintVector();
    x=Vector1.distancia();
    cout<<"La distancia del vector es:" << x;
    return 0;

}
