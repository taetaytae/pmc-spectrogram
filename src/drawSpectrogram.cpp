//
//  spectogram.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#include "drawSpectrogram.hpp"

//Currently Not in use. Draws/makes spectrogram but does nothing audio related. Just takes audio and makes spectrogram.

spectrogram::spectrogram(){
    
    //Spectogram Background
    ofSetBackgroundColor(255);
    
    windowWidth = ofGetWidth()/1.4;
    windowHeight = ofGetHeight()/1.5;

}

//----------------------------------------------------------------
void spectrogram::drawSpecSetup(){
    
    //Try calculating buffer length using ofSoundStream
    
    //Real-time spectrogram setup
    specVOne.spectrogramWidth = ((audioFileLength-myFFTOne.windowSize)/(512*1.4));

    specVOne.binWidth =  (float)windowWidth/specVOne.spectrogramWidth;
    
    if(specVOne.binWidth < 1){
        specVOne.binWidth = 1;
    }
    
    specVOne.frequencyAxis = currentFreqs.size()/5;
    specVOne.binHeight = (float)windowHeight/specVOne.frequencyAxis;
    
    specVOne.binOffset = 0;
    specVOne.windowCount = 0;
    
    
    //Instant Spectrogram setup
    specVTwo.spectrogramWidth = audioFileData.size();
    
    specVTwo.binWidth =  (float)ofGetWidth()/specVTwo.spectrogramWidth;

    specVTwo.frequencyAxis = currentFreqs.size()/5;
    specVTwo.binHeight = (float)ofGetHeight()/specVTwo.frequencyAxis;

    specVTwo.binOffset = 0;
    specVTwo.windowCount = 0;
}

//----------------------------------------------------------------
void spectrogram::drawFFT(){

    ofTranslate(0, ofGetHeight()/4);
    ofSetColor(255, 255, 0);

    // Spread the bins over the width of the window
    int binWidth = ofGetWidth()/myFFTOne.bins;
    // Horizontal line
    ofDrawLine(0, 0, ofGetWidth(), 0);

    int drawFreq = 0;
    // one line per bin
    for(int i = 0; i < myFFTOne.bins; ++i)
    {
        ofDrawRectangle(i * binWidth, 0, binWidth, myFFTOne.magnitudes[i] * -2.);

        //Draw frequency of first peak. Adding 3 to i, so that it is nearer to the magnitude peak
        if (drawFreq <= 0 && myFFTOne.magnitudes[i] > 1.0) {
            ofDrawBitmapString(currentFreqs[i + 3], i * binWidth, -20);
            drawFreq = 15; //Only draw once every 15 bins, at most
        }
        --drawFreq;
    }

}

//----------------------------------------------------------------
void spectrogram::drawSpectrogramRealtime(){
    
    ofPushMatrix();
    ofTranslate(0,37);
    ofSetBackgroundAuto(false);
    
    if(myFFTOne.spectralCentroid() > 100){

            for(int i = 0; i < specVOne.frequencyAxis; i++){
                    color.setHsb(205-(myFFTOne.magnitudes[i] * 20.), 155, 255);
                    ofSetColor(color);
                
                    ofDrawRectangle(specVOne.binOffset+ofGetWidth()/20, windowHeight - (i * specVOne.binHeight), specVOne.binWidth, specVOne.binHeight);
            }
        
        specVOne.binOffset += specVOne.binWidth;
        
        //Start Cycle again once it reaches end of window
        if(specVOne.binOffset > windowWidth){
            specVOne.binOffset = 0;
        }
        
        
    }
    ofPopMatrix();
    
}

//----------------------------------------------------------------
void spectrogram::drawSpectrogram(){
    
    ofPushMatrix();
    ofTranslate(-9, 0);
    ofSetBackgroundAuto(false);
    
//    if(myFFTTwo.spectralCentroid() < 5000){
    
        for(int j = 0; j < specVTwo.spectrogramWidth; j++){
            for(int i = 0; i < specVTwo.frequencyAxis; i++){
                ofSetColor(255, 255-(magSpecTwo[i] * 20.), 255);
                ofDrawRectangle(specVTwo.binOffset, ofGetHeight() - (i * specVTwo.binHeight), specVTwo.binWidth, specVTwo.binHeight);
            }
        }
        specVTwo.windowCount++;
        specVTwo.binOffset += specVTwo.binWidth;
        
//    }

    ofPopMatrix();
    
    
}

//----------------------------------------------------------------
void spectrogram::clearSpectrogram(){
    
    specVOne.binOffset = 0;
    
}
