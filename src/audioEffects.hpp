//
//  audioEffects.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#ifndef audioEffects_hpp
#define audioEffects_hpp

#include <stdio.h>
#include "ofxMaxim.h"
#include "ofMain.h"

class audioEffects{
    public:
        audioEffects();
        void loresParam(double param);
        void hipassParam(double param);
        void hiresParam(double param);
        void lopassParam(double param);
    
        double audioInput(double input);
    
    private:
    
        double rawInput;
    
        double hiResonance;
        double loResonance;
    
        double hiresCutoff;
        double loresCutoff;
    
        double LPFCutoff;
        double HPFCutoff;
    
        maxiFilter hires;
        maxiFilter lores;
        maxiFilter HPFilter;
        maxiFilter LPFilter;
    
};


#endif /* audioEffects_hpp */
