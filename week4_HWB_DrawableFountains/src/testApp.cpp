#include "testApp.h"
//particleEmitter testEmit(250, 250, -10, 10);
//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofBackground(0);
}  

//--------------------------------------------------------------
void testApp::update(){
//    for(int i = 0; i<particles.size(); i++){
//        particles[i].resetForce();
//        particles[i].addDampingForce();
//        particles[i].update();
//    }
    //testEmit.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    for (int i = 0 ; i<particlePath.size(); i++) {
        particlePath[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0);
    
//    ofFill();
//    for (int i = 0; i < particles.size(); i++) {
//        particles[i].draw();
//    }
//    
//    ofNoFill();
//    ofBeginShape();
//    for (int i = 0 ; i < particles.size(); i++) {
//        ofVertex(particles[i].pos.x, particles[i].pos.y);
//    }
//    
//    ofEndShape();
    
    //testEmit.draw();
    
    
    for (int i = 0 ; i<particlePath.size(); i++) {
        particlePath[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    for(int i = 0;i<particlePath.size(); i++){
        particlePath.erase(particlePath.begin()+i);
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    prevMouseX = x;
    prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    float dx = x - prevMouseX;
	float dy = y - prevMouseY;
    
    particlePath.push_back(particleEmitter(x, y, dx*0.3, dy*0.3, tempColor));
//	particle myParticle;
//	myParticle.setInitialCondition(x,y, dx*0.3,dy*0.3);
//	particles.push_back(myParticle);
	
	
	//if (particles.size() > 50){
    //		particles.erase(particles.begin());
    //	}
	
	prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //particles.clear();
    tempColor.set(ofRandom(100, 255), ofRandom(100, 255), ofRandom(100,255));
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