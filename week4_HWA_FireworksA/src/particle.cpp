//
//  particle.cpp
//  Fireworks
//
//  Created by Michael Gonzalez on 10/4/12.
//
//

#include "particle.h"

//------------------------------------------------------------
particle::particle(ofPoint _center){
    center = _center;
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    setInitialCondition(center.x, center.y, ofRandom(-3, 3), ofRandom(-3, 3));
}


//------------------------------------------------------------
void particle::resetForce(){
    frc.set(0, 0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px, py);
    vel.set(vx, vy);
}

//------------------------------------------------------------
void particle::update(){
    vel = vel + frc;
    pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(color, 90);
    ofCircle(pos.x, pos.y, 3);
    ofDisableAlphaBlending();
}