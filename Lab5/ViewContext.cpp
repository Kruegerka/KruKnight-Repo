#include "ViewContext.h"

ViewContext::ViewContext(){
    imageModified = false;
};

void ViewContext::convertToNormal(Image& currentImage){
    
}

void ViewContext::scaleIn(GraphicsContext* gc, Image& currentImage){
    if(imageModified == false){
        ModifiedImage = currentImage;
    }
    for(int i = 0; i < ModifiedImage.getSize(); i++){
        //ModifiedImage.shapeList[i]->
    }
    gc->clear();
    ModifiedImage.draw(gc);
}

void ViewContext::scaleOut(GraphicsContext* gc, Image& currentImage){
    if(imageModified == false){
        ModifiedImage = currentImage;
    }
}

void ViewContext::rotationL(GraphicsContext* gc, Image& currentImage){
    if(imageModified == false){
        ModifiedImage = currentImage;
    }
}

void ViewContext::traslationL(GraphicsContext* gc, Image& currentImage){
    if(imageModified == false){
        ModifiedImage = currentImage;
    }
}

void ViewContext::rotationR(GraphicsContext* gc, Image& currentImage){
    if(imageModified == false){
        ModifiedImage = currentImage;
    }
}

void ViewContext::traslationR(GraphicsContext* gc, Image& currentImage){
    if(imageModified == false){
        ModifiedImage = currentImage;
    }
}

