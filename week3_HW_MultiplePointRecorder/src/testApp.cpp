#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofPoint tempPos;
    tempPos.set(20,20);
    ofDrawBitmapString("Hit 'c' to clear screen and 'f' to enter Fullscreen", tempPos);
    for (int i = 0; i<posSet.size(); i++) {
        posSet[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'f')
    ofToggleFullscreen();
    else if (key == 'c')
    posSet.clear();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    timePos tempPos;
    tempPos.x = x;
    //cout << "y: " << y << endl;
    tempPos.y = y;
    tempPos.t = ofGetElapsedTimef() - startTime;
    
    posSet.push_back(tempPos);
    posSet[posSet.size()-1].setupPosSet();
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    //posSet.clear();
    startTime = ofGetElapsedTimef();
    ofSetColor(200, 0, 0);
    ofNoFill();
    timePos tempPos;
    tempPos.x = x;
    tempPos.y = y;
    tempPos.t = 0;
    
    posSet.push_back(tempPos);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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