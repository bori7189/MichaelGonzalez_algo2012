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
    ofSetColor(0, 122, 198);
    polyline.draw();
}

void arc::interpolateByPos(ofPoint myPos, float myPct){
    pos = myPos;
    pct = myPct;
    
    float thickness, dist;
    
    float pctPosY = pos.y/ofGetHeight();
    
    degreeA += 1;//(1-pct)*0+pct*360;
    degreeB = ((1-pctPosY)*0+pctPosY*360)+degreeA;
    
    degreeA = 0;
    //degreeB = 360;*/
    
    polyline.clear();
    mouseDistance.clear();
    mouseDistance.addVertex(center);
    mouseDistance.addVertex(pos);
    dist = mouseDistance.getPerimeter();

        
    
    
    polyline.setClosed(true);
    polyline.arc(center,radius, radius, degreeA, degreeB, 40);
}





