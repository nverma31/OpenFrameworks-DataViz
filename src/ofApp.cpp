#include "ofApp.h"

void ofApp::setup(){
//    dataPoint = DataPoint(200,200,5);
    weatherRealTime.loaddata();
    weatherRealTime1.loaddata();
    weatherRealTime2.loaddata();
    
    weatherOverview.loaddata();
    weatherOverview1.loaddata();
    weatherOverview2.loaddata();
    
    
    energyRealTime.loaddata();
    energyRealTime2.loaddata();
    energyRealTime3.loaddata();

    ofSetBackgroundAuto(true);
    
    frame = 0;
    screenNumber = 0;
    ofPoint pos;
    pos.x = 600;
    pos.y = 350;
    
    butt1.setup(200, 400, 100, ofColor::grey);
    butt2.setup(200, 400, 300, ofColor::grey);
    butt3.setup(200, 400, 500, ofColor::grey);
    butt4.setup(200, 400, 700, ofColor::grey);

    demoelement = DemoElement(pos, 0, 20, 200, 60, 90, 110);
    
    
   
    for (int i = 5; i < 20; ++i){
        xpos.push_back(i*30.0 +300);
//        highs.push_back(ofMap(60, 0, 100, 200, 480));
//        lows.push_back(ofMap(40, 0, 100, 200, 480));
        bases.push_back(340);
        
    }

    highs.push_back(68);
    highs.push_back(69);
    highs.push_back(73);
    highs.push_back(71);
    highs.push_back(74);
    highs.push_back(76);
    highs.push_back(79);
    highs.push_back(76);
    highs.push_back(87);
    highs.push_back(85);
    highs.push_back(82);
    highs.push_back(85);
    highs.push_back(78);
    highs.push_back(81);
    
    highs1.push_back(55);
    highs1.push_back(54);
    highs1.push_back(59);
    highs1.push_back(53);
    highs1.push_back(58);
    highs1.push_back(61);
    highs1.push_back(64);
    highs1.push_back(62);
    highs1.push_back(65);
    highs1.push_back(63);
    highs1.push_back(65);
    highs1.push_back(66);
    highs1.push_back(68);
    highs1.push_back(65);
    
    highs2.push_back(70);
    highs2.push_back(68);
    highs2.push_back(70);
    highs2.push_back(67);
    highs2.push_back(69);
    highs2.push_back(67);
    highs2.push_back(68);
    highs2.push_back(65);
    highs2.push_back(62);
    highs2.push_back(61);
    highs2.push_back(60);
    highs2.push_back(60);
    highs2.push_back(55);
    highs2.push_back(56);
    
    for (int k = 0; k<highs.size(); k++) {
        lows.push_back(100-highs[k]);
        lows1.push_back(100-highs1[k]);
        lows2.push_back(100-highs2[k]);

    }

    energyDisplay = EnergyDisplay(14);
    
    energyDisplay.setup(xpos, highs, lows, bases);

    
    energyDisplay1 = EnergyDisplay(14);
    highs.clear();
    lows.clear();
//    for (int i = 5; i < 20; ++i){
//        xpos.push_back(i*30.0 +300);
//        highs.push_back(ofMap(80, 0, 100, 200, 480));
//        lows.push_back(ofMap(20, 0, 100, 200, 480));
//        bases.push_back(340);
//        
//    }

    energyDisplay1.setup(xpos, highs1, lows1, bases);

    energyDisplay2 = EnergyDisplay(14);
    highs.clear();
    lows.clear();
//    for (int i = 5; i < 20; ++i){
//        xpos.push_back(i*30.0 +300);
//        highs.push_back(ofMap(80, 0, 100, 200, 480));
//        lows.push_back(ofMap(20, 0, 100, 200, 480));
//        bases.push_back(340);
//        
//    }
    
    energyDisplay2.setup(xpos, highs2, lows2, bases);

    
//    baseImages = images;
    baseImages.resize(1);
    for (int i = 0; i < 1; i++){
        baseImages[i].loadImage("/Users/Neeraj/Desktop/assets/text1.png");
 }
//    imagesWidth = baseImages[0].getWidth();
//    imagesHeight = baseImages[0].getHeight();
    scroll.setup(1000, 400, baseImages);
    
    
    ofPoint chartSize = ofPoint(ofGetWidth() * 0.7, ofGetHeight() * 0.7);
    ofPoint chartPos = ofPoint(ofGetWidth() * 0.15, ofGetHeight() * 0.15);
     vector<float> values;
    
    for (int i =0; i< 10; i++) {
        values.push_back(100+i*20);
    }
    

//    scroll = Scroll();
    demoelement2 = DemoElement(pos, 30, 50, 280, 170, 180, 190);
//    ofAddListener(ofEvents().mousePressed, demoelement2, &DemoElement::mouseReleased);

    

    demoelement3 = DemoElement(pos, 60, 80, 200, 165, 185, 195);
    demoelement4 = DemoElement(pos, 90, 110, 300, 120, 140, 180);
   
    demoelement5 = DemoElement(pos, 120, 140, 200, 130, 140, 170);
    demoelement6 = DemoElement(pos, 150, 170, 200, 170, 180 , 190);
    demoelement7 = DemoElement(pos, 180, 200, 340,170, 180, 190);
    demoelement8 = DemoElement(pos, 210, 230, 200, 175, 185, 195);
    demoelement9 = DemoElement(pos, 240, 260, 200, 170, 180, 190);
    demoelement10 = DemoElement(pos, 270, 290, 200, 160, 170, 180);
    demoelement11 = DemoElement(pos, 300, 320, 200, 160, 170, 180);
    demoelement12 = DemoElement(pos, 330, 350, 200, 170, 180, 190);
    

//    ofAddListener(ofEvents().mousePressed, demoelement3, &DemoElement::mouseReleased);

   ill =0;
    bg.load("/Users/Neeraj/Desktop/assets/bg5.png");
//    nav.load("/Users/Neeraj/Desktop/assets/nav_bg.png");
//    ofBackgroundHex(0xffffff);
    ofBackground(0, 0, 0);
    chart =1;
    /*
     The "panel" is a frame. This frame contains the displayed images, and the scroll bar.
     The scroll bar contains a "grip". The user can drag the grip with the mouse.
     */
    
    gap = 10;               // Distance between rectangles, and between rectangles and scroll bar
    margin =100;            // Distance between the edge of the screen and the panel frame
    scrollBarWidth = 10;
    
    
    // Now two rectangles, for the scroll bar and his grip placements
    // Coordinates are relative to the panel coordinates, not to the screen coordinates
    // This is a first initialisation, but we don't know many things about these placements at this state
    scrollBarRectangle = ofRectangle(0, 0, scrollBarWidth, 0);
    gripRectangle = ofRectangle(0, 0, scrollBarWidth, 0);
    
    isDraggingGrip = false; // true when the user is moving the grip
    isMouseOverGrip = false; // true when the mouse is over the grip
    
    /*
     Now initialisations for the displayed images
     */
    
    // Load 10 images
//    vector<ofImage> baseImages;
//    baseImages.resize(10);
//    for (int i = 0; i < 10; ++i) {
//        baseImages[i].loadImage("/Users/Neeraj/Desktop/of_v0.9.8_osx_release/addons/ofxUI/Scrolling/" + ofToString(i + 1) + ".jpeg");
//    
//    }
//    imagesWidth = baseImages[0].getWidth();
//    imagesHeight = baseImages[0].getHeight();
//    
//    // And create 33 images to display
//    for (int i = 0; i < 15; ++i) {
//        images.push_back(baseImages[i % 10]);
//        rectangles.push_back(ofRectangle(0, 0, imagesWidth, imagesHeight));
//    }
    
//    ofBackground(127);
    
    
    
//    frame = 4;
    screenNumber = 0;
    numClicks = 0;
    startTime = ofGetElapsedTimeMillis();
    interpolate = 0;
//    growTime = 2000;
//    
//    
//    ofLoadImage(imageTexture, "/Users/Neeraj/Desktop/assets/bg.png");
//    ofLoadImage(navtexture, "/Users/Neeraj/Desktop/assets/whbg.png");
//    
//    ofLoadImage(energyTexture, "/Users/Neeraj/Desktop/assets/whbg.png");
    
    
    points[0].x = 0; points[0].y = 0;
    points[1].x = 2560; points[1].y = 0;
    points[2].x = 2560; points[2].y = 1600;
    points[3].x = 0; points[3].y = 1600;
    
    
    points[4].x = 0; points[4].y = 0;
    points[5].x = 200; points[5].y = 0;
    points[6].x = 200; points[6].y = 1080;
    points[7].x = 0; points[7].y = 1080;
    
    points[8].x = 900; points[8].y = 100;
    points[9].x = 1200; points[9].y = 100;
    points[10].x = 1200; points[10].y = 300;
    points[11].x = 900; points[11].y = 300;
    
    ofImage img;
    img.load("/Users/Neeraj/Desktop/assets/nav-hom.png");
    ofImage h;
    h.load("/Users/Neeraj/Desktop/assets/cancel.png");
    
    ofImage ic_demo;
    ic_demo.load("/Users/Neeraj/Desktop/assets/demo.png");
    
    ofImage ic_climate;
    ic_climate.load("/Users/Neeraj/Desktop/assets/climate.png");
    
    ofImage ic_info;
    ic_info.load("/Users/Neeraj/Desktop/assets/madeira.png");
    
    ofImage ic_energy;
    ic_energy.load("/Users/Neeraj/Desktop/assets/energy.png");
    
    
    ofImage ic_back;
    ic_back.load("/Users/Neeraj/Desktop/assets/back.png");
    
    theme =  new ofxDatGuiThemeWireframe();
    themesmoke =  new ofxDatGuiThemeIcons();

    // instantiate a basic button and a toggle button
    
    home = new ofxDatGuiButton("",h);

    button = new ofxDatGuiButton("",img);

    back = new ofxDatGuiButton("",ic_back);

    hdemo = new Button("",ic_demo );
    hdemo->setHeight(500);
    cout <<"hdemo Height" <<hdemo->getHeight();
    hclimate = new ofxDatGuiButton("",ic_climate );
    hinfo = new ofxDatGuiButton("",ic_info );
    henergy = new ofxDatGuiButton("",ic_energy );
    
    testing =  new Button("Hello");
    
    
    
    ofImage real_temp;
    real_temp.load("/Users/Neeraj/Desktop/assets/tempbutt.png");
    
    ofImage real_press;
    real_press.load("/Users/Neeraj/Desktop/assets/pressbut.png");
    
    ofImage real_wind;
    real_wind.load("/Users/Neeraj/Desktop/assets/windbutt.png");
    
    ofImage cl_re;
    cl_re.load("/Users/Neeraj/Desktop/assets/clreal.png");
    ofImage cl_ov;
    cl_ov.load("/Users/Neeraj/Desktop/assets/clover.png");
    
    
    ofImage inb1;
    inb1.load("/Users/Neeraj/Desktop/assets/infob1.png");
    
    ofImage inb2;
    inb2.load("/Users/Neeraj/Desktop/assets/infob2.png");
    
    ofImage inb3;
    inb3.load("/Users/Neeraj/Desktop/assets/infob3.png");
    
    ofImage inb4;
    inb4.load("/Users/Neeraj/Desktop/assets/infob4.png");
    
    ofImage inb5;
    inb5.load("/Users/Neeraj/Desktop/assets/infob5.png");
    
    infob1 = new ofxDatGuiButton("",inb1);
    infob2 = new ofxDatGuiButton("",inb2);
    infob3 = new ofxDatGuiButton("",inb3);
    infob4 = new ofxDatGuiButton("",inb4);
    infob5 = new ofxDatGuiButton("",inb5);


    
    cl_over_temp = new ofxDatGuiButton("",real_temp);
    cl_over_press = new ofxDatGuiButton("",real_press);
    cl_over_wind = new ofxDatGuiButton("",real_wind);
    
    
    cl_over = new ofxDatGuiButton("",cl_ov);
    cl_real = new ofxDatGuiButton("",cl_re);
    cl_main = new ofxDatGuiButton("Main");
    cl_daily = new ofxDatGuiButton("daily");
    cl_hourly = new ofxDatGuiButton("Hourly");
    cl_pre = new ofxDatGuiButton("Precipitatio");
    cl_sea = new ofxDatGuiButton("", real_temp);
    cl_wind = new ofxDatGuiButton("", real_wind);
    cl_press = new ofxDatGuiButton("",real_press);
    
    
    en_over = new ofxDatGuiButton("", cl_ov);
    en_real = new ofxDatGuiButton("",cl_re);
    en_main = new ofxDatGuiButton("Main");
    en_daily = new ofxDatGuiButton("daily");
    en_bio = new ofxDatGuiButton("Biomass");
    en_hyd = new ofxDatGuiButton("Hydro");
    en_wind = new ofxDatGuiButton("Wind");
    en_thermal = new ofxDatGuiButton("Thermal");
    
    ofImage hvt;
    hvt.load("/Users/Neeraj/Desktop/assets/hvt.png");

    ofImage hvc;
    hvc.load("/Users/Neeraj/Desktop/assets/hvc.png");
    
    ofImage pvb;
    pvb.load("/Users/Neeraj/Desktop/assets/pvb.png");
    en_pcb = new ofxDatGuiButton("",pvb);
    en_hct = new ofxDatGuiButton("", hvt);
    en_hcc = new ofxDatGuiButton("",hvc);
    
    label1 = new ofxDatGuiButton("Demographics");

    label2 = new ofxDatGuiButton("Climate");

    label3 = new ofxDatGuiButton("Madeira Info");

    label4 = new ofxDatGuiButton("Energy");
   
    label1->setTheme(theme);
    label2->setTheme(theme);
    label3->setTheme(theme);
    label4->setTheme(theme);

    infob1->setTheme(themesmoke);
    infob2->setTheme(themesmoke);
    infob3->setTheme(themesmoke);
    infob4->setTheme(themesmoke);
    infob5->setTheme(themesmoke);

    cl_over_temp->setTheme(themesmoke);
    cl_over_press->setTheme(themesmoke);
    cl_over_wind->setTheme(themesmoke);

    cl_over->setTheme(themesmoke);
    cl_real->setTheme(themesmoke);
    cl_main->setTheme(theme);
    cl_daily->setTheme(theme);
    cl_hourly->setTheme(theme);
    cl_pre->setTheme(theme);
    
    cl_sea->setTheme(themesmoke);
    cl_wind->setTheme(themesmoke);
    cl_press->setTheme(themesmoke);
    
    en_over->setTheme(themesmoke);
    en_real->setTheme(themesmoke);
    en_main->setTheme(theme);
    en_daily->setTheme(theme);
    en_bio->setTheme(theme);
    en_hyd->setTheme(theme);
    en_wind->setTheme(theme);
    en_thermal->setTheme(theme);
    en_hcc->setTheme(themesmoke);
    en_hct->setTheme(themesmoke);
    en_pcb->setTheme(themesmoke);
    
    
    infob1->onButtonEvent(this, &ofApp::onButtonEvent);
    infob2->onButtonEvent(this, &ofApp::onButtonEvent);
    infob3->onButtonEvent(this, &ofApp::onButtonEvent);
    infob4->onButtonEvent(this, &ofApp::onButtonEvent);
    infob5->onButtonEvent(this, &ofApp::onButtonEvent);

    cl_over_temp->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_over_press->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_over_wind->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_over->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_real->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_main->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_daily->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_hourly->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_pre->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_sea->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_wind->onButtonEvent(this, &ofApp::onButtonEvent);
    cl_press->onButtonEvent(this, &ofApp::onButtonEvent);
    
    en_over->onButtonEvent(this, &ofApp::onButtonEvent);
    en_real->onButtonEvent(this, &ofApp::onButtonEvent);
    en_main->onButtonEvent(this, &ofApp::onButtonEvent);
    en_daily->onButtonEvent(this, &ofApp::onButtonEvent);
    en_bio->onButtonEvent(this, &ofApp::onButtonEvent);
    en_hyd->onButtonEvent(this, &ofApp::onButtonEvent);
    en_wind->onButtonEvent(this, &ofApp::onButtonEvent);
    en_thermal->onButtonEvent(this, &ofApp::onButtonEvent);
    en_hcc->onButtonEvent(this, &ofApp::onButtonEvent);
    en_hct->onButtonEvent(this, &ofApp::onButtonEvent);
    en_pcb->onButtonEvent(this, &ofApp::onButtonEvent);
    
    button->setTheme(themesmoke);
    hdemo->setTheme(themesmoke);
    hclimate->setTheme(themesmoke);
    hinfo->setTheme(themesmoke);
    henergy->setTheme(themesmoke);
    
    home->setTheme(themesmoke);
    back->setTheme(themesmoke);

    
    //toggle = new ofxDatGuiToggle("TOGGLE FULLSCREEN", false);
    
    
    
    
    // position the components in the middle of the screen //
    positionButtons();
    
    // and register to listen for events //
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    //    toggle->onButtonEvent(this, &ofApp::onButtonEvent);
    hclimate->onButtonEvent(this, &ofApp::onButtonEvent);
    hinfo->onButtonEvent(this, &ofApp::onButtonEvent);
    henergy->onButtonEvent(this, &ofApp::onButtonEvent);
    hdemo->onButtonEvent(this, &ofApp::onButtonEvent);

    
    home->onButtonEvent(this, &ofApp::onButtonEvent);
    back->onButtonEvent(this, &ofApp::onButtonEvent);

    
}

