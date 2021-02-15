#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    spec.audioSetup();
    specSetup = false;
    
    
    UI.horizontalPanel->widgets[0]->setMouseDraggedCallback(
     [this](float xNorm, float yNorm)
    {
        // callback here
        std::cout << xNorm << std::endl;
        spec.audioEffects.hiresParam(xNorm);
                                                             
    });
    
    UI.horizontalPanel->widgets[1]->setMouseDraggedCallback(
     [this](float xNorm, float yNorm)
    {
        // callback here
        std::cout << xNorm << std::endl;
        spec.audioEffects.loresParam(xNorm);
                                                             
    });
    
    UI.horizontalPanel->widgets[2]->setMouseDraggedCallback(
     [this](float xNorm, float yNorm)
    {
        // callback here
        std::cout << xNorm << std::endl;
        spec.audioEffects.hipassParam(xNorm);
                                                             
    });
    
    UI.horizontalPanel->widgets[3]->setMouseDraggedCallback(
     [this](float xNorm, float yNorm)
    {
        // callback here
        std::cout << xNorm << std::endl;
        spec.audioEffects.lopassParam(xNorm);
                                                             
    });
    
    /////////////////////////////////////////////////////////////////
    
    UI.verticalPanelOne->widgets[0]->setMouseClickedCallback([this](){
        //Callback here
        UI.openFile();
    });
    
    UI.verticalPanelOne->widgets[1]->setMouseClickedCallback([this](){
        //Callback here
        UI.selectRectPos = ofGetWidth()/1.28;
        //Clear Spectrogram
        spec.isPlaying = false;
        spec.clearSpectrogram();
    });
    
    ///////////////////////////////////////////////////////////////
    
    UI.verticalPanelTwo->widgets[0]->setMouseClickedCallback([this](){
        //Callback here

        if(spec.ofAudioFile.isPlaying()){
            spec.pauseAudioFile();
        }
        else{
            spec.playAudioFile();
        }

    });
    
    UI.verticalPanelTwo->widgets[1]->setMouseClickedCallback([this](){
        //Callback here
        UI.selectRectPos = ofGetWidth()/1.135;
        
        if(!spec.isMicrophone){
            spec.isPlaying = true;
        }
        else{
            //Microphone On
        }
        
    });
    
    ///////////////////////////////////////////////////////////////
    
    UI.verticalPanelThree->widgets[0]->setMouseClickedCallback([this](){
        
        if(!spec.isPlaying && !spec.isMicrophone){
            spec.isMicrophone = true;
        }
        else if(!spec.isPlaying && spec.isMicrophone){
            spec.isMicrophone = false;
        }
        else{
            //Audio File Playing
        }
        
    });

}

//--------------------------------------------------------------
void ofApp::update(){

    UI.updateUI();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(UI.audioFileCheck){
        
        if (!UI.specSetupCheck){
            spec.setupAudioFile(UI.audioFilePath);
            spec.drawSpecSetup();
            UI.specSetupCheck = true;
            
            UI.infoPanelString = spec.audioFileInfo;
        }
        
    }
    
    UI.drawUI();
    
    if(spec.isPlaying || spec.isMicrophone){
        spec.drawSpectrogramRealtime();
    }
    else{
        UI.drawSpecPlaceHolder();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    UI.widgetMouseDragged(x, y);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    UI.widgetMouseClicked(x, y);
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
