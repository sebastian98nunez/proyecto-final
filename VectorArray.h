#ifndef VECTORARRAY_H
#define VECTORARRAY_H
#include <Vector.h>

class VectorArray
{
    private:
        Vector* ArrayVec;
        int tam;
        void resize(int tmn);
    public:
        VectorArray());
        VectorArray(const Vector vec[],  int len);
        VectorArray(const VectorArray& vec);
        void printArray();
        void pushback(Vector &vec);
        void insertar(const int position, const Vector &vec);
        void borrar(const int position);
        const int getSize() const;
        virtual ~VectorArray();
};
