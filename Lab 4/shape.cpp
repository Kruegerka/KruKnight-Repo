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
}

std::istream Shape::in(std::istream &os) const
{
}

std::ofstream Shape::fileOut(std::ofstream &os) const
{
}

std::ifstream Shape::fileIn(std::ifstream &os) const
{
}