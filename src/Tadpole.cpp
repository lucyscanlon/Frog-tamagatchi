//
//  Tadpole.cpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 31/07/2023.
//

#include "Tadpole.hpp"

Tadpole::Tadpole(){
    
   
    
}

Tadpole::~Tadpole() {
    // Nothing to do here - destroy
}

void Tadpole::setPosition(float x, float y) {
    tadPoleOriginX = x;
    tadPoleOriginY = y;
    
}

void Tadpole::update(){
    
    if (tailAnimationReversed == true) {
        tailAnimationStageClass = tailAnimationStageClass - 2;
        tadPoleOriginY = tadPoleOriginY - 0.09;
    } else if (tailAnimationReversed == false) {
        tailAnimationStageClass = tailAnimationStageClass + 2;
        tadPoleOriginY = tadPoleOriginY + 0.09;
    }
    
    
    // reverses the tadpole tail animation
    if (tailAnimationStageClass == 450) {
        tailAnimationReversed = true;
    } else if (tailAnimationStageClass == 50) {
        tailAnimationReversed = false;
        
    }
    
}

void Tadpole::setState(float state) {
    
}

void Tadpole::determineTadpoleDead(bool tadpoledeadornot) {
    tadpoleDead = tadpoledeadornot;
}

void Tadpole::determineLoveStatusBarHeight(float loveStatus) {
    tadpoleLoveBarStatus = loveStatus;
}


void Tadpole::determineColoursOfTadpole(float hungerStatus) {
    
    tadpoleHungerBarStatus = hungerStatus;
    
    tadpoleDarkGreen.r = 138;
    tadpoleDarkGreen.g = 191;
    tadpoleDarkGreen.b = 73;
    
    tadpoleLightGreen.r = 172;
    tadpoleLightGreen.g = 211;
    tadpoleLightGreen.b = 148;
    
    // this changes the alpha channel of the colour based on the hunger level
    if((tadpoleHungerBarStatus < 420) && (tadpoleHungerBarStatus > 286)) {
        tadpoleDarkGreen.a = 255;
    } else if ((tadpoleHungerBarStatus < 286) && (tadpoleHungerBarStatus > 210)) {
        tadpoleDarkGreen.a = 180;
    } else if ((tadpoleHungerBarStatus < 210) && (tadpoleHungerBarStatus > 96)) {
        tadpoleDarkGreen.a = 120;
    } else if ((tadpoleHungerBarStatus < 96) && (tadpoleHungerBarStatus > 10)) {
        tadpoleDarkGreen.a = 80;
    }
    
    // this changes the alpha channel of the colour based on the hunger level
    if((tadpoleHungerBarStatus < 420) && (tadpoleHungerBarStatus > 286)) {
        tadpoleLightGreen.a = 255;
    } else if ((tadpoleHungerBarStatus < 286) && (tadpoleHungerBarStatus > 210)) {
        tadpoleLightGreen.a = 180;
    } else if ((tadpoleHungerBarStatus < 210) && (tadpoleHungerBarStatus > 96)) {
        tadpoleLightGreen.a = 120;
    } else if ((tadpoleHungerBarStatus < 96) && (tadpoleHungerBarStatus > 10)) {
        tadpoleLightGreen.a = 80;
    }
}

