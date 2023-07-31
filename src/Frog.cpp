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



void Frog::draw(){
    
    
    ofSetColor(76, 183, 76);
    ofDrawRectangle(frogXPos, frogYPos + 10, 40, 20);
    ofDrawRectangle(frogXPos + 90, frogYPos + 10, 40, 20);
    ofDrawRectangle(frogXPos, frogYPos + 30, 130, 10);
    ofDrawRectangle(frogXPos - 10, frogYPos + 40, 150, 10);
    ofDrawRectangle(frogXPos - 20, frogYPos + 50, 170, 50);
    ofDrawRectangle(frogXPos - 10, frogYPos + 100, 150, 10);
    ofDrawRectangle(frogXPos + 10, frogYPos + 120, 110, 40);
    ofDrawRectangle(frogXPos + 10, frogYPos + 150, 30, 30);
    ofDrawRectangle(frogXPos + 80, frogYPos + 150, 40, 30);
    ofDrawRectangle(frogXPos + 10, frogYPos + 160, 40, 30);
    ofDrawRectangle(frogXPos + 80, frogYPos + 160, 50, 30);
    ofDrawRectangle(frogXPos - 30, frogYPos + 180, 10, 10);
    ofDrawRectangle(frogXPos - 20, frogYPos + 150, 10, 40);
    ofDrawRectangle(frogXPos - 10, frogYPos + 150, 10, 40);
    ofDrawRectangle(frogXPos + 150, frogYPos + 180, 10, 10);
    ofDrawRectangle(frogXPos + 140, frogYPos + 150, 10, 40);
    ofDrawRectangle(frogXPos + 130, frogYPos + 150, 10, 40);
    
    
    ofSetColor(41);
    // dark outline of the frog
    ofDrawRectangle(frogXPos, frogYPos, 40, 10);
    ofDrawRectangle(frogXPos + 90, frogYPos, 40, 10);
    ofDrawRectangle(frogXPos - 10, frogYPos + 10, 10, 30);
    ofDrawRectangle(frogXPos + 40, frogYPos + 10, 10, 20);
    ofDrawRectangle(frogXPos + 50, frogYPos + 20, 30, 10);
    ofDrawRectangle(frogXPos + 80, frogYPos + 10, 10, 20);
    ofDrawRectangle(frogXPos + 130, frogYPos + 10, 10, 30);
    ofDrawRectangle(frogXPos - 20, frogYPos + 40, 10, 10);
    ofDrawRectangle(frogXPos + 140, frogYPos + 40, 10, 10);
    ofDrawRectangle(frogXPos - 30, frogYPos + 50, 10, 50);
    ofDrawRectangle(frogXPos + 150, frogYPos + 50, 10, 50);
    ofDrawRectangle(frogXPos - 20, frogYPos + 100, 10, 10);
    ofDrawRectangle(frogXPos + 140, frogYPos + 100, 10, 10);
    ofDrawRectangle(frogXPos - 10, frogYPos + 110, 150, 10);
    ofDrawRectangle(frogXPos, frogYPos + 120, 10, 70);
    ofDrawRectangle(frogXPos + 120, frogYPos + 120, 10, 70);
    ofDrawRectangle(frogXPos - 20, frogYPos + 140, 20, 10);
    ofDrawRectangle(frogXPos + 130, frogYPos + 140, 20, 10);
    ofDrawRectangle(frogXPos - 30, frogYPos + 150, 10, 30);
    ofDrawRectangle(frogXPos + 150, frogYPos + 150, 10, 30);
    ofDrawRectangle(frogXPos - 10, frogYPos + 160, 10, 10);
    ofDrawRectangle(frogXPos + 130, frogYPos + 160, 10, 10);
    ofDrawRectangle(frogXPos - 40, frogYPos + 180, 10, 20);
    ofDrawRectangle(frogXPos + 160, frogYPos + 180, 10, 20);
    ofDrawRectangle(frogXPos - 30, frogYPos + 190, 90, 10);
    ofDrawRectangle(frogXPos + 70, frogYPos + 190, 90, 10);
    ofDrawRectangle(frogXPos + 50, frogYPos + 180, 10, 10);
    ofDrawRectangle(frogXPos + 70, frogYPos + 180, 10, 10);
    ofDrawRectangle(frogXPos + 30, frogYPos + 170, 20, 10);
    ofDrawRectangle(frogXPos + 80, frogYPos + 170, 20, 10);
    ofDrawRectangle(frogXPos + 40, frogYPos + 160, 50, 10);
    ofDrawRectangle(frogXPos + 30, frogYPos + 150, 10, 10);
    ofDrawRectangle(frogXPos + 90, frogYPos + 150, 10, 10);
    
    ofDrawRectangle(frogXPos + 10, frogYPos + 20, 20, 20);
    ofDrawRectangle(frogXPos + 100, frogYPos + 20, 20, 20);
    ofDrawRectangle(frogXPos + 40, frogYPos + 50, 50, 10);
    ofDrawRectangle(frogXPos + 35, frogYPos + 45, 10, 10);
    ofDrawRectangle(frogXPos + 85, frogYPos + 45, 10, 10);
    
    ofSetColor(255);
    ofDrawRectangle(frogXPos + 10, frogYPos + 20, 10, 10);
    ofDrawRectangle(frogXPos + 100, frogYPos + 20, 10, 10);
    
    ofSetColor(255, 123, 137);
    ofDrawRectangle(frogXPos, frogYPos + 40, 20, 10);
    ofDrawRectangle(frogXPos + 110, frogYPos + 40, 20, 10);
    
    
    
    
    
    
}

