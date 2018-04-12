#ifndef LINE
#define LINE

#include "shape.h"

class Line: public Shape{
    protected:
        matrix p2 = matrix(4,1);

    public:
        Line(unsigned int pColor,matrix &point1,matrix &point2);
        Line(const Line& from);
        void draw(GraphicsContext* gContext);

};


#endif