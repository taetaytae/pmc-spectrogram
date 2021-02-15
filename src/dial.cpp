//
//  dial.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#include "dial.hpp"

void Dial::draw()
{
    
    ofSetColor(this->bgColor);
    ofDrawCircle(this->xPos, this->yPos+this->height/2, this->width);
    ofSetColor(this->fgColor);
    ofDrawCircle(this->xPos, this->yPos+this->height/2, this->width-2);
    
    ofSetColor(255);
    ofSetLineWidth(2);
    
    float h = this->width;
    float a, o;
    // sin function wants radians
    // value is in the range 0-1
    float theta = ((1-value)-0.15) * PI * 2;
    a = sin(theta) * h;
    o = cos(theta) * h;
    
    ofDrawLine(this->xPos, this->yPos+this->height/2, this->xPos + a,this->yPos+this->height/2 + o);
    
    
    
}

//--------------------------------------------------------------------------
void Dial::update()
{
    //value += 0.01;
}

//--------------------------------------------------------------------------
void Dial::mouseClicked(float mX, float mY)
{
    float dist = ofDist(this->xPos, this->yPos+this->height/2,
                        mX, mY);
    if (dist < this->width){
        Widget::mouseClicked(mX, mY);
    }
    
}

//--------------------------------------------------------------------------
void Dial::mouseDragged(float mX, float mY)
{
    if(mX > this->xPos - this->width
       && mX < this->xPos+ this->width
       && mY > this->yPos+this->height/2 - this->width
       && mY < this->yPos+this->height/2 + this->width){
        
        std::cout << "Raw Value " <<value<< std::endl;
        if (mY < prevMouseY && value < 0.99){
            // down
            std::cout << "down" << std::endl;
            value += 0.01;
        }
        if (mY > prevMouseY && value > 0.01){
            // up
            std::cout << "up" << std::endl;
            value -= 0.01;
        }
        prevMouseY = mY;
        if (value < 0) value = 1 + value;
        value = fmod(value, 1.0);
        
        this->mouseDraggedCallback(value, 1);
    }
    
}
