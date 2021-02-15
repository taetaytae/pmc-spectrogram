//
//  horizontalPanel.hpp
//  PAPLab15
//
//  Created by Mario A. Sánchez on 05/03/2019.
//

#ifndef horizontalPanel_hpp
#define horizontalPanel_hpp

#include <stdio.h>
#include "widget.h"

class HorizontalPanel : public Widget{
    
    public:
    virtual ~HorizontalPanel();
        void addWidget(Widget* widget);
        virtual void draw();
        virtual void update();
        virtual void setSize(float w, float h);
    
        virtual void setPosition(float x, float y);
        virtual void mouseClicked(float mX, float mY);
        virtual void mouseDragged(float mX, float mY);
    
        std::vector<Widget*> widgets;
    
    private:
    
        void fitWidgetsToPanelSize();
};

#endif /* horizontalPanel_hpp */
