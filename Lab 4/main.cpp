#include "line.h"
#include "x11context.h"
#include <unistd.h>
#include <iostream>
 
int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

	gc->drawLine(100,100,100,500);
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(100,500,500,500);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(500,500,500,100);
	gc->setColor(GraphicsContext::YELLOW);
	gc->drawLine(500,100,100,100);

	matrix m1 = matrix(1,4);
	matrix m2 = matrix(1,4);
	
	m2[0][0]=500;
	m2[0][1]=500;
	Line l1 = Line(0x00FF00, m1, m2);
	l1.draw(gc);

	sleep(5);
 
	delete gc;
 
	return 0;
}
