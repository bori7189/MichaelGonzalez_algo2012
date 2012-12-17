#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0);
	
	for (int i = 0; i < 50; i++){
		particle myParticle;
        
        widthBox = ofGetWidth()/2;
        heightBox = 300;
		myParticle.setInitialCondition(ofRandom(ofGetWidth()/2-widthBox/2, ofGetWidth()/2+widthBox/2),ofRandom(ofGetHeight()/2-heightBox/2, ofGetHeight()/2+heightBox/2),0,0);
		particles.push_back(myParticle);
        particles[i].vel.x = ofRandom(-1.5f, 1.5f);
        particles[i].vel.y = ofRandom(-1.5f, 1.5f);

	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	//VF.randomizeField(2.0);
	
	drawingStyle = 0;
	bFade = false;
    ofVec2f *tempPos, *tempPosA;
    tempPos = new ofVec2f;
    tempPosA = new ofVec2f;
    tempPos->set(0, 0);
    tempPosA->set(ofGetWidth(), ofGetHeight());
    
    connectionSet.push_back(connections(tempPos, tempPosA));
    

}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	

	
	for (int i = 0; i < particles.size(); i++){
		//setting bounding force
        if(particles[i].posPoint->x >= ofGetWidth()/2+widthBox || particles[i].posPoint->x <= ofGetWidth()/2-widthBox){
            particles[i].vel.x *= -1;
        }
        if(particles[i].posPoint->y >= ofGetHeight()/2+heightBox || particles[i].posPoint->y <=ofGetHeight()/2-heightBox){
            
            particles[i].vel.y *= -1;
        }
        
        for(int j = 0; j< particles.size(); j++){
            particles[i].resetForce();
            particles[i].addAttractionForce(float(particles[j].posPoint->x), float(particles[j].posPoint->y), 75, 0.01);
            particles[i].addRepulsionForce(float(particles[j].posPoint->x), float(particles[j].posPoint->y), 50, 0.055);
            
            
            if(ofDist(particles[i].posPoint->x, particles[i].posPoint->y, particles[j].posPoint->x, particles[j].posPoint->y)<150){
                bool alreadyExists = false;
                
                
                
                for(int k = 0; k<connectionSet.size(); k++){
                    if((particles[i].posPoint == connectionSet[k].posPtrA && particles[j].posPoint == connectionSet[k].posPtrB) || (particles[i].posPoint == connectionSet[k].posPtrB && particles[j].posPoint == connectionSet[k].posPtrA)){
                        //cout << "true" << endl;
                    
                        alreadyExists = true;
                    }
                }
                if(!alreadyExists) connectionSet.push_back(connections(particles[i].posPoint, particles[j].posPoint));
            }
            
        }
        
        
		
		// get the force from the vector field: 
		//ofVec2f frc;
		//frc = VF.getForceFromPos(particles[i].posPoint->x, particles[i].posPoint->y);
		//particles[i].addForce(frc.x, frc.y);
		//particles[i].addDampingForce();
		//particles[i].update();
	}
    
    for (int i = 0; i<particles.size(); i++) {
//        particles[i].resetForce();
//        particles[i].addAttractionForce(float(ofGetWidth()/2), float(ofGetHeight()/2), 100, 0.01f);
        particles[i].addAttractionForce(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), 0.005f);
        particles[i].addDampingForce();
        particles[i].update();
//        //cout << "Happenning"    <<endl;
    }
	
	
	if (bFade == true) VF.fadeField(0.99f);

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	VF.draw();
	
	ofSetColor(0,0,0);
	
	for (int i = 0; i < particles.size(); i++){
		//particles[i].draw();
	}
	
	ofSetColor(0,130,130, 200);
	//ofRect(30,30,300,75);
	ofSetColor(255,255,255);
//	ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'", 50, 50);
//	
//	
//	ofSetColor(255,255,130);
//	switch (drawingStyle){
//		case 0: ofDrawBitmapString("drawing mode: inward", 50, 90);
//			break;
//		case 1: ofDrawBitmapString("drawing mode: outward", 50, 90);
//			break;
//		case 2: ofDrawBitmapString("drawing mode: clockwise", 50, 90);
//			break;
//		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 50, 90); 
//			break;
//	}	
//    
//    VF.addInwardCircle(ofGetWidth()/2, ofGetHeight()/2, 200, ofRandom(0.01f, 0.02f));
//    VF.addOutwardCircle(ofGetWidth()/2, ofGetHeight()/2, 100, ofRandom(0.001f, 0.05f));
    ofDisableAlphaBlending();
    for(int i = 0; i< connectionSet.size(); i++){
    connectionSet[i].draw();
        
        if (ofDist(connectionSet[i].posPtrA->x, connectionSet[i].posPtrA->y, connectionSet[i].posPtrB->x, connectionSet[i].posPtrB->y)>60) {
            
            connectionSet.erase(connectionSet.begin()+i);     
           // cout << "Size of connectionSet: " << connectionSet.size() << endl;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 4;
	} else if (key == 'f'){
		bFade = !bFade;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if (button == 0) {
		switch (drawingStyle){
			case 0: VF.addInwardCircle((float)x, (float)y, 200, 0.01f);
                    VF.addOutwardCircle((float)x, (float)y, 50, 0.03f);
				break;
			case 1: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 2: VF.addClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
		}		
	} else {
		
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
		
		
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
