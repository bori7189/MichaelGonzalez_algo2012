//
//  polygon.cpp
//  emptyExample
//
//  Created by Michael Gonzalez on 9/24/12.
//
//

#include "polygon.h"

poly::poly(int _count, int _radius, int relRadPos, int _direction){
    refNum = _count;
    sides = 3;
    radius = _radius;
    centerX  = ofGetWidth()/2;
    centerY = ofGetHeight()/2;
    direction = _direction;
    
    color.r = 255; color.g = 0; color.b = 0;  color.a  = 70;
    
    degree = 0;
    
    polyRad = 10;
    
    relPos = relRadPos;
    //cout << _count<<": "<<relPos << endl;
}

void poly::draw(){
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(degree);
    ofEnableAlphaBlending();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    //ofSetColor(255, 0, 0, 25);
    polygon.setColor(color);
    
    polygon.draw();
    ofDisableAlphaBlending();
    ofPopMatrix();
}

void poly::modulate(int mouseX, int mouseY){
    centerX = mouseX;
    centerY = mouseY;
    ofPoint origin;
    origin.x = 0; origin.y = 0;
    degree++;
    float proportion = ((relPos+0.0f)/(numInRadius+0.0f))*360.0f;
    polygon.clear();
    polygon.arc(origin, polyRad, polyRad, 0, 360, 60);
    polygon.setArcResolution(sides);
    
    angle = ofGetElapsedTimef()*.25;
    
    x = centerX + radius * cos(angle+proportion) * direction;
    y = centerY + radius * -sin(angle+proportion);
    float polySine = sin(ofGetElapsedTimef()*2);
    polyRad = ofMap(polySine, -1, 1, 20, 40);
    float tempRedShift = sin(ofGetElapsedTimef()*5 + numInRadius);
    color.setHue(ofMap(tempRedShift, -1, 1, 140, 145));
    color.a = 50;
    
    //color.r = round(ofMap(tempRedShift, -1, 1, 0, 255));
    pos.x  = x;
    pos.y = y;
    

}

/*ofPolyline poly;
 ofPoint point;
 ofPath path;
 point.x = ofGetWidth()/2;
 point.y = ofGetHeight()/2;
 //path.setMode(ofPath::Mode mode)
 
 int sides = ofMap(mouseX, 0, ofGetHeight(), 1, 10);
 poly.arc(point, 30, 30, 0, 360, sides);
 poly.close();
 path.arc(point, 30, 30, 0, 360);
 path.setArcResolution(sides);
 
 cout << path.getArcResolution() << endl;
 
 ofSetColor(255);
 path.draw();
 //poly.draw();*/
