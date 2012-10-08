//
//  firework.h
//  Fireworks
//
//  Created by Michael Gonzalez on 10/4/12.
//
//

#ifndef __Fireworks__firework__
#define __Fireworks__firework__

#include <iostream>
#include "ofMain.h"
#include "particle.h"

class firework{
public:
    
    firework(ofPoint _start);
    
    void resetForce();
    void addForce(float x, float y);
    void setInitialCondition(float px, float py, float vx, float vy);
    
    void update();
    void draw();
    
    
    ofPoint fireworkPos;
    ofPoint fireworkVel;
    ofPoint fireworkFrc;

    ofColor color, colorExplosion;
    
    bool explode, done;

    //float explosionChecker;
    
    ofSoundPlayer fireworkSound;
    ofSoundPlayer explosionSound;



    vector <particle> particles;
    
    int fireWorkExplodeVel;
};



#endif /* defined(__Fireworks__firework__) */
