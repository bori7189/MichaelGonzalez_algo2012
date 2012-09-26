//
//  polygon.cpp
//  emptyExample
//
//  Created by Michael Gonzalez on 9/24/12.
//
//

#include "polygon.h"
//#define totalNum = 20
poly::poly(int _refPos){
    refPos = _refPos;
    pos.x = ofMap(refPos, 0, 20, 0, ofGetWidth());
    pos.x+=50;
    color.r = 255; color.g = 0; color.b = 0;
    pos.y = ofGetHeight()/2;
    radius = 100;
    cout << "RefNum: " << refPos << " x: " << pos.x << endl;
}

void poly::draw(){
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofSetColor(color);
    ofCircle(0, 0, radius);
    ofPopMatrix();
}

void poly::update(){
    float colorSine = sin(ofGetElapsedTimef()*5+(refPos*.1));
    color.setHue(ofMap(colorSine, -1, 1, 100, 360));
   // color.r = ofMap(colorSine, -1, 1, 0, 255);
}