//
//  WeatherOverview.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 26/05/17.
//
//

#ifndef WeatherOverview_hpp
#define WeatherOverview_hpp

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




class WeatherOverview {
    
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
    
    ofPolyline pressPolyline;
    ofPolyline windPolyline;
    ofPolyline tempOverPolyline;
    ofPolyline pressOverPolyline;
    ofPolyline windOverPolyline;
    
    void loaddata();
    
    void displayTemp();
    void updateTemp();
    void displayTempText();
    
    void displayPress();
    void updatePress();
    void displayPressText();
    
    void displayPrec();
    void updatePrec();
    void displayPrecText();
    
    
    void displayOverTemp();
    void updateOverTemp();
    void displayOverTempText();
    
    void displayOverPress();
    void updateOverPress();
    void displayOverPressText();
    
    void displayOverPrec();
    void updateOverPrec();
    void displayOverText();
    
    
    void displayOverWind();
    void updateOverWind();
    void displayOverWindText();
    
    
    
    void displaydays();
    WeatherOverview();
    
    
};

#endif /* WeatherOverview_hpp */
