#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(244, 217, 191);
    
    // tadpole animation
    tadpoleAnimatedTailStage = 50;
    
    tailReverseAnimation = false;
    
    tadPoleOriginX = 650;
    tadPoleOriginY = 500;
    
    // load the font for the status bars
    secondFont.load("SecondFont.ttf", 30);
    
    // set the initial value of the variable which decreases the status bars
    statusBarHeight = -38;
    hungerStatusBarDecrease = -38;
    cleanlinessStatusBarDecrease = -38;
    loveStatusBarDecrease = -38;
    
    hungerPressed = 0;
    cleanlinessPressed = 0;
    lovePressed = 0;
    
   
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (tailReverseAnimation == true) {
        tadpoleAnimatedTailStage = tadpoleAnimatedTailStage - 2;
        tadPoleOriginY = tadPoleOriginY - 0.09;
    } else if (tailReverseAnimation == false) {
        tadpoleAnimatedTailStage = tadpoleAnimatedTailStage + 2;
        tadPoleOriginY = tadPoleOriginY + 0.09;
    }
    
    if (tadpoleAnimatedTailStage == 450) {
        tailReverseAnimation = true;
    } else if (tadpoleAnimatedTailStage == 50) {
        tailReverseAnimation = false;

    }
    
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Show mouse coordinates onto the screen
    string pixelCoords = "("+to_string(mouseX)+", "+to_string(mouseY)+")";
    ofSetColor(255,0,255);     // set text color
    ofDrawBitmapString(pixelCoords, mouseX, mouseY);
    
    calculateStatusBarHeight();
    drawTadpole();
    drawWaterGlass();
    drawStatusBars();
    
    //std::cout << tadpoleAnimatedTailStage  << std::endl;
    
    
 

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == '1') {
        hungerStatusBarDecrease = hungerStatusBarDecrease - 38;
        hungerPressed++;
    }
    
    if (key == '2') {
        cleanlinessStatusBarDecrease = cleanlinessStatusBarDecrease - 38;
        cleanlinessPressed++;
    }
    
    if(key == '3') {
        loveStatusBarDecrease = loveStatusBarDecrease - 38;
        lovePressed++;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

// class which draws the tadpole to the screen
void ofApp::drawTadpole() {
    
    // dark green colour of tadpole
    ofSetColor(138, 191, 73);
    ofDrawRectangle(tadPoleOriginX, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX - 20, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX + 20, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX + 40, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX - 40, tadPoleOriginY - 40, 20, 80);
    ofDrawRectangle(tadPoleOriginX + 60, tadPoleOriginY - 40, 20, 80);
    
    
    
    // tadpole face and eyes
    ofSetColor(72, 72, 72);
    ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY - 25, 15, 15);
    ofDrawRectangle(tadPoleOriginX - 30,tadPoleOriginY - 25, 15, 15);
    ofDrawRectangle(tadPoleOriginX - 10,tadPoleOriginY + 20, 15, 15);
    ofDrawRectangle(tadPoleOriginX + 5,tadPoleOriginY + 20, 15, 15);
    ofDrawRectangle(tadPoleOriginX + 20,tadPoleOriginY + 12, 15, 15);
    ofDrawRectangle(tadPoleOriginX - 25,tadPoleOriginY + 12, 15, 15);
    
    // tail of tadpole
    
    if (tadpoleAnimatedTailStage < 100 ) {
        // stage one of tail
        // dark green colour of the tadpoles tail
        ofSetColor(138, 191, 73);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY + 20, 20, 20);
        
        // light green colour of tadpole
        ofSetColor(172, 211, 148);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY + 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY + 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY + 20, 20, 20);
    } else if ((tadpoleAnimatedTailStage > 100) && (tadpoleAnimatedTailStage < 200)) {
        // stage two of tail
        // dark green of tail
        ofSetColor(138, 191, 73);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY, 20, 20);
        
        // light green colour of tadpole
        ofSetColor(172, 211, 148);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY + 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY, 20, 20);
    } else if ((tadpoleAnimatedTailStage > 200) && (tadpoleAnimatedTailStage < 300)) {
        // stage three of tail
        // dark green of tail
        ofSetColor(138, 191, 73);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 20, 20, 20);
        
        // light green colour of tadpole
        ofSetColor(172, 211, 148);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY - 20, 20, 20);
    } else if ((tadpoleAnimatedTailStage > 300) && (tadpoleAnimatedTailStage < 400)) {
        // stage four of tail
        // dark green of tail
        ofSetColor(138, 191, 73);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 40, 20, 20);
        
        // light green colour of tadpole
        ofSetColor(172, 211, 148);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY -20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 60, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY - 40, 20, 20);
    } else if (tadpoleAnimatedTailStage > 400) {
        // stage five of tail
        // dark green of tail
        ofSetColor(138, 191, 73);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 60, 20, 20);
        
        // light green colour of tadpole
        ofSetColor(172, 211, 148);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 60, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 40, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 80, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 160, tadPoleOriginY - 60, 20, 20);
    }
    
}

