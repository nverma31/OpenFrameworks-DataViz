//
//  DataPoint.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 24/05/17.
//
//
#include "ofMain.h"

class DataPoint {
    
    float x;
    float y;
    float radius;
    float text;
    
public:
    void display();
    DataPoint();
    DataPoint(float xpos,float ypos, float rad);
    bool isinside();
    void createText();
    
    
    
};
