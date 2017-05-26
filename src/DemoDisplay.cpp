
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
    return "Education";
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
        return "  Peace Index";
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
    return "Income Inequality";
}

string DemoDisplay::getRank(){
    
    float angle = getAngle();
    float length = getLength();
    
    if(angle>= 0 && angle <=20 && length <=200) {
        return rank2;
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return rank3;
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return rank2;
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
        return "123";
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return "0.9";
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return "1.1";
    }
    if(angle>= 90 && angle <=110 && length <=200) {
        return "2.1k";
    }if(angle>= 120 && angle <=140 && length <=200) {
        return "3.1";
    }
    if(angle>= 150 && angle <=170 && length <=200) {
        return "81";
    }
    if(angle>= 180 && angle <=200 && length <=200) {
        return "27";
    }
    
    if(angle>= 210 && angle <=230 && length <=200) {
        return "65";
    }
    if(angle>= 240 && angle <=260 && length <=200) {
        return "12.2";
    }if(angle>= 270 && angle <=290 && length <=200) {
        return "51";
    }
    
    if(angle>= 300 && angle <=320 && length <=200) {
        return "0.101";
    }
    if(angle>= 330 && angle <=350 && length <=200) {
        return "0.28";
    }
   
    return "0.28";
}



string DemoDisplay::getRankValue(){
    
    float angle = getAngle();
    float length = getLength();
    
    if(angle>= 0 && angle <=20 && length <=200) {
        return "1.1\n.84\n.79";
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return "12\n13\n16";
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return "1.4\n1.2\n0.9";
    }
    if(angle>= 90 && angle <=110 && length <=200) {
        return "2.6k\n2k\n1.8k";
    }if(angle>= 120 && angle <=140 && length <=200) {
        return "3.4\n3.1\n3.0";
    }
    if(angle>= 150 && angle <=170 && length <=200) {
        return "84\n81\n79";
    }
    if(angle>= 180 && angle <=200 && length <=200) {
        return "31%\n27%\n24%";
    }
    
    if(angle>= 210 && angle <=230 && length <=200) {
        return "68%\n65%\n60%";
    }
    if(angle>= 240 && angle <=260 && length <=200) {
        return "12.5\n12.2\n12.0";
    }if(angle>= 270 && angle <=290 && length <=200) {
        return "55.8\n51\n46";
    }
    
    if(angle>= 300 && angle <=320 && length <=200) {
        return ".111\n.101\n.091";
    }
    if(angle>= 330 && angle <=350 && length <=200) {
        return "0.34\n0.28\n0.27";
    }
    
    return "0.34\n0.28\n0.27";
}




string DemoDisplay::getText(){
    
    float angle = getAngle();
    float length = getLength();
    
    if(angle>= 0 && angle <=20 && length <=200) {
        return "123 People per 100,000 are in jail";
    }
    if(angle>= 30 && angle <=50&& length <=200 ) {
        //            cout << category;
        return "1.1 people per 100,000 are murdered";
    }
    if(angle>= 60 && angle <=80 && length <=200) {
        return "Global Peace index is 1.1(lower is better)";
    }
    if(angle>= 90 && angle <=110 && length <=200) {
        return "The annual spending on health care\n services per person is 2.6k";
    }if(angle>= 120 && angle <=140 && length <=200) {
        return "Average Life Expectancy for both\n men and women is 82";
    }
    if(angle>= 150 && angle <=170 && length <=200) {
        return "3.1 children out of 1,00 died \nbefore age one";
    }
    
    if(angle>= 210 && angle <=230 && length <=200) {
        return "27% of people ages 25-34 hold a \nbachelor degree or higher";
    }
    if(angle>= 240 && angle <=260 && length <=200) {
        return "65% of people ages 25-34 completed\n high school";
    }if(angle>= 270 && angle <=290 && length <=200) {
        return "People ages 25-34 avergae 12.2 years\n of education";
    }
    
    if(angle>= 300 && angle <=320 && length <=200) {
        return "51% of of eligible voters cast a ballot\n in a parliamentary or congressional election";
    }
    if(angle>= 330 && angle <=350 && length <=200) {
        return "Women's reproductive health, empowerment, \nand labor force participation has\n value 0.154(lower is better)";
    }
    if(angle>= 180 && angle <=200 && length <=200) {
        return "The Gini Index of income inequality \nis a value from 0.28 on a\n scale from 0 to 1.";
    }
    return "123 People per 100,000 are in jail";
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
    ofDrawCircle(1055, 280, 30);
    
    ofSetColor(255, 255, 255);
    
//    verdana26.drawStringAsShapes(entity, 980, 150);//entity
    verdana26.drawStringAsShapes(getCategory(), 980, 205);//category
    
    verdana14.drawStringAsShapes(getSubCategory(), 980, 240);//category
//
   verdana14.drawStringAsShapes(getValue(), 1040, 287);//percent
    
    verdana12.drawStringAsShapes(getText(), 940, 330);//text
    
    verdana14.drawStringAsShapes("Comparision", 980, 380);//category
    
  verdana12.drawStringAsShapes(getRank(), 950, 420);//text
    verdana12.drawStringAsShapes(getRankValue(), 1150, 420);//text

    
    
    
    
    ofPopStyle();
}
