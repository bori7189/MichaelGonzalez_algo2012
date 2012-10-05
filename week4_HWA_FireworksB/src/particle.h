//
//  particle.h
//  Fireworks
//
//  Created by Michael Gonzalez on 10/4/12.
//
//

#ifndef __Fireworks__particle__
#define __Fireworks__particle__

#include <iostream>
#include "ofMain.h"


class particle
{
public:
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    
    particle(ofPoint _center, ofColor   _color);
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    float damping;
    ofPoint center;
    ofColor color;
    int opacity;
    
    vector <ofPoint> pointPath;
protected:
private:
    
};
#endif /* defined(__Fireworks__particle__) */
