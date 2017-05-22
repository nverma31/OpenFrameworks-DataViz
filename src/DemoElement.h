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
    ofColor color;
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
    
    DemoElement();
    DemoElement(ofPoint pt, float angBeg, float angEnd, float rad);
};
