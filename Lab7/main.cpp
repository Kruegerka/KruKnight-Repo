#include "x11context.h"
#include "line.h"
#include "triangle.h"
#include "image.h"
#include "mydrawing.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
int main(void)
{
	GraphicsContext *gc = new X11Context(800, 600, GraphicsContext::BLACK);
	sleep(1);

	gc->setColor(GraphicsContext::GREEN);

	MyDrawing md;

	gc->runLoop(&md);

	delete gc;

	return 0;
}
