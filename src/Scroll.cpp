//
//  Scroll.cpp
//  Scrolling
//
//  Created by Neeraj Verma on 19/05/17.
//
//

#include "Scroll.h"


Scroll::Scroll() {
    
    
    
    
}

void Scroll::setup(int height, int width, vector<ofImage> & baseImages) {
    gap = 10;               // Distance between rectangles, and between rectangles and scroll bar
    margin = 20;            // Distance between the edge of the screen and the panel frame
    scrollBarWidth = 20;
    
    panelWidth = width;
    panelHeight=height;
    
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
//    baseImages = images;
//    baseImages.resize(10);
//    for (int i = 0; i < 10; ++i)
//        baseImages[i].loadImage("/Users/Neeraj/Desktop/of_v0.9.8_osx_release/addons/ofxUI/Scrolling/" + ofToString(i + 1) + ".jpg");
    imagesWidth = baseImages[0].getWidth();
    imagesHeight = baseImages[0].getHeight();
    
    // And create 33 images to display
    for (int i = 0; i < baseImages.size(); ++i) {
        images.push_back(baseImages[i % 10]);
        rectangles.push_back(ofRectangle(0, 0, imagesWidth, imagesHeight));
    }


}

void Scroll::update(){
    // The size of the panel. All the screen except margins
  
    
    
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
void Scroll::display() {
    
    ofPushMatrix();
    ofTranslate(margin, margin, 0);
    
    ofRectangle r;
    ofImage img;
    ofSetColor(255);
    
    for (int i = 0; i < images.size(); ++i) {
        
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

    
}

void Scroll::updateContent(vector<ofImage> & baseImages){
    baseImages.resize(10);
    //    for (int i = 0; i < 10; ++i)
    //        baseImages[i].loadImage("/Users/Neeraj/Desktop/of_v0.9.8_osx_release/addons/ofxUI/Scrolling/" + ofToString(i + 1) + ".jpg");
    imagesWidth = baseImages[0].getWidth();
    imagesHeight = baseImages[0].getHeight();
    
    // And create 33 images to display
    for (int i = 0; i < 33; ++i) {
        images.push_back(baseImages[i % 10]);
        rectangles.push_back(ofRectangle(0, 0, imagesWidth, imagesHeight));
    }

}
