//
//  WeatherRealTime.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 23/05/17.
//
//

#include "ofMain.h"
#include <vector>
#include "ofxJSON.h"
#include "DataPoint.h"
#include <boost/date_time.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
#include <string>
#include <algorithm>




class WeatherRealTime {
    
public:
    
    ofTrueTypeFont	verdana32;
    ofTrueTypeFont	verdana14;
    ofTrueTypeFont	verdana12;
    ofTrueTypeFont	verdana18;
    ofTrueTypeFont	verdana22;
    ofTrueTypeFont	verdana26;
    
    ofTrueTypeFont testFont;
    ofTrueTypeFont testFont2;
    
    vector<float> temp;
    vector<float> prec;
    vector<float> wind;
    vector<float> press;
    vector<string> days;
    vector<string> dates;
    vector<DataPoint> points;
    vector<float> xaxis;
    
    string url;
    float maxTemp;
    float maxPrec;
    float maxPress;
    float maxWind;
    float minTemp;
    float minPrec;
    float mindWind;
    float minPress;
    int i = 0;
    int increment;
    
    ofPolyline tempPolyline;

    void loaddata();
    
    void displayTemp();
    void updateTemp();
    void displayTempText();
    
    void displayPress();
    void updatePress();
    void displayPressText();

    void displayPrec();
    void updatePrec();
    void displayText();

    
    void displayWind();
    void updateWind();
    void displayWindText();

    
    
    void displaydays();
    WeatherRealTime();


};
