

//  Created by Neeraj Verma on 44/05/17.
//
//

#include "EnergyElement.h"

EnergyElement::EnergyElement(){
    
}
EnergyElement::EnergyElement(float b, float h, float l, float x) {
    
    speed =0;
    base = b;
    high = h;
    low = l;
    xpos = x;


//    ofAddListener(ofEvents().mousePressed, this, &EnergyElement::mousePressed);

    
}

void EnergyElement::display() {
    int i =0;
    speed++;
    base = (high + low)/2;
    if (base - 10*speed > high) {
    ofDrawLine(xpos, base,xpos, base -15*speed);
        dataPointHigh =  DataPoint(xpos, base-15*speed, 4);
        dataPointHigh.display();
//    ofDrawCircle(xpos, base-4*speed, 1);
    }
    else {
        ofDrawLine(xpos, base,xpos, high);
        dataPointHigh =  DataPoint(xpos, high, 4);
        dataPointHigh.display();

    
    }
    
    if (base + 10*speed < low) {
    ofDrawLine(xpos, base, xpos, base +15*speed);
    dataPointLow =  DataPoint(xpos, base-15*speed, 4);
        dataPointLow.display();
    }
    else {
        ofDrawLine(xpos, base,xpos, low);
        dataPointLow =  DataPoint(xpos, low, 4);
        dataPointLow.display();

    }

}
void EnergyElement::update() {
    
}
