//
//  particleEmitter.h
//  Drawing Fountains
//
//  Created by Michael Gonzalez on 10/6/12.
//
//

#ifndef __Drawing_Fountains__particleEmitter__
#define __Drawing_Fountains__particleEmitter__

#include <iostream>
#include "ofMain.h"
#include "particle.h"

class particleEmitter{
public:
    particleEmitter(int _posX, int _posY, float _vx, float _vy, ofColor _color);
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    vector <particle> particleSet;
    
    void update();
    void draw();
    
    int counterDelay, numberToEmit;
    
    ofColor color;

protected:
private:
    
};

#endif /* defined(__Drawing_Fountains__particleEmitter__) */
