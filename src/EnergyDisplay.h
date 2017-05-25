//
//  EnergyDisplay.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 23/05/17.
//
//



#include "ofMain.h"

//#include "ofApp.h"
#include "EnergyElement.h"
#include <vector>

#ifndef FLOCK_H_INCLUDED
#define FLOCK_H_INCLUDED

class EnergyDisplay {
    
public:
    
    EnergyDisplay(){};
    EnergyDisplay(int startNumber);
    void display();
    void add(float x,float y, float z);
    void setup(std::vector<float> &x, std::vector<float> &b ,std::vector<float> &h, std::vector<float> &l);
    void _mouseReleased(ofMouseEventArgs &e);

    ofTrueTypeFont	verdana32;

    
private:
    
    float boidCount;
    string text;

    std::vector<EnergyElement> boids;
    std::vector<float> xpos;
    std::vector<float> highs;
    std::vector<float> lows ;
//    void mouseReleased(ofMouseEventArgs & args);

    void drawButtons();
    void updateButtons();

};

#endif // FLOCK_H_INCLUDED