void Tadpole::draw(){
    
    //ofSetColor(tadpoleDarkColour);
    // draw tadpoles body
    ofSetColor(tadpoleDarkGreen);
    ofDrawRectangle(tadPoleOriginX, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX - 20, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX + 20, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX + 40, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX - 40, tadPoleOriginY - 40, 20, 80);
    ofDrawRectangle(tadPoleOriginX + 60, tadPoleOriginY - 40, 20, 80);
    
    
    
    // tadpole face
    // changes depending on the love status
    // display the face for love status of 8-7
    
    if(tadpoleDead == false) {
        if ((tadpoleLoveBarStatus < 400) && (tadpoleLoveBarStatus > 286)) {
            ofSetColor(72, 72, 72);
            ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 30,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 10,tadPoleOriginY + 20, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 5,tadPoleOriginY + 20, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY + 12, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 25,tadPoleOriginY + 12, 15, 15);
            
            // blush of the cheeks
            ofSetColor(251, 145, 147);
            ofDrawRectangle(tadPoleOriginX + 35,tadPoleOriginY - 5, 12, 12);
            ofDrawRectangle(tadPoleOriginX - 35,tadPoleOriginY - 5, 12, 12);
            
            // white glint in the eye
            ofSetColor(255, 255, 255, 200);
            ofDrawRectangle(tadPoleOriginX + 22,tadPoleOriginY - 23, 5, 5);
            ofDrawRectangle(tadPoleOriginX - 28,tadPoleOriginY - 23, 5, 5);
            
        } else if ((tadpoleLoveBarStatus < 286) && (tadpoleLoveBarStatus > 210)) {
            // displays face of the tadpole when happy
            ofSetColor(72, 72, 72);
            ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 30,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 10,tadPoleOriginY + 20, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 5,tadPoleOriginY + 20, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY + 12, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 25,tadPoleOriginY + 12, 15, 15);
            
            // white glint in the eye
            ofSetColor(255, 255, 255, 200);
            ofDrawRectangle(tadPoleOriginX + 22,tadPoleOriginY - 23, 5, 5);
            ofDrawRectangle(tadPoleOriginX - 28,tadPoleOriginY - 23, 5, 5);
        } else if ((tadpoleLoveBarStatus < 210) && (tadpoleLoveBarStatus > 96)) {
            // displays the face when in normal state
            ofSetColor(72, 72, 72);
            ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 30,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 10,tadPoleOriginY + 20, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 5,tadPoleOriginY + 20, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 15,tadPoleOriginY + 20, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 20,tadPoleOriginY + 20, 15, 15);
            
            // white glint in the eye
            ofSetColor(255, 255, 255, 200);
            ofDrawRectangle(tadPoleOriginX + 22,tadPoleOriginY - 23, 5, 5);
            ofDrawRectangle(tadPoleOriginX - 28,tadPoleOriginY - 23, 5, 5);
        } else if ((tadpoleLoveBarStatus < 96) && (tadpoleLoveBarStatus > 0)) {
            // draw the tadpole if almost dead
            ofSetColor(72, 72, 72);
            ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 30,tadPoleOriginY - 25, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 10,tadPoleOriginY + 10, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 5,tadPoleOriginY + 10, 15, 15);
            ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY + 18, 15, 15);
            ofDrawRectangle(tadPoleOriginX - 25,tadPoleOriginY + 18, 15, 15);
            
            // white glint in the eye
            ofSetColor(255, 255, 255, 200);
            ofDrawRectangle(tadPoleOriginX + 22,tadPoleOriginY - 23, 5, 5);
            ofDrawRectangle(tadPoleOriginX - 28,tadPoleOriginY - 23, 5, 5);
        }
    } else {
        // draw the tadpoles face if its dead
        ofSetColor(72, 72, 72);
        // right eye - X eye
        ofDrawRectangle(tadPoleOriginX + 20, tadPoleOriginY - 20, 5, 5);
        ofDrawRectangle(tadPoleOriginX + 25, tadPoleOriginY - 25, 5, 5);
        ofDrawRectangle(tadPoleOriginX + 25, tadPoleOriginY - 15, 5, 5);
        ofDrawRectangle(tadPoleOriginX + 15, tadPoleOriginY - 25, 5, 5);
        ofDrawRectangle(tadPoleOriginX + 15, tadPoleOriginY - 15, 5, 5);
        
        // left eye - X eye
        ofDrawRectangle(tadPoleOriginX - 25, tadPoleOriginY - 20, 5, 5);
        ofDrawRectangle(tadPoleOriginX - 30, tadPoleOriginY - 25, 5, 5);
        ofDrawRectangle(tadPoleOriginX - 30, tadPoleOriginY - 15, 5, 5);
        ofDrawRectangle(tadPoleOriginX - 20, tadPoleOriginY - 25, 5, 5);
        ofDrawRectangle(tadPoleOriginX - 20, tadPoleOriginY - 15, 5, 5);
        
        ofDrawRectangle(tadPoleOriginX - 10,tadPoleOriginY + 10, 15, 15);
        ofDrawRectangle(tadPoleOriginX + 5,tadPoleOriginY + 10, 15, 15);
        ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY + 10, 15, 15);
        ofDrawRectangle(tadPoleOriginX - 25,tadPoleOriginY + 10, 15, 15);
        
    }
    
    
    
    // tail of tadpole
    
    if (tailAnimationStageClass < 100 ) {
        // stage one of tail
        // dark green colour of the tadpoles tail
        ofSetColor(tadpoleDarkGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY + 20, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY + 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY + 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY + 20, 20, 20);
    } else if ((tailAnimationStageClass > 100) && (tailAnimationStageClass < 200)) {
        // stage two of tail
        // dark green of tail
        ofSetColor(tadpoleDarkGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY + 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY, 20, 20);
    } else if ((tailAnimationStageClass > 200) && (tailAnimationStageClass < 300)) {
        // stage three of tail
        // dark green of tail
        ofSetColor(tadpoleDarkGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 20, 20, 20);
        
        // light green colour of tadpole
        ofSetColor(tadpoleLightGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY - 20, 20, 20);
    } else if ((tailAnimationStageClass > 300) && (tailAnimationStageClass < 400)) {
        // stage four of tail
        // dark green of tail
        ofSetColor(tadpoleDarkGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 40, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY -20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 60, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY - 40, 20, 20);
    } else if (tailAnimationStageClass > 400) {
        // stage five of tail
        // dark green of tail
        ofSetColor(tadpoleDarkGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 60, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightGreen);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 60, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 80, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY - 60, 20, 20);
    }
    
    
}
