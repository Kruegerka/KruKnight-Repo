#include "shape.h"

Shape::Shape(unsigned int Color, matrix &point1)
{
    p1 = point1;
    p1[0][3] = 1.0;
    shapeColor = Color;
}

Shape::Shape(const Shape &from)
{
    shapeColor = from.shapeColor;
}

Shape &Shape::operator=(const Shape &rhs)
{
    shapeColor = rhs.shapeColor;
    p1 = rhs.p1;
}

std::ostream Shape::out(std::ostream &os) const
{
    int x;
    int y;
    int z;
    x = p1[0][0];
    y = p1[0][1];
    z = p1[0][2];
    os << x << " ";
    os << y << " ";
    os << z << " ";

}

std::istream Shape::in(std::istream &is) const
{
    std::string str;
    int x;
    int y;
    int z;
    is >> shapeColor; 
    shapeColor = std::stoul(&str,0,10);
    is >> x;
    is >> y;
    is >> z;
    p1[0][0] = x;
    p1[0][1] = y;
    p1[0][2] = z;
    p1[0][3] = 1.0;
    
}

