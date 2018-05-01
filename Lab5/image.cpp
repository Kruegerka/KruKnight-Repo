#include "image.h"

Image::Image()
{
}

Image::Image(const Image& from){
    for (unsigned int i = 0; i < from.shapeList.size(); i++)
    {
        shapeList.push_back(from.shapeList[i]->clone());
    }
}

Image::~Image(){
    shapeList.clear();
}

Image &Image::operator=(const Image &rhs) {
    shapeList = rhs.shapeList;
    return *this;
}

void Image::add(Shape* addShape) {
    shapeList.push_back(addShape);
}

void Image::draw(GraphicsContext* gContext) {
    for(unsigned int i = 0; i<shapeList.size(); i++){
        shapeList[i]->draw(gContext);
    }
}

void Image::out(std::ostream &os) {
    for(unsigned int i = 0; i<shapeList.size(); i++){
        shapeList[i]->out(os);
        os << std::endl;
    }
}

void Image::in(std::istream &is) {
    std::string str;
    while(is >> str){
        if(str.compare("L") == 0){
            Line* s = new Line();
            s->in(is);
            this->add(s);
        }
        else if(str.compare("T") == 0){
            Triangle* s = new Triangle();
            s->in(is);
            this->add(s);
        }
    }
        
}

void Image::erase() {
    shapeList.clear();
}

int Image::getSize(){
    return shapeList.size();
}