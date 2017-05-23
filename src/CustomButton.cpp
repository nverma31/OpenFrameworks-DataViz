//
//  CustomButton.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 23/05/17.
//
//

#include "CustomButton.h"
ofEvent<ofVec2f> CustomButton::clickedInsideGlobal = ofEvent<ofVec2f>();

CustomButton::CustomButton() {
    bRegisteredEvents = false;
}

CustomButton::~CustomButton() {
    clear();
}

void CustomButton::setup(int radius, int x, int y, ofColor color){
    this->radius = radius;
    this->x = x;
    this->y = y;
    this->color = color;
    if(!bRegisteredEvents) {
        ofRegisterMouseEvents(this); // this will enable our circle class to listen to the mouse events.
        bRegisteredEvents = true;
    }
}
void CustomButton::draw(){
    ofPushStyle();
    ofSetColor(color);
    ofDrawCircle(x,y, radius);
    ofPopStyle();
}

void CustomButton::clear() {
    if(bRegisteredEvents) {
        ofUnregisterMouseEvents(this); // disable litening to mous events.
        bRegisteredEvents = false;
    }
}

void CustomButton::mouseMoved(ofMouseEventArgs & args){}
void CustomButton::mouseDragged(ofMouseEventArgs & args){}
void CustomButton::mousePressed(ofMouseEventArgs & args){}
void CustomButton::mouseReleased(ofMouseEventArgs & args){
    if (inside(args.x, args.y)) {
        // if the mouse is pressed over the circle an event will be notified (broadcasted)
        // the circleEvent object will contain the mouse position, so this values are accesible to any class that is listening.
        ofVec2f mousePos = ofVec2f(args.x, args.y);
        ofNotifyEvent(clickedInside, mousePos, this);
        ofNotifyEvent(clickedInsideGlobal, mousePos);
    }
}
void CustomButton::mouseScrolled(ofMouseEventArgs & args){}
void CustomButton::mouseEntered(ofMouseEventArgs & args){}
void CustomButton::mouseExited(ofMouseEventArgs & args){}

//this function checks if the passed arguments are inside the circle.
bool CustomButton::inside(float _x, float _y ){
    return (ofVec2f(_x, _y).distance(ofVec2f(x, y)) <radius);
}
