#ifndef WIDGET_H
#define WIDGET_H

#include <functional>
#include <ofMain.h>

class Widget {

   public:
    Widget();
    virtual ~Widget();

    // virtual allows you to override it and make sure the right version is called

    /** resize the widget */
    virtual void setSize(float w, float h);

    /** change the position of the widget */
    virtual void setPosition(float x, float y);
    /** change the colour of the widget */
    virtual void setColours(ofColor fg, ofColor bg);


    /** draw the widget at the current position */
    virtual void draw() = 0; // this is a pure virtual function so sub classes have to implement it!
    /** update thw widget (e.g. if it has animation) */
    virtual void update();

    /** call this to pass a mouse event to the widget */
    virtual void mouseClicked(float mX, float mY);
    /** call this to set the callback for the mouse event */
    virtual void setMouseClickedCallback(std::function <void()> callback);

    /** call this to pass a mouse event to the widget */
    virtual void mouseDragged(float mX, float mY);
    /** call this to set the callback for the mouse event. x and yNormed
      * are the normalised position of the mouse in the widget 0-1
      */
    virtual void setMouseDraggedCallback(std::function <void(float xNormed, float yNormed)> callback);

    /** call this to pass a keyPressed event to the widget*/
    virtual void keyPressed(int keyCode);
    /** call this to set the callback for a keypressed event */
    virtual void setKeyPressedCallback(std::function <void(int keyCode)> callback);



   protected: //  protected so sub classes can access the basic properties
     float width;
     float height;
     float xPos;
     float yPos;
     ofColor fgColor;
     ofColor bgColor;
     std::function<void()> mouseCallback;
     std::function<void(float xNorm, float yNorm)> mouseDraggedCallback;

     std::function<void(int keyCode)> keyCallback;

};

#endif // WIDGET_H

