#ifndef TRIANGLE
#define TRIANGLE

#include "shape.h"

class Triangle: public Shape{
    protected:
        matrix p2 = matrix(4,1);
        matrix p3 = matrix(4,1);
        Triangle& operator=(const Triangle& rhs);
        
    public:
        ~Triangle();
        Triangle();
        Triangle(unsigned int pColor, matrix &point1, matrix &point2, matrix &point3);
        Triangle(const Triangle& from);
        void draw(GraphicsContext* gContext);
        void out(std::ostream &os);
        void in(std::istream &is);
        Shape* clone();
};


#endif