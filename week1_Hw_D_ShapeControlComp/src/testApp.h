#pragma once

#include "ofMain.h"
#include "arc.h"

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
    
    ofPolyline polyline;
    ofPoint mouse;
    vector <arc> arcGrid;
    int myWidthA, myWidthB, myHeightA, myHeightB;
    float pct;
};