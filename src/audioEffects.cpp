//
//  audioEffects.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#include "audioEffects.hpp"

audioEffects::audioEffects(){
    
    //Chorus
    //Delay
    //Flanger
    //Distortion
    //Filter
    
    LPFCutoff = 1;
    HPFCutoff = 0.01;
    
    loResonance = 0;
    hiResonance = 0;
    
    hiresCutoff = 0;
    loresCutoff = 8000;
    
    rawInput = 0;
    
}
//--------------------------------------------------------
double audioEffects::audioInput(double input){
    
    double output;
    
    rawInput = input;
    
    output = hires.hires(rawInput, hiresCutoff, 20);
    output = lores.lores(output, loresCutoff, 20);
    
    output = HPFilter.hipass(output, HPFCutoff);
    output = LPFilter.lopass(output, LPFCutoff);
    
    return output;
    
}

//--------------------------------------------------------
void audioEffects::loresParam(double param){
    
    double cutoff = ofMap(param, 0, 1, 8000, 0);
    double resonance = ofMap(param, 0, 1, 0, 20);
    
    
    loresCutoff = cutoff;
    loResonance = resonance;
    
}

//--------------------------------------------------------
void audioEffects::hipassParam(double param){
    
    double cutoff = ofMap(param, 0, 1, 0.2, 1);

    HPFCutoff = cutoff;
    
}

//--------------------------------------------------------
void audioEffects::hiresParam(double param){
    
    double cutoff = ofMap(param, 0, 1, 0, 5000);
    double resonance = ofMap(param, 0, 1, 0, 20);
    
    hiresCutoff = cutoff;
    hiResonance = resonance;
    
}

//--------------------------------------------------------
void audioEffects::lopassParam(double param){
    
    double cutoff = 1 - ofMap(param, 0, 1, 0.2, 1);
    
    LPFCutoff = cutoff;
    
}
