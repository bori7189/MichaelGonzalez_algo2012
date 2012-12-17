//
//  timePos.cpp
//  emptyExample
//
//  Created by Michael Gonzalez on 12/17/12.
//
//

#include "timePos.h"

void timePos::setupPosSet(){
    
    int rnd = round(ofRandom(2, 5));
    for (int i = 0; i < rnd; i++) {
        ofPoint tempPos;
        tempPos.x = round(x + ofRandom(-50, 50));
        tempPos.y = round(y + ofRandom(-50, 50));
        //cout << "x: " << tempPos.x << " y : " << tempPos.y << endl;
        posSet.push_back(tempPos);
        ofColor tempColor;
        tempColor.set(ofRandom(150, 255), 0, ofRandom(20, 50));
        colorSet.push_back(tempColor);
        offset.push_back(ofRandom(360));
    }
    
    cout << "y : " << y;
    
    radius = ofRandom(2, 5);
    
    
}


void timePos::draw(){
    
        //ofNoFill();
        
    for (int i = 0; i<posSet.size(); i++) {
        ofSetColor(colorSet[i]);
        
        /*
        ofBeginShape();
        cout << "original x : " << x << " original y: " << y << endl;
        cout << "new x: " << posSet[i].x << " new y: " << posSet[i].y << endl;
        ofVertex(x, y);
        //ofVertex(ofGetWidth()/2, ofGetHeight()/2);
        ofVertex(posSet[i].x, posSet[i].y);
        ofEndShape();
         */
        ofPoint tempPos;
        tempPos.set(x, y);
        ofPoint tempRadius =  tempPos-posSet[i];

        
        tempPos.x = x + tempRadius.length() * cos (ofGetElapsedTimef()+ offset[i]);
        tempPos.y = y + tempRadius.length() * sin (ofGetElapsedTimef()+ offset[i] );
        ofCircle(tempPos.x, tempPos.y, 2);
    }
    
    

    
}