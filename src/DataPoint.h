//
//  DataPoint.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 24/05/17.
//
//


#pragma once
#ifndef DATAPOINT_H_INCLUDED
#define DATAPOINT_H_INCLUDED
#include "ofMain.h"


class DataPoint {
    
    float x;
    float y;
    float radius;
    string text;
    float width;
    
public:
    void display();
    DataPoint();
    DataPoint(float xpos,float ypos, float rad, float wid, string txt);
    bool isinside();
    void createText();
    void setup(float xpos,float ypos, float rad,  float wid, string txt);
    
    
    
};

#endif
