//
//  particle.h
//  Drawing Fountains
//
//  Created by Michael Gonzalez on 10/6/12.
//
//

#ifndef __Drawing_Fountains__particle__
#define __Drawing_Fountains__particle__

#include <iostream>
#include "ofMain.h"

class particle{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    float damping;

    

protected:
private:
    
};

#endif /* defined(__Drawing_Fountains__particle__) */
