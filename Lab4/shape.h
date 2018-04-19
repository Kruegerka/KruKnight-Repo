/** 
 * @Kruegerka
 * IMAGE.H
 */

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
        virtual ~Shape();
        Shape(unsigned int Color,matrix &point1);
        Shape(const Shape& from);
        Shape();
        virtual void out(std::ostream &os)=0;
        virtual void in(std::istream &is)=0;
        virtual void draw(GraphicsContext* gContext)=0;
        virtual Shape* clone() = 0;
};

#endif
