//
//  connections.h
//  vectorField_wParticles
//
//  Created by Michael Gonzalez on 11/29/12.
//
//

#ifndef __vectorField_wParticles__connections__
#define __vectorField_wParticles__connections__

#include <iostream>
#include "ofMain.h"

class connections{
public:
    connections(ofVec2f *_posPtrA, ofVec2f *_posPtrB);
     
    ofVec2f *posPtrA, *posPtrB, posA, posB;
    ofColor color;
    
    bool draw();
    
private:
protected:
};
#endif /* defined(__vectorField_wParticles__connections__) */
