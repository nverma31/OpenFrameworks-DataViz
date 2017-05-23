//
//  EnergyDisplay.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 23/05/17.
//
//

#include "EnergyDisplay.h"
//#include "ofApp.h"

EnergyDisplay::EnergyDisplay(int initCount)
{
    boidCount =  initCount;
    
}

void EnergyDisplay::setup(std::vector<float> &x, std::vector<float> &b ,std::vector<float> &h, std::vector<float> &l) {
    for(int i = 0; i < boidCount; i++ ) {
        EnergyElement newBoid = EnergyElement(x[i], b[i], h[i], l[i]);
        cout <<"x[i]" << x[i] << "base[]" << b[i];
        boids.push_back(newBoid);
    }
}

void EnergyDisplay::display(){
    for (std::vector<EnergyElement>::iterator it = boids.begin() ; it != boids.end(); ++it)
    {
        (*it).display();
    }
}





