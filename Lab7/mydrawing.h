/** 
 * @Kruegerka
 * mydrawing.h
 */
#ifndef MYDRAWING_H
#define MYDRAWING_H

#include "drawbase.h"
#include "image.h"
#include <fstream>
#include "ViewContext.h"


class GraphicsContext;

class MyDrawing : public DrawingBase{
    public:
        //Remove errors
        MyDrawing();

        /** 
         * @brief  clears the screen and then prints out currentImage
         * @param  gc: GraphicContext for drawing the image to
         * @retval None
         */
        virtual void paint(GraphicsContext* gc);

        /** 
         * @brief  Draws the line when the mouse is clicked
         * @param  gc: GraphicContext for drawing the image to
         * @param  button: button pressed
         * @param  x: cordinite
         * @param  y: cordinite
         * @retval None
         */
        virtual void mouseButtonDown(GraphicsContext* gc, unsigned int button, int x, int y);

        /** 
         * @brief  Draws the final location of the shape and then addes it to currentImage
         * @param  gc: GraphicContext for drawing the image to
         * @param  button: button pressed
         * @param  x: cordinite
         * @param  y: cordinite
         * @retval None
         */
        virtual void mouseButtonUp(GraphicsContext* gc, unsigned int button, int x, int y);

        /** 
         * @brief  Draws the shape as the user drags
         * @param  gc: GraphicContext for drawing the image to
         * @param  x: cordinite
         * @param  y: cordinite
         * @retval None
         */
        virtual void mouseMove(GraphicsContext* gc, int x, int y);

        /** 
         * @brief  Sets what mode or function should be done based on key pressed
         * @param  gc: GraphicContext for drawing the image to
         * @param  keycode: key pressed
         * @retval None
         */
        virtual void keyDown(GraphicsContext* gc, unsigned int keycode);
    
    private:
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        Image CurrentImage;
        ViewContext VC;
        bool dragging;
        bool triangle1;
        bool triangle2;
        bool point;
        bool line;
        unsigned int currentColor;

};

#endif