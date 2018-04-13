#include "x11context.h"
#include "line.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
 
int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
	sleep(1);

	matrix m1 = matrix(2,4);
	matrix m2 = matrix(2,4);
	m2[0][0]=500;
	m2[0][1]=500;
	Line l1 = Line(0x00FF00, m1, m2);
	l1.draw(gc);

	sleep(5);
 
	delete gc;
 
	return 0;
}
