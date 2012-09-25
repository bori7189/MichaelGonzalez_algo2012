#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofBackground(0,0,0);
    //ofSetCircleResolution(100);
    int radCounter = 4;
    int tempRad = 10;
    int relPos = 1;
    int direction = 1;
    int tempI;
    for(int i = 0; i< 1000; i++){
        relPos++;
        tempI++;
        if(tempI%radCounter == 0){
            radCounter+=5;
            tempRad +=15;
            relPos = 1;
            //stopped with adding direction
            direction *= -1;
            tempI = 0;
        }
        myPolys.push_back(poly(i-1, tempRad, relPos, direction));
    }
    
    for(int i=0; i<myPolys.size(); i++){
        int counter = 0;
        int refCounter = 0;
        bool foundInit = false;
        for(int j = 0; j<myPolys.size(); j++){
            if(myPolys[i].radius == myPolys[j].radius) {
                //cout << myPolys[i].radius << " == " << myPolys[j].radius << endl;
                counter++; foundInit = true; refCounter = j;
                //cout<<"works" << endl;
                
            }
            else if(foundInit==true){
                //cout << "breaks" << endl;
                break;
                
            }
        }
            for(int j = i; j<=refCounter; j++){
                myPolys[j].numInRadius = counter;
            }
            
            i = refCounter;
            
        
        
    }
    
    for(int i = 0; i<myPolys.size(); i++){
        cout << "Num in Radius: " <<  myPolys[i].relPos << endl;
    }

}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i<myPolys.size(); i++){
        myPolys[i].modulate();
    }
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
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