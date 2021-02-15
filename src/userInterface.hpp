//
//  userInterface.hpp
//  PMCSpec
//
//  Created by Mario A. Sánchez on 09/04/2019.
//

#ifndef userInterface_hpp
#define userInterface_hpp

#include <stdio.h>
#include "panel.hpp"
#include "horizontalPanel.hpp"
#include "slider.hpp"
#include "dial.hpp"
#include "button.hpp"

class userInterface{
    public:
        userInterface();
        ~userInterface();
        void setupWidgets();
    
        void drawUI();
        void drawCanvas();
        void drawSpecPlaceHolder();
        void drawText();
        void drawWidgets();
    
        void updateUI();
        void widgetMouseDragged(int x, int y);
        void widgetMouseClicked(int x, int y);
    
        //System dialog/load in File
        void openFile();
    
    bool audioFileCheck;
    bool specSetupCheck;
    string audioFilePath;
    
    string infoPanelString;
    
    float selectRectPos;
    
    //Widget Variables
    HorizontalPanel* horizontalPanel;
    Panel* verticalPanelOne;
    Panel* verticalPanelTwo;
    Panel* verticalPanelThree;
    
    private:
        int specWidth;
        int specHeight;
        ofTrueTypeFont myFont;
        
};

#endif /* userInterface_hpp */
