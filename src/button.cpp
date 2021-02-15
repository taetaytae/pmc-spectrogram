//
//  button.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#include "button.hpp"

Button::Button(){
    
    buttonWidth =  this->width;
    buttonHeight = this->height;
    
    animationSwitch = true;
    
}

//--------------------------------------------------------------------------
void Button::draw(){
    
    ofSetColor(this->bgColor);
    ofDrawRectangle(this->xPos, this->yPos, buttonWidth, buttonHeight);
    if (this->animationState > 0){
        ofSetColor(this->animationState * 255);
    }
    else {
        ofSetColor(this->fgColor);
    }
    ofDrawRectangle(this->xPos+2, this->yPos+2, buttonWidth-4, buttonHeight-4);
}

//--------------------------------------------------------------------------
void Button::update(){
    
    if(this->animationState == 1){
        animationSwitch = true;
    }
    
    if (this->animationSwitch == true){
        // colours
        this->animationState -=  0.05;
    }
    else if(this->animationSwitch == false){
        this->animationState +=  0.05;
    }
    
    
    buttonWidth =  this->width;
    buttonHeight = this->height;
    
}

//--------------------------------------------------------------------------
void Button::mouseClicked(float mX, float mY)
{
    // put some code in here to check if mX mY is actually in
    // the box covered by the button
    // CLUE use bounding box collision detection on this->xPos, this->width et.
    if(mX > this->xPos &&
       mX < this->xPos+buttonWidth-4 &&
       mY > this->yPos &&
       mY < this->yPos+buttonHeight-4)
    {
        Widget::mouseClicked(mX, mY);
//        this->animationState = 1.0;
//        animationSwitch = false;
    }
    
    
}

//--------------------------------------------------------------------------
void Button::mouseDragged(float mX, float mY)
{
    // don't do anything...
}
