//
//  Pond.cpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 03/08/2023.
//

#include "Pond.hpp"

Pond::Pond(){
    
   
    
}

Pond::~Pond() {
    // Nothing to do here - destroy
}

void Pond::setPosition(float x, float y) {
    pondXPos = x;
    pondYPos = y;
    
}

void Pond::update(){
    
}



void Pond::draw(){
    
    // brown outline
    ofSetColor(165, 134, 111);
    ofDrawRectangle(pondXPos - 10, pondYPos - 10, 220, 10);
    ofDrawRectangle(pondXPos - 60, pondYPos, 320, 10);
    ofDrawRectangle(pondXPos - 100, pondYPos + 10, 400, 10);
    ofDrawRectangle(pondXPos - 140, pondYPos + 20, 480, 10);
    ofDrawRectangle(pondXPos - 170, pondYPos + 30, 540, 10);
    ofDrawRectangle(pondXPos - 190, pondYPos + 40, 580, 10);
    ofDrawRectangle(pondXPos - 200, pondYPos + 50, 600, 10);
    
    // light blue colour of the pond
    ofSetColor(121, 168, 180);
    ofDrawRectangle(pondXPos, pondYPos, 200, 10);
    ofDrawRectangle(pondXPos - 40, pondYPos + 10, 280, 10);
    ofDrawRectangle(pondXPos - 80, pondYPos + 20, 360, 10);
    ofDrawRectangle(pondXPos - 120, pondYPos + 30, 440, 10);
    ofDrawRectangle(pondXPos - 160, pondYPos + 40, 520, 10);
    ofDrawRectangle(pondXPos - 180, pondYPos + 50, 560, 10);
    ofDrawRectangle(pondXPos - 200, pondYPos + 60, 600, 30); //
    ofDrawRectangle(pondXPos - 180, pondYPos + 90, 560, 10);
    ofDrawRectangle(pondXPos - 160, pondYPos + 100, 520, 10);
    ofDrawRectangle(pondXPos - 120, pondYPos + 110, 440, 10);
    ofDrawRectangle(pondXPos - 80, pondYPos + 120, 360, 10);
    ofDrawRectangle(pondXPos - 40, pondYPos + 130, 280, 10);
    
    // dark blue colour of the pond
    ofSetColor(98, 133, 156);
    ofDrawRectangle(pondXPos, pondYPos, 200, 10);
    ofDrawRectangle(pondXPos - 40, pondYPos + 10, 170, 10);
    ofDrawRectangle(pondXPos - 80, pondYPos + 20, 130, 10);
    ofDrawRectangle(pondXPos - 120, pondYPos + 30, 90, 10);
    ofDrawRectangle(pondXPos - 160, pondYPos + 40, 80, 10);
    ofDrawRectangle(pondXPos - 180, pondYPos + 50, 70, 10);
    ofDrawRectangle(pondXPos - 200, pondYPos + 60, 50, 10);
    ofDrawRectangle(pondXPos - 200, pondYPos + 70, 40, 10);
    ofDrawRectangle(pondXPos - 200, pondYPos + 80, 30, 10);
    ofDrawRectangle(pondXPos - 180, pondYPos + 90, 20, 10);
    ofDrawRectangle(pondXPos - 160, pondYPos + 100, 10, 10);
    
    // lily pad shadow
    ofDrawRectangle(pondXPos + 220, pondYPos + 70, 50, 10);
    ofDrawRectangle(pondXPos + 200, pondYPos + 80, 90, 10);
    ofDrawRectangle(pondXPos + 190, pondYPos + 90, 110, 10);
    ofDrawRectangle(pondXPos + 220, pondYPos + 110, 50, 10);
    ofDrawRectangle(pondXPos + 200, pondYPos + 100, 90, 10);
    
    ofDrawRectangle(pondXPos + 180, pondYPos + 50, 50, 10);
    ofDrawRectangle(pondXPos + 160, pondYPos + 60, 90, 10);
    ofDrawRectangle(pondXPos + 150, pondYPos + 70, 110, 10);
    ofDrawRectangle(pondXPos + 180, pondYPos + 90, 50, 10);
    ofDrawRectangle(pondXPos + 160, pondYPos + 80, 90, 10);
    
    
    // darker green lily pads
    ofSetColor(125, 179, 132);
    ofDrawRectangle(pondXPos + 220, pondYPos + 60, 50, 10);
    ofDrawRectangle(pondXPos + 200, pondYPos + 70, 90, 10);
    ofDrawRectangle(pondXPos + 190, pondYPos + 80, 110, 10);
    ofDrawRectangle(pondXPos + 220, pondYPos + 100, 50, 10);
    ofDrawRectangle(pondXPos + 200, pondYPos + 90, 90, 10);
    
    // green lily pads
    ofSetColor(148, 193, 139);
    ofDrawRectangle(pondXPos + 180, pondYPos + 40, 50, 10);
    ofDrawRectangle(pondXPos + 160, pondYPos + 50, 90, 10);
    ofDrawRectangle(pondXPos + 150, pondYPos + 60, 110, 10);
    ofDrawRectangle(pondXPos + 180, pondYPos + 80, 50, 10);
    ofDrawRectangle(pondXPos + 160, pondYPos + 70, 90, 10);
    
    
    
    
}
