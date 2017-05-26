//
//  DataPoint.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 24/05/17.
//
//

#include "DataPoint.h"

DataPoint::DataPoint(){
    
}
DataPoint::DataPoint(float xpos, float ypos, float rad, float wid, string txt){
    
    x = xpos;
    y = ypos;
    radius = rad;
    
}

void DataPoint::display(){
    ofNoFill();
    ofDrawCircle(x, y, 2);
    if (isinside()) {
//        ofDrawRectangle(x -20, y+20, width, 25);
        ofDrawBitmapString(text, x-10, y+25);
    }
}

bool DataPoint::isinside(){
    return (ofVec2f(ofGetMouseX(), ofGetMouseY()).distance(ofVec2f(x, y)) < radius);
}

void DataPoint::setup(float xpos, float ypos, float rad,float wid, string txt){
    
    x = xpos;
    y = ypos;
    radius = rad;
    width =wid;
    text = txt;
}

