//
//  particleEmitter.cpp
//  Drawing Fountains
//
//  Created by Michael Gonzalez on 10/6/12.
//
//

#include "particleEmitter.h"

particleEmitter::particleEmitter(int _posX, int _posY, float _vx, float _vy, ofColor _color){
    pos.x = _posX;
    pos.y = _posY;
    
    vel.x = _vx;
    vel.y = _vy;
    
    counterDelay = 0;
    numberToEmit = 10;ofRandom(5, 10);
    color = _color;
}

void particleEmitter::update(){
    counterDelay++;
    if(counterDelay > 10){
        counterDelay = 0;
    for(int i = 0; i<numberToEmit; i++){
        particleSet.push_back(particle());
        particleSet[particleSet.size()-1].setInitialCondition(pos.x, pos.y, vel.x, vel.y);
    }
    }
    
    for (int i = 0; i <particleSet.size(); i++) {
        particleSet[i].resetForce();
        particleSet[i].addForce(0, 0.1);
        particleSet[i].addDampingForce();
        particleSet[i].update();
    }
    
    for(int i= 0; i<particleSet.size(); i++){
        if(particleSet[i].pos.x < 0 || particleSet[i].pos.x > ofGetWidth() || particleSet[i].pos.y < 0 || particleSet[i].pos.y > ofGetHeight()) particleSet.erase(particleSet.begin()+i);
    }
}

void particleEmitter::draw(){
    ofSetColor(0, 0, 0);
    //ofCircle(pos.x, pos.y, 3);
    ofSetColor(color, 25);
    for (int i = 0; i<particleSet.size(); i++) {
        ofEnableAlphaBlending();
        //ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        particleSet[i].draw();
        ofDisableBlendMode();
        ofDisableAlphaBlending();
    }
}
