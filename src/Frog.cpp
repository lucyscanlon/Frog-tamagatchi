//
//  Frog.cpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 31/07/2023.
//

#include "Frog.hpp"

Frog::Frog(){
    
   
    
}

Frog::~Frog() {
    // Nothing to do here - destroy
}

void Frog::setPosition(float x, float y) {
    frogXPos = x;
    frogYPos = y;
    
}

void Frog::update(){
    
}

void Frog::setState(float state) {
    frogState = state;
}

void Frog::draw(){
    
    if(frogState == 1) {
        ofSetColor(0);
        ofDrawRectangle(frogXPos, frogYPos, 100, 100);
    } else if (frogState == 2 ) {
        ofSetColor(255);
        ofDrawRectangle(frogXPos, frogYPos, 100, 100);
    }
    
    
}

