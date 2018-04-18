#ifndef LINE
#define LINE

#include "shape.h"

class Line: public Shape{
    protected:
        matrix p2 = matrix(4,1);
        Line& operator=(const Line& rhs);
        

    public:
        ~Line();
        Line(unsigned int pColor,matrix &point1,matrix &point2);
        Line(const Line& from);
        void draw(GraphicsContext* gContext);
        std::ostream out(std::ostream &os);
        std::istream in(std::istream &is);
        Shape* clone();

};


#endif