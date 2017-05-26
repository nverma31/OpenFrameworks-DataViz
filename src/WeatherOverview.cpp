//
//  WeatherOverview.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 26/05/17.
//
//

#include "WeatherOverview.h"


WeatherOverview::WeatherOverview() {
    url = "http://api.openweathermap.org/data/2.5/forecast?id=2267827&units=metric&appid=f8f91a5f5f0db2e682cc8af3dc51a655";
    //
    //    tempPolyline.clear();
    //    pressPolyline.clear();
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


void WeatherOverview::loaddata(){
    
    
    temp.push_back(16);
    temp.push_back(16);
    temp.push_back(16);
    temp.push_back(17);
    temp.push_back(18);
    temp.push_back(19);
    temp.push_back(21);
    temp.push_back(22);
    temp.push_back(22);
    temp.push_back(21);
    temp.push_back(19);
    temp.push_back(17);
    
    prec.push_back(103);
    prec.push_back(87);
    prec.push_back(64);
    prec.push_back(39);
    prec.push_back(19);
    prec.push_back(2);
    prec.push_back(3);
    prec.push_back(37);
    prec.push_back(75);
    prec.push_back(101);
    prec.push_back(100);
    
    wind.push_back(4.3);
    wind.push_back(3.8);
    wind.push_back(5.1);
    wind.push_back(4.6);
    wind.push_back(3.9);
    wind.push_back(3.1);
    wind.push_back(1.8);
    wind.push_back(1.7);
    wind.push_back(2.4);
    wind.push_back(3.2);
    wind.push_back(3.8);
    wind.push_back(4.0);
    
    
    days.push_back("Jan");
    days.push_back("Feb");
    days.push_back("Mar");
    days.push_back("Apr");
    days.push_back("May");
    days.push_back("Jun");
    days.push_back("July");
    days.push_back("Aug");
    days.push_back("Sep");
    days.push_back("Oct");
    days.push_back("Nov");
    days.push_back("Dec");

    
//            temp.push_back(strtof((response["list"][i]["main"]["temp"].asString()).c_str(),0));
//            //            prec.push_back(ofMap(p, 0,100,150, 600));
//    
//            float pr =strtof((response["list"][i]["main"]["pressure"].asString()).c_str(),0);
//            //            press.push_back(ofMap(pr, 1021,1031,150, 600));
//            
//            prec.push_back(strtof((response["list"][i]["clouds"]["all"].asString()).c_str(),0));
//            press.push_back(strtof((response["list"][i]["main"]["pressure"].asString()).c_str(),0));
//            float w =strtof((response["list"][i]["wind"]["speed"].asString()).c_str(),0);
//            //            wind.push_back(ofMap(w, 0,10,150, 600));
//            wind.push_back(strtof((response["list"][i]["wind"]["speed"].asString()).c_str(),0));
//            
//            
//            string date =response["list"][i]["dt_txt"].asString();
//            dates.push_back(date);
////            cout<<" date"<<" "<<date[8]<<" "<<date[9];
////            string d = date.substr (8,2);
//            days.push_back(d);
//            cout << "  d  "<< d;
//            
    
}
void WeatherOverview::displayTempText() {
    
    minTemp = *min_element(temp.begin(), temp.end());
    minTemp = floor(minTemp * 100.0) / 100.0;
    maxTemp = *max_element(temp.begin(), temp.end());
    maxTemp = floor(maxTemp * 100.0) / 100.0;
    
    
    float n = ((maxTemp-minTemp)/4);
    n = floor(n * 100.0) / 100.0;
    
    
    //    int min = static_cast<int>(minTemp);
    //    int max =  static_cast<int>(maxTemp);
    ofPushStyle();
    ofColor(140,140,140, 1);
    verdana12.drawStringAsShapes(std::to_string(minTemp).substr(0,4), 260, 480);
    verdana12.drawStringAsShapes(std::to_string(minTemp+n).substr(0,4), 260, 410);
    verdana12.drawStringAsShapes(std::to_string(minTemp+2*n).substr(0,4), 260, 340);
    verdana12.drawStringAsShapes(std::to_string(minTemp+3*n).substr(0,4), 260, 270);
    verdana12.drawStringAsShapes(std::to_string(minTemp+4*n).substr(0,4), 260, 200);
    
    ofDrawLine(300, 200, 1000, 200);
    ofDrawLine(300, 270, 1000, 270);
    ofDrawLine(300, 340, 1000, 340);
    ofDrawLine(300, 410, 1000, 410);
    
    ofDrawLine(300, 480, 1000, 480);
    
    //entity
    
    ofPopStyle();
}
void WeatherOverview::displayTemp() {
    tempPolyline.draw();
    if (i  == temp.size()) {
        for (int l =0; l < temp.size(); l++) {
            DataPoint data = DataPoint(300+36*l, ofMap(temp[l], 16,25,150, 800), 5);
            data.display();
            //            ofNoFill();
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k++) {
        
        verdana12.drawStringAsShapes(days[k], 300+36*k, 500);
        
    }
}

void WeatherOverview::updateTemp() {
    if (i <temp.size()) {
        tempPolyline.lineTo(300 + 36*i, ofMap(temp[i], 16,25,150, 800));
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}

//Real Time Pressure
void WeatherOverview::displayPressText() {
    
    minTemp = *min_element(press.begin(), press.end());
    minTemp = floor(minTemp * 100.0) / 100.0;
    maxTemp = *max_element(press.begin(), press.end());
    maxTemp = floor(maxTemp * 100.0) / 100.0;
    
    cout <<"minTemp"<<minTemp ;
    cout<<"\nmaxTemp " <<maxTemp;
    float n = ((maxTemp-minTemp)/4);
    n = floor(n * 100.0) / 100.0;
    
    
    //    int min = static_cast<int>(minTemp);
    //    int max =  static_cast<int>(maxTemp);
    ofPushStyle();
    ofColor(140,140,140, 1);
    verdana12.drawStringAsShapes(std::to_string(minTemp).substr(0,4), 260, 480);
    verdana12.drawStringAsShapes(std::to_string(minTemp+n).substr(0,4), 260, 410);
    verdana12.drawStringAsShapes(std::to_string(minTemp+2*n).substr(0,4), 260, 340);
    verdana12.drawStringAsShapes(std::to_string(minTemp+3*n).substr(0,4), 260, 270);
    verdana12.drawStringAsShapes(std::to_string(minTemp+4*n).substr(0,4), 260, 200);
    
    ofDrawLine(300, 200, 1000, 200);
    ofDrawLine(300, 270, 1000, 270);
    ofDrawLine(300, 340, 1000, 340);
    ofDrawLine(300, 410, 1000, 410);
    
    ofDrawLine(300, 480, 1000, 480);
    
    //entity
    
    ofPopStyle();
}
void WeatherOverview::displayPress() {
    pressPolyline.draw();
    if (i  == prec.size()) {
        for (int l =0; l < prec.size(); l++) {
            
            DataPoint data = DataPoint(300+36*l, ofMap(prec[l], 5,110,150, 800), 5);
//            cout <<"\npress[l] "<<prec[l];
            
            data.display();
            //            ofNoFill();
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k++) {
        
        verdana12.drawStringAsShapes(days[k], 300+36*k, 500);
        
    }
}

void WeatherOverview::updatePress() {
    if (i <prec.size()) {
        pressPolyline.lineTo(300 + 18*i, ofMap(prec[i], 5,110,150, 800));
        cout <<"\npress[i] "<<press[i];
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}


void WeatherOverview::displayPrecText() {
    
    minTemp = *min_element(wind.begin(), wind.end());
    minTemp = floor(minTemp * 100.0) / 100.0;
    maxTemp = *max_element(wind.begin(), wind.end());
    
    cout <<"minTemp"<<minTemp ;
    cout<<"\nmaxTemp " <<maxTemp;
    float n = ((maxTemp-minTemp)/4);
    n = floor(n * 100.0) / 100.0;
    
    
    //    int min = static_cast<int>(minTemp);
    //    int max =  static_cast<int>(maxTemp);
    ofPushStyle();
    ofColor(140,140,140, 1);
    verdana12.drawStringAsShapes(std::to_string(minTemp).substr(0,4), 260, 480);
    verdana12.drawStringAsShapes(std::to_string(minTemp+n).substr(0,4), 260, 410);
    verdana12.drawStringAsShapes(std::to_string(minTemp+2*n).substr(0,4), 260, 340);
    verdana12.drawStringAsShapes(std::to_string(minTemp+3*n).substr(0,4), 260, 270);
    verdana12.drawStringAsShapes(std::to_string(minTemp+4*n).substr(0,4), 260, 200);
    
    ofDrawLine(300, 200, 1000, 200);
    ofDrawLine(300, 270, 1000, 270);
    ofDrawLine(300, 340, 1000, 340);
    ofDrawLine(300, 410, 1000, 410);
    
    ofDrawLine(300, 480, 1000, 480);
    
    //entity
    
    ofPopStyle();
}
void WeatherOverview::displayPrec() {
    minTemp = *min_element(wind.begin(), wind.end());
    maxTemp = *max_element(wind.begin(), wind.end());
    pressPolyline.draw();
    if (i  == wind.size()) {
        for (int l =0; l < wind.size(); l++) {
            
            DataPoint data = DataPoint(300+36*l, ofMap(wind[l], minTemp,maxTemp,200, 480), 5);
            cout <<"\npress[l] "<<wind[l];
            
            data.display();
            //            ofNoFill();
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k= k+4) {
        
        verdana12.drawStringAsShapes(days[k], 300+36*k, 500);
        
    }
}

void WeatherOverview::updatePrec() {
    minTemp = *min_element(wind.begin(), wind.end());
    maxTemp = *max_element(wind.begin(), wind.end());
    
    if (i <wind.size()) {
        pressPolyline.lineTo(300 + 18*i, ofMap(wind[i], minTemp,maxTemp,200, 480));
        cout <<"\npress[i] "<<press[i];
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}

