//
//  rectangle.h
//  emptyExample
//
//  Created by Michael Gonzalez on 9/16/12.
//
//

#ifndef __emptyExample__rectangle__
#define __emptyExample__rectangle__

#include "ofMain.h"

class rectangle{
public:
    rectangle(int _count);
    
    void draw();
    void xenoToPt(float catchX, float catchY);
    
    int rectNum;
    ofColor color;
    ofPoint pos;
    float catchUpSpeed;
    
};

#endif /* defined(__emptyExample__rectangle__) */
