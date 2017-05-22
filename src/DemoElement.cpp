//
//  DemoElement.cpp
//  Scrolling
//
//  Created by Neeraj Verma on 22/05/17.
//
//

#include "DemoElement.h"
DemoElement::DemoElement(){
    
}
DemoElement::DemoElement(ofPoint pt, float angBeg, float angEnd, float rad) {
    pos = pt;
    radius = rad;
    beginAngle =  angBeg;
    endAngle = angEnd;
    
    circle.setFillColor(0x34495e);
    circle.moveTo(pt);
    circle.arc(pt, rad, rad, angBeg, angEnd);
  
    curve.arc(pt, rad, rad, angBeg, angEnd);
    curve.arcNegative(pt, 30, 30, angEnd, angBeg);
    curve.close();
    curve.setArcResolution(60);
    ofColor c(255, 0,0);
    curve.setFillColor(c);
    curve.setFilled(true);
}

void DemoElement::display() {
 
   
    //        circle.lineTo(pos);
    //        circle.moveTo(pos);
   // circle.draw();
    curve.draw();

}


void DemoElement::update() {
}


void DemoElement::showData() {
    
}
