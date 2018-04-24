#ifndef MYDRAWING_H
#define MYDRAWING_H

#include "drawbase.h"
#include "image.h"
#include <fstream>


class GraphicsContext;

class MyDrawing : public DrawingBase{
    public:
        MyDrawing();
        virtual void paint(GraphicsContext* gc);
        virtual void mouseButtonDown(GraphicsContext* gc, unsigned int button, int x, int y);
        virtual void mouseButtonUp(GraphicsContext* gc, unsigned int button, int x, int y);
        virtual void mouseMove(GraphicsContext* gc, int x, int y);
        virtual void keyDown(GraphicsContext* gc, unsigned int keycode);
    private:
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        Image CurrentImage;
        bool dragging;
        bool triangle1;
        bool triangle2;
        bool point;
        bool line;
        unsigned int currentColor;

};

#endif