//
//  groupCircles.cpp
//  MusicVisualization
//
//  Created by Michael Gonzalez on 9/29/12.
//
//

#include "groupCircles.h"

circle::circle(float _radius, ofPoint _center){
    radius = _radius;
    center = _center;
    

}




groupCircles::groupCircles(int _index){
    numOfCircles = ofRandom(10, 30);
    sizeBetweenRadius = ofRandom(1, 5);
    int tempRadius = ofRandom(0, 5);
    ofPoint tempPos;
    beginTime = _index;
    tempPos.x = ofRandom(0, ofGetWidth());
    tempPos.y = ofRandom(0, 0.25 * ofGetHeight());
    color.r = 0; color.g = 0; color.b =150; color.a = 0;

    for(int i = 0; i<=numOfCircles; i++){
        tempRadius += sizeBetweenRadius;
        circleSet.push_back(circle(tempRadius, tempPos));
    }
}

void groupCircles::update(){
    float opacitySine = abs(sin((ofGetElapsedTimef()-beginTime)*1.0f));
    
    color.a = round(ofMap(opacitySine, 0, 1.0, 0, 10));
}

void groupCircles::draw(){
    for(int i=0; i<circleSet.size(); i++){
        ofEnableAlphaBlending();
        ofSetColor(color);
        ofCircle(circleSet[i].center.x,circleSet[i].center.y, circleSet[i].radius);
        ofDisableAlphaBlending();
    }
}

bool groupCircles::opaque(){
    if(color.a == 0)return true;
    else return false;
}

