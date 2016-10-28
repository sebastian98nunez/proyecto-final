#include "PointArray.h"
#include "PointArray.h"


PointArray::PointArray(Point points[], tmñ){
    puntos=points;
    size=tmñ;
}
PointArray(){
    size=0;
    puntos=new Point[0];
}
PointArray(PointArray &pv){
    puntos.resize(pv.size);
    for(int x=0; x< size; x++){
        puntos[x]=pv[x]:
    }
    }

PointArray PointArray::resize(tmñ){
    PointArray pts = new Point[tmñ];
    for(int x=0; x< tmñ; x++){
        pts[x]=puntos[x];
    }
    return pts;
}    

void PointArray::insert(posicion, *pv){
    puntos.resize(size+1);
    Point temp=puntos[posicion];
    puntos[posicion]=pv;
    for(int i=posicion+1;puntos[i]!= NULL;i++){
        Point temp=puntos[posicion];
        puntos[posicion]=pv;
    }
    }
void PointArray::push_back(Point){
    puntos.resize(size+1);
    puntos[size-1]=Point;
}
void PointArray::borrar(posicion){
    Point temp=puntos[size-1];
    puntos.resize(size-1);
    for(int i=posicion;puntos[i]!= NULL;i++){
        puntos[posicion]=puntos[posicion+1];
     }
    puntos[size]=temp;
    }