void ofApp::drawWaterGlass() {
    waterGlassOriginX = 540;
    waterGlassOriginY = 280;
    
    // water in the water glass
    ofSetColor(82, 212, 255, 70);
    ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
    
    // outline of the water glass
    ofSetColor(129, 62, 1, 60);
    ofDrawRectangle(waterGlassOriginX - 10, waterGlassOriginY - 40, 10, 390);
    ofDrawRectangle(waterGlassOriginX - 10, waterGlassOriginY + 350, 370, 10);
    ofDrawRectangle(waterGlassOriginX + 350, waterGlassOriginY - 40, 10, 390);
    
    // water reflections on the water glass
    ofSetColor(255, 255, 255, 200);
    ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
    ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
}

void ofApp::drawStatusBars() {
    statusBarsOriginX = 138;
    statusBarsOriginY = 250;
    
    // draw the status bar colours
    ofSetColor(175, 159, 255, 100);
    ofDrawRectangle(statusBarsOriginX, statusBarsOriginY + 380, 60, (- 380 + hungerStatusBarDecrease));
    
    ofSetColor(126, 197, 134, 100);
    ofDrawRectangle(statusBarsOriginX + 110, statusBarsOriginY + 380, 60, (- 380 + cleanlinessStatusBarDecrease));
    
    ofSetColor(255, 154, 203, 100);
    ofDrawRectangle(statusBarsOriginX + 220, statusBarsOriginY + 380, 60, (- 380 + loveStatusBarDecrease));
    
    // draw the status bar outline
    ofSetColor(129, 62, 1, 60);
    ofDrawRectangle(statusBarsOriginX, statusBarsOriginY - 10, 60, 10);
    ofDrawRectangle(statusBarsOriginX, statusBarsOriginY + 380, 60, 10);
    ofDrawRectangle(statusBarsOriginX - 10, statusBarsOriginY - 10, 10, 400);
    ofDrawRectangle(statusBarsOriginX + 60, statusBarsOriginY - 10, 10, 400);
    
    ofDrawRectangle(statusBarsOriginX + 110, statusBarsOriginY - 10, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 110, statusBarsOriginY + 380, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 100, statusBarsOriginY - 10, 10, 400);
    ofDrawRectangle(statusBarsOriginX + 170, statusBarsOriginY - 10, 10, 400);
    
    ofDrawRectangle(statusBarsOriginX + 220, statusBarsOriginY - 10, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 220, statusBarsOriginY + 380, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 210, statusBarsOriginY - 10, 10, 400);
    ofDrawRectangle(statusBarsOriginX + 280, statusBarsOriginY - 10, 10, 400);
    
    
    // draw the text labels for the status bars
    ofSetColor(175, 159, 255);
    ofPushMatrix();
    ofTranslate(182, 616);
    ofRotateZ(270);
    secondFont.drawString("Hunger", 0, 0);
    ofPopMatrix();
    
    ofSetColor(126, 197, 134);
    ofPushMatrix();
    ofTranslate(292, 616);
    ofRotateZ(270);
    secondFont.drawString("Cleaniness", 0, 0);
    ofPopMatrix();
    
    ofSetColor(225, 137, 180);
    ofPushMatrix();
    ofTranslate(402, 616);
    ofRotateZ(270);
    secondFont.drawString("Love", 0, 0);
    ofPopMatrix();
}

void ofApp::calculateStatusBarHeight() {
    
    if ((ofGetFrameNum() % 300) == 0) {
        if (statusBarHeight < (380 + (hungerPressed * 38))) {
            hungerStatusBarDecrease = hungerStatusBarDecrease + 38;
        }
        
        if (statusBarHeight < (380 + (cleanlinessPressed * 38))) {
            cleanlinessStatusBarDecrease = cleanlinessStatusBarDecrease + 38;
        }
        
        if (statusBarHeight < (380 + (lovePressed * 38))) {
            loveStatusBarDecrease = loveStatusBarDecrease + 38;
        }
        
        statusBarHeight = statusBarHeight + 38;
    }
}
