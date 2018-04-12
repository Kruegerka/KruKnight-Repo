/* This is an abstract base class representing a generic graphics
 * context.  Most implementation specifics will need to be provided by
 * a concrete implementation.  See header file for specifics. */

#define _USE_MATH_DEFINES	// for M_PI
#include <cmath>	// for trig functions
#include "gcontext.h"	

/*
 * Destructor - does nothing
 */
GraphicsContext::~GraphicsContext()
{
	// nothing to do
	// here to insure subclasses handle destruction properly
}


/* This is a naive implementation that uses floating-point math
 * and "setPixel" which will need to be provided by the concrete
 * implementation.
 * 
 * Parameters:
 * 	x0, y0 - origin of line
 *  x1, y1 - end of line
 *
 * Returns: void
 */
void GraphicsContext::drawLine(int x0, int y0, int x1, int y1)
{

	// find slope
	int dx = x1-x0;
	int dy = y1-y0;

	if (std::abs(dx) > std::abs(dy))
	{
		if (x1 > x0)
		{
			int yi = 1;
			if ( dy < 0)
			{
				yi = -1;
				dy = -dy;
			}
			int D = 2*dy - dx;
			int y = y0;
			for (int x = x0; x < x1; x++)
			{
				setPixel(x,y);
				if (D>0){
					y+=yi;
					D-=2*dx;
				}
				D = D + 2*dy;
			}
		}
		else
		{
			drawLine(x1,y1,x0,y0);
		}
	} else
	{
		if (y1>y0)
		{
			int xi = 1;
			if (dx < 0) {
				xi = -1;
				dx = -dx;
			}
			int D = 2*dx - dy;
			int x = x0;
			for (int y = y0; y < y1; y++)
			{
				setPixel(x,y);
				if (D>0)
				{
					x = x + xi;
					D = D - 2*dy;
				}
				D = D + 2*dx;
			}
		}
		else
		{
			drawLine(x1,y1,x0,y0);
		}
	}

	return;
}



/* This is a naive implementation that uses floating-point math
 * and "setPixel" which will need to be provided by the concrete
 * implementation.
 * 
 * Parameters:
 * 	x0, y0 - origin/center of circle
 *  radius - radius of circle
 * 
 * Returns: void
 */
void GraphicsContext::drawCircle(int x0, int y0, unsigned int radius)
{
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int error = dx - (radius <<1);

	while(x >= y){
		setPixel(x0+x, y0+y);
		setPixel(x0+y, y0+x);
		setPixel(x0-y, y0+x);
		setPixel(x0-x, y0+y);
		setPixel(x0-x, y0-y);
		setPixel(x0-y, y0-x);
		setPixel(x0+y, y0-x);
		setPixel(x0+x, y0-y);

		if(error <= 0){
			y++;
			error += dy;
			dy += 2;
		}

		if(error > 0){
			x--;
			dx += 2;
			error += dx - (radius << 1);
		}
	}
	
	
	return;	
}

void GraphicsContext::endLoop()
{
	run = false;
}


