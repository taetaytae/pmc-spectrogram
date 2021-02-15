#include "widget.h"
#include <iostream>

Widget::Widget()
{
    /** note I am using 'this' here to explicitly refer to my
     *  variable members
     */

     // initialise the variable members to sensible defaults
    this->setColours(ofColor(20, 20, 20), ofColor(240, 255, 240));
    this->setPosition(0, 0);
    this->setSize(100, 50);

    this->setMouseClickedCallback([](){
        std::cout << "widget mouse click " << std::endl;
    });
    this->setKeyPressedCallback([](int keyCode){
        std::cout << "widget key click on key " << keyCode << std::endl;
    });
}

//--------------------------------------------------------------------------
Widget::~Widget()
{
    
    
}

//--------------------------------------------------------------------------
void Widget::update()
{
    
}

//--------------------------------------------------------------------------
void Widget::mouseClicked(float mX, float mY)
{
    std::cout << "Widget::mouseClicked triggering the callback" << std::endl;
    this->mouseCallback();
}

//--------------------------------------------------------------------------
void Widget::setMouseClickedCallback(std::function<void ()> callback)
{
    this->mouseCallback = callback;
}

//--------------------------------------------------------------------------
void Widget::mouseDragged(float mX, float mY)
{
    std::cout << "Widget::mouseDragged triggering the callback" << std::endl;

    this->mouseDraggedCallback(1, 1);
}

//--------------------------------------------------------------------------
void Widget::setMouseDraggedCallback(std::function<void (float xNorm, float yNorm)> callback)
{
    this->mouseDraggedCallback = callback;
}

//--------------------------------------------------------------------------
void Widget::keyPressed(int keyCode)
{
    std::cout << "keyPressed on widget not checking bounding box! you might want to override me in your widget" << std::endl;
    this->keyCallback(keyCode);
}

//--------------------------------------------------------------------------
void Widget::setKeyPressedCallback(std::function<void (int keyCode)> callback)
{
    this->keyCallback = callback;
}

//--------------------------------------------------------------------------
void Widget::setSize(float w, float h)
{
    this->width = w;
    this->height = h;
}

//--------------------------------------------------------------------------
void Widget::setPosition(float x, float y)
{
    this->xPos = x;
    this->yPos = y;
}

//--------------------------------------------------------------------------
void Widget::setColours(ofColor fg, ofColor bg)
{
    this->bgColor = bg;
    this->fgColor = fg;
}
