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
    
}
DemoElement::DemoElement(ofPoint pt, float angBeg, float angEnd, float rad, float value1, float value2, float value3) {
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

    curve.setFillColor(color);
    curve.setFilled(true);

    arc1.arc(pt, value1+2, value1+2, angBeg+2, angEnd-2);
    arc1.arcNegative(pt, value1, value1, angEnd-2, angBeg+2);
    arc1.close();
    arc1.setArcResolution(60);
    arccolor = ofColor(0, 0,0);
    arccolor.setHex(0xbdc3c7);
    arc1.setFillColor(arccolor);
    arc1.setFilled(true);
    
    arc3.arc(pt, value3+2, value3+2, angBeg+2, angEnd-2);
    arc3.arcNegative(pt, value3, value3, angEnd-2, angBeg+2);
    arc3.close();
    arc3.setArcResolution(60);
    color = ofColor(0, 0,0);
    color.setHex(0xbdc3c7);
    arc3.setFillColor(color);
    arc3.setFilled(true);
    
    arc2.arc(pt, value2+2, value2+2, angBeg+2, angEnd-2);
    arc2.arcNegative(pt, value2, value2, angEnd-2, angBeg+2);
    arc2.close();
    arc2.setArcResolution(60);
    color = ofColor(0, 0,0);
    color.setHex(0x2ecc71);
    arc2.setFillColor(color);
    arc2.setFilled(true);

    
    
    
}

void DemoElement::display() {
 
   
    //        circle.lineTo(pos);
    //        circle.moveTo(pos);
   // circle.draw();
//    cout<<"  isinside " <<inside<< endl;

    curve.setFillColor(color);
    
    if (isInside()) {
        color.setHex(0x95a5a6);
        
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
        arccolor.set(0 ,0,0);
        cout <<"arc inside";
        
        //        ofDrawRectangle(200, 300, 500, 500);
    }if (isInsideArc3()) {
        arc3.arc(pos, arcrad3+3, arcrad3+3, beginAngle+2, endAngle-2);
        arc3.arcNegative(pos, arcrad3, arcrad3, endAngle-2, beginAngle+2);
        arccolor.set(0 ,0,0);
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

float DemoElement::getAngle(float _x, float _y) {
    if (_x == 0.0) {
        if(_y < 0.0)
            return 270;
        else
            return 90;
    } else if (_y == 0) {
        if(_x < 0)
            return 180;
        else
            return 0;
    }
    
    if ( _y > 0.0)
        if (_x > 0.0)
            return atan(_y/_x) * PI;
        else
            return 180.0 - (atan(_y/-_x) * GRAD_PI);
        else
            if (_x > 0.0)
                return 360.0 - (atan(-_y/_x) * GRAD_PI);  
            else  
                return 180.0 + (atan(-_y/-_x) * GRAD_PI);  
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




void DemoElement::update() {
    
    if (isInside()) {
        color = ofColor(255, 255,0);
        ofDrawRectangle(500, 500, 200, 200);
    }
    else {
        color = ofColor(255, 0,0);

    }
}

void DemoElement::mouseReleased(ofMouseEventArgs & args){
    if (isInside()) {
        // if the mouse is pressed over the circle an event will be notified (broadcasted)
        // the circleEvent object will contain the mouse position, so this values are accesible to any class that is listening.
        ofVec2f mousePos = ofVec2f(args.x, args.y);
        ofNotifyEvent(clickedInside, mousePos, this);
    }
}

void DemoElement::showData() {
    
}
