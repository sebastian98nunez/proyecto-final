#include "Vector.h"
#include <iostream>
#include <math.h>
using namespace std;

Vector::Vector(){
    inicio=Point();
    fin=Point();
    }

Vector::Vector( Point in , Point fi){
    inicio=in;
    fin= fi;
    }

void Vector::PrintVector(){
    cout<<"El punto incial del vector es:";
    inicio.PrintPoint();
    cout<<endl;
   cout<<"El punto final del vector es:";
   fin.PrintPoint();
   cout<<endl;
    }

int Vector::distancia(){
    int dist=0;
    dist= sqrt(pow(fin.GetX()-inicio.GetX(),2)+ pow(fin.GetY()-inicio.GetY(),2));
    return dist;
    }
