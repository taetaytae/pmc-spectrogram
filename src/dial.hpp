//
//  dial.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#ifndef dial_hpp
#define dial_hpp

#include <stdio.h>
#include "widget.h"

class Dial : public Widget{
    public:
        virtual void draw();
        virtual void update();
        virtual void mouseClicked(float mX, float mY);
        virtual void mouseDragged(float mX, float mY);
    
    private:
        float value = 0;
        float prevMouseY;
    
};

#endif /* dial_hpp */
