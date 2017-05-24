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
    string text;
    DataPoint dataPointLow;
    DataPoint dataPointHigh;

    
public:
    void display();
    void update();
    EnergyElement();
    void _mouseReleased(ofMouseEventArgs &e);


    EnergyElement(float x, float y, float z, float k);

    
};
