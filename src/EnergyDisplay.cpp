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
    verdana32.load("avenir-light.ttf", 28, true, true,true);

    text = "";
    
    
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
    verdana32.drawStringAsShapes(text, 100, 100);//category

}

void EnergyDisplay::_mouseReleased(ofMouseEventArgs & args){
    for(int i = 0; i < boidCount; i++ ) {
    if(args.x>=boids[i].xpos - 5 && args.x<=boids[i].xpos+5 && args.y < boids[i].high && args.y>boids[i].low){
        boids[i].update();
//        text = boids[i].+"31 % of Energy was produced by Thermal";
        }
    else {
        boids[i].changeWidth();
    }
    }
   }





