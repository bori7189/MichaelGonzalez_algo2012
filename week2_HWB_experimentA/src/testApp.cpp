#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 16, 35);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, 5);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    if(mouseIsPressed){
        int _x = ofRandom(ofGetWidth());
        int _y = ofGetHeight();
        myShapes.push_back(shape(-1, _x, _y));
        //cout << "Current Size of vector"<< myShapes.size() << endl;
    }
    for(int i = 0; i<myShapes.size(); i++){
        myShapes[i].update();
        if(myShapes[i].checkStatus()) {
           // cout << "Vector size minimized" << endl;
            myShapes.erase(myShapes.begin()+i);
            i--;
        }
    }
    
    int numCirclesAdded =1;// ofRandom(3);
    if(myCircles.size()<=15){
        if(myCirclesCounter == 30){
    for(int i = 0; i<numCirclesAdded; i++){
       // myCircles.push_back(groupCircles(ofGetElapsedTimef()));
        myCirclesCounter = 0;
    }
    }
        myCirclesCounter++;
    }
    for(int i = 0; i<myCircles.size(); i++){
        myCircles[i].update();
        if(myCircles[i].opaque()){
            myCircles.erase(myCircles.begin()+i);
        }
    }
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i<myCircles.size(); i++){
        myCircles[i].draw();
    }
    
    for(int i = 0; i<myShapes.size(); i++){
        myShapes[i].draw();
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'f'){
        ofToggleFullscreen();
    }
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
    mouseIsPressed = true;
    cout << mouseIsPressed << endl;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mouseIsPressed = false;
    cout << mouseIsPressed << endl;
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