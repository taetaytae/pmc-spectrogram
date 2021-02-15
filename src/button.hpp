//
//  button.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#ifndef button_hpp
#define button_hpp

#include <stdio.h>
#include "widget.h"

class Button : public Widget{
    public:
        Button();
        virtual void draw();
        virtual void update();
        virtual void mouseClicked(float mX, float mY);
        virtual void mouseDragged(float mX, float mY);
    
    private:
        float animationState;
        bool animationSwitch;
        float buttonHeight;
        float buttonWidth;
 
};

//-----------------------
#endif /* button_hpp */
