//
//  DemoElement.cpp
//  Scrolling
//
//  Created by Neeraj Verma on 22/05/17.
//
//
#define GRAD_PI 180.000/PI


#include "DemoElement.h"
DemoElement::DemoElement(){
    ofAddListener(ofEvents().mousePressed, this, &DemoElement::mouseReleased);

    
}
DemoElement::DemoElement(ofPoint pt, float angBeg, float angEnd, float rad, float value1, float value2, float value3) {
    ofTrueTypeFont::setGlobalDpi(96);
    rank = "1.Continent\n2.Madeira\n3.Azores";
    entity = "Madiera";
    category = "Health";
    subcategory = "Life Expectancy";
    percent = "81";

    verdana14.load("avenir-light.ttf", 14, true, true,true);
    verdana32.load("avenir-light.ttf", 32, true, true,true);
    verdana12.load("avenir-light.ttf", 10, true, true,true);
    verdana18.load("avenir-light.ttf", 18, true, true,true);
    verdana22.load("avenir-light.ttf", 22, true, true,true);
    verdana26.load("avenir-light.ttf", 24, true, true,true);

//    verdana14.setLineHeight(18.0f);
//    verdana14.setLetterSpacing(1.037);
//    ofFill();

    testFont.load("Avenir.ttc", 10, true, true, true);
    testFont2.load("cooperBlack.ttf", 12, true, true, false);
    
     entity = "Madeira";
//     category= "Education";
     text = "Madeira has 31% of students doing some shit in some other shit";
     rank = "3rd";
     percent = "61%";
    
    pos = pt;
    radius = rad;
    beginAngle =  angBeg;
    endAngle = angEnd;
    arcrad1 = value1;

    arcrad2 = value2;
    arcrad3 = value3;

    circle.setFillColor(0x34495e);
    circle.moveTo(pt);
    circle.arc(pt, rad, rad, angBeg, angEnd);
  
    curve.arc(pt, rad, rad, angBeg, angEnd);
    curve.arcNegative(pt, 30, 30, angEnd, angBeg);
    curve.close();
    curve.setArcResolution(60);
    color = ofColor(0, 0,0);
    color.setHex(0x2c3e50);

    curve.setFillColor(ofColor::aquamarine);
    curve.setFilled(true);

    arc1.arc(pt, value1+5, value1+5, angBeg+2, angEnd-2);
    arc1.arcNegative(pt, value1, value1, angEnd-2, angBeg+2);
    arc1.close();
    arc1.setArcResolution(60);
    arccolor = ofColor(113, 113,113);
    arccolor.setHex(0xbdc3c7);
    arc1.setFillColor(arccolor);
    arc1.setFilled(true);
    
    arc3.arc(pt, value3+5, value3+5, angBeg+2, angEnd-2);
    arc3.arcNegative(pt, value3, value3, angEnd-2, angBeg+2);
    arc3.close();
    arc3.setArcResolution(60);
    color = ofColor(0, 0,0);
    color.setHex(0xbdc3c7);
    arc3.setFillColor(arccolor);
    arc3.setFilled(true);
    
    arc2.arc(pt, value2+5, value2+5, angBeg+2, angEnd-2);
    arc2.arcNegative(pt, value2, value2, angEnd-2, angBeg+2);
    arc2.close();
    arc2.setArcResolution(60);
    color = ofColor(0, 0,0);
    color.setHex(0x2ecc71);
    arc2.setFillColor(arccolor);
    arc2.setFilled(true);

    
    
    
}

