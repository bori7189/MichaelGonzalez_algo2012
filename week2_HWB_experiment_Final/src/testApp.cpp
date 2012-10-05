#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 16, 35);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
    // 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// BUFFER_SIZE samples per buffer
	// 4 num buffers (latency)
	
	ofSoundStreamSetup(0,2,this, 44100, BUFFER_SIZE, 4);	
	
	left = new float[BUFFER_SIZE];
	right = new float[BUFFER_SIZE];	
	
	FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
	
	FFTanalyzer.peakHoldTime = 15; // hold longer
	FFTanalyzer.peakDecayRate = 0.95f; // decay slower
	FFTanalyzer.linearEQIntercept = 0.9f; // reduced gain at lowest frequency
	FFTanalyzer.linearEQSlope = 0.01f; // increasing gain at higher frequencies
    

    
    song.loadSound("deep_space.mp3");
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
    FFTCounter++;
    if(FFTCounter == 10){
        FFTCounter = 0;
    for(int i = 0; i<(int)BUFFER_SIZE/2; i++){
        
        if(FFTrecord[i] >= 50){
           int _x = ofMap(i, 0, 50, 0, ofGetWidth())+ofRandom(-30, 30);
            int _y = ofGetHeight();
            myShapes.push_back(shape(-1, _x, _y));
        }
        
    }
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
    ofPushMatrix();
    for(int i = 0; i<myCircles.size(); i++){
        myCircles[i].draw();
    }
    
    for(int i = 0; i<myShapes.size(); i++){
        myShapes[i].draw();
    }
    
    ofPopMatrix();
    
    float avg_power = 0.0f;	
    
	/* do the FFT	*/
	myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, left,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&avg_power);
    
	for (int i = 0; i < (int)(BUFFER_SIZE/2); i++){
		freq[i] = magnitude[i];
	}
	
	FFTanalyzer.calculate(freq);
	
	ofSetColor(255);
	for (int i = 0; i < (int)(BUFFER_SIZE/2 - 1); i+=10){
		//ofRect(50+(i*4),600,4,-freq[i]*10.0f);
        FFTrecord[i] = freq[i]*10.0f;
        //cout << "freq[" << i << "]: " << freq[i]*10.0f << endl;
        //ofRect(float x1, float y1, float w, float h)
	}
	
	for (int i = 0; i < FFTanalyzer.nAverages; i++){
		//ofRect(200+(i*40),600,20,-FFTanalyzer.averages[i] * 6);
	}
	
	ofSetColor(255,0,0);
	for (int i = 0; i < FFTanalyzer.nAverages; i++){
		//ofRect(200+(i*40),600-FFTanalyzer.peaks[i] * 6,20,-4);
	}
    
    //float * averages; // the actual averages
    //float * peaks; // peaks of the averages, aka "maxAverages" in other implementations
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

//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
}