//
//  rectangle.cpp
//  emptyExample
//
//  Created by Michael Gonzalez on 9/16/12.
//
//

#include "rectangle.h"

rectangle::rectangle(int _count){
    
    rectNum = _count;
/*switch(rectNum){
    case 0: catchUpSpeed = 0.005f;
        color.r = round(ofRandom(0, 255));
        color.g = round(ofRandom(0, 255));
        color.b = round(ofRandom(0, 255));
        break;
    case 1: catchUpSpeed = 0.03f;
        color.r = round(ofRandom(0, 255));
        color.g = round(ofRandom(0, 255));
        color.b = round(ofRandom(0, 255));
        break;
    case 2: catchUpSpeed = 0.01f;
        color.r = round(ofRandom(0, 255));
        color.g = round(ofRandom(0, 255));
        color.b = round(ofRandom(0, 255));
        break;
    case 3: catchUpSpeed = 0.05f;
        color.r = round(ofRandom(0, 255));
        color.g = round(ofRandom(0, 255));
        color.b = round(ofRandom(0, 255));
        break;
    case 4: catchUpSpeed = 0.1f;
        color.r = round(ofRandom(0, 255));
        color.g = round(ofRandom(0, 255));
        color.b = round(ofRandom(0, 255));
        break;
    case 5: catchUpSpeed = 0.25f;
        color.r = round(ofRandom(0, 255));
        color.g = round(ofRandom(0, 255));
        color.b = round(ofRandom(0, 255));
        break;
        
}*/
    catchUpSpeed = ofRandom(0.005, .25);
    color.r = round(ofRandom(0, 255));
    color.g = round(ofRandom(0, 255));
    color.b = round(ofRandom(0, 255));
    
}

void rectangle::draw(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(color);
    ofRect(pos.x, pos.y, 50, 50);
}

void rectangle::xenoToPt(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}