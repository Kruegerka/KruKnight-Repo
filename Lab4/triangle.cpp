#include "triangle.h"

Triangle::Triangle(unsigned int pColor,  matrix &point1, matrix &point2, matrix &point3) : Shape(pColor, point1)
{
    p2 = point2;
    p3 = point3;
    p2[0][3] = 1.0;
}

Triangle::Triangle(const Triangle &from) : Shape(from)
{
    p2 = from.p2;
    p3 = from.p3;
}

void Triangle::draw(GraphicsContext *gContext)
{
    gContext->setColor(shapeColor);
    gContext->drawLine(p1[0][0], p1[0][1], p2[0][0], p2[0][1]);
    gContext->drawLine(p2[0][0], p2[0][1], p3[0][0], p3[0][1]);
    gContext->drawLine(p3[0][0], p3[0][1], p1[0][0], p1[0][1]);
}

Triangle &Triangle::operator=(const Triangle &rhs)
{
    shapeColor = rhs.shapeColor;
    p1 = rhs.p1;
    p2 = rhs.p2;
    p3 = rhs.p3;
}

std::ostream Triangle::out(std::ostream &os) const
{
}

std::istream Triangle::in(std::istream &is) const
{
}

Shape* Triangle::clone(){
    return new Triangle(*this);
}