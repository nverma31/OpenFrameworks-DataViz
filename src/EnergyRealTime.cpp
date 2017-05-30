//
//  EnergyRealTime.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 23/05/17.
//
//

#include "EnergyRealTime.h"
EnergyRealTime::EnergyRealTime() {
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


void EnergyRealTime::loaddata(){
    
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    //        cout << "calculating date" <<(now->tm_year + 1900) << '-'
    //        << (now->tm_mon + 1) << '-'
    //        <<  now->tm_mday
    //        << endl;
    
    
    string date = std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1)+  "-" ;
    
    //    cout << " date " <<date;
    
    vector<string> dates;
    
    dates.push_back(std::to_string(now->tm_mday - 7));
    dates.push_back(std::to_string(now->tm_mday - 6));
    dates.push_back(std::to_string(now->tm_mday - 5));
    
    dates.push_back(std::to_string(now->tm_mday - 4));
    dates.push_back(std::to_string(now->tm_mday - 3));
    dates.push_back(std::to_string(now->tm_mday - 2));
    dates.push_back(std::to_string(now->tm_mday - 1));
    dates.push_back(std::to_string(now->tm_mday));
    
    
    
    
    
    
    
    vector <ofxJSONElement> responses;
    
    for (int i = 0; i<8; i++) {
        url ="http://aveiro.m-iti.org/sinais_energy_production/services/daily_production_request.php?date="+date +dates[i];
        ofxJSONElement response;
        if (!response.open(url)){
            cout << "Failed to parse JSON" << endl;
            
        }
        else {
            responses.push_back(response);
        }
        
    }
    
    
    /*--------------------------------------------------------------------------*/
    // Loading and displaying confirmation message
    /*--------------------------------------------------------------------------*/
    
    //        cout << "JSON loaded successfully" << endl;
    //        cout << "************************" << endl;
    
    // ofxJSON is doing all the heavy lifting of parsing the JSON
    // and allowing us to navigate through it:
    
    // City name is under response > current_observation > display_location > city
    
    float total, thermal, hydro;
    
    //        cout << responses[0]["prod_data"] << endl;
    for (int k = 0 ; k < responses.size(); k++)
    {
        total =0;
        thermal = 0;
        hydro = 0;
        for (Json::ArrayIndex i = 0; i < responses[k]["prod_data"].size(); ++i)
            
        {
            //            ofMap(temp[l], 50,22,200, 480)
            total =total + strtof((responses[k]["prod_data"][i]["total"].asString()).c_str(),0);
            thermal =thermal + strtof((responses[k]["prod_data"][i]["termica"].asString()).c_str(),0);
            hydro = hydro +strtof((responses[k]["prod_data"][i]["hidrica"].asString()).c_str(),0);
        }
        totals.push_back(total);
        thermals.push_back(thermal);
        hydros.push_back(hydro);
    }
    
    
    for (int k = 0 ; k < responses.size(); k++) {
        cout <<"totals: "<<totals[k]<<endl;
        cout <<"totals: "<<thermals[k]<<endl;
        cout <<"totals: "<<hydros[k]<<endl;
        cout <<"totals: "<<dates[k]<<endl;
        
        
        
    }
    temp = totals;
    press = thermals;
    prec = hydros;
    wind =hydros;
}


