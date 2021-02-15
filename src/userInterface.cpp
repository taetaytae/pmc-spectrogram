//
//  userInterface.cpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#include "userInterface.hpp"

userInterface::userInterface(){
    
    ofSetBackgroundColor(214, 218, 219);
    ofSetLogLevel(OF_LOG_VERBOSE);
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    selectRectPos = ofGetWidth();
    
    audioFileCheck = false;
    
    infoPanelString = "Load in wav. file to\nstart.";
    
    setupWidgets();
    
}

//----------------------------------------------------------
userInterface::~userInterface(){
    
    delete horizontalPanel;
    delete verticalPanelOne;
    delete verticalPanelTwo;
    delete verticalPanelThree;
    
}

//----------------------------------------------------------
void userInterface::setupWidgets(){
    
    //Horizontal Panel
    horizontalPanel = new HorizontalPanel();
    
    Widget* dialOne = new Dial();
    Widget* dialTwo = new Dial();
    Widget* dialThree = new Dial();
    Widget* dialFour = new Dial();

    horizontalPanel->addWidget(dialOne);
    horizontalPanel->addWidget(dialTwo);
    horizontalPanel->addWidget(dialThree);
    horizontalPanel->addWidget(dialFour);
    
    horizontalPanel->setSize(ofGetWidth()/1.5, ofGetHeight()/4.5);
    horizontalPanel->setPosition(ofGetWidth()/20, ofGetHeight()/1.35);
    
    //Vertical Panel
    verticalPanelOne = new Panel();
    verticalPanelTwo = new Panel();
    verticalPanelThree = new Panel();
    
    Widget* buttonOne = new Button();
    Widget* buttonTwo = new Button();
    Widget* buttonThree = new Button();
    Widget* buttonFour = new Button();
    
    Widget* buttonFive = new Button();
    
    verticalPanelOne->addWidget(buttonOne);
    verticalPanelOne->addWidget(buttonTwo);
    
    verticalPanelTwo->addWidget(buttonThree);
    verticalPanelTwo->addWidget(buttonFour);
    
    verticalPanelThree->addWidget(buttonFive);
    
    verticalPanelOne->setSize((ofGetWidth()/5)/2, (ofGetHeight()/1.5)/3);
    verticalPanelOne->setPosition(ofGetWidth()/1.28, ofGetHeight()/20);
    
    verticalPanelTwo->setSize((ofGetWidth()/5)/2, (ofGetHeight()/1.5)/3);
    verticalPanelTwo->setPosition(ofGetWidth()/1.135, ofGetHeight()/20);
    
    verticalPanelThree->setSize(ofGetWidth()/5-20, ofGetHeight()/12-20);
    verticalPanelThree->setPosition(ofGetWidth()/1.28+10, ofGetHeight()/1.57+10);
    
}

//----------------------------------------------------------
void userInterface::drawUI(){
    
    //Draw Everything
    drawCanvas();
    drawWidgets();
    drawText();
}

//----------------------------------------------------------
void userInterface::updateUI(){
    
    //Update drawing Everything
    horizontalPanel->update();
    verticalPanelOne->update();
    verticalPanelTwo->update();
    verticalPanelThree->update();
}

//----------------------------------------------------------
void userInterface::drawCanvas(){
    
    ofSetColor(240);
    //Horizontal
    ofDrawRectangle(ofGetWidth()/20, ofGetHeight()/1.35, ofGetWidth()/1.5, ofGetHeight()/4.5);
    //Vertical
    ofDrawRectangle(ofGetWidth()/1.28, ofGetHeight()/20,  ofGetWidth()/5, ofGetHeight()/1.5);
    //Selection Rectangle
    ofSetColor(250, 100, 100);
    ofDrawRectangle(selectRectPos+15, ofGetHeight()/3.6,(ofGetWidth()/5)/2-30, ofGetHeight()/50);
    
    //Spec Info
    ofSetColor(20,20,20);
    ofDrawRectangle(ofGetWidth()/1.28+10, ofGetHeight()/3.2+10,  ofGetWidth()/5-20, ofGetHeight()/3-20);
    
}

