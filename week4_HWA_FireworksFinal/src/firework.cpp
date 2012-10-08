//
//  firework.cpp
//  Fireworks
//
//  Created by Michael Gonzalez on 10/4/12.
//
//

#include "firework.h"

firework::firework(ofPoint _start){
    setInitialCondition(_start.x, _start.y, ofRandom(-2, 2), ofRandom(-7, -8));
    color.set(255, 255, 255);
    colorExplosion.set(ofRandom(100,255), ofRandom(100, 255), ofRandom(100, 255));
    explode = false;
    done = false;
    fireworkSound.loadSound("whistleFirework.mp3");
    fireworkSound.setVolume(0.50f);
    fireworkSound.play();
    explosionSound.loadSound("fireworkExplosion.mp3");
    //explosionSound.setVolume(0.25f);
    fireWorkExplodeVel = ofRandom(1, 3);
    
}

void firework::setInitialCondition(float px, float py, float vx, float vy){
    fireworkPos.set(px, py);
    fireworkVel.set(vx, vy);
}

void firework::resetForce(){
    fireworkFrc.set(0,0);
}

void firework::addForce(float x, float y){
    fireworkFrc.x+=x;
    fireworkFrc.y+=y;
}

void firework::update(){
    fireworkVel += fireworkFrc;
    fireworkPos += fireworkVel;
    
    if(fireworkVel.y >= fireWorkExplodeVel){
       // 
        explode = true;
        fireworkSound.stop();
        
       // cout << fireworkPos.x << "  ,  " << fireworkPos.y << endl;
    }
    
    if(explode){
        if(particles.size()==0){
            explosionSound.play();
        for(int i = 0; i < 100; i++){
            //cout << "EXPLOSION" << endl;
            particles.push_back(particle(fireworkPos, colorExplosion));
            }
        }
        for(int i = 0; i<particles.size(); i++){
            particles[i].resetForce();
            particles[i].addForce(0, 0.05); //gravity
            particles[i].addDampingForce();
            particles[i].update();
            
            if(particles[i].done == true) particles.erase(particles.begin()+i);
            //cout << particles.size() << endl;
            
            if(particles.size()==1){
                done = true;
            }
        }
        //cout << "explosion size: " << particles.size() << "     ";
    }
}

void firework::draw(){
    
    if(!explode){
    ofSetColor(color);
        ofFill();
   // cout << "Drawing firework" << endl;
   // cout << fireworkPos.x << " , " << fireworkPos.y << endl;
    ofCircle(fireworkPos.x, fireworkPos.y, 3);
    }
    
    else{
        for(int i= 0; i<particles.size(); i++){
            particles[i].draw();
        }
    }
    
   

}
