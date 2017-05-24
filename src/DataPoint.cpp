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
DataPoint::DataPoint(float xpos, float ypos, float rad){
    x = xpos;
    y = ypos;
    radius = rad;
}

void DataPoint::display(){
    ofNoFill();
    ofDrawCircle(x, y, 2);
    if (isinside()) {
        ofDrawRectangle(x -20, y+20, 20, 20);
    }
}

bool DataPoint::isinside(){
    return (ofVec2f(ofGetMouseX(), ofGetMouseY()).distance(ofVec2f(x, y)) < radius);
}

