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

Line::~Line(){

}

Line::Line(){
 
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
    y = p1[0][1];
    z = p1[0][2];
    //std::cout<< p2;
    os << p1[0][0] << " ";
    os << p1[0][1] << " ";
    os << p1[0][2] << " ";
    x = p2[0][0];
    y = p2[0][1];
    z = p2[0][2];
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
    std::cout<<"the line has " << x << " " << y << " " << z;
    p1[0][0] = x;
    p1[0][1] = y;
    p1[0][2] = z;
    p1[0][3] = 1.0;
    std::cout<<"the line has " << x << " " << y << " " << z;
    is >> x;
    is >> y;
    is >> z;
    p2[0][0] = x;
    p2[0][1] = y;
    p2[0][2] = z;
    p2[0][3] = 1.0;
}

Shape* Line::clone(){
    return new Line(*this);
}
