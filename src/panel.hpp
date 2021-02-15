//
//  panel.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 11/04/2019.
//

#ifndef panel_hpp
#define panel_hpp

#include <stdio.h>
#include "widget.h"

class Panel : public Widget {
public:
    virtual ~Panel();
    /** add a widget to the panel. Should resize and place the widget according to the panel layout rules*/
    void addWidget(Widget* widget);
    
    /** call draw on all widgets added to this panel */
    virtual void draw();
    
    /** call update on all widgets added to this panel */
    virtual void update();
    
    /** need to update our own size then resize all the other widgets */
    virtual void setSize(float w, float h);
    
    /** need to update our own position. We assume the positions of the sub widgets are relative to our position
     */
    virtual void setPosition(float x, float y);
    
    /** pass the event onto all widgets */
    virtual void mouseClicked(float mX, float mY);
    /** pass the event onto all widgets */
    virtual void mouseDragged(float mX, float mY);
    
    std::vector<Widget*> widgets;
    
    
private:
    /** vector to store the widgets on this panel */
    
    void fitWidgetsToPanelSize();
};


#endif /* panel_hpp */
