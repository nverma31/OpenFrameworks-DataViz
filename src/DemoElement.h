//
//  DemoElement.hpp
//  Scrolling
//
//  Created by Neeraj Verma on 22/05/17.
//
//

#pragma once

#include <stdio.h>
#include "ofMain.h"


class DemoElement {

    ofPoint pos;
    float radius;
    float arcrad1;
    float arcrad2;
    float arcrad3;

    ofColor color;
    ofColor arccolor;

    float beginAngle;
    float endAngle;
    ofPath circle;
    ofPath curve;

    ofPath arc1;
    ofPath arc2;
    ofPath arc3;


    public:
    void display();
    void update();
    void showData();
    bool isInside();

    bool isInsideArc1();

    bool isInsideArc2();
    bool isInsideArc3();

    ofEvent<ofVec2f> clickedInside;

    void mouseReleased(ofMouseEventArgs & args);

    float getAngle(float _x, float _y);
    bool inside;

    float normalizeAngle(float angle);
    DemoElement();
    DemoElement(ofPoint pt, float angBeg, float angEnd, float rad, float val1, float val2, float val3);
    
    
protected:
    bool bRegisteredEvents;
};
