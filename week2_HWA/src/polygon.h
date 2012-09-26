//
//  polygon.h
//  emptyExample
//
//  Created by Michael Gonzalez on 9/24/12.
//
//

#ifndef __emptyExample__polygon__
#define __emptyExample__polygon__

#include <iostream>
#include "ofMain.h"

class poly{
public:
    poly(int _count, int _radius, int relRadPos, int _direction);
    
    void draw();
    void modulate();
    
    int refNum, sides;
    ofColor color;
    ofPoint pos;
    ofPath polygon;
    float degree;
    float degreeChanger;
    float radius, polyRad;
    float angle;
    float x, y, centerX, centerY;
    int numInRadius;
    int  relPos, direction;
    int radNum;
    //float size;
    
};

#endif /* defined(__emptyExample__polygon__) */
