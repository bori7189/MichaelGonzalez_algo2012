#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    for(int i = 0; i<6; i++){
        myRecs.push_back(rectangle(i));
    }
}

//--------------------------------------------------------------
void testApp::update(){
    myRecs[0].xenoToPt(mouseX, mouseY);
    for(int i=1; i<myRecs.size(); i++){
        myRecs[i].xenoToPt(myRecs[i-1].pos.x, myRecs[i-1].pos.y);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<myRecs.size(); i++){
        myRecs[i].draw();
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