//----------------------------------------------------------
void userInterface::drawSpecPlaceHolder(){
    
    specWidth = ofGetWidth()/1.4;
    specHeight = ofGetHeight()/1.5;
    
    ofPushMatrix();
    ofSetBackgroundAuto(false);
    
    ofSetColor(0);
    ofDrawRectangle(ofGetWidth()/20, ofGetHeight()/20, ofGetWidth()/1.4, ofGetHeight()/1.5);
    
    ofPopMatrix();
    
}

//----------------------------------------------------------
void userInterface::drawText(){
    
    //Title
    myFont.load("Ardour3d.ttf", ofGetWidth()/25);
    ofSetColor(0);
    myFont.drawString("Spectogram\n   Grabber", ofGetWidth()/1.35, ofGetHeight()/1.2);
    
    //Effects
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    ofSetColor(255);
    myFont.drawString("Hi-Res Filter", ofGetWidth()/13, ofGetHeight()/1.06);
    myFont.drawString("Lo-Res Filter", ofGetWidth()/4.2, ofGetHeight()/1.06);
    myFont.drawString("Hi-Pass Filter", ofGetWidth()/2.47, ofGetHeight()/1.06);
    myFont.drawString("Low-Pass Filter", ofGetWidth()/1.79, ofGetHeight()/1.06);
    
    //Buttons
    myFont.drawString("Load\n File", ofGetWidth()/1.24, ofGetHeight()/10);
    myFont.drawString("Play\n File", ofGetWidth()/1.103, ofGetHeight()/10);
    
    myFont.drawString("Clear\nSpec", ofGetWidth()/1.24, ofGetHeight()/4.9);
    
    myFont.load("Ardour3d.ttf", ofGetWidth()/60);
    myFont.drawString("Draw\nSpec\nRealtime", ofGetWidth()/1.110, ofGetHeight()/5.2);
    
    //Info
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    myFont.drawString("File Info: ", ofGetWidth()/1.28+20, ofGetHeight()/2.8);
    
    myFont.load("raleway.ttf", ofGetWidth()/70);
    myFont.drawString(infoPanelString, ofGetWidth()/1.28+15, ofGetHeight()/2.5);
    
    //Microphone Button
//    myFont.load("Ardour3d.ttf", ofGetWidth()/55);
//    myFont.drawString("Microphone On/Off ", ofGetWidth()/1.28+24, ofGetHeight()/1.48+10);
    
}

//----------------------------------------------------------
void userInterface::drawWidgets(){
    
    
    horizontalPanel->draw();
    verticalPanelOne->draw();
    verticalPanelTwo->draw();
//    verticalPanelThree->draw();
    
}

//----------------------------------------------------------
void userInterface::widgetMouseDragged(int x, int y){
    
    horizontalPanel->mouseDragged(x, y);
    verticalPanelOne->mouseDragged(x, y);
    verticalPanelTwo->mouseDragged(x, y);
//    verticalPanelThree->mouseDragged(x, y);
    
}

//----------------------------------------------------------
void userInterface::widgetMouseClicked(int x, int y){
    
    horizontalPanel->mouseClicked(x, y);
    verticalPanelOne->mouseClicked(x, y);
    verticalPanelTwo->mouseClicked(x, y);
//    verticalPanelThree->mouseClicked(x, y);
    
}

//----------------------------------------------------------
void userInterface::openFile(){
    
    //From input/output example
    
    //Open the Open File Dialog
    ofFileDialogResult openFileResult = ofSystemLoadDialog("Select a jpg or png");
    
    //Check if the user opened a file
    if (openFileResult.bSuccess){
        
        ofLogVerbose("User selected a file");
        
        //We have a file, check it and process it
        ofFile file (openFileResult.getPath());
        
        //Check if file exists
        if(file.exists()){
            
            string fileExtension = ofToUpper(file.getExtension());
            
            //Check file for the right extension
            if(fileExtension == "wav" || fileExtension == "WAV"){
            
                audioFilePath = openFileResult.getPath();
                std::cout<<audioFilePath<<std::endl;
                
                audioFileCheck = true;
                specSetupCheck = false;
            }
            else{
                ofLogVerbose("Wrong File Extension/Wrong type of file");
                infoPanelString = "Wrong File\nExtension";
            }
        }
        else{
            ofLogVerbose("No file found in selected filepath");
            infoPanelString = "No file found in selected filepath";
        }
        
    }else {
        ofLogVerbose("User hit cancel");
        infoPanelString = "User hit cancel";
    }
    
}
