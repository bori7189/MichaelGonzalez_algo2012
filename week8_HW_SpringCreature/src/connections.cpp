//
//  connections.cpp
//  vectorField_wParticles
//
//  Created by Michael Gonzalez on 11/29/12.
//
//

#include "connections.h"

connections::connections(ofVec2f *_posPtrA, ofVec2f *_posPtrB){
    posPtrA = new ofVec2f;
    posPtrB = new ofVec2f;
    ofVec2f *posPtrTempA, *posPtrTempB;
    
    posPtrA = _posPtrA;
    posPtrB = _posPtrB;
        
    //cout << posPtrA->x << " " << posPtrA->y << endl; 
    //cout << posPtrB->x << " " << posPtrB->y << endl;
}

bool connections::draw(){
    ofEnableAlphaBlending();
    
    float a = 100.0f*(1.0f - (ofDist(posPtrA->x, posPtrA->y, posPtrB->x, posPtrB->y))/160);
    //cout << "alpha: " << a << endl;
    
    float colorSine = abs(sin(ofGetElapsedTimef()));
    cout << colorSine << endl;
    //color.setHue(ofMap(colorSine, 0.0, 1.0, 0.0f, 360.0f));
    //color.setHue(100);
    ofSetColor(100, 0, 255, a);
    ofSetLineWidth(2);
    
    ofLine(*posPtrA, *posPtrB);
    ofDisableAlphaBlending();
}