//
//  DemoElement.cpp
//  Scrolling
//
//  Created by Neeraj Verma on 22/05/17.
//
//

#include "DemoElement.h"



void DemoElement::display() {
    ofPath circle;
        
//    circle.setArcResolution(1000);
    //circle.setCurveResolution(60);
    circle.setFillColor(0x34495e);

    ofPoint pos;
    pos.x = ofGetWidth()/2-50;
    pos.y = ofGetHeight()/2-50;
    
    circle.moveTo(pos);
    circle.arc(pos, 200, 200, 0, 30);
    
    //        circle.lineTo(pos);
    //        circle.moveTo(pos);
    circle.draw();
}


void DemoElement::update() {
    
}


void DemoElement::showData() {
    
}
