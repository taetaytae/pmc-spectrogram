//
//  horizontalPanel.cpp
//  PAPLab15
//
//  Created by Mario A. Sánchez on 05/03/2019.
//

#include "horizontalPanel.hpp"

HorizontalPanel::~HorizontalPanel(){
    
    for(int i = 0; i < this->widgets.size(); i++){
        delete this->widgets[i];
    }
    std::cout<<"panel contents deleted"<<std::endl;
}

void HorizontalPanel::setPosition(float x, float y)
{
    // move us and all our widgets
    float dx = this->xPos - x;
    float dy = this->yPos - y;
    Widget::setPosition(x, y);// call the parent class implementation
    this->fitWidgetsToPanelSize();
    
}

void HorizontalPanel::setSize(float w, float h)
{
    // need to resize all our widgets!
    // we assume a column layout
    Widget::setSize(w, h);
    this->fitWidgetsToPanelSize();
}

void HorizontalPanel::fitWidgetsToPanelSize()
{
    if (this->widgets.size() > 0 ){
        // one column per widget
        // enough rows to fit all widgets in the panel
//        float column_l = this->width / this->widgets.size();
        float column_l = (this->width)/ this->widgets.size();
        for (int i=0;i<this->widgets.size();i++)
        {
//            this->height/(widgets.size()*2)
            // set the size to be the width of this panel
            // and the height of a row
            this->widgets[i]->setSize((column_l/3) - 4, this->height/(widgets.size()*2) - 4);
            // move the widget to its column position
            this->widgets[i]->setPosition(this->xPos + column_l * i + (this->width/8), this->yPos + 2 + this->height/2.5);
        }
    }
}

void HorizontalPanel::draw()
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

void HorizontalPanel::update()
{
    for (int i=0;i<this->widgets.size();i++)
    {
        this->widgets[i]->update();
    }
}

void HorizontalPanel::addWidget(Widget *widget)
{
    this->widgets.push_back(widget);
    // now resize and move everything so it fits!
    this->fitWidgetsToPanelSize();
    
}

void HorizontalPanel::mouseClicked(float mX, float mY)
{
    for (int i=0;i<this->widgets.size();i++)
    {
        this->widgets[i]->mouseClicked(mX, mY);
    }
}

void HorizontalPanel::mouseDragged(float mX, float mY)
{
    for (int i=0;i<this->widgets.size();i++)
    {
        this->widgets[i]->mouseDragged(mX, mY);
    }
}