//--------------------------------------------------------------
void ofApp::update(){
    scroll.update();


    demoelement.update();
    demoelement2.update();
    demoelement3.update();
    demoelement4.update();
    demoelement5.update();
    demoelement7.update();
    demoelement8.update();
    demoelement9.update();
    demoelement10.update();
    demoelement11.update();
    demoelement12.update();
    demoelement6.update();


    button->update();
    home->update();
    back->update();
    if (frame ==0) {
    hdemo->update();
    hclimate->update();
    henergy->update();
    hinfo->update();
    }
    if (frame ==2) {
    cl_over->update();

    cl_real->update();
        if (screenNumber == 221) {
            weatherRealTime.updateTemp();

        }
        if (screenNumber == 223) {
            weatherRealTime2.updatePrec();
            
        }
        if (screenNumber == 222) {
            weatherRealTime1.updatePress();
            
        }

        if (screenNumber == 224) {
            cl_over_wind->update();
            cl_over_temp->update();
            cl_over_press->update();
            weatherOverview.updateTemp();
            
        }
        if (screenNumber == 225) {
            weatherOverview1.updatePrec();
            cl_over_wind->update();
            cl_over_temp->update();
            cl_over_press->update();



            
        }
        if (screenNumber == 226) {
            weatherOverview2.updatePress();
            cl_over_wind->update();
            cl_over_temp->update();
            cl_over_press->update();
            
        }

        if (screenNumber == 221) {
            cl_sea->update();
            cl_press->update();
            cl_wind->update();


        }
        if (screenNumber == 222) {
            cl_sea->update();
            cl_press->update();
            cl_wind->update();

        }
        if (screenNumber == 223) {
            cl_sea->update();
            cl_press->update();
            cl_wind->update();
        }
    
    cl_main->update();
    cl_daily->update();
    cl_hourly->update();
    cl_pre->update();
        
    }
    if (frame == 4) {
        en_over->update();
        en_real->update();
        en_hct->update();
        en_hcc->update();
        en_pcb->update();
    }
    if (frame == 3) {
        infob1->update();
        infob2->update();
        infob3->update();
        infob4->update();
        infob5->update();

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    scroll = Scroll();

    
//    ofClear(255,255,255); // clears the background
    if (frame == 0) {
//        ofClear(255,255,255);
        ofImage img;
        img.load("/Users/Neeraj/Desktop/assets/bg5.png");

//        bg.resize(100,1000);

        img.draw(0,0);
        ofImage tit;
        tit.load("/Users/Neeraj/Desktop/assets/title.png");
        
        ofImage et;
        et.load("/Users/Neeraj/Desktop/assets/et.png");
        
        
        ofImage infot;
        infot.load("/Users/Neeraj/Desktop/assets/infot.png");
        
        ofImage clt;
        clt.load("/Users/Neeraj/Desktop/assets/clt.png");
        ofImage dt;
        dt.load("/Users/Neeraj/Desktop/assets/dt.png");
        //        bg.resize(100,1000);
        
        tit.draw(460,150);
        dt.draw(150,450);
        clt.draw(450,450);
        et.draw(700,450);
        infot.draw(900,450);

        //        dataPoint.display();

        
        ofPoint pos1;
        pos1.x = 400;
        pos1.y = 100;

//        home->draw(1, 200, 200);
//        back->draw(1, 200, 200);
        

        
        
        hdemo->draw(1, 200,200);
        hclimate->draw(1, 200, 110);
        henergy->draw(1, 200,200);
        hinfo->draw(1, 200,100);

        
//        cam.begin();
//        //uncomment these 3 lines to understand how nodes are moving
//        // baseNode.draw();
//        //childNode.draw();
//        //grandChildNode.draw();
//        if(line.size()<200)
//            line.draw();
//        cam.end();
    }
    
    else if (frame == 3) {
        
//        ofClear(255,255,255);
        ofImage img;
        img.load("/Users/Neeraj/Desktop/assets/bg5.png");
        img.draw(0,0);
        
        ofImage infot;
        infot.load("/Users/Neeraj/Desktop/assets/infotitle.png");
        infot.draw(100,35);
        home->draw(1,200,200);
        infob1->draw(1, 200,100);
        infob2->draw(1, 200,100);
        infob3->draw(1, 200,100);
        infob4->draw(1, 200,100);
        infob5->draw(1, 200,100);

        scroll.display();
        
        
    }
    
    //Climate
     if (frame == 2) {
        
        ofImage img;
        img.load("/Users/Neeraj/Desktop/assets/bg5.png");

        img.draw(0,0);
//        weatherRealTime.displayTemp();
//        weatherRealTime.displayTempText();


         ofImage infot;
         infot.load("/Users/Neeraj/Desktop/assets/cltitle.png");
         infot.draw(100,35);
         home->draw(1, 200, 200);
        cl_over->draw(1,200,200);
        cl_real->draw(1,200,200);
        
       
        if (screenNumber == 221) {
      
            cl_sea->draw(1,200,200);
            cl_wind->draw(1,200,200);
            cl_press->draw(1,200,200);
            weatherRealTime.displayTemp();
            weatherRealTime.displayTempText();
////            avgSeaSurface.draw("line", pos2, test3);
        }
        if (screenNumber == 222) {
           
            cl_sea->draw(1,200,200);
            cl_wind->draw(1,200,200);
            cl_press->draw(1,200,200);
            weatherRealTime1.displayPress();
            weatherRealTime1.displayPressText();
        

        }
        if (screenNumber == 223) {
            
            
            cl_sea->draw(1,200,200);
            cl_wind->draw(1,200,200);
            cl_press->draw(1,200,200);
            weatherRealTime2.displayPrec();
            weatherRealTime2.displayPrecText();
            
        }
        
        if (screenNumber == 224) {
            
            cl_over_temp->draw(1,200,200);
            cl_over_press->draw(1,200,200);
            cl_over_wind->draw(1,200,200);
            weatherOverview.displayTemp();
            weatherOverview.displayTempText();
            
          
            
        }
        if (screenNumber == 225) {
            
            cl_over_temp->draw(1,200,200);
            cl_over_press->draw(1,200,200);
            cl_over_wind->draw(1,200,200);
            weatherOverview1.displayPrec();
            weatherOverview1.displayPrecText();
            
 
            
        }
         if (screenNumber == 226) {
             
             cl_over_temp->draw(1,200,200);
             cl_over_press->draw(1,200,200);
             cl_over_wind->draw(1,200,200);
             weatherOverview2.displayPress();
             weatherOverview2.displayPressText();
             
             
         }
    }

    //Demographics
    
     if (frame ==1) {

//        ofClear(255,255,255);
        ofImage img;
        img.load("/Users/Neeraj/Desktop/assets/bg5.png");
//         bg.resize(100,1000);

        img.draw(0,0);

        home->draw(1, 200, 200);
         
         ofImage infot;
         infot.load("/Users/Neeraj/Desktop/assets/demotitle.png");
         infot.draw(100,35);

         demoDisplay.displayTextData();
        demoelement.display();
        demoelement2.display();

        demoelement3.display();
        demoelement4.display();
        demoelement5.display();
        demoelement6.display();
        demoelement7.display();
        demoelement8.display();
        demoelement9.display();
        demoelement10.display();
        demoelement11.display();
        demoelement12.display();

       
    }
    
    //Energy
     if (frame ==4) {

         
         ofImage infot;
         infot.load("/Users/Neeraj/Desktop/assets/etitle.png");
         infot.draw(100,35);
        ofImage img;
        img.load("/Users/Neeraj/Desktop/assets/bg5.png");
//         bg.resize(100,1000);

        img.draw(0,0);
         ofImage lowpercent;

         lowpercent.load("/Users/Neeraj/Desktop/assets/0.png");
         lowpercent.draw(400, 480);
         
         ofImage highpercent;
         
         highpercent.load("/Users/Neeraj/Desktop/assets/100.png");
         highpercent.draw(400, 220);

         en_hct->draw(1, 200, 200);
         en_pcb->draw(1, 200, 200);
         en_hcc->draw(1, 200, 200);
         
         en_over->draw(1,200,200);
         en_real->draw(1,200,200);

          if (screenNumber == 41) {
        energyDisplay.display();
              ofImage etext1;
              etext1.load("/Users/Neeraj/Desktop/assets/etext2.png");
              etext1.draw(450, 150);

          }
         if (screenNumber == 42) {
             ofImage etext;
             etext.load("/Users/Neeraj/Desktop/assets/etext.png");
             etext.draw(450, 150);
         energyDisplay1.display();
         }
         if (screenNumber == 43) {
             ofImage etext2;
             etext2.load("/Users/Neeraj/Desktop/assets/etext3.png");
             etext2.draw(450, 150);

         energyDisplay2.display();
         }
        label4->draw();
        home->draw(1, 200, 200);
//        back->draw(1, 200, 200);
        
        if (screenNumber == 413) {

            en_hyd->draw();
            en_thermal->draw();
            en_wind->draw();
            en_bio ->draw();
            
            
        }
        if (screenNumber == 411) {
            
            en_hyd->draw();
            en_thermal->draw();
            en_wind->draw();
            en_bio ->draw();
          
            
        }
        if (screenNumber == 412) {
            
            en_hyd->draw();
            en_thermal->draw();
            en_wind->draw();
            en_bio ->draw();
            
            ofPoint pos2;
            pos2.x = 400;
            pos2.y = 0;
            avgSeaSurface.draw("line", pos2, test);
            
        }
        if (screenNumber == 415) {
            en_hyd->draw();
            en_thermal->draw();
            en_wind->draw();
            en_bio ->draw();
            
            ofPoint pos2;
            pos2.x = 400;
            pos2.y = 0;
            avgSeaSurface.draw("line", pos2, test1);
            
        }
       
        
     

    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    if (scroll.isScrollBarVisible) {
        ofRectangle r = scroll.gripRectangle;
        r.translate(margin, margin); // This translation because the coordinates of the grip are relative to the panel, but the mouse position is relative to the screen
        scroll.isMouseOverGrip = r.inside(x, y);
    } else {
        scroll.isMouseOverGrip = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (scroll.isScrollBarVisible && scroll.isDraggingGrip) {
        
        // Move the grip according to the mouse displacement
        int dy = y - scroll.mousePreviousY;
        scroll.mousePreviousY = y;
        scroll.gripRectangle.y += dy;
        
        // Check if the grip is still in the scroll bar
        if (scroll.gripRectangle.y < 0) {
            scroll.gripRectangle.y = 0;
        }
        if (scroll.gripRectangle.getBottom() > scroll.scrollBarRectangle.getBottom()) {
            scroll.gripRectangle.y = scroll.scrollBarRectangle.getBottom() - scroll.gripRectangle.height;
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // Check if the click occur on the grip
    
    if (scroll.isScrollBarVisible) {
        ofRectangle r = scroll.gripRectangle;
        r.translate(scroll.margin, scroll.margin); // This translation because the coordinates of the grip are relative to the panel, but the mouse position is relative to the screen
        if (r.inside(x, y)) {
            scroll.isDraggingGrip = true;
            scroll.mousePreviousY = y;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    scroll.isDraggingGrip = false;
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
    // Place the grip at the top of the scroll bar if the size of the panel change
    scroll.gripRectangle.y = 0;
    
}


//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    // we have a couple ways to figure out which button was clicked //
    
    // we can compare our button pointer to the target of the event //
    if (e.target == hdemo){
        ofClear(ofColor::lightGray);

        frame =1;
        
        
    }
    if (e.target == home){
        ofClear(ofColor::lightGray);
        
        frame =0;
        
        
    }

    
    if (e.target == hclimate){
        ofClear(ofColor::lightGray);

        frame =2;
//        weatherRealTime.tempPolyline.clear();
        screenNumber = 221;

    }
    
    if (e.target == henergy){
        ofClear(ofColor::lightGray);
        screenNumber = 400;

        frame =4;
    }
    
    if (e.target == hinfo){
        ofClear(ofColor::lightGray);

        frame =3;
    }
    if (e.target == en_over){
        ofClear(ofColor::lightGray);
        screenNumber = 400;


        cout <<"Energy Overview CLicked" <<"   Frame   "<< 4;
        frame =4;
    }
    if (e.target == en_hcc){
        frame =4;
        screenNumber = 41;
    }if (e.target == en_hct){
        frame =4;
        screenNumber = 42;

    }if (e.target == en_pcb){
        frame =4;
        screenNumber = 43;

    }
    
    if (e.target == en_real){
        frame =4;
        screenNumber = 411;

    }
    if (e.target == en_hyd){
        frame =4;
        screenNumber = 412;

    } if (e.target == en_wind){
        frame =4;
        screenNumber = 413;

    } if (e.target == en_bio){
        frame =4;
        screenNumber = 414;

    } if (e.target == en_thermal){
        frame =4;
        screenNumber = 415;

    }
    
    if (e.target == button){
        ofClear(ofColor::lightGray);

        frame =0;
    }
    if (e.target == cl_real) {
        
        cout<<"button" << e.target;
        screenNumber = 221;
        frame =2;
//        cout<<"Frame"<<frame;
    }
    if (e.target == cl_over) {
        cout<<"button" << e.target;
        frame =2;
        screenNumber = 224;
//        cout<<"Frame"<<frame;
        cout <<"\nscreenNumber" <<screenNumber;

    }
    if (e.target == cl_over_temp) {
        cout<<"button" << e.target;
        frame =2;
        screenNumber = 224;
//        cout<<"Frame"<<frame;
        cout <<"\nscreenNumber" <<screenNumber;

    }if (e.target == cl_over_press) {
        cout<<"button" << e.target;
        frame =2;
        screenNumber = 225;
//        cout<<"Frame"<<frame;
        cout <<"\nscreenNumber" <<screenNumber;

    }
    if (e.target == cl_over_wind) {
        cout<<"button" << e.target;
        screenNumber = 226;
        frame =2;
        cout <<"\nscreenNumber" <<screenNumber;


//        cout<<"Frame"<<frame;
    }
    
    if (e.target == cl_sea) {
        cout<<"button" << e.target;
        screenNumber = 221;
        frame =2;
        cout <<"\nscreenNumber" <<screenNumber;

        cout<<"Frame"<<frame;
    }if (e.target == cl_press) {
        cout<<"button" << e.target;
        screenNumber = 222;
        frame =2;
        cout <<"\nscreenNumber" <<screenNumber;
//        cout<<"Frame"<<frame;
    }if (e.target == cl_wind) {
        cout<<"button" << e.target;
        screenNumber = 223;
        frame =2;
        cout <<"\nscreenNumber" <<screenNumber;


//        cout<<"Frame"<<frame;
    }
    
    if (e.target == infob1) {
        ofImage img;
        //    cout<<"cliecked";
        
        img.load("/Users/Neeraj/Desktop/assets/text.png");
        //    baseImages.push_back(img);
        scroll.updateContent(img);
        
    }
    if (e.target == infob2) {
        ofImage img;
        //    cout<<"cliecked";
        
        img.load("/Users/Neeraj/Desktop/assets/text2.png");
        //    baseImages.push_back(img);
        scroll.updateContent(img);
        
    }if (e.target == infob3) {
        ofImage img;
        //    cout<<"cliecked";
        
        img.load("/Users/Neeraj/Desktop/assets/text3.png");
        //    baseImages.push_back(img);
        scroll.updateContent(img);
        
    }if (e.target == infob4) {
        ofImage img;
        //    cout<<"cliecked";
        
        img.load("/Users/Neeraj/Desktop/assets/text4.png");
        //    baseImages.push_back(img);
        scroll.updateContent(img);
        
    }if (e.target == infob5) {
        ofImage img;
        //    cout<<"cliecked";
        
        img.load("/Users/Neeraj/Desktop/assets/text5.png");
        //    baseImages.push_back(img);
        scroll.updateContent(img);
        
    }
}

void ofApp::positionButtons()
{
    home->setPosition(1150,25);
    back->setPosition(0,50);

    hdemo->setPosition(150,350);
    hclimate->setPosition(450,350);
    hinfo->setPosition(900,350);
    henergy->setPosition(700,350);
    cl_over->setPosition(400, 50);
    cl_real->setPosition(650, 50);

    
    en_over->setPosition(450, 50);
    en_real->setPosition(700, 50);
    
//    en_bio = new ofxDatGuiButton("Biomass");
//    en_bio = new ofxDatGuiButton("Hydro");
//    en_bio = new ofxDatGuiButton("Wind");
//    en_bio = new ofxDatGuiButton("Thermal");
//    en_pcb = new ofxDatGuiButton("Primary vs Bought");
//    en_hct = new ofxDatGuiButton("Hydro VS Thermal");
//    en_hcc = new ofxDatGuiButton("House Vs Commercial");
    
    en_bio->setPosition(100, 450);
    
    en_hyd->setPosition(400,450);
    
    en_thermal->setPosition(1000, 450);
    en_wind->setPosition(700, 450);
    
    
    en_pcb->setPosition(750,550);
    
    en_hcc->setPosition(600, 550);
    en_hct->setPosition(450, 550);

    cl_pre->setPosition(100, 450);
    
    cl_press->setPosition(400,550);
    
    cl_sea->setPosition(600, 550);
    cl_wind->setPosition(800, 550);
    
    cl_over_press->setPosition(400,550);
    
    cl_over_temp->setPosition(600, 550);
    cl_over_wind->setPosition(800, 550);
    cl_hourly->setPosition(800, 150);
    cl_daily->setPosition(550, 150);
   // cout <<"ofGetHeight"<<ofGetHeight();
    
   cl_main->setPosition(300, 150);
    
    label1->setPosition(75, 0);

    label2->setPosition(75, 0);
    label3->setPosition(75, 0);
    label4->setPosition(75, 0);
    infob1->setPosition(75, 200);
    infob2->setPosition(75, 300);
    infob3->setPosition(75, 400);
    infob4->setPosition(75, 500);
    infob5->setPosition(75, 600);

    
    //    toggle->setPosition(button->getX(), button->getY() + button->getHeight() + 20);
}



