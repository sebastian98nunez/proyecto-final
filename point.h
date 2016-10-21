#ifndef Point_h
#define Point_h

class Point{
private:
    int x,y;
public:
    Point();
    Point(int , int );
    Point(Point &);
    void SetX(int );
    void SetY(int );
    int GetX();
    int GetY();
    void PrintPoint();
    void ModifyPoint(int , int );

};

#endif
