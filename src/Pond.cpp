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
    pondXPos = y;
    
}

void Pond::update(){
    
}



void Pond::draw(){
    
    // brown outline
    ofSetColor(165, 134, 111);
    ofDrawRectangle(pondXPos - 10, pondXPos - 10, 220, 10);
    ofDrawRectangle(pondXPos - 60, pondXPos, 320, 10);
    ofDrawRectangle(pondXPos - 100, pondXPos + 10, 400, 10);
    ofDrawRectangle(pondXPos - 140, pondXPos + 20, 480, 10);
    ofDrawRectangle(pondXPos - 170, pondXPos + 30, 540, 10);
    ofDrawRectangle(pondXPos - 190, pondXPos + 40, 580, 10);
    ofDrawRectangle(pondXPos - 200, pondXPos + 50, 600, 10);
    
    // light blue colour of the pond
    ofSetColor(121, 168, 180);
    ofDrawRectangle(pondXPos, pondXPos, 200, 10);
    ofDrawRectangle(pondXPos - 40, pondXPos + 10, 280, 10);
    ofDrawRectangle(pondXPos - 80, pondXPos + 20, 360, 10);
    ofDrawRectangle(pondXPos - 120, pondXPos + 30, 440, 10);
    ofDrawRectangle(pondXPos - 160, pondXPos + 40, 520, 10);
    ofDrawRectangle(pondXPos - 180, pondXPos + 50, 560, 10);
    ofDrawRectangle(pondXPos - 200, pondXPos + 60, 600, 30); //
    ofDrawRectangle(pondXPos - 180, pondXPos + 90, 560, 10);
    ofDrawRectangle(pondXPos - 160, pondXPos + 100, 520, 10);
    ofDrawRectangle(pondXPos - 120, pondXPos + 110, 440, 10);
    ofDrawRectangle(pondXPos - 80, pondXPos + 120, 360, 10);
    ofDrawRectangle(pondXPos - 40, pondXPos + 130, 280, 10);
    
    // dark blue colour of the pond
    ofSetColor(98, 133, 156);
    ofDrawRectangle(pondXPos, pondXPos, 200, 10);
    ofDrawRectangle(pondXPos - 40, pondXPos + 10, 170, 10);
    ofDrawRectangle(pondXPos - 80, pondXPos + 20, 130, 10);
    ofDrawRectangle(pondXPos - 120, pondXPos + 30, 90, 10);
    ofDrawRectangle(pondXPos - 160, pondXPos + 40, 80, 10);
    ofDrawRectangle(pondXPos - 180, pondXPos + 50, 70, 10);
    ofDrawRectangle(pondXPos - 200, pondXPos + 60, 50, 10);
    ofDrawRectangle(pondXPos - 200, pondXPos + 70, 40, 10);
    ofDrawRectangle(pondXPos - 200, pondXPos + 80, 30, 10);
    ofDrawRectangle(pondXPos - 180, pondXPos + 90, 20, 10);
    ofDrawRectangle(pondXPos - 160, pondXPos + 100, 10, 10);
    
    // darker green lily pads
    ofSetColor(125, 179, 132);
    ofDrawRectangle(pondXPos + 220, pondXPos + 60, 50, 10);
    ofDrawRectangle(pondXPos + 200, pondXPos + 70, 90, 10);
    ofDrawRectangle(pondXPos + 190, pondXPos + 80, 110, 10);
    ofDrawRectangle(pondXPos + 220, pondXPos + 100, 50, 10);
    ofDrawRectangle(pondXPos + 200, pondXPos + 90, 90, 10);
    
    // green lily pads
    ofSetColor(148, 193, 139);
    ofDrawRectangle(pondXPos + 180, pondXPos + 40, 50, 10);
    ofDrawRectangle(pondXPos + 160, pondXPos + 50, 90, 10);
    ofDrawRectangle(pondXPos + 150, pondXPos + 60, 110, 10);
    ofDrawRectangle(pondXPos + 180, pondXPos + 80, 50, 10);
    ofDrawRectangle(pondXPos + 160, pondXPos + 70, 90, 10);
    
    
    
    
}
