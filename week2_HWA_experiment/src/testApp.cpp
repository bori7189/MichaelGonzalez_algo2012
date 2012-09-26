#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofBackground(0,0,0);
    int counter;
    for(int i= 0; i<20-1; i++){
        
        cout << "the counter: " << counter << endl;
        myPolys.push_back(poly(counter));
        counter++;
        
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<myPolys.size(); i++){
        myPolys[i].update();
    }
   }

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i<myPolys.size(); i++){
        
        myPolys[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mousePress = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mousePress = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}