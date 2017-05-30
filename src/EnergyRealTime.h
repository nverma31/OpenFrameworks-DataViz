//
//  EnergyRealTime.hpp
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




class EnergyRealTime {
    
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
    int count = 0;
    int increment;
    
    ofPolyline tempPolyline;
    
    ofPolyline pressPolyline;
    ofPolyline windPolyline;
 
    
    void loaddata();
    
    void displayTotal();
    void updateTotal();
    void displayTotalText();
    
    void displayThermal();
    void updateThermal();
    void displayThermalText();
    
    void displayHydro();
    void updateHydro();
    void displayHydroText();
    
    
       
    vector<float> totals;
    vector<float> thermals;
    vector<float> hydros;
    
    void displaydays();
    EnergyRealTime();
    
    
};
