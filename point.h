
#include "Point.h"
#include <iostream>
using namespace std;
Point::Point() : x(0),y(0) {}

Point::Point(int xo, int yo) :x(xo),y(yo){}

Point::Point( Point &a) {
    x=a.x;
    y=a.y;
}

void Point::SetX(int xo){
    x=xo;
    }

void Point::SetY(int yo) {
    y=yo;
    }

int Point::GetX(){
    //cout << "El valor de x es: "<<x << endl;
    return x;

}

int Point::GetY(){
    //cout << "El valor de y es: "<<y << endl;
    return y;

}

void Point::PrintPoint(){
    cout << "El punto es: (" <<x <<"," <<y << ")" << endl;

}
