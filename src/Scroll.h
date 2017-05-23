#include "ofMain.h"

#ifndef MOVER_H_INCLUDED
#define MOVER_H_INCLUDED

class Scroll {
    
public:
    vector<ofImage> images;  // Object to draw in the panel.
    int imagesWidth;
    int imagesHeight;
    
    /* Display parameters for the panel */
    int gap;
    int margin;
    int scrollBarWidth;
    
    
    int panelWidth;
    int panelHeight;
    int contentScrollY;
    bool isScrollBarVisible;
    ofRectangle scrollBarRectangle;
    ofRectangle gripRectangle;
    bool isDraggingGrip;
    bool isMouseOverGrip;
    int mousePreviousY;
    vector<ofRectangle> rectangles;
    
    
    Scroll();
    void display();
    void update();
    void setup(int, int,vector<ofImage> & baseImages);
    void updateContent(vector<ofImage> & baseImages);
    
};

#endif // MOVER_H_INCLUDED
