//
//  EnergyElement.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 22/05/17.
//
//


//#include <stdio.h>
#include "ofMain.h"

class EnergyElement {
    float base;
    float high;
    float speed;
    float low;
    float xpos;
    
public:
    void display();
    void update();
    EnergyElement();

    EnergyElement(float x, float y, float z, float k);

    
};
