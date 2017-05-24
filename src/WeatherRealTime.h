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

class WeatherRealTime {
    
public:
    
    vector<float> temp;
    vector<float> prec;
    vector<float> wind;
    vector<float> press;
    vector<float> days;
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

    void displayPress();
    void displayPrec();
    void displaydays();
    WeatherRealTime();


};
