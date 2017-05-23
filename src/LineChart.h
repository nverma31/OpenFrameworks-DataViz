//
//  LineChart.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 22/05/17.
//
//



#include <stdio.h>
#include "ofMain.h"

class LineChart {
public:
    void setup(string _url, string _name, int _i, int _numCities, vector<float> &values);
    void update();
    void draw(string _chartType, ofPoint chartsize, int test[]);
    
    void setLayout(ofPoint _chartPos, ofPoint _chartSize, float _highestTemp, float _lowestTemp);
    void drawLineChart();
    
    string name;
    int cityIndex;
    int numCities;
    ofPoint chartPos;
    ofPoint chartSize;
    float highestTemp;
    float lowestTemp;
    
    // Let's create 2 lists:
    vector<float> highs;        // high temperature
    vector<float> lows;         // low temperature
    
    //Visuals:
    ofColor highColor;
    ofColor lowColor;
};

