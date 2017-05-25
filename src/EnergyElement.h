//
//  EnergyElement.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 22/05/17.
//
//
//#include <stdio.h>
#include "ofMain.h"
#include "DataPoint.h"


class EnergyElement {
    float base;
    float high;
    float speed;
    float low;
    float xpos;
    float width;
    string text;
    DataPoint dataPointLow;
    DataPoint dataPointHigh;
    ofEvent<ofVec2f> clickedInside;
    int inc;
    bool clicked;


    
public:
    void display();
    void update();
    EnergyElement();
    void _mouseReleased(ofMouseEventArgs &e);
    bool isInside();

    EnergyElement(float x, float y, float z, float k);

    
};
