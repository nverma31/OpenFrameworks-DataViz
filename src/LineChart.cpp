//
//  City.cpp
//  example_3_drawLineChart
//
//  Created by Gabriel Gianordoli on 9/19/14.
//
//

#include "LineChart.h"

void LineChart::setup(string _url, string _name, int _i, int _numCities, vector<float> &values){
    name = _name;
    cityIndex = _i;
    
    highs = values;
    lows = values;
    highColor.setHsb(ofMap(_i, 0, _numCities - 1, 0, 160),
                     255, 255);
    lowColor.setHsb(ofMap(_i, 0, _numCities - 1, 0, 160),
                    255, 200);
}

void LineChart::update(){
    
}

void LineChart::draw(string _chartType, ofPoint position){
    
    int test [12] = { 16, 22, 15, 19, 21, 24, 27,21,18,16, 14, 11 };
    int test1 [12] = { 0, 22, 15, 0, 21, 0, 27,21,0,16, 14, 0 };
    ofPoint chartSize = ofPoint(ofGetWidth() * 0.4, ofGetHeight() * 0.4);
    ofPoint pos;
    pos.x = 400;
    pos.y = 100;
    chartPos =pos;
    ofNoFill();
    ofSetLineWidth(2);
    
    //ofDrawBitmapStringHighlight(ofToString("Average Temperature"), ofGetWidth()/2, ofGetHeight()/2-200);
    
    // HIGH
    ofBeginShape();
    for(int i = 0; i < 7; i++){
        ofPoint pos;
        
        pos.x = ofMap(i,
                      0, 9,
                      chartPos.x, chartPos.x + chartSize.x);
        
        pos.y = ofMap(test[i],
                      20, 50,
                      chartPos.y + chartSize.y-100, chartPos.y);
        ofVertex(pos);
        ofDrawBitmapString(ofToString(test[i]), pos);
    }
    ofSetColor(ofColor::red);
    ofEndShape();
    ofSetColor(ofColor::grey);

}

void LineChart::setLayout(ofPoint _chartPos, ofPoint _chartSize, float _highestTemp, float _lowestTemp){
    chartPos = _chartPos;
    chartSize = _chartSize;
    highestTemp = _highestTemp;
    lowestTemp = _lowestTemp;
}

void LineChart::drawLineChart(){
    
    
    ofNoFill();
    ofSetLineWidth(2);
    
    // HIGH
    ofBeginShape();
    for(int i = 0; i < highs.size(); i++){
        ofPoint pos;
        pos.x = ofMap(i,
                      0, highs.size()-1,
                      chartPos.x, chartPos.x + chartSize.x);
        
        pos.y = ofMap(highs[i],
                      lowestTemp, highestTemp,
                      chartPos.y + chartSize.y, chartPos.y);
        ofVertex(pos);
        ofDrawBitmapString(ofToString(highs[i]), pos);
    }
    ofSetColor(highColor);
    ofEndShape();
    
    // LOW
    ofSetColor(lowColor);
    ofBeginShape();
    for(int i = 0; i < lows.size(); i++){
        ofPoint pos;
        pos.x = ofMap(i,
                      0, lows.size()-1,
                      chartPos.x, chartPos.x + chartSize.x);
        
        pos.y = ofMap(lows[i],
                      lowestTemp, highestTemp,
                      chartPos.y + chartSize.y, chartPos.y);
        ofVertex(pos);
        ofDrawBitmapString(ofToString(lows[i]), pos);
    }
    ofEndShape();
}

