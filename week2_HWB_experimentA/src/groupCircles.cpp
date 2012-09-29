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

groupCircles::groupCircles(){
    numOfCircles = ofRandom(10, 50);
    sizeBetweenRadius = ofRandom(1, 5);
    int tempRadius = ofRandom(0, 5);
    color.r = 0; color.g = 0; color.b = 255; color.a = 10;
    
    for(int i = 0; i<=numOfCircles; i++){
        tempRadius += sizeBetweenRadius;
        ofPoint tempPos;
        tempPos.x = ofRandom(0, ofGetWidth());
        tempPos.y = ofRandom(0, ofGetHeight());
        
        circleSet.push_back(circle(tempRadius, tempPos));
    }
}

void groupCircles::update(){
    
}

void groupCircles::draw(){
    for(int i=0; i<circleSet.size(); i++){
        ofSetColor(color);
        ofCircle(circleSet[i].center.x,circleSet[i].center.y, circleSet[i].radius);
    }
}