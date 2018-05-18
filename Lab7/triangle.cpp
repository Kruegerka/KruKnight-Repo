#include "triangle.h"
#include <cmath>


Triangle::Triangle(){

}

Triangle::Triangle(unsigned int pColor,  matrix &point1, matrix &point2, matrix &point3) : Shape(pColor, point1)
{
    p2 = point2;
    p3 = point3;
    p2[3][0] = 1.0;
}

Triangle::Triangle(const Triangle &from) : Shape(from)
{
    p2 = from.p2;
    p3 = from.p3;
}

Triangle::~Triangle()
{

}

void Triangle::draw(GraphicsContext *gContext)
{
    gContext->setColor(shapeColor);
    gContext->drawLine(p1[0][0]+400+(p1[2][0]*cos(M_PI/3)),300-p1[1][0]-(p1[2][0]*0.5),p2[0][0]+400+(p2[2][0]*cos(M_PI/3)),300-p2[1][0]-(p2[2][0]*0.5));
    gContext->drawLine(p1[0][0]+400+(p1[2][0]*cos(M_PI/3)),300-p1[1][0]-(p1[2][0]*0.5),p3[0][0]+400+(p3[2][0]*cos(M_PI/3)),300-p3[1][0]-(p3[2][0]*0.5));
    gContext->drawLine(p2[0][0]+400+(p2[2][0]*cos(M_PI/3)),300-p2[1][0]-(p2[2][0]*0.5),p3[0][0]+400+(p3[2][0]*cos(M_PI/3)),300-p3[1][0]-(p3[2][0]*0.5));
}

void Triangle::draw(GraphicsContext *gContext, ViewContext VC)
{
    gContext->setColor(shapeColor);
    matrix m1 = matrix(4,4);
    matrix m2 = matrix(4,4);
    matrix m3 = matrix(4,4);

    m1 = VC.applyTransform(p1);
    m2 = VC.applyTransform(p2);
    m3 = VC.applyTransform(p3);

/*
    //std::cout << m3<<std::endl; 
    if(m1[3][0] != 1.0){
        for(int i = 0; i < 4; i++){
            m1[i][0] = m1[i][0] / m1[3][0];
        }
    }
    std::cout << m1<<std::endl; 
    if(m2[3][0] != 1.0){
        for(int i = 0; i < 4; i++){
            m2[i][0] = m2[i][0] / m2[3][0];
        }
    }
    std::cout << m2<<std::endl; 

    if(m3[3][0] != 1.0){
        for(int i = 0; i < 4; i++){
            m3[i][0] = m3[i][0] / m3[3][0];
        }
    }
    std::cout << m3<<std::endl; 
*/


    //gContext->drawLine(400+m1[0][0], 300-m1[1][0], 400+m2[0][0], 300-m2[1][0]);
    //gContext->drawLine(400+m2[0][0], 300-m2[1][0], 400+m3[0][0], 300-m3[1][0]);
    //gContext->drawLine(400+m3[0][0], 300-m3[1][0], 400+m1[0][0], 300-m1[1][0]);

    gContext->drawLine(m1[0][0]+400+(m1[2][0]*cos(M_PI/3)),300-m1[1][0]-(m1[2][0]*0.5),m2[0][0]+400+(m2[2][0]*cos(M_PI/3)),300-m2[1][0]-(m2[2][0]*0.5));
    gContext->drawLine(m1[0][0]+400+(m1[2][0]*cos(M_PI/3)),300-m1[1][0]-(m1[2][0]*0.5),m3[0][0]+400+(m3[2][0]*cos(M_PI/3)),300-m3[1][0]-(m3[2][0]*0.5));
    gContext->drawLine(m2[0][0]+400+(m2[2][0]*cos(M_PI/3)),300-m2[1][0]-(m2[2][0]*0.5),m3[0][0]+400+(m3[2][0]*cos(M_PI/3)),300-m3[1][0]-(m3[2][0]*0.5));
}


Triangle &Triangle::operator=(const Triangle &rhs)
{
    shapeColor = rhs.shapeColor;
    p1 = rhs.p1;
    p2 = rhs.p2;
    p3 = rhs.p3;
    return *this;
}

void Triangle::out(std::ostream &os)
{
    int x;
    int y;
    int z;
    os << "T ";
    os << shapeColor << " ";
    x = p1[0][0];
    y = p1[1][0];
    z = p1[2][0];
    os << x << " ";
    os << y << " ";
    os << z << " ";
    x = p2[0][0];
    y = p2[1][0];
    z = p2[2][0];
    os << x << " ";
    os << y << " ";
    os << z << " ";
    x = p3[0][0];
    y = p3[1][0];
    z = p3[2][0];
    os << x << " ";
    os << y << " ";
    os << z << " ";
}

void Triangle::in(std::istream &is)
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
    is >> x;
    is >> y;
    is >> z;
    p3[0][0] = x;
    p3[1][0] = y;
    p3[2][0] = z;
    p3[3][0] = 1.0;
    
}

void Triangle::inSTL(std::istream &is)
{
    std::string currentWord;
    shapeColor = GraphicsContext::WHITE;
    int x;
    int y;
    int z;
    is >> x;
    is >> y;
    is >> z;
    p1[0][0] = x;
    p1[1][0] = y;
    p1[2][0] = z;
    p1[3][0] = 1.0;
    is >> currentWord;
    is >> x;
    is >> y;
    is >> z;
    p2[0][0] = x;
    p2[1][0] = y;
    p2[2][0] = z;
    p2[3][0] = 1.0;
    is >> currentWord;
    is >> x;
    is >> y;
    is >> z;
    p3[0][0] = x;
    p3[1][0] = y;
    p3[2][0] = z;
    p3[3][0] = 1.0;
}

Shape* Triangle::clone(){
    return new Triangle(*this);
}