void DemoElement::displayTextData() {
    ofPushStyle();
    ofSetColor(0, 0, 0);
//    cout <<" \n in display category " <<category;
    ofNoFill();
//    ofSetLineWidth(0.5);
    ofPolyline closedShapePolyline;
    ofDrawRectangle(900, 175, 300, 400);

    ofFill();

    ofSetColor(0, 0, 0,2);
    ofDrawRectangle(900, 120, 300, 40);
   
    ofSetColor(0, 0, 0);
    ofDrawRectangle(900, 175, 300, 40);

    ofSetColor(231, 128, 70);
    ofDrawCircle(1050, 280, 20);
    
    ofSetColor(255, 255, 255);

    verdana26.drawStringAsShapes(entity, 980, 150);//entity
    verdana26.drawStringAsShapes(getCategory(), 980, 205);//category

    verdana14.drawStringAsShapes(subcategory, 980, 240);//category

    verdana14.drawStringAsShapes(percent, 1040, 287);//percent

    verdana12.drawStringAsShapes("A bunch of random kjahkadsjhdskjkjdhjkdahdsjkhdaskjdash\nklsakjaslkjaslk text about bullshit", 940, 330);//text

    verdana14.drawStringAsShapes("Comparision", 980, 450);//category

    verdana12.drawStringAsShapes(rank, 980, 490);//text


    

    ofPopStyle();
}

void DemoElement::display() {
    

    
//    
//    //Drawing Text
//    ofFill();
//    verdana32.drawStringAsShapes("Measure of Madeira", 50, 50);
//    testFont.drawString("Comparing Madeira Across 12 key areas:\neducation, health, democracy, safety, \n equality", 50, 70);
//    
//    verdana22.drawStringAsShapes(entity, 900, 200);
//    ofPushStyle();
//    ofSetColor(0, 240, 0);
//    ofDrawRectangle(900, 205, 250, 5);
//    ofPopStyle();
//    
//    verdana26.drawStringAsShapes(category, 900, 250);
//    verdana26.drawStringAsShapes(rank, 900, 300);
//
//    verdana12.drawStringAsShapes(text, 900, 330);
//
//    verdana14.drawStringAsShapes("comparision", 920, 370);
    
    displayTextData();
    curve.setFillColor(color);
    
    if (isInside()) {
        arccolor = ofColor(113, 113,113,200);
        
        //        ofDrawRectangle(200, 300, 500, 500);
    }
    if (isInsideArc1()) {
        arc1.arc(pos, arcrad1+3, arcrad1+3, beginAngle+2, endAngle-2);
        arc1.arcNegative(pos, arcrad1, arcrad1, endAngle-2, beginAngle+2);
        arccolor.set(0 ,0,0);
        cout <<"arc inside";

//        ofDrawRectangle(200, 300, 500, 500);
    }
    
    if (isInsideArc2()) {
        arc2.arc(pos, arcrad2+3, arcrad2+3, beginAngle+2, endAngle-2);
        arc2.arcNegative(pos, arcrad2, arcrad2, endAngle-2, beginAngle+2);
        arccolor = ofColor(113, 113,113,200);
        cout <<"arc inside";
        
        //        ofDrawRectangle(200, 300, 500, 500);
//    }if (isInsideArc3()) {
//        arc3.arc(pos, arcrad3+3, arcrad3+3, beginAngle+2, endAngle-2);
//        arc3.arcNegative(pos, arcrad3, arcrad3, endAngle-2, beginAngle+2);
        arccolor = ofColor(113, 113,113,200);
        cout <<"arc inside";
        
        //        ofDrawRectangle(200, 300, 500, 500);
    }
  
//    arc2.draw();
    
    curve.draw();
    arc1.draw();

    arc2.draw();
    arc3.draw();


}
float DemoElement::normalizeAngle(float angle)
{
    // First, limit it between -2*PI and 2*PI, using modulo operator
    float na = angle;
    // If the result is negative, bring it back to 0, 2*PI interval
    if (na < 0) na = 2*PI + na;
 
    return angle;
}

float DemoElement::getAngle() {
    float centerX = pos.x;
    float centerY = pos.y;
    float diameter = 2*radius;
    float angle1 = beginAngle;
    float angle2 = endAngle;
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
    //    cout<<"centerX"<<centerX<<endl;
    //    cout<<"MouseX"<<pointX<<endl;
    //
    //
    
    // Find if the mouse is close enough of center
    bool nearCenter = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY))) <= diameter/2;
    //        if (!nearCenter)
    //            return false; // Quick exit...
    
    // Normalize angles
    float na1 = normalizeAngle(angle1);
    float na2 = normalizeAngle(angle2);
    //    cout <<"Mouse Angle  "<<getAngle(pointX, pointY)<<endl;
    //    cout <<"na1  " <<na1<<endl;
    //    cout <<"na2  "<<na2<<endl;
    // Find the angle between the point and the x axis from the center of the circle
    float a = atan2(pointY - centerY, pointX - centerX);
    
    float length = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY)));
    
    
    float angle =a*(180/PI);
    if (angle <0 ) {
        angle = angle +360;
    }
    
