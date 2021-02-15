//
//  audio.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#ifndef audio_hpp
#define audio_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxMaxim.h"
#include "audioEffects.hpp"

class audio{
    public:
        audio();
        void audioSetup();
        void setupAudioFile(string audioFilePath);
        void setupAudioVector();
        void playAudioFile();
        void pauseAudioFile();
    
        //Maxilib audio loops
        void audioOut(ofSoundBuffer& output);
        void audioIn(ofSoundBuffer& input);
    
        ofSoundPlayer ofAudioFile;
        bool isPlaying;
        bool isMicrophone;
        audioEffects audioEffects;
    
        string audioFileInfo;
    
    private:
    
        std::vector<float> fftFreqs(int fftSize, int sampleRate);
        maxiSample audioFile;
    
        ofSoundStreamSettings soundStreamSettings;
        ofSoundStream soundStream;
    
        std::vector <float> lAudio;
        std::vector <float> rAudio;
    
        //Functions adapted from Jack Schaedler code/ jupyter notebook exercises https://ofdsp.blogspot.com/2011/08/short-time-fourier-transform-with-fftw3.html
        void hammingWindow(int windowLength, float *buffer);
        void STFT(std::vector <float> *signal, int signalLength, int windowSize, int hopSize);
    
    
    protected:
        int sampleRate;
        int bufferSize;
        int audioFileLength;
        std::vector<float> currentFreqs;
        std::vector<float> magSpec;
        std::vector<float> magSpecTwo;
    
        std::vector<float> audioFileData;
    
        maxiFFT myFFTOne;
        maxiFFT myFFTTwo;
    
        maxiFFT windowFFT;
    
};

#endif /* audio_hpp */
