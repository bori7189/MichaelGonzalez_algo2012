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
    poly(int _refPos);
    void draw();
    void update();
    ofPoint pos;
    ofColor color;
    float radius;
    int refPos;
};

#endif /* defined(__emptyExample__polygon__) */
