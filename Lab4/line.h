/** 
 * @Kruegerka
 * LINE.H
 */

#ifndef LINE
#define LINE

#include "shape.h"

class Line: public Shape{
    protected:
        matrix p2 = matrix(1,4);
        Line& operator=(const Line& rhs);
        

    public:
        Line();
        ~Line();
        Line(unsigned int pColor,matrix &point1,matrix &point2);
        Line(const Line& from);
        void draw(GraphicsContext* gContext);
        void out(std::ostream &os);
        void in(std::istream &is);
        Shape* clone();

};


#endif