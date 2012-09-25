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
    catchUpSpeed = 0.05f;
    
}

void rectangle::draw(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableAlphaBlending();
    ofSetColor(color, 50);
    ofRect(pos.x, pos.y, 50, 50);
    ofDisableAlphaBlending();
}

void rectangle::xenoToPt(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}