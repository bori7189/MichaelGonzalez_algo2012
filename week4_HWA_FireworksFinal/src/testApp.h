#pragma once

#include "ofMain.h"
#include "firework.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector <firework> myFireworks;
        

        //width and y location of where the firework will start from
        int startPos, endPos;
        
        //for setting a random time to wait for the a group of fireworks to go off
        int fireworkCounterEmmiter, fireworkCounterSet;
        bool fireworkCounterEqual;
        int delayEmitter;

        //number of fireworks that will go off in one group
        int numberFireworks;

        bool newEmitterPos;
        
        ofPoint emitterPos;
    
        ofImage background;

        
};
