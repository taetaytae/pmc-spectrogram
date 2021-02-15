//
//  slider.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#ifndef slider_hpp
#define slider_hpp

#include <stdio.h>
#include "widget.h"

class Slider : public Widget{
    public:
        virtual void draw();
        virtual void mouseClicked(float mX, float mY);
        virtual void mouseDragged(float mX, float mY);
    
    private:
        float pos;
    
};

#endif /* slider_hpp */
