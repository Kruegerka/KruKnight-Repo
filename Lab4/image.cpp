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
    //for(unsigned int i = 0; i<shapeList.size(); i++){
        //delete shapeList[i];
    //}
}

Image &Image::operator=(const Image &rhs) {
    shapeList = rhs.shapeList;
    return *this;
}

void Image::add(Shape* addShape) {
    shapeList.push_back((Shape*)addShape->clone());
}

void Image::draw(GraphicsContext* gContext) {
    for(unsigned int i = 0; i<shapeList.size(); i++){
        shapeList[i]->draw(gContext);
    }
}

void Image::out(std::ostream &os) {
    for(unsigned int i = 0; i<shapeList.size(); i++){
        shapeList[i]->out(os);
    }
}

void Image::in(std::istream &is) {
    std::string str;
    Shape* s;
    while(is){
        is >> str;
        if(str.compare("L") == 0){
            s = new Line();
            s->in(is);
            this->add(s);
        }
        if(str.compare("T") == 0){
            s = new Triangle();
            s->in(is);
            this->add(s);
        }
    }
        
}

void Image::erase() {
    for (unsigned int i = 0; i < shapeList.size(); i++)
    {
        delete shapeList[i];
    }
    shapeList.erase(shapeList.begin());
}