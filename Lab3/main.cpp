#include "x11context.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
 
int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
	srand(time(0));
	for(int i =0; i<20; i++){
		gc->setColor(GraphicsContext::GREEN);
		gc->drawLine(rand()%500,rand()%500,rand()%500,rand()%500);
		gc->drawLine(rand()%500,rand()%500,rand()%500,rand()%500);

		gc->setColor(GraphicsContext::RED);
		gc->drawLine(rand()%500,rand()%500,rand()%500,rand()%500);

		gc->setColor(GraphicsContext::YELLOW);
		gc->drawCircle(rand()%500,rand()%500,rand()%500);
	}

 
	// draw some lines
	gc->setColor(GraphicsContext::GREEN);
	gc->setPixel(10,10);
	gc->setPixel(30,30);
	gc->drawLine(100,100,100,500);
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(100,500,500,500);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(500,500,500,100);
	gc->setColor(GraphicsContext::YELLOW);
	gc->drawLine(500,100,100,100);
	gc->setColor(GraphicsContext::MAGENTA);
	gc->drawCircle(300,300,200);
	sleep(5);
 
	delete gc;
 
	return 0;
}
