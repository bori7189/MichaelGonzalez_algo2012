//
//  groupCircles.h
//  MusicVisualization
//
//  Created by Michael Gonzalez on 9/29/12.
//
//

#ifndef __MusicVisualization__groupCircles__
#define __MusicVisualization__groupCircles__

#include <iostream>
#include "ofMain.h"

class circle{
    public:
        circle(float _radius, ofPoint _center);
    
        ofPoint center;
        float radius;
};

class groupCircles{
public:
    groupCircles();
    
    void draw();
    void update();
    
    vector <circle> circleSet;
    ofColor color;
    int numOfCircles, sizeBetweenRadius;
};

#endif /* defined(__MusicVisualization__groupCircles__) */
