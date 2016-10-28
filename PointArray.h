#ifndef POINTARRAY_H
#define POINTARRAY_H

class PointArray
{
    public:
        PointArray(Point points[], tmñ);
        PointArray();
        PointArray(PointArray &pv);
        virtual ~PointArray();
        void insert(posicion, *pv);
        void push_back(Point);
        void borrar(posicion);
        

    private:
        Point* puntos;
        int size;
        PointArray resize();
        
        
        
};
