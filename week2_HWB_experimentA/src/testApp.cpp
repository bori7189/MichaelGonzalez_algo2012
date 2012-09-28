#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 16, 35);
    ofSetVerticalSync(true);
    
}

//--------------------------------------------------------------
void testApp::update(){
    if(mouseIsPressed){
        int _x = ofRandom(ofGetWidth());
        int _y = ofGetHeight();
        myShapes.push_back(shape(-1, _x, _y));
        cout << "Current Size of vector"<< myShapes.size() << endl;
    }
    for(int i = 0; i<myShapes.size(); i++){
        myShapes[i].update();
        if(myShapes[i].checkStatus()) {
            cout << "Vector size minimized" << endl;
            myShapes.erase(myShapes.begin()+i);
            i--;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
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