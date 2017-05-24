#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxSmartFont.h"
#include "Button.h"
#include "DemoElement.h"
//#include "EnergyElement.h"
#include "Scroll.h"
#include "LineChart.h"
#include "EnergyDisplay.h"
#include "CustomButton.h"
//#include "DataPoint.h"
#include "WeatherRealTime.h"
class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<ofImage> images;  // Object to draw in the panel.
    int imagesWidth;
    int imagesHeight;
    
    /* Display parameters for the panel */
    int gap;
    int margin;
    int scrollBarWidth;
    
    
    int panelWidth;
    int panelHeight;
    int contentScrollY;
    bool isScrollBarVisible;
    ofRectangle scrollBarRectangle;
    ofRectangle gripRectangle;
    bool isDraggingGrip;
    bool isMouseOverGrip;
    int mousePreviousY;
    vector<ofRectangle> rectangles;
    
    int ill;
    
    //Buttons
    int numClicks;
    bool isFullscreen;
    ofxDatGuiButton* button;
    ofxDatGuiButton* back;

    ofxDatGuiButton* home;

    Button* testing;

    
    ofxDatGuiButton* label1;

    ofxDatGuiButton* label2;
    ofxDatGuiButton* label3;
    ofxDatGuiButton* label4;
    ofxDatGuiButton* label5;

    ofxDatGuiButton* toggle;
    void positionButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
    ofxDatGuiTheme* theme;

    ofxDatGuiTheme* themesmoke;

    
    
    float interpolate ;
    int growTime;
    
    ofImage bg;
    ofImage nav;

    ofImage bg1;
    ofImage bg2;
    ofImage bg3;
    ofImage bg4;

    
    ofNode baseNode;
    ofNode childNode;
    ofNode grandChildNode;
    ofPolyline line;
    ofEasyCam cam;
    
    
    int startTime;
    
    ofTexture imageTexture;
    ofTexture navtexture;
    ofTexture titletexture;
    ofTexture energyTexture;
    
    
    int screenNumber;
    
    ofPoint points[20];
    Button* hdemo;
    ofxDatGuiButton* hclimate;
    ofxDatGuiButton* henergy;
    ofxDatGuiButton* hinfo;
    void drawChart(int type, int data[], ofPoint pos);
    void drawLineChart();
    void drawPieChart();
    int test [12] = { 16, 22, 15, 19, 21, 24, 27,21,18,16, 14, 11 };
    int test1 [12] = { 0, 22, 15, 0, 21, 0, 27,21,0,16, 14, 0 };

    int test3 [12] = { 14, 23, 10, 19, 21, 24, 27,22,18,16, 14, 18 };
    int test4 [12] = { 5, 22, 15, 8, 21, 4, 8,21,3,5, 12, 2 };

    int test5[12] = { 8, 15, 15, 19, 21, 24, 7,21,11,16, 10, 11 };
    int test6 [12] = { 5, 10, 15, 15, 21, 4, 8,11,2,5, 9, 2 };

    int tes7 [12] = { 16, 22, 15, 19, 21, 24, 27,21,18,16, 14, 11 };
    int test8 [12] = { 5, 22, 15, 8, 21, 4, 8,21,3,5, 12, 2 };

    int test9 [12] = { 16, 22, 15, 19, 21, 24, 27,21,18,16, 14, 11 };
    int test10 [12] = { 5, 22, 15, 8, 21, 4, 8,21,3,5, 12, 2 };

    int test11 [12] = { 16, 22, 15, 19, 21, 24, 27,21,18,16, 14, 11 };
    int test12 [12] = { 0, 22, 15, 0, 21, 0, 27,21,0,16, 14, 0 };

    int test13 [12] = { 16, 22, 15, 19, 21, 24, 27,21,18,16, 14, 11 };
    int test14 [12] = { 0, 22, 15, 0, 21, 0, 27,21,0,16, 14, 0 };

    
    int frame;
    int chart;
    
    //Buttons for Climate
    
    ofxDatGuiButton* cl_over;
    ofxDatGuiButton* cl_real;
    
    ofxDatGuiButton* cl_main;
    ofxDatGuiButton* cl_daily;
    ofxDatGuiButton* cl_hourly;
    ofxDatGuiButton* cl_pre;
    ofxDatGuiButton* cl_sea;
    ofxDatGuiButton* cl_wind;
    ofxDatGuiButton* cl_press;
    
    
    //Buttons for Energy
    
    ofxDatGuiButton* en_over;
    ofxDatGuiButton* en_real;
    
    ofxDatGuiButton* en_hcc;
    
    ofxDatGuiButton* en_hct;
    
    ofxDatGuiButton* en_pcb;
    
    ofxDatGuiButton* en_main;
    ofxDatGuiButton* en_daily;
    ofxDatGuiButton* en_monthly;
    ofxDatGuiButton* en_bio;
    ofxDatGuiButton* en_hyd;
    ofxDatGuiButton* en_wind;
    ofxDatGuiButton* en_thermal;
    
    
    DemoElement demoelement;

    DemoElement demoelement2;
    DemoElement demoelement3;
    DemoElement demoelement4;
    DemoElement demoelement5;
    DemoElement demoelement6;
    DemoElement demoelement7;
    DemoElement demoelement8;
    DemoElement demoelement9;
    DemoElement demoelement10;
    DemoElement demoelement11;
    DemoElement demoelement12;

    
    EnergyElement energyElement;
    vector<ofImage> baseImages;

    vector<float> xpos;
    vector<float> bases;
    vector<float> highs;
    vector<float> lows;

    Scroll scroll;
    LineChart avgTemp;
    LineChart avgPrec;
    LineChart avgSeaSurface;
    LineChart temp;
    LineChart precReal;
    LineChart seaReal;
    LineChart windReal;
    LineChart pressReal;

    LineChart avgBiomass;
    LineChart avgHydro;
    LineChart avgThermal;
    LineChart avgWind;
    LineChart avgEnergy;


    EnergyDisplay energyDisplay;
    
    CustomButton butt1;

    CustomButton butt2;
    CustomButton butt3;
    CustomButton butt4;
    
    void onMouseInCustomButton1(ofVec2f & e);
    void onMouseInCustomButton2(ofVec2f & e);
    void onMouseInCustomButton3(ofVec2f & e);
    void onMouseInCustomButton4(ofVec2f & e);

    WeatherRealTime weatherRealTime;
//    DataPoint dataPoint;




    
};
