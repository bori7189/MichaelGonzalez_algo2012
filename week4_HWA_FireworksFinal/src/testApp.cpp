#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    cout << "---------------------------------------------------" << endl;
    ofSetVerticalSync(true);
    ofBackground(100);
    
    
    fireworkCounterSet = 100;
    fireworkCounterEqual = false;
    newEmitterPos = true;
    numberFireworks = ofRandom(5, 20);
    background.loadImage("background.png");
    ofToggleFullscreen();
    
}

//--------------------------------------------------------------
void testApp::update(){
    startPos = ofGetWidth()*0.30;
    endPos = ofGetWidth()*0.70;
    //ofSetWindowTitle(ofToString(ofGetFrameRate()));
    background.resize(ofGetWidth(), background.getHeight()*(ofGetWidth()/background.getWidth()));
    if(!fireworkCounterEqual) fireworkCounterEmmiter++;
    
    if(fireworkCounterEmmiter == fireworkCounterSet){
        fireworkCounterEqual = true;
        
        delayEmitter++;
        
        
        //setting a new pos for the emittion of a new group of fireworks
        if(newEmitterPos){
            emitterPos.set(ofRandom(startPos, endPos), ofGetHeight()*0.95);
            newEmitterPos = false;
            //cout << "New Emitter Pos X:  " << emitterPos.x << "   Pos Y:  " << emitterPos.y << endl;
        }
        
        if(myFireworks.size() < numberFireworks){
            //a suddle delay so the group of fireworks dont all fire off at once
            if(delayEmitter >= ofRandom(15, 50)){
                delayEmitter = 0;
            myFireworks.push_back(firework(emitterPos));
            }
        }
        
        //once all the fireworks have been emmitted
        else {
            newEmitterPos = true;
            fireworkCounterEmmiter = 0;
            fireworkCounterSet = ofRandom(20, 100);
            fireworkCounterEqual = false;
            if(numberFireworks < 8){
            numberFireworks = ofRandom(10, 15);
            }
            else{
            numberFireworks = ofRandom(1, 5);
            }
        }
        
    }
    
    for(int i = 0; i<myFireworks.size(); i++){
        myFireworks[i].resetForce();
        myFireworks[i].addForce(0, 0.05);  //gravity of firework 
        myFireworks[i].update();
        if(myFireworks[i].done == true){
            myFireworks.erase(myFireworks.begin()+i);
        }
    }
    
    
    //cout << "fireworks size:   " << myFireworks.size() << endl;
    
    ofSoundUpdate();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    background.draw(0, -1*(background.getHeight()-ofGetHeight()));
    for(int i = 0; i<myFireworks.size(); i++){
        myFireworks[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    ofToggleFullscreen();
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