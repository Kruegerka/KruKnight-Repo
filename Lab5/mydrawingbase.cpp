#include "mydrawing.h"
#include "gcontext.h"

MyDrawing::MyDrawing(){
    dragging = false;
    triangle1 = false;
    triangle2 = false;
    point = false;
    line = true;
    x0=0;
    y0=0;
    x1=0;
    y1=0;
    x2=0;
    y2=0;
    return;
}

void MyDrawing::paint(GraphicsContext* gc){
    gc->clear();
    CurrentImage.draw(gc,VC);
    return;
}

void MyDrawing::mouseButtonDown(GraphicsContext* gc, unsigned int button, int x, int y){
    if(line){
        x0=x1=x;
        y0=y1=y;
        gc->setMode(GraphicsContext::MODE_XOR);
        gc->drawLine(x0,y0,x1,y1);
        dragging = true;
    }
    else if(triangle1){
        x0=x1=x;
        y0=y1=y;
        gc->setMode(GraphicsContext::MODE_XOR);
        gc->drawLine(x0,y0,x1,y1);
        dragging = true;
    }
    else if(triangle2){
        x2 = x;
        y2 = y;
        gc->setMode(GraphicsContext::MODE_XOR);
        gc->drawLine(x0,y0,x2,y2);
        gc->drawLine(x1,y1,x2,y2);
        dragging = true;
    }
    return;
}

void MyDrawing::mouseButtonUp(GraphicsContext* gc, unsigned int button, int x, int y){
    if(dragging){
        if(point){
            gc->setMode(GraphicsContext::MODE_NORMAL);
            gc->setPixel(x, y);
        }
        else if(line){
            gc->drawLine(x0,y0,x1,y1);
            x1=x;
            y1=y;
            gc->setMode(GraphicsContext::MODE_NORMAL);
            gc->drawLine(x0,y0,x1,y1);
            matrix m1 = matrix(4,1);
            matrix m2 = matrix(4,1);
            m1[0][0] = x0;
            m1[1][0] = y0;
            m1[2][0] = 0;
            m1[3][0] = 1;
            m2[0][0] = x1;
            m2[1][0] = y1;
            m2[2][0] = 0;
            m2[3][0] = 1;

            m1 = VC.applyInverse(m1);
            m2 = VC.applyInverse(m2);

            Line* s = new Line(currentColor, m1, m2);
            CurrentImage.add(s);
        }
        else if(triangle1){
            gc->drawLine(x0,y0,x1,y1);
            x1=x;
            y1=y;
            gc->drawLine(x0,y0,x1,y1);
            triangle1 = false;
            triangle2 = true;
        }
        else if(triangle2){
            x2=x;
            y2=y;
            gc->drawLine(x0,y0,x1,y1);
            gc->drawLine(x1,y1,x2,y2);
            gc->setMode(GraphicsContext::MODE_NORMAL);
            gc->drawLine(x0,y0,x1,y1);
            gc->drawLine(x1,y1,x2,y2);

            matrix m1 = matrix(4,1);
            matrix m2 = matrix(4,1);
            matrix m3 = matrix(4,1);
            m1[0][0] = x0;
            m1[1][0] = y0;
            m1[2][0] = 0;
            m1[3][0] = 1;
            m2[0][0] = x1;
            m2[1][0] = y1;
            m2[2][0] = 0;
            m2[3][0] = 1;
            m3[0][0] = x2;
            m3[1][0] = y2;
            m3[2][0] = 0;
            m3[3][0] = 1;

            m1 = VC.applyInverse(m1);
            m2 = VC.applyInverse(m2);
            m3 = VC.applyInverse(m3);
            
            Triangle* s = new Triangle(currentColor, m1, m2, m3);
            CurrentImage.add(s);
            triangle2 = false;
            triangle1 = true;
        }
        dragging = false;
    }
    return;
}

void MyDrawing::mouseMove(GraphicsContext* gc, int x, int y){
    if(dragging){
        if(line){
            gc->drawLine(x0,y0,x1,y1);
            x1 = x;
            y1 = y;
            gc->drawLine(x0,y0,x1,y1);
        }
        else if(triangle1){
            gc->drawLine(x0,y0,x1,y1);
            x1 = x;
            y1 = y;
            gc->drawLine(x0,y0,x1,y1);
        }
        else if(triangle2){
            gc->drawLine(x0,y0,x2,y2);
            gc->drawLine(x1,y1,x2,y2);
            x2 = x;
            y2 = y;
            gc->drawLine(x0,y0,x2,y2);
            gc->drawLine(x1,y1,x2,y2);
        }
    }
    return;
}

void MyDrawing::keyDown(GraphicsContext* gc, unsigned int keycode){
    point = false;
    line = false;
    triangle1 = false;
    triangle2 = false;
    if(keycode == 'p'){
        point = true;
        std::cout << "Point" << std::endl;
    }
    else if(keycode == 'l'){
        line = true;
        std::cout << "Line" << std::endl;
    }
    else if(keycode == 't'){
        triangle1 = true;
        std::cout << "Triangle" << std::endl;
    }
    else if(keycode == 'o'){
        std::cout << "Save" << std::endl;
        std::ofstream myfile ("Output.txt");
        if (myfile.is_open())
        {
            CurrentImage.out(myfile);
            myfile.close();
        }
    }
    else if(keycode == 'i'){
        std::cout << "Load" << std::endl;
        std::ifstream myfile ("Output.txt");
        CurrentImage.in(myfile);
        gc->setMode(GraphicsContext::MODE_NORMAL);
        CurrentImage.draw(gc);
        gc->setMode(GraphicsContext::MODE_XOR);
    }
    else if(keycode == '1'){
        gc->setColor(GraphicsContext::WHITE);
        currentColor = GraphicsContext::WHITE;
    }
    else if(keycode == '2'){
        gc->setColor(GraphicsContext::GREEN);
        currentColor = GraphicsContext::GREEN;
    }
    else if(keycode == '3'){
        gc->setColor(GraphicsContext::RED);
        currentColor = GraphicsContext::RED;
    }
    else if(keycode == 65361){
        VC.traslation(-10,0,0);
        paint(gc);
    }
    else if(keycode == 65363){
        VC.traslation(10,0,0);
        paint(gc);
    }
    else if(keycode == 65362){
        VC.rotation(0,0,3.14/20);
        paint(gc);
    }
    else if(keycode == 65364){
        VC.rotation(0,0,-3.14/20);
        paint(gc);
    }
    else if(keycode == 61){
        VC.scale(2,2,2);
        paint(gc);
    }
    else if(keycode == 45){
        VC.scale(0.5,0.5,0.5);
        paint(gc);
    }
    else if(keycode == 'r'){
        std::cout << "Reset" << std::endl;
        gc->clear();
    }

}
