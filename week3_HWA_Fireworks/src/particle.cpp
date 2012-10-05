//
//  particle.cpp
//  Fireworks
//
//  Created by Michael Gonzalez on 10/4/12.
//
//

#include "particle.h"

//------------------------------------------------------------
particle::particle(ofPoint _center, ofColor _color){
    center = _center;
    color = _color;
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
    ofSetColor(color);
    ofCircle(pos.x, pos.y, 3);
}