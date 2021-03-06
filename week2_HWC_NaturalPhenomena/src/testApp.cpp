#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    changeRadius = ofRandom(70, 150);
    
    xorig = ofGetWidth()/2;
    yorig = ofGetHeight()/2;
    
    radiusAdd = 0.1;
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
   
    radius = radius + radiusAdd;
    if (radius >= changeRadius) {
      changeRadius = ofRandom(70,150);
      radiusAdd *= -1;
        
        
        xorig = x + radius;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    if(ofGetElapsedTimef()>0) angle = ofGetElapsedTimef()*3.5;
    else  angle = 3.5;
    
    
    
    x = xorig + radius * cos (angle);
    y = yorig + radius * -sin(angle);
    
    float dx = x - xorig;
    float dy = y - yorig;
    
    tanAngle = (atan2(dx, dy)) *RAD_TO_DEG;
    
    //cout << tanAngle  << endl;
    ofPoint temp;
    temp.x = x;
    temp.y = y;
    pointSet.push_back(temp);
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255 , 0, 127);
    ofFill();
    ofCircle(x,y,10);
    
    ofSetColor(200, 0, 255);
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i<pointSet.size(); i++){
        ofVertex(pointSet[i].x, pointSet[i].y);
    }
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