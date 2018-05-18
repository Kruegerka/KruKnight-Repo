/** 
 * @Kruegerka
 * IMAGE.H
 */



#ifndef IMAGE
#define IMAGE

#include "shape.h"
#include "line.h"
#include "triangle.h"
#include <vector>

class Image{
    protected:
    
    
    public:
    std::vector<Shape*> shapeList;
        /** 
         * @brief  Method used for overriding the equal operator for copying the object
         * @param  rhs: objected to be copied
         * @retval current object
         */
        Image& operator=(const Image& rhs);

        /** 
         * @brief  adds the passed in object to the shapelist
         * @param  newShape: shape object to be added
         * @retval None
         */
        void add(Shape* newShape);

        /** 
         * @brief  Draws the current object shapelist to the gContext
         * @param  gContext: file for drawing the shapes
         * @retval None
         */
        void draw(GraphicsContext* gContext);
        void draw(GraphicsContext* gContext, ViewContext VC);

        /** 
         * @brief  Prints out the Vector of shapes
         * @param  &os: output stream
         * @retval None
         */
        void out(std::ostream& os);

        /** 
         * @brief  Reads in an text and converts it to an objects for the shapeList
         * @param  &is: inputstream
         * @retval None
         */
        void in(std::istream& os);

        /** 
         * @brief  Reads in a STL file and converts it to an object
         * @param  &is: inputstream
         * @retval None
         */
        void inSTL(std::istream& os);

        /** 
         * @brief  erases the current object's shapeslist
         * @retval None
         */
        void erase();
        Image();
        ~Image();

        /** 
         * @brief  Copy Constructor
         * @param  from: Object to be copied
         * @retval current object
         */
        Image(const Image& from);

        int getSize();
};


#endif