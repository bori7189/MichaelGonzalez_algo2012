#include "testApp.h"

float xpos;
//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    xpos = ofGetWidth()/2;
    
}

//--------------------------------------------------------------
void testApp::update(){
    if(xpos > ofGetWidth()){
        xpos = 0.0f;
    }
    xpos += 10.0f;
}

//--------------------------------------------------------------
void testApp::draw(){
    float modulator = 1;//ofMap( sin(ofGetElapsedTimef()*12.7), -1, 1, 0, 1);
	
	float ypos		= ofMap( sin(ofGetElapsedTimef()*3) * modulator, -1, 1, 0, ofGetHeight()-20);
	
	
	ofSetColor(255,255,255);
	
	ofRect(xpos, ypos, 20,20);
    
    ofNoFill();
    ofSetColor(255);
    
    ofBeginShape();
    ofVertex(0,ofGetHeight()*0.5);
    
    
    ofCurveVertex(ofGetWidth()*.25, ofGetHeight());
    ofCurveVertex(ofGetWidth()/2, ofGetHeight()/2);
    //ofCurveVertex(ofGetWidth()/2, ofGetHeight()*0.5 + sin( ofGetElapsedTimef())*30 );
    
    ofVertex(ofGetWidth(),ofGetHeight()*0.5);
    ofEndShape();
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