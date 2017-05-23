//
//  WeatherRealTime.hpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 23/05/17.
//
//

#include "ofMain.h"
#include <vector>

class WeatherRealTime {
    
public:
    
    vector<float> temp;
    vector<float> prec;
    vector<float> wind;
    vector<float> press;
    vector<float> days;
    
    float maxTemp;
    float maxPrec;
    float maxPress;
    float maxWind;
    float minTemp;
    float minPrec;
    float mindWind;
    float minPress;

    void loaddata(string _url);
    void displayTemp();
    void displayPress();
    void displayPrec();
    void displaydays();


};
