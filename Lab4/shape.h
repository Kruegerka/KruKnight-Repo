#ifndef SHAPE
#define SHAPE

#include <iostream>
#include <fstream>
#include <string>
#include "gcontext.h"
#include "matrix.h"

class Shape{
    protected:
        unsigned int shapeColor;
        matrix p1 = matrix(4,1);
        Shape& operator=(const Shape& rhs);

    public:
        Shape(unsigned int Color,matrix &point1);
        Shape(const Shape& from);
        Shape();
        std::ostream out(std::ostream &os) const;
        std::istream in(std::istream &is) const;
        virtual void draw(GraphicsContext* gContext)=0;

};

#endif
