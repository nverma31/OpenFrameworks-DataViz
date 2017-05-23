

//  Created by Neeraj Verma on 22/05/17.
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
    
}

void EnergyElement::display() {
    int i =0;
    speed++;
    if (base - 10*speed > high) {
    ofDrawLine(xpos, base,xpos, base -10*speed);
//    ofDrawCircle(xpos, base-4*speed, 1);
    }
    else {
        ofDrawLine(xpos, base,xpos, high);
        ofDrawCircle(xpos, high,1);
    }
    
    cout << "xpos "<<xpos <<"base " <<base << "low "<< low;
    if (base + 10*speed < low) {
    ofDrawLine(xpos, base, xpos, base +10*speed);
//    ofDrawCircle(xpos, base+4*speed, 1);
    }
    else {
        ofDrawLine(xpos, base,xpos, low);
        ofDrawCircle(xpos, high,1);

    }

}
void EnergyElement::update() {
    
}
