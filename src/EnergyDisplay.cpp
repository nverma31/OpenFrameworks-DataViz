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
    verdana32.load("avenir-light.ttf", 16, true, true,true);

    text = "63";
    text2 = "37";
    
    
}

void EnergyDisplay::setup(std::vector<float> &x, std::vector<float> &h ,std::vector<float> &l, std::vector<float> &b) {
    ofAddListener(ofEvents().mousePressed, this, &EnergyDisplay::_mouseReleased);

    for(int i = 0; i < boidCount; i++ ) {
        
        EnergyElement newBoid = EnergyElement(x[i],ofMap(h[i], 0, 100, 200, 480), ofMap(l[i], 0, 100, 200, 480), b[i]);
        cout <<"\n highs " << h[i] << "\nlows " << l[i];
        boids.push_back(newBoid);
    }
}

void EnergyDisplay::display(){
    for (std::vector<EnergyElement>::iterator it = boids.begin() ; it != boids.end(); ++it)
    {
        (*it).display();
    }
    ofPushStyle();
    ofSetColor(231, 128, 70);
    ofFill();
    verdana32.drawStringAsShapes(text, 490, 193);//category

    verdana32.drawStringAsShapes(text2, 425, 166);//category
    ofPopStyle();

}

void EnergyDisplay::_mouseReleased(ofMouseEventArgs & args){
    for(int i = 0; i < boidCount; i++ ) {
    if(args.x>=boids[i].xpos - 5 && args.x<=boids[i].xpos+5 && args.y < boids[i].high && args.y>boids[i].low){
        boids[i].update();
//        text = boids[i].+"31 % of Energy was produced by Thermal";
        float h =ofMap(boids[i].high, 200, 480, 0, 100);
        float l =ofMap(boids[i].low, 200, 480, 0, 100);
        text2 = std::to_string(ofMap(boids[i].high, 200, 480, 0, 100)).substr(0,2);
        text = std::to_string(ofMap(boids[i].low, 200, 480, 0, 100)).substr(0,2);

    }
    else {
        boids[i].changeWidth();
    }
    }
   }





