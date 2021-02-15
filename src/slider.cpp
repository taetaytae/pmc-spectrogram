//
//  slider.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#include "slider.hpp"

void Slider::mouseClicked(float mX, float mY)
{
    // don't do anything!
}

/**
 * @brief extended from the base class to do bounding box test and calculate relative position for callback
 * @param mX
 * @param mY
 */

//--------------------------------------------------------------------------
void Slider::mouseDragged(float mX, float mY)
{
    std::cout << "slider mousedragged checking space..." << std::endl;
    
    float x2, y2;
    x2 = this->xPos + this->width;
    y2 = this->yPos + this->height;
    if (mX > this->xPos && mX < x2 &&
        mY > this->yPos && mY < y2){
        std::cout << "slider mousedragged in my space" << std::endl;
        // note that we actually call the callback directly
        // unlike the button example, where we called the parent mouseClicked
        //
        // now calculate the relative position of the mouse
        // in our space
        float relX, relY;
        float xOff, yOff;
        xOff = mX - this->xPos;
        yOff = mY - this->yPos;
        relX = xOff / this->width;
        relY = yOff / this->height;
        // remember where the slider is for drawing...
        this->pos = relX;
        this->mouseDraggedCallback(relX, relY);
    }
}

//--------------------------------------------------------------------------
void Slider::draw()
{
    ofSetColor(this->bgColor);
    ofDrawRectangle(this->xPos, this->yPos, this->width, this->height);
    ofSetColor(this->fgColor);
    ofDrawRectangle(this->xPos+2, this->yPos+2, this->width-4, this->height-4);
    // now draw a slider position thing
    ofSetColor(this->bgColor);
    ofDrawRectangle(this->xPos + (this->width * this->pos), this->yPos, this->width/10, this->height);
    
}
