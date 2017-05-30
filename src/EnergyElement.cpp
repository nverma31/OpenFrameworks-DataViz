

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
    
//    cout <<"xpos" <<xpos;


    ofAddListener(ofEvents().mousePressed, this, &EnergyElement::_mouseReleased);

    
}

void EnergyElement::display() {
    int i =0;
    speed++;
    
    ofImage img;
    img.load("assets/leg1.png");
    img.draw(430, 510);
    
//    cout << "  high "<< high << "   Low  " << low <<"  base  " << base << "speed  " <<speed;
    ofPushStyle();
    ofSetLineWidth(width);
//  cout <<"width  "<<width;
    if (340 + 2*speed < high) {

    ofDrawLine(xpos, base,xpos, base +2*speed );
        dataPointHigh.setup(xpos, base+2*speed, 4, 50, std::to_string(base+2*speed));
        dataPointHigh.display();
//    ofDrawCircle(xpos, base-4*speed, 1);
        isInside();
    }
    else {

        ofDrawLine(xpos, base,xpos, high);
        dataPointHigh.setup(xpos, high, 4,50, std::to_string(high));
        dataPointHigh.display();
        isInside();

    
    }
    
    if (base - 2*speed > low) {

    ofDrawLine(xpos, base, xpos, base -2*speed);
    dataPointLow .setup(xpos, base-2*speed, 4, 50, std::to_string(base -2*speed));
        dataPointLow.display();
    }
    else {

        ofDrawLine(xpos, base,xpos, low);
        dataPointLow.setup(xpos, low, 4,50, std::to_string(low));
        dataPointLow.display();

    }

    ofPopStyle();
}
void EnergyElement::update() {
    width = 4;
}

void EnergyElement::changeWidth() {
    width = 1;
}

bool EnergyElement::isInside() {
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
//    cout<<pointX<<" Mouse X" << " Mouse Y" << pointY << " low " <<low <<" high " <<high << "xpos" << xpos;
    if(pointX <= 515 && pointX >= 505 && pointY <= high && pointY >=low) {
        return true;
    }
    return false;
    
}
void EnergyElement::_mouseReleased(ofMouseEventArgs & args){
    if (isInside()) {
//        this->width =4;
////        ofSetLineWidth(this->width);
//        float pointX= (float)ofGetMouseX();
//        float pointY = (float)ofGetMouseY();
//        cout<<pointX<<" Mouse X" << " Mouse Y" << pointY << " low " <<low <<" high " <<high << "xpos" << xpos;
//
////        cout<<"\nwidth\n"<< this->width;
////        cout <<ofGetWidth();
////        cout<<"clicked inside";
////        cout<<"Mouse  " <<args.x;
        
    }
}

