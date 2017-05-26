//
//  DemoDisplay.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 22/05/17.
//
//

#include <vector>
#include "ofMain.h"

class DemoDisplay {
    
public:
    
    DemoDisplay();
    void update();
    void display();
    
    ofTrueTypeFont	verdana32;
    ofTrueTypeFont	verdana14;
    ofTrueTypeFont	verdana12;
    ofTrueTypeFont	verdana18;
    ofTrueTypeFont	verdana22;
    ofTrueTypeFont	verdana26;
    
    ofTrueTypeFont testFont;
    ofTrueTypeFont testFont2;
    float getAngle();
    float getLength();
    string rank = "1.Continent\n2.Madeira\n3.Azores";

    string getCategory();
    string getSubCategory();
    string getRank();
    string getValue();
    string getText();


    
    void displayTextData();
private:
    
    float elementCount;
};
