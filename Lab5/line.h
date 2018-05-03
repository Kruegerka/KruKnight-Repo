/** 
 * @Kruegerka
 * LINE.H
 */

#ifndef LINE
#define LINE

#include "shape.h"
#include "ViewContext.h"

class Line: public Shape{
    protected:
        matrix p2 = matrix(4,1);
        /** 
         * @brief  Method used for overriding the equal operator for copying the object
         * @param  rhs: objected to be copied
         * @retval current object
         */
        Line& operator=(const Line& rhs);
        

    public:
        Line();
        ~Line();

        /** 
         * @param  Color: Shape color 
         * @param  &point1: First point of the shape
         * @param  &point2: Second point of the shape
         * @retval none
         */
        Line(unsigned int pColor,matrix &point1,matrix &point2);

        /** 
         * @brief  Copy Constructor
         * @param  from: Object to be copied
         * @retval current object
         */
        Line(const Line& from);

        /** 
         * @brief  Draws the current object to the gContext
         * @param  gContext: file for drawing the shape
         * @retval None
         */
        void draw(GraphicsContext* gContext);
        
        /** 
         * @brief  Draws the current object to the gContext
         * @param  gContext: file for drawing the shape
         * @param  VC Viewcontext object containing transformation matrix
         * @retval None
         */
        void draw(GraphicsContext *gContext, ViewContext VC);
        
        /** 
         * @brief  Prints out the current Object
         * @param  &os: output stream
         * @retval None
         */
        void out(std::ostream &os);

        /** 
         * @brief  Reads in an text and converts it to an object
         * @param  &is: inputstream
         * @retval None
         */
        void in(std::istream &is);

        /** 
         * @brief  makes a new clone of current object then returns it
         * @retval cloned object
         */
        Shape* clone();

};


#endif