void EnergyRealTime::displayTempText() {
    
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
void EnergyRealTime::displayTemp() {
    
    minTemp = *min_element(temp.begin(), temp.end());
    maxTemp = *max_element(temp.begin(), temp.end());
    
    tempPolyline.draw();
    if (i  == temp.size()) {
        for (int l =0; l < temp.size(); l++) {
            DataPoint data = DataPoint(300+18*l, ofMap(temp[l], minTemp ,maxTemp,150, 480), 5, 50, std::to_string(temp[l]));
            data.display();
            //            ofNoFill();
            cout <<"temp[] l  " <<temp[l]<<endl;
            
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k= k+4) {
        
        verdana12.drawStringAsShapes(days[k], 300+18*k, 500);
        
    }
    //    ofImage img;
    //
    //    img.load("assets/label.png");
    //    img.draw(500, 550);
    //
    //    ofImage img2;
    //    img2.load("assets/labeltemp.png");
    //    img.resize(100,100);
    //    img2.draw(100, 340);
    
}


void EnergyRealTime::updateTemp() {
    
    minTemp = *min_element(temp.begin(), temp.end());
    maxTemp = *max_element(temp.begin(), temp.end());
    if (i <temp.size()) {
        tempPolyline.lineTo(300 + 18*i, ofMap(temp[i], minTemp ,maxTemp,150, 480));
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}

//Real Time Pressure
void EnergyRealTime::displayPressText() {
    
    minTemp = *min_element(press.begin(), press.end());
    maxTemp = *max_element(press.begin(), press.end());
    
    //    cout <<"minTemp"<<minTemp ;
    //    cout<<"\nmaxTemp " <<maxTemp;
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
    ofImage img;
    //
    //    img.load("assets/label.png");
    //    img.draw(500, 550);
    //
    //    ofImage img2;
    //    img2.load("assets/pressurelabel.png");
    //    img.resize(100,100);
    //
    //    img2.draw(100, 340);
    
    //entity
    
    ofPopStyle();
}
void EnergyRealTime::displayPress() {
    
    minTemp = *min_element(press.begin(), press.end());
    maxTemp = *max_element(press.begin(), press.end());
    pressPolyline.draw();
    
    if (i  == press.size()) {
        for (int l =0; l < press.size(); l++) {
            
            DataPoint data = DataPoint(300+18*l, ofMap(press[l], minTemp ,maxTemp ,150, 480), 5, 50, std::to_string(press[l]));
            //            cout <<"\npress[l] "<<press[l];
            
            data.display();
            //            ofNoFill();
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k= k+4) {
        
        verdana12.drawStringAsShapes(days[k], 300+18*k, 500);
        
    }
}

void EnergyRealTime::updatePress() {
    
    minTemp = *min_element(press.begin(), press.end());
    maxTemp = *max_element(press.begin(), press.end());
    if (i <press.size()) {
        pressPolyline.lineTo(300 + 18*i, ofMap(press[i], minTemp,maxTemp,150, 480));
        //        cout <<"\npress[i] "<<press[i];
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}


void EnergyRealTime::displayPrecText() {
    
    minTemp = *min_element(wind.begin(), wind.end());
    minTemp = floor(minTemp * 100.0) / 100.0;
    maxTemp = *max_element(wind.begin(), wind.end());
    
    //    cout <<"minTemp"<<minTemp ;
    //    cout<<"\nmaxTemp " <<maxTemp;
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
    ofImage img;
    //
    //    img.load("assets/label.png");
    //    img.draw(500, 550);
    //
    //    ofImage img2;
    //    img2.load("assets/windlabel.png");
    //    img.resize(100,100);
    //
    //    img2.draw(100, 340);
    //    //entity
    
    ofPopStyle();
}
void EnergyRealTime::displayPrec() {
    minTemp = *min_element(wind.begin(), wind.end());
    maxTemp = *max_element(wind.begin(), wind.end());
    pressPolyline.draw();
    if (i  == wind.size()) {
        for (int l =0; l < wind.size(); l++) {
            
            DataPoint data = DataPoint(300+18*l, ofMap(wind[l], minTemp,maxTemp,200, 480), 5, 50, std::to_string(wind[l]));
            //            cout <<"\npress[l] "<<wind[l];
            
            data.display();
            //            ofNoFill();
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k= k+4) {
        
        verdana12.drawStringAsShapes(days[k], 300+18*k, 500);
        
    }
}

void EnergyRealTime::updatePrec() {
    minTemp = *min_element(wind.begin(), wind.end());
    maxTemp = *max_element(wind.begin(), wind.end());
    
    if (i <wind.size()) {
        pressPolyline.lineTo(300 + 18*i, ofMap(wind[i], minTemp,maxTemp,200, 480));
        //        cout <<"\npress[i] "<<press[i];
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}

