

//  Created by Neeraj Verma on 44/05/17.
//
//

#include "EnergyElement.h"

EnergyElement::EnergyElement(){
    
}
EnergyElement::EnergyElement(float x, float h, float l, float b) {
    
    speed =3;
    base = b;
    high = h;
    low = l;
    xpos = x;
    width = 1;
    inc = 1;


    ofAddListener(ofEvents().mousePressed, this, &EnergyElement::_mouseReleased);

    
}

void EnergyElement::display() {
    int i =0;
    base = 340;
    speed++;
    
//    cout << "  high "<< high << "   Low  " << low <<"  base  " << base << "speed  " <<speed;
    ofSetLineWidth(4);
//  cout <<"width  "<<width;
    if (340 + 2*speed < high) {

    ofDrawLine(xpos, base,xpos, base +2*speed );
        dataPointHigh.setup(xpos, base+2*speed, 4);
        dataPointHigh.display();
//    ofDrawCircle(xpos, base-4*speed, 1);
        isInside();
    }
    else {

        ofDrawLine(xpos, base,xpos, high);
        dataPointHigh.setup(xpos, high, 4);
        dataPointHigh.display();
        isInside();

    
    }
    
    if (base - 2*speed > low) {

    ofDrawLine(xpos, base, xpos, base -2*speed);
    dataPointLow .setup(xpos, base-2*speed, 4);
        dataPointLow.display();
    }
    else {

        ofDrawLine(xpos, base,xpos, low);
        dataPointLow.setup(xpos, low, 4);
        dataPointLow.display();

    }

}
void EnergyElement::update() {
    
}

bool EnergyElement::isInside() {
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
    cout<<pointX<<" Mouse X" << " Mouse Y" << pointY << " low " <<low <<" high " <<high << "xpos" << xpos;
    if(pointX <= xpos +1 && pointX >= xpos-1 && pointY <= low && pointY >=high) {
        return true;
    }
    
}
void EnergyElement::_mouseReleased(ofMouseEventArgs & args){
    if (isInside()) {
        // if the mouse is pressed over the circle an event will be notified (broadcasted)
        // the circleEvent object will contain the mouse position, so this values are accesible to any class that is listening.
//        ofVec2f mousePos = ofVec2f(args.x, args.y);
//        ofNotifyEvent(clickedInside, mousePos, this);
//        ofSetLineWidth(4);
//        ofSetColor(0, 0, 0);
        this->width =4;
//        ofSetLineWidth(this->width);
        float pointX= (float)ofGetMouseX();
        float pointY = (float)ofGetMouseY();
//        cout<<pointX<<" Mouse X" << " Mouse Y" << pointY << " low " <<low <<" high " <<high << "xpos" << xpos;

        cout<<"\nwidth\n"<< this->width;
//        cout <<ofGetWidth();
        cout<<"clicked inside";
//        cout<<"Mouse  " <<args.x;
        
    }
}

