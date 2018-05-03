#ifndef VIEWCONTEXT_H
#define VIEWCONTEXT_H
#include "matrix.h"

class ViewContext
{
    protected:
    matrix invTransform = matrix(4,4);
    matrix transform = matrix(4,4);

	public:
		ViewContext();
        matrix applyTransform(matrix theMatrix);
        matrix applyInverse(matrix theMatrix);
        void scale(double x, double y, double z);
        void rotation(double roll, double pitch, double yaw);
        void traslation(double x, double y, double z);
		
};
#endif