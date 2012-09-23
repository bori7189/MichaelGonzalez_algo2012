//
//  arc.h
//  emptyExample
//
//  Created by Michael Gonzalez on 9/14/12.
//
//

#ifndef emptyExample_arc_h
#define emptyExample_arc_h
#include "ofMain.h"

class arc{
public:
    arc(ofPoint myCenter);
    
    void draw();
    void interpolateByPos(ofPoint myPos, float myPct);
    
    ofPoint center, pos;
    ofPolyline polyline, mouseDistance;
    float pct, radius, radiusA, radiusB, degreeA, degreeB, opacity;
    
};


#endif
