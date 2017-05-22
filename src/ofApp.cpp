#include "ofApp.h"

void ofApp::setup(){
    
    frame = 2;
    screenNumber = 0;
    
    bg.load("/Users/Neeraj/Desktop/assets/bg.png");
    nav.load("/Users/Neeraj/Desktop/assets/nav_bg.png");
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
    vector<ofImage> baseImages;
    baseImages.resize(10);
    for (int i = 0; i < 10; ++i) {
        baseImages[i].loadImage("/Users/Neeraj/Desktop/of_v0.9.8_osx_release/addons/ofxUI/Scrolling/" + ofToString(i + 1) + ".jpeg");
    
    }
    imagesWidth = baseImages[0].getWidth();
    imagesHeight = baseImages[0].getHeight();
    
    // And create 33 images to display
    for (int i = 0; i < 15; ++i) {
        images.push_back(baseImages[i % 10]);
        rectangles.push_back(ofRectangle(0, 0, imagesWidth, imagesHeight));
    }
    
//    ofBackground(127);
    
    
    
    frame = 4;
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
    img.load("/Users/Neeraj/Desktop/assets/home.png");
    ofImage h;
    h.load("/Users/Neeraj/Desktop/assets/home.png");
    
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
    themesmoke =  new ofxDatGuiThemeSmoke();

    // instantiate a basic button and a toggle button
    
    home = new ofxDatGuiButton("",h);

    button = new ofxDatGuiButton("",img);

    back = new ofxDatGuiButton("",ic_back);

    hdemo = new ofxDatGuiButton("",ic_demo );
    hdemo->setHeight(500);
    hclimate = new ofxDatGuiButton("",ic_climate );
    hinfo = new ofxDatGuiButton("",ic_info );
    henergy = new ofxDatGuiButton("",ic_energy );
    
    testing =  new Button("Hello");
    
    //    ofxDatGuiButton* en_over;
    //    ofxDatGuiButton* en_real;
    //
    //    ofxDatGuiButton* en_main;
    //    ofxDatGuiButton* en_daily;
    //    ofxDatGuiButton* en_monthly;
    //    ofxDatGuiButton* en_bio;
    //    ofxDatGuiButton* en_hyd;
    //    ofxDatGuiButton* en_wind;
    //    ofxDatGuiButton* en_thermal;
    
    
    
    cl_over = new ofxDatGuiButton("Overview");
    cl_real = new ofxDatGuiButton("Real Time");
    cl_main = new ofxDatGuiButton("Main");
    cl_daily = new ofxDatGuiButton("daily");
    cl_hourly = new ofxDatGuiButton("Hourly");
    cl_pre = new ofxDatGuiButton("Precipitatio");
    cl_sea = new ofxDatGuiButton("Sea Surface temp");
    cl_wind = new ofxDatGuiButton("Wind");
    cl_press = new ofxDatGuiButton("Pressure");
    
    
    en_over = new ofxDatGuiButton("Overview");
    en_real = new ofxDatGuiButton("Real Time");
    en_main = new ofxDatGuiButton("Main");
    en_daily = new ofxDatGuiButton("daily");
    en_bio = new ofxDatGuiButton("Biomass");
    en_hyd = new ofxDatGuiButton("Hydro");
    en_wind = new ofxDatGuiButton("Wind");
    en_thermal = new ofxDatGuiButton("Thermal");
    en_pcb = new ofxDatGuiButton("Primary vs Bought");
    en_hct = new ofxDatGuiButton("Hydro VS Thermal");
    en_hcc = new ofxDatGuiButton("House Vs Commercial");
    
    label1 = new ofxDatGuiButton("Demographics");

    label2 = new ofxDatGuiButton("Climate");

    label3 = new ofxDatGuiButton("Madeira Info");

    label4 = new ofxDatGuiButton("Energy");
   
    label1->setTheme(themesmoke);
    label2->setTheme(themesmoke);
    label3->setTheme(themesmoke);
    label4->setTheme(themesmoke);

    
    cl_over->setTheme(theme);
    cl_real->setTheme(theme);
    cl_main->setTheme(theme);
    cl_daily->setTheme(theme);
    cl_hourly->setTheme(theme);
    cl_pre->setTheme(theme);
    cl_sea->setTheme(theme);
    cl_wind->setTheme(theme);
    cl_press->setTheme(theme);
    
    en_over->setTheme(theme);
    en_real->setTheme(theme);
    en_main->setTheme(theme);
    en_daily->setTheme(theme);
    en_bio->setTheme(theme);
    en_hyd->setTheme(theme);
    en_wind->setTheme(theme);
    en_thermal->setTheme(theme);
    en_hcc->setTheme(theme);
    en_hct->setTheme(theme);
    en_pcb->setTheme(theme);
    
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
    
    button->setTheme(theme);
    hdemo->setTheme(theme);
    hclimate->setTheme(theme);
    hinfo->setTheme(theme);
    henergy->setTheme(theme);
    
    home->setTheme(theme);
    back->setTheme(theme);

    
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
    
    button->update();
    home->update();
    back->update();
    if (frame ==0) {
    hdemo->update();
    hclimate->update();
    henergy->update();
    hinfo->update();
    }
    
    cl_over->update();
    cl_real->update();
    cl_main->update();
    cl_daily->update();
    cl_hourly->update();
    cl_pre->update();
    cl_sea->update();
    cl_wind->update();
    cl_press->update();
        
    
    if (frame == 1) {
    // The size of the panel. All the screen except margins
      
    panelWidth = ofGetWidth() - margin * 2 -200;
    panelHeight = ofGetHeight() - margin * 2-200;
    
    // Space available for displayed rectangles
    int availableWidth = panelWidth - scrollBarWidth - gap;
    
    // Coordinates for first rectangle
    int x = 0;
    int y = 0;
    
    ofRectangle * r;
    
    // Place the rectangles in rows and columns. A row must be smaller than availableWidth
    // After this loop, we know that the rectangles fits the panel width. But the available panel height can be to small to display them all.
    for (int i = 0; i < images.size(); ++i) {
        
        r = &rectangles[i];
        r->x = x;
        r->y = y;
        
        // Now compute the next rectangle position
        x += imagesWidth + gap;
        if (x + imagesWidth > availableWidth) {
            scrollBarRectangle.x = r->getRight() + gap; // Adjust the scroll bar position to draw it just at the right
            x = 0;
            y += imagesHeight + gap;
        }
        
    }
    
    gripRectangle.x = scrollBarRectangle.x; // Also adjust the grip x coordinate
    
    int contentHeight = r->getBottom(); // Total height for all the rectangles
    // TODO: take care if colors.size() == 0
    
    if (contentHeight > panelHeight) {
        /* In the case where there's not enough room to display all the rectangles */
        
        /* First, the scroll bar */
        
        // Show the scroll bar
        isScrollBarVisible = true;
        // Set the scroll bar height to fit the panel height
        scrollBarRectangle.height = panelHeight;
        
        
        /* Now, the grip */
        
        // This ratio is between 0 and 1. The smaller it is, the smaller the grip must be.
        // If its value is 0.5, for example, it means that there's only half of the room in the panel to display all the rectangles.
        float gripSizeRatio = (float)panelHeight / (float)contentHeight;
        
        // Compute the height of the grip, according to this ratio
        gripRectangle.height = panelHeight * gripSizeRatio;
        
        /* Now, the vertical scrolling to add to the rectangles position */
        
        // this ratio, between 0 and 1, tell us the amount of scrolling to add if the grip is at the bottom of the scroll bar
        float scrollMaxRatio = 1 - gripSizeRatio;
        
        // this ration tell us how much the grip is down. If 0, the grip is at the top of the scroll bar.
        // if 1, the grip is at the bottom of the scroll bar
        float gripYRatio = gripRectangle.y / (scrollBarRectangle.height - gripRectangle.height);
        
        // Now, the amount of scrolling to do, according to the twos previous ratios
        float contentScrollRatio = gripYRatio * scrollMaxRatio;
        
        // And now the scrolling value to add to each rectangle y coordinate
        contentScrollY = contentHeight * contentScrollRatio;
        
    } else {
        /* In the case where there's enough room to display all the rectangles */
        
        isScrollBarVisible = false;
        contentScrollY = 0;
        
    }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofClear(255,255,255); // clears the background


    if (frame == 0) {
        ofClear(255,255,255);
        bg.draw(0,0);
    
//        bg.draw(0,0);
//        nav.draw(0,0);
        home->draw(1, 200, 200);
        back->draw(1, 200, 200);
        demoelement.display();


        
        //        imageTexture.bind();
        // imageTexture.draw(points[0], points[1], points[2], points[3]);
        ////        imageTexture.unbind();
        //        ofImage img;
        //        img.load("/Users/Neeraj/Desktop/assets/title.png");
        //        img.draw(100,10);
        
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
    
    if (frame == 3) {
        
        ofClear(255,255,255);/* First draw the rectangles */
            // Add a translation to bring the panel to the good position
        ofImage bg;
        bg.load("/Users/Neeraj/Desktop/assets/bg3.png");
        bg.draw(0,0);
        label3->draw();
    ofPushMatrix();
    ofTranslate(margin, margin, 0);
    
    ofRectangle r;
    ofImage img;
    ofSetColor(255);
    
    for (int i = 0; i < images.size()-10; ++i) {
        
        r = rectangles[i];        // the rectangle position in the panel
        r.y -= contentScrollY;    // adjust this position according to the scrolling
        img = images[i];          // image to display. OF don't copy big objects like ofImage, so no need to use a pointor.
        
        if (r.y < 0) {
            if (r.getBottom() > 0) {
                // Exception 1: If a rectangle is cut at the top of the panel
                img.getTextureReference().drawSubsection(r.x, 0, r.width, imagesHeight + r.y, 0, - r.y, r.width, imagesHeight + r.y);
            }
        } else if (r.getBottom() > panelHeight) {
            if (r.y < panelHeight) {
                // Exception 2: If a rectangle is cut at the bottom of the panel.
                img.getTextureReference().drawSubsection(r.x, r.y, r.width, panelHeight - r.y, 0, 0, r.width, panelHeight - r.y);
            }
        } else {
            // Draw a rectangle in the panel
            images[i].draw(r.x, r.y);
        }
        
    }
    
    /* Draw the scroll bar, is needed */
    
    if (isScrollBarVisible) {
        ofSetColor(110);
        ofRect(scrollBarRectangle);
        if (isDraggingGrip || isMouseOverGrip) {
            ofSetColor(230);
        } else {
            ofSetColor(180);
        }
        ofRect(gripRectangle);
    }
    
    // Remove the translation added at the begining
    ofPopMatrix();
        home->draw(1, 200, 200);
        back->draw(1, 200, 200);

    }
    if (frame == 2) {
        
        ofClear(255,255,255);
        ofImage img;
        img.load("/Users/Neeraj/Desktop/assets/bg1.png");
        img.draw(0,0);
         label2->draw();
        home->draw(1, 200, 200);
        back->draw(1, 200, 200);
        cl_over->draw();
        cl_real->draw();
        if (screenNumber == 22) {
        cl_main->draw();
        cl_daily->draw();
        cl_hourly->draw();
        cl_pre->draw();
        cl_sea->draw();
        cl_wind->draw();
        cl_press->draw();
        
        }
        if (screenNumber == 21) {
        ofPoint pos;
        pos.x = 400;
        pos.y = 100;
        drawChart(1, test, pos);
        
        pos.x = 400;
        pos.y = 200;
        drawChart(1, test1, pos);
        pos.x = 400;
        pos.y = 0;
        drawChart(1, test1, pos);
        pos.x = 400;
        pos.y = 200;
        drawChart(1, test1, pos);
        }
        
    }
    if (frame ==1) {
        ofClear(255,255,255);
        ofImage bg;
        bg.load("/Users/Neeraj/Desktop/assets/bg5.png");
        bg.draw(0,0);

        home->draw(1, 200, 200);
        back->draw(1, 200, 200);
        label1->draw();


        
        ofPath circle;
        home->draw(1, 200, 200);
        back->draw(1, 200, 200);
        
        circle.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle.setFillColor(0x34495e);
        ofColor d;
        d.set(0, 0, 0);
        ofPoint pos;
        pos.x = ofGetWidth()/2-50;
        pos.y = ofGetHeight()/2-50;
        
        circle.moveTo(pos);
        circle.arc(pos, 200, 200, 0, 30);

        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle.draw();
        
        
        ofPath circle1;
        
        circle1.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle1.setFillColor(0x34495e);
      
        ofPoint pos1;
        pos1.x = ofGetWidth()/2-50+10;
        pos1.y = ofGetHeight()/2-50;
        circle1.moveTo(pos);
        circle1.arc(pos, 200, 200, 40, 80);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle1.draw();
        
  
        
        ofPath circle2;
        
        circle1.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle1.setFillColor(0x34495e);
        
        ofPoint pos2;
        pos2.x = ofGetWidth()/2-50+20;
        pos2.y = ofGetHeight()/2-50;
        circle2.moveTo(pos);
        circle2.arc(pos, 200, 200, 80, 100);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle2.draw();
        

        
        ofPath circle3;
        
        circle3.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle3.setFillColor(0x34495e);
        
        ofPoint pos3;
        pos3.x = ofGetWidth()/2-50+30;
        pos3.y = ofGetHeight()/2-50;
        circle3.moveTo(pos);
        circle3.arc(pos, 200, 200, 100, 130);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle3.draw();
        

        
        ofPath circle4;
        
        circle4.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle4.setFillColor(0x34495e);
        
        ofPoint pos4;
        pos4.x = ofGetWidth()/2-50+10+40;
        pos4.y = ofGetHeight()/2-50;
        circle4.moveTo(pos);
        circle4.arc(pos, 200, 200, 130, 180);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle4.draw();
        

        
        ofPath circle5;
        
        circle5.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle5.setFillColor(0x34495e);
        
        ofPoint pos5;
        pos5.x = ofGetWidth()/2-50+10;
        pos5.y = ofGetHeight()/2-50;
        circle5.moveTo(pos);
        circle5.arc(pos, 200, 200, 40, 80);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle5.draw();
        

        
        ofPath circle6;
        
        circle6.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle6.setFillColor(0x34495e);
        
        ofPoint pos6;
        pos6.x = ofGetWidth()/2-50+10;
        pos6.y = ofGetHeight()/2-50;
        circle6.moveTo(pos);
        circle6.arc(pos, 200, 200, 40, 80);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle6.draw();
        

        
        ofPath circle7;
       circle7.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle7.setFillColor(0x34495e);
        
        ofPoint pos7;
        pos7.x = ofGetWidth()/2-50+10;
        pos7.y = ofGetHeight()/2-50;
        circle7.moveTo(pos);
        circle7.arc(pos, 200, 200, 40, 80);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle7.draw();
        

        
        ofPath circle8;
        
        circle8.setArcResolution(1000);
        //circle.setCurveResolution(60);
        circle8.setFillColor(0x34495e);
        
        ofPoint pos8;
        pos8.x = ofGetWidth()/2-50+10;
        pos8.y = ofGetHeight()/2-50;
        circle8.moveTo(pos);
        circle8.arc(pos, 200, 200, 40, 80);
        
        //        circle.lineTo(pos);
        //        circle.moveTo(pos);
        circle8.draw();
        


        //draw

       
    }
    if (frame ==4) {
        ofImage bg;
        bg.load("/Users/Neeraj/Desktop/assets/bg5.png");
        bg.draw(0,0);
        testing->draw();
        label4->draw();
        home->draw(1, 200, 200);
        back->draw(1, 200, 200);
        cl_over->draw();
        cl_real->draw();
       
            cl_main->draw();
            cl_daily->draw();
            cl_hourly->draw();
            cl_pre->draw();
            cl_sea->draw();
            cl_wind->draw();
            cl_press->draw();
     

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
    if (frame ==1) {
    if (isScrollBarVisible) {
        ofRectangle r = gripRectangle;
        r.translate(margin, margin); // This translation because the coordinates of the grip are relative to the panel, but the mouse position is relative to the screen
        isMouseOverGrip = r.inside(x, y);
    } else {
        isMouseOverGrip = false;
    }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (frame ==1) {
    if (isScrollBarVisible && isDraggingGrip) {
        
        // Move the grip according to the mouse displacement
        int dy = y - mousePreviousY;
        mousePreviousY = y;
        gripRectangle.y += dy;
        
        // Check if the grip is still in the scroll bar
        if (gripRectangle.y < 0) {
            gripRectangle.y = 0;
        }
        if (gripRectangle.getBottom() > scrollBarRectangle.getBottom()) {
            gripRectangle.y = scrollBarRectangle.getBottom() - gripRectangle.height;
        }
        
    }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // Check if the click occur on the grip
    if (frame == 1) {
    if (isScrollBarVisible) {
        ofRectangle r = gripRectangle;
        r.translate(margin, margin); // This translation because the coordinates of the grip are relative to the panel, but the mouse position is relative to the screen
        if (r.inside(x, y)) {
            isDraggingGrip = true;
            mousePreviousY = y;
        }
    }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (frame ==1) {
    isDraggingGrip = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    if (frame ==1) {
    
    // Place the grip at the top of the scroll bar if the size of the panel change
    gripRectangle.y = 0;
    
    }
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
        frame =1;
    }
    
    if (e.target == hclimate){
        frame =2;
        screenNumber = 21;

    }
    
    if (e.target == henergy){
        frame =4;
    }
    
    if (e.target == hinfo){
        frame =3;
    }
    if (e.target == button){
        frame =0;
    }
    if (e.target == cl_real) {
        cout<<"button" << e.target;
        screenNumber = 22;
        frame =2;
        cout<<"Frame"<<frame;
    }
    if (e.target == cl_over) {
        cout<<"button" << e.target;
        frame =2;
        screenNumber = 21;
        cout<<"Frame"<<frame;
    }
    if (e.target == cl_press) {
        cout<<"button" << e.target;
        screenNumber = 222;
        cout<<"Frame"<<frame;
    }
    
    if (e.target == cl_sea) {
        cout<<"button" << e.target;
        screenNumber = 223;
        cout<<"Frame"<<frame;
    }if (e.target == cl_pre) {
        cout<<"button" << e.target;
        screenNumber = 224;
        cout<<"Frame"<<frame;
    }if (e.target == cl_wind) {
        cout<<"button" << e.target;
        screenNumber = 225;
        cout<<"Frame"<<frame;
    }
}

void ofApp::positionButtons()
{
    home->setPosition(0,0);
    back->setPosition(0,50);

    hdemo->setPosition(150,350);
    hclimate->setPosition(400,350);
    hinfo->setPosition(650,350);
    henergy->setPosition(900,350);
    cl_over->setPosition(400, 100);
    cl_real->setPosition(650, 100);
    
    cl_pre->setPosition(100, 450);
    
    cl_press->setPosition(400,450);
    
    cl_sea->setPosition(1000, 450);
    cl_wind->setPosition(700, 450);
    
    cl_hourly->setPosition(800, 150);
    cl_daily->setPosition(550, 150);
   // cout <<"ofGetHeight"<<ofGetHeight();
    
   cl_main->setPosition(300, 150);
    
    label1->setPosition(75, 0);

    label2->setPosition(75, 0);
    label3->setPosition(75, 0);
    label4->setPosition(75, 0);

    
    //    toggle->setPosition(button->getX(), button->getY() + button->getHeight() + 20);
}


void ofApp::drawChart(int type, int test[], ofPoint pos) {
    ofPoint chartSize = ofPoint(ofGetWidth() * 0.4, ofGetHeight() * 0.4);
    ofPoint chartPos = pos;
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
    
    //ofDrawBitmapStringHighlight(ofToString("Average Precipitation"), ofGetWidth()/2, 50);
    
  //  ofDrawBitmapStringHighlight(ofToString("Mean Monthly Sunshine Hours"), ofGetWidth()/2, 250+200);
    
    //ofDrawBitmapStringHighlight(ofToString(" Average Sea Surface Temperature "), ofGetWidth()/2, 350);
    
    
}

void ofApp::drawLineChart() {
    for(int i = 0; i < 10; i++){
        ofDrawLine(100+i*20 +300, 100, 100+i*20 +300, 300);
    }
    
}


void ofApp::drawPieChart() {
    float cx = 500; //center of image
    float cy = 500;
    float step = TWO_PI/64; //size of a slice in radians
    float r = 512; //outerRadius
    
    
    glBegin(GL_TRIANGLE_FAN);
    ofNoFill();
    ofSetColor(ofColor::red);
    
    
    for (float f=0; f<TWO_PI; f+=step) {
        //        glTexCoord2f(cx,cy);
        glVertex2f(500 ,500);
        //        glTexCoord2f(cx+cx*sin(f), cy+cy*cos(f));
        glVertex2f(r*sin(f), r*cos(f));
        //        glTexCoord2f(cx+cx*sin(f+step), cy+cy*cos(f+step));
        glVertex2f(r*sin(f+step), r*cos(f+step));
    }
    glEnd();
}
