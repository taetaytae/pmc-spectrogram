//
//  spectogram.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#ifndef spectogram_hpp
#define spectogram_hpp

#include <stdio.h>
#include "audio.hpp"

struct specVariables{
    
    float binOffset;
    float binWidth;
    float binHeight;
    
    float spectrogramWidth;
    int frequencyAxis;
    int windowCount;
    
};

class spectrogram : public audio{
    public:
        spectrogram();
        void drawSpecSetup();
        void drawFFT();
        void drawSpectrogramRealtime();
        void drawSpectrogram();
        void clearSpectrogram();

    private:
    
        float windowWidth;
        float windowHeight;
    
        ofColor color;
        specVariables specVOne;
        specVariables specVTwo;
//        int minIndex;
//        int maxIndex;
    
};

#endif /* spectogram_hpp */
