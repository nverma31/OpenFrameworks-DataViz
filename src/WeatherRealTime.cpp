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
        cout << "JSON loaded successfully" << endl;
        cout << "************************" << endl;
        
        // ofxJSON is doing all the heavy lifting of parsing the JSON
        // and allowing us to navigate through it:
        
        // City name is under response > current_observation > display_location > city
        cout << response["list"] << endl;
        for (Json::ArrayIndex i = 0; i < response["list"].size(); ++i)
        {
//            ofMap(temp[l], 18,22,200, 800)
            float t =strtof((response["list"][i]["main"]["temp"].asString()).c_str(),0);
            temp.push_back(ofMap(t, 18,25,150, 600));
            float p = strtof((response["list"][i]["clouds"]["all"].asString()).c_str(),0);
//            temp.push_back(strtof((response["list"][i]["main"]["temp"].asString()).c_str(),0));
            prec.push_back(ofMap(p, 0,100,150, 600));
            
            float pr =strtof((response["list"][i]["main"]["pressure"].asString()).c_str(),0);
            press.push_back(ofMap(pr, 1021,1031,150, 600));
            
//            prec.push_back(strtof((response["list"][i]["clouds"]["all"].asString()).c_str(),0));
//            press.push_back(strtof((response["list"][i]["main"]["pressure"].asString()).c_str(),0));
            float w =strtof((response["list"][i]["wind"]["speed"].asString()).c_str(),0);
            wind.push_back(ofMap(w, 0,10,150, 600));
            //wind.push_back(strtof((response["list"][i]["wind"]["speed"].asString()).c_str(),0));
            
            
            string date =response["list"][i]["dt_txt"].asString();
            dates.push_back(date);
            cout<<" date"<<" "<<date[8]<<" "<<date[9];
            string d = date.substr (8,2);
            days.push_back(d);
            cout << "  d  "<< d;

        }
    }
}
void WeatherRealTime::display() {
    
      minTemp = *min_element(temp.begin(), temp.end());
    cout <<"minTemp" ;
    ofPushStyle();
    ofColor(140,140,140, 1);
   
    ofDrawLine(300, 200, 1000, 200);
    ofDrawLine(300, 270, 1000, 270);
    ofDrawLine(300, 340, 1000, 340);
    ofDrawLine(300, 410, 1000, 410);

    ofDrawLine(300, 480, 1000, 480);

    //entity

    ofPopStyle();
}
void WeatherRealTime::displayTemp() {
    tempPolyline.draw();
    if (i  == temp.size()) {
        for (int l =0; l < temp.size(); l++) {
            DataPoint data = DataPoint(300+18*l, temp[l], 5);
            data.display();
//            ofNoFill();
//            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
    for (int k =0; k < days.size(); k= k+4) {
        
        verdana12.drawStringAsShapes(days[k], 300+18*k, 500);
        
    }
}

void WeatherRealTime::updateTemp() {
    if (i <temp.size()) {
    tempPolyline.lineTo(300 + 18*i, temp[i]);
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
    
        i++;}

}

