#include "line.h"

Line::Line(unsigned int pColor, matrix &point1, matrix &point2) : Shape(pColor, point1)
{
    p2 = point2;
    p2[3][0] = 1.0;
}

Line::Line(const Line &from) : Shape(from)
{
    p2 = from.p2;
}

Line::~Line(){

}

Line::Line(){
 
}

void Line::draw(GraphicsContext *gContext)
{
    gContext->setColor(shapeColor);
    gContext->drawLine(p1[0][0], p1[1][0], p2[0][0], p2[1][0]);
}

void Line::draw(GraphicsContext *gContext, ViewContext VC)
{
    gContext->setColor(shapeColor);
    matrix m1 = matrix(4,4);
    matrix m2 = matrix(4,4);

    m1 = VC.applyTransform(p1);
    m2 = VC.applyTransform(p2);

    gContext->drawLine(m1[0][0], m1[1][0], m2[0][0], m2[1][0]);
}

Line &Line::operator=(const Line &rhs)
{
    shapeColor = rhs.shapeColor;
    p1 = rhs.p1;
    p2 = rhs.p2;
    return *this;
}

void Line::out(std::ostream &os)
{
    int x;
    int y;
    int z;
    os << "L ";
    os << shapeColor << " ";
    x = p1[0][0];
    y = p1[1][0];
    z = p1[2][0];
    os << p1[0][0] << " ";
    os << p1[1][0] << " ";
    os << p1[2][0] << " ";
    x = p2[0][0];
    y = p2[1][0];
    z = p2[2][0];
    os << x << " ";
    os << y << " ";
    os << z << " ";
}

void Line::in(std::istream &is)
{
    int x;
    int y;
    int z;
    is >> shapeColor; 
    is >> x;
    is >> y;
    is >> z;
    p1[0][0] = x;
    p1[1][0] = y;
    p1[2][0] = z;
    p1[3][0] = 1.0;
    is >> x;
    is >> y;
    is >> z;
    p2[0][0] = x;
    p2[1][0] = y;
    p2[2][0] = z;
    p2[3][0] = 1.0;
}

Shape* Line::clone(){
    return new Line(*this);
}
