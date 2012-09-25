//
//  arc.cpp
//  emptyExample
//
//  Created by Michael Gonzalez on 9/14/12.
//
//

#include "arc.h"

arc::arc(ofPoint myCenter){
    center = myCenter;
    radius = 40;
}

void arc::draw(){
    ofEnableAlphaBlending();
    ofSetColor(0, 122, 198, opacity);
    polyline.draw();
    ofDisableAlphaBlending();
}

void arc::interpolateByPos(ofPoint myPos, float myPct){
    pos = myPos;
    pct = myPct;
    
    float dist;
    float radChng = 1.0f;
    
    
    float pctPosY = pos.y/ofGetHeight();
    
    degreeA += 0;//(1-pct)*0+pct*360;
    degreeB = ((1-pctPosY)*1+pctPosY*360);//.+degreeA;
    
    //degreeA = 0;
    //degreeB = 360;*/
    
    polyline.clear();
    mouseDistance.clear();
    mouseDistance.addVertex(center);
    mouseDistance.addVertex(pos);
    dist = mouseDistance.getPerimeter() + 0.0;
    
    if(dist > ofGetWidth()/4) dist = 1.0f;
    else ((dist+0.0f)/(ofGetWidth()/4.0f));
    
    opacity = (1-dist)*5+(dist)*100;
    
    
    if(radius>100)radius *= -1;

        
    radius += radChng;
    polyline.setClosed(true);
    polyline.arc(center,radius, radius, degreeA, degreeB, 40);
}





