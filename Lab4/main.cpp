#include "x11context.h"
#include "line.h"
#include "triangle.h"
#include "image.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

int main(void)
{
	GraphicsContext *gc = new X11Context(800, 600, GraphicsContext::BLACK);
	sleep(1);

	matrix m1 = matrix(2, 4);
	matrix m2 = matrix(2, 4);
	m2[0][0] = 500;
	m2[0][1] = 500;
	Line l1 = Line(0x00FF00, m1, m2);

	matrix m3 = matrix(2, 4);
	m2[0][1] = 600;
	m3[0][0] = 500;
	Triangle t1 = Triangle(0x00FFF0, m1, m2, m3);
	
	Image i1 = Image();
	i1.add(&l1);
	i1.add(&t1);
	i1.out(std::cout);
	Image i2 = Image();
	std::cout << std::endl;
	i2.in(std::cin);
	i2.out(std::cout);
	std::cout << std::endl;
	i1.draw(gc);
	sleep(5);

	delete gc;

	return 0;
}
