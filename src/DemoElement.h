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

    public:
    void display();
    void update();
    void showData();
};
