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
    opacity = 100;
    //color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    setInitialCondition(center.x, center.y, ofRandom(-3, 3), ofRandom(-3, 3));
    done = false;
    
   
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
    
    //for streaks
    ofPoint temp;
    temp.x = pos.x;
    temp.y = pos.y;
    
    pointPath.push_back(temp);
    if(pointPath.size()>100){
        pointPath.erase(pointPath.begin());
    }
    
    if(pointPath[pointPath.size()-1].y > ofGetHeight()){
        for(int i = 0; i< pointPath.size(); i++){
            pointPath.erase(pointPath.begin());
        }
        done = true;
    }
    
    //cout << pointPath.size() << endl;
    
    
    
    //shaper
    
//    float tempPct = pos.y/(ofGetHeight()*0.9f);
//    opacity = (1-tempPct)*100 + tempPct*1;
}

//------------------------------------------------------------
void particle::draw(){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(color, opacity);
    
    //ofCircle(pos.x, pos.y, 3);
    
    
    ofNoFill();
    ofSetLineWidth(3);
    ofBeginShape();
    for(int i = 0; i<pointPath.size(); i++){
        ofVertex(pointPath[i].x, pointPath[i].y);
    }
    ofEndShape();
    //ofCircle(pos.x, pos.y, 3);
    ofDisableAlphaBlending();
}