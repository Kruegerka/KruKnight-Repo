#ifndef LINE
#define LINE

#include "shape.h"

class Triangle: public Shape{
    protected:
        matrix p2;
        matrix p3;
        Triangle(unsigned int pColor,float point1,float point2,float point3);
        Triangle(const Triangle& from);
};


#endif