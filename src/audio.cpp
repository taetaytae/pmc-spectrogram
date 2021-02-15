//
//  audio.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#include "audio.hpp"

audio::audio(){
    
    sampleRate = 44100;
    bufferSize = 1024;
    
    // FFT size, bins, hop size
    int FFTSize = 2048;
    myFFTOne.setup(FFTSize, 1024, 512);
    myFFTTwo.setup(FFTSize, 1024, 512);
    
    //Calculate frequencies per bin
    currentFreqs = fftFreqs(FFTSize, sampleRate);
    
    isPlaying = false;
    isMicrophone = false;
    
    soundStreamSettings.setInListener(this);
    soundStreamSettings.setOutListener(this);
    soundStreamSettings.sampleRate = sampleRate;
    soundStreamSettings.bufferSize = bufferSize;
    soundStreamSettings.numInputChannels = 1;
    soundStreamSettings.numOutputChannels = 2;
    
    
}

//--------------------------------------------
void audio::audioSetup(){
    
    soundStream.setup(soundStreamSettings);
    
}

//--------------------------------------------
std::vector<float> audio::fftFreqs(int fftSize, int sampleRate)
{
    std::vector<float> theFreqs;
    for (int i = 0; i < fftSize; ++i){
        theFreqs.push_back((sampleRate/float(fftSize)) * i);
    }
    return theFreqs;
}

//------------------------------------------------------------------
void audio::hammingWindow(int windowLength, float *buffer){
    
    for(int i = 0; i < windowLength; i++) {
        buffer[i] = 0.54 - (0.46 * cos( 2 * PI * (i / ((windowLength - 1) * 1.0))));
    }
    
}

//--------------------------------------------
void audio::setupAudioFile(string audioFilePath){
    
    audioFile.clear();
    audioFile.load(audioFilePath);
    
    audioFile.getSummary();
    
    audioFileLength = audioFile.myDataSize*(0.5/audioFile.myChannels);
    
    audioFile.normalise(1.0);
    
    ofAudioFile.load(audioFilePath);
    
    audioFileInfo = audioFile.getSummary();
}

//----------------------------------------------
void audio::setupAudioVector(){
    
    audioFile.getLength();
    
    for(int i = 0; i < audioFile.length; i++){
        audioFileData.push_back(audioFile.play());
    }
    
    std::cout<<audioFileData.size()<<std::endl;
    
}

//----------------------------------------------
void audio::playAudioFile(){
    
    ofAudioFile.play();
    
}

//----------------------------------------------
void audio::pauseAudioFile(){
    
    ofAudioFile.stop();
}

//------------------------------------------------------------------
void audio::STFT(std::vector<float> *signal, int signalLength, int windowSize, int hopSize){
    
    int nyquist = signalLength/2;
    int win_index = 0;
    
    float window[windowSize];
    hammingWindow(windowSize, window);
    
    windowFFT.setup(windowSize, windowSize/2, hopSize);
    
    //Stop when last frame ends since it probably won't be the size of a complete window
    int bStop = 0;
    
    std::vector<float> results;
    
    while(win_index < signalLength && !bStop){
        
        int read_index;
        std::vector<float> next_frame;
        
        for(int i = 0; i < windowSize; i++){
            
            read_index = win_index + i;
            
            if(read_index < signalLength) {
                next_frame[i] = (*signal)[read_index] * window[i];
            }
            else{
                next_frame[i] = 0;
                bStop = 1;
            }
        }
        
        for(int i = 0; i < next_frame.size(); i++){
            windowFFT.process(next_frame[i]);
            //Pushing in location not actual magnitude
            results.push_back(*windowFFT.magnitudes);
            std::cout<<"vectorWindowFFT: "<<windowFFT.magnitudes<<std::endl;
        }
        
        win_index = win_index + hopSize;
    }
    
}

//---------------------------------------------
void audio::audioIn(ofSoundBuffer &input){
    
    for (unsigned int i = 0; i < input.getNumFrames(); i++){
    
        //Unused attempt at microphone input for spectrogram
        if(isMicrophone){
//            myFFTOne.process(input[i*input.getNumChannels()] + input[i*input.getNumChannels() + 1]*0.9);
        }
    }
    
}

//---------------------------------------------
void audio::audioOut(ofSoundBuffer &output){
    
    for (int i = 0; i < output.getNumFrames(); i++){
        // synthesize sound here if you want!

        //Check if there is an audio file loaded/ if yes, play audio file
        if(isPlaying){
            output[i*output.getNumChannels()    ] = audioEffects.audioInput(audioFile.playOnce(0.5));
            output[i*output.getNumChannels() + 1] = audioEffects.audioInput(audioFile.playOnce(0.5));
        }
        else{
            audioFile.reset();
        }
        
        // Goes into buffer for next calclation
        myFFTOne.process(output[i * output.getNumChannels()]);
        
        magSpec.push_back(myFFTOne.magnitudes[i]);
    }
    
    
}
