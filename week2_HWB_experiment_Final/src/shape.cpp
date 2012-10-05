//
//  shape.cpp
//  MusicVisualization
//
//  Created by Michael Gonzalez on 9/28/12.
//
//

#include "shape.h"

shape::shape(int _index, int _x, int _y){
    
    index = _index;
    pos.x = _x;
    pos.y = _y;
    posBegin.x = _x;
    posBegin.y = _y;
    posEnd.x = _x;
    posEnd.y = -50.0;
    catchUpSpeed = ofRandom(0.05, 0.001);
    
    color.r = ofRandom(30);
    color.g = ofRandom(0, 100);
    color.b = ofRandom(100, 230);
    color.a = 100;
    
    width = 50; widthBegin = 50; widthEnd = 10;
    height = 50; heightBegin = 50; heightEnd = 100;
    opacityBegin = 100; opacityEnd = 0;
    xChange = ofRandom(0.05f, 0.1f);
    pctForY = 0;
    pctForOpacity;
    
    zMovement = ofRandom(-0.25, 0.25);
    zLocation = 0;
}

void shape::update(){
    
    //xeno to point
    //pos.y = catchUpSpeed * posEnd.y + (1-catchUpSpeed) * pos.y;
    pctForY += 0.01f;
    
    float pctTemp = powf(pctForY, 1.5);
    pos.y = (1-pctTemp) * posBegin.y + (pctTemp) * posEnd.y;
    width = (1-pctTemp) * widthBegin + (pctTemp) * widthEnd;
    height = (1-pctTemp) * heightBegin + (pctTemp) * heightEnd;
    
    
    if(pctForY > .75){
        pctForOpacity += 0.035f;
        color.a = (1-pctForOpacity) * opacityBegin + (pctForOpacity) * opacityEnd;
    }
    pos.x = ofMap(sin(ofGetElapsedTimef())*20, -1.0, 1.0, pos.x-xChange, pos.x+xChange);
    zLocation += zMovement;
    
}

void shape::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(color);
    
    
    ofPushMatrix();
        //ofTranslate(0, 0, zLocation); //not sure if i like this
    ofRect(pos.x, pos.y, width, height);
    ofDisableAlphaBlending();
    ofDisableBlendMode();
    ofPushMatrix();
}

bool shape::checkStatus(){
    if(pos.y < -50 ) return true;
    else return false;
}



//trying a smooth color modulator
//ofColor theColor;
//float sineHue = abs(sin(ofGetElapsedTimef()*0.25));
//theColor.r == sineHue*40; theColor.g = sineHue*255; theColor.b = 20;//(ofMap(sineHue, -1.0, 1.0, 0.0, 1.0));
//
//ofSetColor(theColor);
//
//ofCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/4);

