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
        cout << response["list"][0] << endl;
        for (Json::ArrayIndex i = 0; i < response["list"].size(); ++i)
        {
//            ofMap(temp[l], 18,22,200, 800)
            float t =strtof((response["list"][i]["main"]["temp"].asString()).c_str(),0);
            temp.push_back(ofMap(t, 18,22,200, 400));
//            temp.push_back(strtof((response["list"][i]["main"]["temp"].asString()).c_str(),0));
            prec.push_back(strtof((response["list"][i]["clouds"]["all"].asString()).c_str(),0));
            press.push_back(strtof((response["list"][i]["main"]["pressure"].asString()).c_str(),0));
            wind.push_back(strtof((response["list"][i]["wind"]["speed"].asString()).c_str(),0));
            
            string date =response["list"][i]["dt_txt"].asString();
            cout<<"date"<<date[9];

        }
    }
}

void WeatherRealTime::displayTemp() {
    tempPolyline.draw();
    if (i  == temp.size()) {
        for (int l =0; l < temp.size(); l++) {
            DataPoint data = DataPoint(100+30*l, temp[l], 5);
            data.display();
//            ofNoFill();
//            ofDrawCircle(100 + 30*l, temp[l], 2);
        }
    }
}

void WeatherRealTime::updateTemp() {
    if (i <temp.size()) {
    tempPolyline.lineTo(100 + 30*i, temp[i]);
        ofPushStyle();
        ofSetColor(ofColor::red);
        ofPopStyle();
    
        i++;}

}
