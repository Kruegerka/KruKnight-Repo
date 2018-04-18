#include "line.h"

Line::Line(unsigned int pColor, matrix &point1, matrix &point2) : Shape(pColor, point1)
{
    p2 = point2;
    p2[0][3] = 1.0;
}

Line::Line(const Line &from) : Shape(from)
{
    p2 = from.p2;
}

void Line::draw(GraphicsContext *gContext)
{
    gContext->setColor(shapeColor);
    gContext->drawLine(p1[0][0], p1[0][1], p2[0][0], p2[0][1]);
}

Line &Line::operator=(const Line &rhs)
{
    shapeColor = rhs.shapeColor;
    p1 = rhs.p1;
    p2 = rhs.p2;
}

std::ostream Line::out(std::ostream &os) const
{
}

std::istream Line::in(std::istream &os) const
{
}

std::ofstream Line::fileOut(std::ofstream &os) const
{
}

std::ifstream Line::fileIn(std::ifstream &os) const
{
}
