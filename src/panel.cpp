//
//  panel.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 11/04/2019.
//

#include "panel.hpp"

Panel::~Panel(){
    
    for(int i = 0; i < this->widgets.size(); i++){
        delete this->widgets[i];
    }
    std::cout<<"panel contents deleted"<<std::endl;
}

//--------------------------------------------------------------------------
void Panel::setPosition(float x, float y)
{
    // move us and all our widgets
    float dx = this->xPos - x;
    float dy = this->yPos - y;
    Widget::setPosition(x, y);// call the parent class implementation
    this->fitWidgetsToPanelSize();
    
}

//--------------------------------------------------------------------------
void Panel::setSize(float w, float h)
{
    // need to resize all our widgets!
    // we assume a column layout
    Widget::setSize(w, h);
    this->fitWidgetsToPanelSize();
}

//--------------------------------------------------------------------------
void Panel::fitWidgetsToPanelSize()
{
    if (this->widgets.size() > 0 ){
        // one row per widget
        // enough rows to fit all widgets in the panel
        float row_h = this->height / this->widgets.size();
        for (int i=0;i<this->widgets.size();i++)
        {
            // set the size to be the width of this panel
            // and the height of a row
            this->widgets[i]->setSize(this->width - 4, row_h - 4);
            // move the widget to its row position
            this->widgets[i]->setPosition(this->xPos+2, yPos + row_h * i + 2);
        }
    }
}

//--------------------------------------------------------------------------
void Panel::draw()
{
    ofSetColor(this->bgColor);
    ofDrawRectangle(this->xPos, this->yPos, this->width, this->height);
    ofSetColor(this->fgColor);
    ofDrawRectangle(this->xPos+2, this->yPos+2, this->width-4, this->height-4);
    
    for (int i=0;i<this->widgets.size();i++)
    {
        this->widgets[i]->draw();
    }
}

//--------------------------------------------------------------------------
void Panel::update()
{
    for (int i=0;i<this->widgets.size();i++)
    {
        this->widgets[i]->update();
    }
}

//--------------------------------------------------------------------------
void Panel::addWidget(Widget *widget)
{
    this->widgets.push_back(widget);
    // now resize and move everything so it fits!
    this->fitWidgetsToPanelSize();
    
}

//--------------------------------------------------------------------------
void Panel::mouseClicked(float mX, float mY)
{
    for (int i=0;i<this->widgets.size();i++)
    {
        this->widgets[i]->mouseClicked(mX, mY);
    }
}

//--------------------------------------------------------------------------
void Panel::mouseDragged(float mX, float mY)
{
    for (int i=0;i<this->widgets.size();i++)
    {
        this->widgets[i]->mouseDragged(mX, mY);
    }
}
