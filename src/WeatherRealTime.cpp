//
//  WeatherRealTime.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 23/05/17.
//
//

#include "WeatherRealTime.h"
WeatherRealTime::WeatherRealTime() {
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


void WeatherRealTime::loaddata(){
    
    
    
    ofxJSONElement response;
    
    /*--------------------------------------------------------------------------*/
    // Loading and displaying confirmation message
    /*--------------------------------------------------------------------------*/
    if (!response.open(url)){
        cout << "Failed to parse JSON" << endl;
        
    }else{
//        cout << "JSON loaded successfully" << endl;
//        cout << "************************" << endl;
        
        // ofxJSON is doing all the heavy lifting of parsing the JSON
        // and allowing us to navigate through it:
        
        // City name is under response > current_observation > display_location > city
//        cout << response["list"] << endl;
        for (Json::ArrayIndex i = 0; i < response["list"].size(); ++i)
        {
//            ofMap(temp[l], 18,22,200, 480)
            float t =strtof((response["list"][i]["main"]["temp"].asString()).c_str(),0);
//            temp.push_back(ofMap(t, 18,25,150, 600));
            float p = strtof((response["list"][i]["clouds"]["all"].asString()).c_str(),0);
            temp.push_back(strtof((response["list"][i]["main"]["temp"].asString()).c_str(),0));
//            prec.push_back(ofMap(p, 0,100,150, 600));
            
            float pr =strtof((response["list"][i]["main"]["pressure"].asString()).c_str(),0);
//            press.push_back(ofMap(pr, 1021,1031,150, 600));
            
            prec.push_back(strtof((response["list"][i]["clouds"]["all"].asString()).c_str(),0));
            press.push_back(strtof((response["list"][i]["main"]["pressure"].asString()).c_str(),0));
            float w =strtof((response["list"][i]["wind"]["speed"].asString()).c_str(),0);
//            wind.push_back(ofMap(w, 0,10,150, 600));
            wind.push_back(strtof((response["list"][i]["wind"]["speed"].asString()).c_str(),0));
            
            
            string date =response["list"][i]["dt_txt"].asString();
            dates.push_back(date);
//            cout<<" date"<<" "<<date[8]<<" "<<date[9];
            string d = date.substr (8,2);
            days.push_back(d);
//            cout << "  d  "<< d;

        }
    }
}
void WeatherRealTime::displayTempText() {
    
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
    ofDrawLine(300, 150, 1000, 150);
    ofDrawLine(300, 230, 1000, 230);
    ofDrawLine(300, 310, 1000, 310);
    ofDrawLine(300, 390, 1000, 390);


    ofDrawLine(300, 480, 1000, 480);

    //entity

    ofPopStyle();
}
void WeatherRealTime::displayTemp() {
    
    minTemp = *min_element(temp.begin(), temp.end());
    maxTemp = *max_element(temp.begin(), temp.end());
    
    tempPolyline.draw();
    if (i  == temp.size()) {
        for (int l =0; l < temp.size(); l++) {
            float y =ofMap(temp[l], minTemp ,maxTemp,150, 480);
            float middle = (480+150)/2;
            
            
            if (y <= middle){
                float diff = middle - y;
                
                DataPoint data = DataPoint(300+18*l, middle+diff, 5, 50, std::to_string(temp[l]));
                data.display();
                
            }
            
            if (y > middle){
                float diff =  y - middle;
                
                DataPoint data = DataPoint(300+18*l, middle-diff, 5, 50, std::to_string(temp[l]));
                data.display();
                
            }
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


void WeatherRealTime::updateTemp() {
    
    minTemp = *min_element(temp.begin(), temp.end());
    maxTemp = *max_element(temp.begin(), temp.end());
    if (i <temp.size()) {
        float y =ofMap(temp[i], minTemp ,maxTemp,150, 480);
        float middle = (480+150)/2;
        
        
        if (y <= middle){
            float diff = middle - y;
            
            tempPolyline.lineTo(300 + 18*i, middle+diff);
            
        }
        
        if (y > middle){
            float diff =  y - middle;
            
            tempPolyline.lineTo(300 + 18*i, middle-diff);
            
            
        }
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
    
        i++;}

}

//Real Time Pressure
void WeatherRealTime::displayPressText() {
    
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
    
    ofDrawLine(300, 150, 1000, 150);
    ofDrawLine(300, 230, 1000, 230);
    ofDrawLine(300, 310, 1000, 310);
    ofDrawLine(300, 390, 1000, 390);

    
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
void WeatherRealTime::displayPress() {
    
    minTemp = *min_element(press.begin(), press.end());
    maxTemp = *max_element(press.begin(), press.end());
    pressPolyline.draw();
    
    if (i  == press.size()) {
        for (int l =0; l < press.size(); l++) {
            
            float y =ofMap(prec[l], minTemp ,maxTemp,150, 480);
            float middle = (480+150)/2;
            
            
            if (y <= middle){
                float diff = middle - y;
                
                DataPoint data = DataPoint(300+18*l, middle+diff, 5, 50, std::to_string(press[l]));
                data.display();
                
            }
            
            if (y > middle){
                float diff =  y - middle;
                
                DataPoint data = DataPoint(300+18*l, middle-diff, 5, 50, std::to_string(press[l]));
                data.display();
                
            }
            //            ofNoFill();
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k= k+4) {
        
        verdana12.drawStringAsShapes(days[k], 300+18*k, 500);
        
    }
}

void WeatherRealTime::updatePress() {
    
    minTemp = *min_element(press.begin(), press.end());
    maxTemp = *max_element(press.begin(), press.end());
    if (i <press.size()) {
        float y =ofMap(press[i], minTemp ,maxTemp,150, 480);
        float middle = (480+150)/2;
        
        
        if (y <= middle){
            float diff = middle - y;
            
            pressPolyline.lineTo(300 + 18*i, middle+diff);
            
        }
        
        if (y > middle){
            float diff =  y - middle;
            
            pressPolyline.lineTo(300 + 18*i, middle-diff);
            
            
        }//        cout <<"\npress[i] "<<press[i];
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}


void WeatherRealTime::displayPrecText() {
    
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
    
    ofDrawLine(300, 150, 1000, 150);
    ofDrawLine(300, 230, 1000, 230);
    ofDrawLine(300, 310, 1000, 310);
    ofDrawLine(300, 390, 1000, 390);

    
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
void WeatherRealTime::displayPrec() {
    minTemp = *min_element(wind.begin(), wind.end());
    maxTemp = *max_element(wind.begin(), wind.end());
    windPolyline.draw();
    if (i  == wind.size()) {
        for (int l =0; l < wind.size(); l++) {
            
            float y =ofMap(wind[l], minTemp ,maxTemp,150, 480);
            float middle = (480+150)/2;
            
            
            if (y <= middle){
                float diff = middle - y;
                
                DataPoint data = DataPoint(300+18*l, middle+diff, 5, 50, std::to_string(wind[l]));
                data.display();
                
            }
            
            if (y > middle){
                float diff =  y - middle;
                
                DataPoint data = DataPoint(300+18*l, middle-diff, 5, 50, std::to_string(wind[l]));
                data.display();
                
            }            //            ofNoFill();
            //            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k= k+4) {
        
        verdana12.drawStringAsShapes(days[k], 300+18*k, 500);
        
    }
}

void WeatherRealTime::updatePrec() {
    minTemp = *min_element(wind.begin(), wind.end());
    maxTemp = *max_element(wind.begin(), wind.end());

    if (i <wind.size()) {
        float y =ofMap(wind[i], minTemp ,maxTemp,150, 480);
        float middle = (480+150)/2;
        
        
        if (y <= middle){
            float diff = middle - y;
            
            windPolyline.lineTo(300 + 18*i, middle+diff);
            
        }
        
        if (y > middle){
            float diff =  y - middle;
            
            windPolyline.lineTo(300 + 18*i, middle-diff);
            
            
        }//        cout <<"\npress[i] "<<press[i];
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
        
        i++;}
    
}