//    cout <<"angle" <<angle;
    
    return angle;
}  


bool DemoElement::isInside() {

    float centerX = pos.x;
    float centerY = pos.y;
    float diameter = 2*radius;
    float angle1 = beginAngle;
    float angle2 = endAngle;
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
//    cout<<"centerX"<<centerX<<endl;
//    cout<<"MouseX"<<pointX<<endl;
//
//    

        // Find if the mouse is close enough of center
//        bool nearCenter = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY))) <= diameter/2;
//        if (!nearCenter)
//            return false; // Quick exit...
    
        // Normalize angles
        float na1 = normalizeAngle(angle1);
        float na2 = normalizeAngle(angle2);
//    cout <<"Mouse Angle  "<<getAngle(pointX, pointY)<<endl;
//    cout <<"na1  " <<na1<<endl;
//    cout <<"na2  "<<na2<<endl;
        // Find the angle between the point and the x axis from the center of the circle
        float a = atan2(pointY - centerY, pointX - centerX);
    
    float length = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY)));
    

    float angle =a*(180/PI);
    if (angle <0 ) {
        angle = angle +360;
    }
        bool between;
        // First case: small arc, below half of circle
        if (angle >= na1 &&  angle <=na2 && length <=radius)
        {
            
            // Just check we are between these two angles
            inside = true;
            return true;
}
    
    else
        inside = false;
    
    //cout <<"isinside" <<between<<endl;
        return false;
   

}


bool DemoElement::isInsideArc1() {
    
    float centerX = pos.x;
    float centerY = pos.y;
    float diameter = 2*radius;
    float angle1 = beginAngle;
    float angle2 = endAngle;
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
    //    cout<<"centerX"<<centerX<<endl;
    //    cout<<"MouseX"<<pointX<<endl;
    //
    //
    
    // Find if the mouse is close enough of center
    bool nearCenter = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY))) <= diameter/2;
    //        if (!nearCenter)
    //            return false; // Quick exit...
    
    // Normalize angles
    float na1 = normalizeAngle(angle1);
    float na2 = normalizeAngle(angle2);
    //    cout <<"Mouse Angle  "<<getAngle(pointX, pointY)<<endl;
    //    cout <<"na1  " <<na1<<endl;
    //    cout <<"na2  "<<na2<<endl;
    // Find the angle between the point and the x axis from the center of the circle
    float a = atan2(pointY - centerY, pointX - centerX);
    
    float length = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY)));
    
    
    float angle =a*(180/PI);
    if (angle <0 ) {
        angle = angle +360;
    }
    bool between;
    // First case: small arc, below half of circle
    if (angle >= na1 &&  angle <=na2 && length <=arcrad1+10 && length >=arcrad1)
    {
        // Just check we are between these two angles
        inside = true;
        return true;
    }
    
    else
        inside = false;
    
    //cout <<"isinside" <<between<<endl;
    return false;
    
    
}


