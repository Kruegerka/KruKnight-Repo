#ifndef VIEWCONTEXT_H
#define VIEWCONTEXT_H
#include "image.h"

class ViewContext
{
    protected:
    std::vector<matrix*> matrixList;
    Image ModifiedImage;
    bool imageModified;

	public:
		ViewContext();
        void convertToNormal(Image& currentImage);
        void scaleIn(GraphicsContext* gc, Image& currentImage);
        void scaleOut(GraphicsContext* gc, Image& currentImage);
        void rotationL(GraphicsContext* gc, Image& currentImage);
        void traslationL(GraphicsContext* gc, Image& currentImage);
        void rotationR(GraphicsContext* gc, Image& currentImage);
        void traslationR(GraphicsContext* gc, Image& currentImage);
		
};
#endif