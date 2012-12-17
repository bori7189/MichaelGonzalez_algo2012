#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.00005f;
    
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    
    //ofVec2f tempPos = *posPoint;

    //tempPos.set(px,py);
    posPoint = new ofVec2f;
    posPoint->set(px, py);
	//vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
    
    //cout << "initial vel x: " << vel.x << " vel y: " << vel.y << endl;
    //cout << "force : " << frc << endl;
	vel = vel + frc;
    ofVec2f tempPos = *posPoint;
    
	tempPos = tempPos + vel;
    *posPoint = tempPos;
    
    //cout << "vel x: " << vel.x << " vel y: " << vel.y << endl;
    
}

//------------------------------------------------------------
void particle::draw(){
    ofCircle(posPoint->x, posPoint->y, 2);
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (posPoint->x > maxx){
		posPoint->x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (posPoint->x < minx){
		posPoint->x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (posPoint->y > maxy){
		posPoint->y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (posPoint->y < miny){
		posPoint->y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}

//-------------------------------------------------------------

void particle::addRepulsionForce( float px, float py, float radius, float strength){
	
	
	ofVec2f posOfForce;
	posOfForce.set(px, py);
	
	ofVec2f diff = *posPoint - posOfForce;
	
	if (diff.length() < radius){
       
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x += diff.x * pct * strength;
		frc.y += diff.y * pct * strength;
	}
	
}

//------------------------------------------------------------
void particle::addAttractionForce( float px, float py, float radius, float strength){
	
	
	ofVec2f posOfForce;
	posOfForce.set(px, py);
	
	ofVec2f diff = *posPoint - posOfForce;
	//cout << "diff: " << diff.length() << " radius: " << radius << endl;
	if (diff.length() < radius){
         //cout << "HAPPENNING" << endl;
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x -= diff.x * pct * strength;
		frc.y -= diff.y * pct * strength;
	}
	
}