bool DemoElement::isInsideArc2() {
    
    float centerX = pos.x;
    float centerY = pos.y;
    float diameter = 2*radius;
    float angle1 = beginAngle;
    float angle2 = endAngle;
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
    //    cout<<"centerX"<<centerX<<endl;
    //    cout<<"MouseX"<<pointX<<endl;
    //
    //
    
    // Find if the mouse is close enough of center
    bool nearCenter = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY))) <= diameter/2;
    //        if (!nearCenter)
    //            return false; // Quick exit...
    
    // Normalize angles
    float na1 = normalizeAngle(angle1);
    float na2 = normalizeAngle(angle2);
    //    cout <<"Mouse Angle  "<<getAngle(pointX, pointY)<<endl;
    //    cout <<"na1  " <<na1<<endl;
    //    cout <<"na2  "<<na2<<endl;
    // Find the angle between the point and the x axis from the center of the circle
    float a = atan2(pointY - centerY, pointX - centerX);
    
    float length = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY)));
    
    
    float angle =a*(180/PI);
    if (angle <0 ) {
        angle = angle +360;
    }
    bool between;
    // First case: small arc, below half of circle
    if (angle >= na1 &&  angle <=na2 && length <=arcrad2+10 && length >=arcrad3)
    {
        // Just check we are between these two angles
        inside = true;
       

        return true;
    }
    
    else
        inside = false;
    
    //cout <<"isinside" <<between<<endl;
    return false;
    
    
}

bool DemoElement::isInsideArc3() {
    
    float centerX = pos.x;
    float centerY = pos.y;
    float diameter = 2*radius;
    float angle1 = beginAngle;
    float angle2 = endAngle;
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
    //    cout<<"centerX"<<centerX<<endl;
    //    cout<<"MouseX"<<pointX<<endl;
    //
    //
    
    // Find if the mouse is close enough of center
    bool nearCenter = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY))) <= diameter/2;
    //        if (!nearCenter)
    //            return false; // Quick exit...
    
    // Normalize angles
    float na1 = normalizeAngle(angle1);
    float na2 = normalizeAngle(angle2);
    //    cout <<"Mouse Angle  "<<getAngle(pointX, pointY)<<endl;
    //    cout <<"na1  " <<na1<<endl;
    //    cout <<"na2  "<<na2<<endl;
    // Find the angle between the point and the x axis from the center of the circle
    float a = atan2(pointY - centerY, pointX - centerX);
    
    float length = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY)));
    
    
    float angle =a*(180/PI);
    if (angle <0 ) {
        angle = angle +360;
    }
    bool between;
    // First case: small arc, below half of circle
    if (angle >= na1 &&  angle <=na2 && length <=arcrad3+10 && length >=arcrad3)
    {
        // Just check we are between these two angles
        inside = true;
        return true;
    }
    
    else
        inside = false;
    
    //cout <<"isinside" <<between<<endl;
    return false;
    
    
}


string DemoElement::getCategory(){
    float angle = getAngle();
    if (inside) {
    if(angle>= 0 && angle <=20) {
        return "health";
    }
    if(angle>= 30 && angle <=50) {
        return "Education";
    }
    if(angle>= 60 && angle <=80) {
        return "health";
    }
    if(angle>= 90 && angle <=110) {
        return "health";
    }if(angle>= 120 && angle <=140) {
        return "Education";
    }
    if(angle>= 150 && angle <=170) {
        return "health";
    }
    if(angle>= 180 && angle <=200) {
        return "Education";
    }
    if(angle>= 210 && angle <=230) {
        return "health";
    }
    if(angle>= 240 && angle <=260) {
        return "health";
    }if(angle>= 270 && angle <=290) {
        return "Education";
    }

    if(angle>= 300 && angle <=320) {
        return "health";
    }
    if(angle>= 330 && angle <=350) {
        return "Education";
    }
    }
    return category;
}

void DemoElement::update() {
    
    if (isInside()) {
        color = ofColor(17, 203,189, 200);
        ofDrawRectangle(500, 500, 200, 200);
//        cout <<"category" <<category;
        inside = true;
            }
    else {
        color = ofColor(17, 203,189);
        inside = false;
    }
}

void DemoElement::mouseReleased(ofMouseEventArgs & args){
   
    if (isInside()) {
        // if the mouse is pressed over the circle an event will be notified (broadcasted)
        // the circleEvent object will contain the mouse position, so this values are accesible to any class that is listening.
        ofVec2f mousePos = ofVec2f(args.x, args.y);
        ofNotifyEvent(clickedInside, mousePos, this);
//        color = ofColor(0,0,0);
        ofDrawRectangle(100, 100, 100, 100);
//        cout<<"clicked inside";
//        cout<<"Mouse  " <<args.x;

    }
}

void DemoElement::showData() {
    
}
