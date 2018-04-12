#include "x11context.h"
#include "line.h"
#include <unistd.h>
#include <iostream>

int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

	matrix m1 = matrix(1,4);
	matrix m2 = matrix(1,4);
	m2[0][0]=500;
	m2[0][1]=500;
	Line l1 = Line(0x00FF00, m1, m2);

	sleep(5);

	delete gc;

	return 0;
}
