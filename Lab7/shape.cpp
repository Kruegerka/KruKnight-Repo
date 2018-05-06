#include "shape.h"

Shape::Shape(unsigned int Color, matrix &point1)
{
    p1 = point1;
    p1[3][0] = 1.0;
    shapeColor = Color;
}

Shape::Shape(const Shape &from)
{
    shapeColor = from.shapeColor;
    p1 = from.p1;
}

Shape::~Shape(){
}

Shape::Shape(){
}

Shape &Shape::operator=(const Shape &rhs)
{
    shapeColor = rhs.shapeColor;
    p1 = rhs.p1;
    return *this;
}


