
#include "DemoDisplay.h"


DemoDisplay::DemoDisplay() {
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
}

float DemoDisplay::getAngle() {
    float centerX = 600;
    float centerY = 350;
    float diameter = 400;
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
    //    cout<<"centerX"<<centerX<<endl;
    //    cout<<"MouseX"<<pointX<<endl;
    //
    //
    
    float a = atan2(pointY - centerY, pointX - centerX);
    
    float length = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY)));
    
    
    float angle =a*(180/PI);
    if (angle <0 ) {
        angle = angle +360;
    }
    return angle;
}
float DemoDisplay::getLength() {
    float centerX = 600;
    float centerY = 350;
    float diameter = 400;
    float pointX= (float)ofGetMouseX();
    float pointY = (float)ofGetMouseY();
   
    
    
    float length = sqrtf(((pointX - centerX)*(pointX - centerX)) + ((pointY - centerY)*(pointY - centerY)));
    
  
    return length;
}

string DemoDisplay::getCategory(){
    
    float angle = getAngle();
    float length = getLength();
   
        if(angle>= 0 && angle <=20 && length <=200) {
            return "Safety";
        }
        if(angle>= 30 && angle <=50&& length <=200 ) {
//            cout << category;
            return "Safety";
        }
        if(angle>= 60 && angle <=80 && length <=200) {
            return "Safety";
        }
        if(angle>= 90 && angle <=110 && length <=200) {
            return "Health";
        }if(angle>= 120 && angle <=140 && length <=200) {
            return "Health";
        }
        if(angle>= 150 && angle <=170 && length <=200) {
            return "Health";
        }
        
        if(angle>= 210 && angle <=230 && length <=200) {
            return "Education";
        }
        if(angle>= 240 && angle <=260 && length <=200) {
            return "Education";
        }if(angle>= 270 && angle <=290 && length <=200) {
            return "Democracy";
        }
        
        if(angle>= 300 && angle <=320 && length <=200) {
            return "Equality";
        }
        if(angle>= 330 && angle <=350 && length <=200) {
            return "Equality";
        }
        if(angle>= 180 && angle <=200 && length <=200) {
            return "Education";
        }
  return "Health";
}

string DemoDisplay::getSubCategory(){
    
    float angle = getAngle();
    float length = getLength();
    
    if(angle>= 0 && angle <=20 && length <=200) {
        return "Prison Population";
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return "    Homicide";
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return "  Gun Deaths";
    }
    if(angle>= 90 && angle <=110 && length <=200) {
        return "Health Expenditure";
    }if(angle>= 120 && angle <=140 && length <=200) {
        return "Infant mortality";
    }
    if(angle>= 150 && angle <=170 && length <=200) {
        return "Life Expectancy";
    }
    
    if(angle>= 210 && angle <=230 && length <=200) {
        return "College Education";
    }
    if(angle>= 240 && angle <=260 && length <=200) {
        return "High School Education";
    }if(angle>= 270 && angle <=290 && length <=200) {
        return "Years of Education";
    }
    
    if(angle>= 300 && angle <=320 && length <=200) {
        return "Voter Turnout";
    }
    if(angle>= 330 && angle <=350 && length <=200) {
        return "Gender Inequality";
    }
    if(angle>= 180 && angle <=200 && length <=200) {
        return "Income Inequality";
    }
    return "";
}

string DemoDisplay::getRank(){
    
    float angle = getAngle();
    float length = getLength();
    
    if(angle>= 0 && angle <=20 && length <=200) {
        return rank;
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return rank;
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return rank;
    }
    if(angle>= 90 && angle <=110 && length <=200) {
        return rank;
    }if(angle>= 120 && angle <=140 && length <=200) {
        return rank;
    }
    if(angle>= 150 && angle <=170 && length <=200) {
        return rank;
    }
    
    if(angle>= 210 && angle <=230 && length <=200) {
        return rank;
    }
    if(angle>= 240 && angle <=260 && length <=200) {
        return rank;
    }if(angle>= 270 && angle <=290 && length <=200) {
        return rank;
    }
    
    if(angle>= 300 && angle <=320 && length <=200) {
        return rank;
    }
    if(angle>= 330 && angle <=350 && length <=200) {
        return rank;
    }
    if(angle>= 180 && angle <=200 && length <=200) {
        return rank;
    }
    return rank;
}



string DemoDisplay::getValue(){
    
    float angle = getAngle();
    float length = getLength();
    
    if(angle>= 0 && angle <=20 && length <=200) {
        return "Safety";
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return "Safety";
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return "Safety";
    }
    if(angle>= 90 && angle <=110 && length <=200) {
        return "Health";
    }if(angle>= 120 && angle <=140 && length <=200) {
        return "Health";
    }
    if(angle>= 150 && angle <=170 && length <=200) {
        return "Health";
    }
    
    if(angle>= 210 && angle <=230 && length <=200) {
        return "Education";
    }
    if(angle>= 240 && angle <=260 && length <=200) {
        return "Education";
    }if(angle>= 270 && angle <=290 && length <=200) {
        return "Democracy";
    }
    
    if(angle>= 300 && angle <=320 && length <=200) {
        return "Equality";
    }
    if(angle>= 330 && angle <=350 && length <=200) {
        return "Equality";
    }
    if(angle>= 180 && angle <=200 && length <=200) {
        return "Education";
    }
    return "Health";
}


string DemoDisplay::getText(){
    
    float angle = getAngle();
    float length = getLength();
    
    if(angle>= 0 && angle <=20 && length <=200) {
        return "Safety";
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return "Safety";
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return "Safety";
    }
    if(angle>= 90 && angle <=110 && length <=200) {
        return "Health";
    }if(angle>= 120 && angle <=140 && length <=200) {
        return "Health";
    }
    if(angle>= 150 && angle <=170 && length <=200) {
        return "Health";
    }
    
    if(angle>= 210 && angle <=230 && length <=200) {
        return "Education";
    }
    if(angle>= 240 && angle <=260 && length <=200) {
        return "Education";
    }if(angle>= 270 && angle <=290 && length <=200) {
        return "Democracy";
    }
    
    if(angle>= 300 && angle <=320 && length <=200) {
        return "Equality";
    }
    if(angle>= 330 && angle <=350 && length <=200) {
        return "Equality";
    }
    if(angle>= 180 && angle <=200 && length <=200) {
        return "Education";
    }
    return "Health";
}



void DemoDisplay::displayTextData() {
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
    
//    verdana26.drawStringAsShapes(entity, 980, 150);//entity
    verdana26.drawStringAsShapes(getCategory(), 980, 205);//category
    
    verdana14.drawStringAsShapes(getSubCategory(), 980, 240);//category
//
//    verdana14.drawStringAsShapes(percent, 1040, 287);//percent
    
    verdana12.drawStringAsShapes("A bunch of random kjahkadsjhdskjkjdhjkdahdsjkhdaskjdash\nklsakjaslkjaslk text about bullshit", 940, 330);//text
    
    verdana14.drawStringAsShapes("Comparision", 980, 450);//category
    
  verdana12.drawStringAsShapes(getRank(), 980, 490);//text
    
    
    
    
    ofPopStyle();
}
