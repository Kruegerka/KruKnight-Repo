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
    std::vector<Shape*> shapeList;
    
    public:
        Image& operator=(const Image& rhs);
        void add(Shape* newShape);
        void draw(GraphicsContext* gContext);
        void out(std::ostream& os);
        void in(std::istream& os);
        void erase();
        Image();
        ~Image();
        Image(const Image& from);
};


#endif