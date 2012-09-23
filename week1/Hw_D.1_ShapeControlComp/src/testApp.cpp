#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0, 69, 125);
    
    //give my grid some padding
    myWidthA = ofGetWidth()*.1;
    myWidthB = ofGetWidth()*.9;
    myHeightA = ofGetHeight()*.1;
    myHeightB = ofGetHeight()*.9;
    
    //cout << myWidthA << "   " << myWidthB << endl;
    //cout << myHeightA << "  " << myHeightB << endl << endl;
    
    int rowColumnCount = 15;
    
    
    //setting up the grid of arcs
    for(int i = 0; i < rowColumnCount; i++){
        for(int j = 0; j<rowColumnCount; j++){
            
            
            ofPoint tempPoint;
            
            float pctX = (i+0.0f)/(rowColumnCount-1.0f);
            float pctY = (j+0.0f)/(rowColumnCount-1.0f);
            
            tempPoint.x = (1-pctX) * myWidthA + (pctX) * myWidthB;
            tempPoint.y = (1-pctY) * myHeightA + (pctY) * myHeightB;
            
            
            
            cout << tempPoint.x << ",  " << tempPoint.y << endl;
            /*tempPoint.x = ofGetWidth()/2;
             tempPoint.y = ofGetHeight()/2;*/
            arcGrid.push_back(arc(tempPoint));
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    if (pct > 1) pct = 0;
    pct += 0.01f;
    
    for(int i = 0; i<arcGrid.size(); i++){
        arcGrid[i].interpolateByPos(mouse, pct);
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<arcGrid.size(); i++){
        arcGrid[i].draw();
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
    mouse.x = x;
    mouse.y = y;
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