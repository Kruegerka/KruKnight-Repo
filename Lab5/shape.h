/** 
 * @Kruegerka
 * IMAGE.H
 */

#ifndef SHAPE
#define SHAPE

#include <iostream>
#include <fstream>
#include <string>
#include "gcontext.h"
#include "matrix.h"
#include "ViewContext.h"

class Shape{
    protected:
        unsigned int shapeColor;
        matrix p1 = matrix(4,1);

        /** 
         * @brief  Method used for overriding the equal operator for copying the object
         * @param  rhs: objected to be copied
         * @retval current object
         */
        Shape& operator=(const Shape& rhs);
        
    public:
        virtual ~Shape();
        Shape();

        /** 
         * @param  Color: Shape color 
         * @param  &point1: First point of the shape
         * @retval none
         */
        Shape(unsigned int Color,matrix &point1);
        /** 
         * @brief  Copy Constructor
         * @param  from: Object to be copied
         * @retval current object
         */
        Shape(const Shape& from);
        
        /** 
         * @brief  Prints out the current Object
         * @param  &os: output stream
         * @retval None
         */
        virtual void out(std::ostream &os)=0;

        /** 
         * @brief  Reads in an text and converts it to an object
         * @param  &is: inputstream
         * @retval None
         */
        virtual void in(std::istream &is)=0;

        /** 
         * @brief  Draws the current object to the gContext
         * @param  gContext: file for drawing the shape
         * @retval None
         */
        virtual void draw(GraphicsContext* gContext)=0;

        virtual void draw(GraphicsContext* gContext,ViewContext VC)=0;
        /** 
         * @brief  makes a new clone of current object then returns it
         * @retval cloned object
         */
        virtual Shape* clone() = 0;
};

#endif
