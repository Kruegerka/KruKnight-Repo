#ifndef IMAGE
#define IMAGE

#include "shape.h"

class Image{
    protected:
    
    public:
        Image& operator=(const Image& rhs);
        void add(Shape newShape);
        void draw(GraphicsContext gContext);
        std::ostream& out(std::ostream& os);
        std::istream& in(std::istream& os);
        void erase();
};


#endif