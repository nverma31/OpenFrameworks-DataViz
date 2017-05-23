

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
    if (base - 2*speed > high)
    ofDrawLine(xpos, base,xpos, base -2*speed);
    
    cout << "xpos "<<xpos <<"base " <<base << "low "<< low;
    if (base - 2*speed < low)
    ofDrawLine(xpos, base, xpos, base +2*speed);

}
void EnergyElement::update() {
    
}
