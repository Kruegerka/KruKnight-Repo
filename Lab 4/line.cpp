#include "line.h"

Line::Line(unsigned int pColor, matrix &point1,matrix &point2) : Shape(pColor, point1){
    p2=point2;
    p2[0][3]=1.0;
}

Line::Line(const Line& from) : Shape(from){
    p2=from.p2;
}


void Line::draw(GraphicsContext* gContext){
    gContext->setColor(shapeColor);
    gContext->drawLine(p1[0][0],p1[0][1],p2[0][0],p2[0][1]);
}
