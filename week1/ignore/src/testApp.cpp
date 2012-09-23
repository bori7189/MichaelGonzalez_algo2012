#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    for(int i = 0; i<100; i++){
        myRecs.push_back(rectangle(i));
    }
    
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;
    poly.arc(center, (ofGetWidth()*.9)/2, (ofGetHeight()*9)/2, 0, 360, 40);
    
    moverX = 50;
    moverY = 0;
    mover.x = 0;
    mover.y = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<myRecs.size(); i++){
        myRecs[i].xenoToPt(mouseX, mouseY);
    }
    
    if(mover.x < 0)
    
    mover.x += moverX;
    mover.y += moverY;
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<myRecs.size(); i++){
        myRecs[i].draw();
    }
    ofCircle(mover.x, mover.y, 50);
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