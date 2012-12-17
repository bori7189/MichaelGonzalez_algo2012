//
//  timePos.h
//  emptyExample
//
//  Created by Michael Gonzalez on 12/17/12.
//
//

#ifndef __emptyExample__timePos__
#define __emptyExample__timePos__

#include <iostream>
#include "ofMain.h"

class timePos{
public:
    float x, y, t, radius;
    vector<float> offset;
    void setupPosSet();
    void draw();
    vector <ofColor> colorSet;
    vector <ofPoint> posSet;
    
private:
protected:
};

#endif /* defined(__emptyExample__timePos__) */
