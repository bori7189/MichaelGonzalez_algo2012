//
//  shape.h
//  MusicVisualization
//
//  Created by Michael Gonzalez on 9/28/12.
//
//

#ifndef __MusicVisualization__shape__
#define __MusicVisualization__shape__

#include <iostream>
#include "ofMain.h"

class shape{
public:
    shape(int _index, int _x, int _y);
    
    ofPoint pos, posEnd, posBegin;
    ofColor color, startColor, EndColor;
    float width, widthBegin, widthEnd, height, heightBegin, heightEnd, opacityBegin, opacityEnd, catchUpSpeed, xChange, pctForY, pctForOpacity;
    int index;
    
    float zMovement;

    
    void update();
    void draw();
    bool checkStatus();
};


#endif /* defined(__MusicVisualization__shape__) */
