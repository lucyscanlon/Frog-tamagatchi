#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    
    // tadpole animation
    tadpoleAnimatedTailStage = 50;
    
    tailReverseAnimation = false;
    
    tadPoleOriginX = 650;
    tadPoleOriginY = 500;
    
    // load the font for the status bars
    secondFont.load("SecondFont.ttf", 30);
    smallerFont.load("SecondFont.ttf", 24);
    smallestFont.load("SecondFont.ttf", 12);
    
    // set the initial value of the variable which decreases the status bars
    statusBarHeight = -38;
    hungerStatusBarDecrease = -38;
    cleanlinessStatusBarDecrease = -38;
    loveStatusBarDecrease = -38;
    
    hungerPressed = 0;
    cleanlinessPressed = 0;
    lovePressed = 0;
    
    hungerStatusBarHeight = 418;
    cleanlinessStatusBarHeight = 418;
    loveStatusBarHeight = 418;

    lifespanBarLength = 0;
    
    isTadpoleDead = true;
    
    daysLived = 0;
   
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(isTadpoleDead == false) {
        // animates the tadpole tale
        if (tailReverseAnimation == true) {
            tadpoleAnimatedTailStage = tadpoleAnimatedTailStage - 2;
            tadPoleOriginY = tadPoleOriginY - 0.09;
        } else if (tailReverseAnimation == false) {
            tadpoleAnimatedTailStage = tadpoleAnimatedTailStage + 2;
            tadPoleOriginY = tadPoleOriginY + 0.09;
        }
        
        
        // reverses the tadpole tail animation
        if (tadpoleAnimatedTailStage == 450) {
            tailReverseAnimation = true;
        } else if (tadpoleAnimatedTailStage == 50) {
            tailReverseAnimation = false;
            
        }
    }
    
    
    // increase the lifespan bar as time increases
    if (isTadpoleDead == false) {
        if (lifespanBarLength < 600) {
           if ((ofGetFrameNum() % 100) == 0) {
               lifespanBarLength = lifespanBarLength + 20;
               daysLived = lifespanBarLength / 20;
           }
       }
    }
     
    
    checkifTadpoleIsDead();
    
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(244, 217, 191);
    
    // if the stats get too low add a red overlay to the screen to warn the player
    if ((hungerStatusBarHeight < 114) || (cleanlinessStatusBarHeight < 114) || (loveStatusBarHeight < 114)) {
        ofSetColor(255, 104, 104, 20);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    // make the red screen even darker when one point away from end of game
    if ((hungerStatusBarHeight < 76) || (cleanlinessStatusBarHeight < 76) || (loveStatusBarHeight < 76)) {
        ofSetColor(255, 104, 104, 30);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    // Show mouse coordinates onto the screen
    string pixelCoords = "("+to_string(mouseX)+", "+to_string(mouseY)+")";
    ofSetColor(255,0,255);     // set text color
    ofDrawBitmapString(pixelCoords, mouseX, mouseY);
    
    calculateStatusBarHeight();
    
    // if the tadpole is alive
    if(isTadpoleDead == false) {
        drawStatusBars();
    } else {
        // if the tadpole is dead
        drawDeadText();
    }
    
    drawLifeSpanBar();
    drawTadpole();
    drawWaterGlass();
    

    
    cout << isTadpoleDead << endl;
    cout << hungerStatusBarHeight << endl;
 

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == '1') {
        hungerStatusBarDecrease = hungerStatusBarDecrease - 38;
        if (hungerStatusBarHeight < 380) {
            hungerPressed++;
            hungerStatusBarHeight = hungerStatusBarHeight + 38;
        }
    }
    
    if (key == '2') {
        cleanlinessStatusBarDecrease = cleanlinessStatusBarDecrease - 38;
        if (cleanlinessStatusBarHeight < 380) {
            cleanlinessPressed++;
            cleanlinessStatusBarHeight = cleanlinessStatusBarHeight + 38;
        }
    }
    
    if(key == '3') {
        loveStatusBarDecrease = loveStatusBarDecrease - 38;
        if (loveStatusBarHeight < 380) {
            lovePressed++;
            loveStatusBarHeight = loveStatusBarHeight + 38;
        }
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
    
    determineTadpoleColourFromHunger();
    // dark green colour of tadpole
    // fade the tadpole away if its hungry
    
    ofSetColor(tadpoleDarkColour);
    // draw tadpoles body
    ofDrawRectangle(tadPoleOriginX, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX - 20, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX + 20, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX + 40, tadPoleOriginY - 60, 20, 120);
    ofDrawRectangle(tadPoleOriginX - 40, tadPoleOriginY - 40, 20, 80);
    ofDrawRectangle(tadPoleOriginX + 60, tadPoleOriginY - 40, 20, 80);
    
    
    
    // tadpole face
    // changes depending on the love status
    // display the face for love status of 8-7
    
    if(isTadpoleDead == false) {
        if ((loveStatusBarHeight < 400) && (loveStatusBarHeight > 286)) {
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
            
        } else if ((loveStatusBarHeight < 286) && (loveStatusBarHeight > 210)) {
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
        } else if ((loveStatusBarHeight < 210) && (loveStatusBarHeight > 96)) {
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
        } else if ((loveStatusBarHeight < 96) && (loveStatusBarHeight > 0)) {
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
    
    if (tadpoleAnimatedTailStage < 100 ) {
        // stage one of tail
        // dark green colour of the tadpoles tail
        ofSetColor(tadpoleDarkColour);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY + 20, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightColour);
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
        ofSetColor(tadpoleDarkColour);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightColour);
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
        ofSetColor(tadpoleDarkColour);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 20, 20, 20);
        
        // light green colour of tadpole
        ofSetColor(tadpoleLightColour);
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
        ofSetColor(tadpoleDarkColour);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 20, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 40, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightColour);
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
        ofSetColor(tadpoleDarkColour);
        ofDrawRectangle(tadPoleOriginX + 80, tadPoleOriginY - 20, 20, 20);
        ofDrawRectangle(tadPoleOriginX + 100, tadPoleOriginY - 40, 40, 20);
        ofDrawRectangle(tadPoleOriginX + 140, tadPoleOriginY - 60, 20, 20);
        
        // light green colour of tadpole
        // light green colour of tadpole
        ofSetColor(tadpoleLightColour);
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
    
    if ((cleanlinessStatusBarHeight < 400) && (cleanlinessStatusBarHeight > 286)) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
        
        // sparkles
        ofSetColor(255);
        ofDrawRectangle(waterGlassOriginX + 100, waterGlassOriginY + 100, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 80, waterGlassOriginY + 100, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 93, waterGlassOriginY + 106, 6, 12);
        ofDrawRectangle(waterGlassOriginX + 93, waterGlassOriginY + 87 , 6, 12);
        
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 300, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 280, waterGlassOriginY + 300, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 293, waterGlassOriginY + 306, 6, 12);
        ofDrawRectangle(waterGlassOriginX + 293, waterGlassOriginY + 287 , 6, 12);
    } else if ((cleanlinessStatusBarHeight < 286) && (cleanlinessStatusBarHeight > 210)) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
    } else if ((cleanlinessStatusBarHeight < 210) && (cleanlinessStatusBarHeight > 96)) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        ofSetColor(165, 126, 15, 30);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
    } else if (cleanlinessStatusBarHeight < 96) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        ofSetColor(165, 126, 15, 80);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
    }
    
    // outline of the water glass
    ofSetColor(129, 62, 1, 60);
    ofDrawRectangle(waterGlassOriginX - 10, waterGlassOriginY - 40, 10, 390);
    ofDrawRectangle(waterGlassOriginX - 10, waterGlassOriginY + 350, 370, 10);
    ofDrawRectangle(waterGlassOriginX + 350, waterGlassOriginY - 40, 10, 390);
    
}

void ofApp::drawStatusBars() {
    statusBarsOriginX = 138;
    statusBarsOriginY = 250;
    
    // draw the status bar colours
    ofSetColor(175, 159, 255, 100);
    ofDrawRectangle(statusBarsOriginX, statusBarsOriginY + 380, 60, - hungerStatusBarHeight);
    
    ofSetColor(126, 197, 134, 100);
    ofDrawRectangle(statusBarsOriginX + 110, statusBarsOriginY + 380, 60, - cleanlinessStatusBarHeight);
    
    ofSetColor(255, 154, 203, 100);
    ofDrawRectangle(statusBarsOriginX + 220, statusBarsOriginY + 380, 60, - loveStatusBarHeight);
    
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
    
    // uses modulo to decrease the status bars over time
    if(isTadpoleDead == false) {
        if ((ofGetFrameNum() % 100) == 0) {
            // this makes sure the bars stop decreasing once they hit zero. it also uses
            // the amount the user has pressed the button to increase the stautus bar.
            if (statusBarHeight < (380 + (hungerPressed * 38))) {
                // decreases by 10% each time
                hungerStatusBarDecrease = hungerStatusBarDecrease + 38;
                hungerStatusBarHeight = hungerStatusBarHeight - 38;
            }
            
            if (statusBarHeight < (380 + (cleanlinessPressed * 38))) {
                cleanlinessStatusBarDecrease = cleanlinessStatusBarDecrease + 38;
                cleanlinessStatusBarHeight = cleanlinessStatusBarHeight - 38;
            }
            
            if (statusBarHeight < (380 + (lovePressed * 38))) {
                loveStatusBarDecrease = loveStatusBarDecrease + 38;
                loveStatusBarHeight = loveStatusBarHeight - 38;
            }
            
            statusBarHeight = statusBarHeight + 38;
        }
    }
    
}

void ofApp::determineTadpoleColourFromHunger() {
    
    // fade out the colour of the tadpole as it gets hungry
    // set the rgb values of each colour as this wont be changed by the hunger level decreasing
    tadpoleDarkColour.r = 138;
    tadpoleDarkColour.g = 191;
    tadpoleDarkColour.b = 73;
    
    tadpoleLightColour.r = 172;
    tadpoleLightColour.g = 211;
    tadpoleLightColour.b = 148;
    
    // this changes the alpha channel of the colour based on the hunger level
    if((hungerStatusBarHeight < 420) && (hungerStatusBarHeight > 286)) {
        tadpoleDarkColour.a = 255;
    } else if ((hungerStatusBarHeight < 286) && (hungerStatusBarHeight > 210)) {
        tadpoleDarkColour.a = 180;
    } else if ((hungerStatusBarHeight < 210) && (hungerStatusBarHeight > 96)) {
        tadpoleDarkColour.a = 120;
    } else if ((hungerStatusBarHeight < 96) && (hungerStatusBarHeight > 10)) {
        tadpoleDarkColour.a = 80;
    }
    
    // this changes the alpha channel of the colour based on the hunger level
    if((hungerStatusBarHeight < 420) && (hungerStatusBarHeight > 286)) {
        tadpoleLightColour.a = 255;
    } else if ((hungerStatusBarHeight < 286) && (hungerStatusBarHeight > 210)) {
        tadpoleLightColour.a = 180;
    } else if ((hungerStatusBarHeight < 210) && (hungerStatusBarHeight > 96)) {
        tadpoleLightColour.a = 120;
    } else if ((hungerStatusBarHeight < 96) && (hungerStatusBarHeight > 10)) {
        tadpoleLightColour.a = 80;
    }
    
    
}

void ofApp::drawLifeSpanBar() {
    // the function to draw the lifespan of the tadpole/frog
    ofSetColor(255, 239, 160, 150);
    ofDrawRectangle(190, 80, lifespanBarLength, 60);
    
    // draw the border around the life span bar
    ofSetColor(129, 62, 1, 60);
    ofDrawRectangle(190, 70, 600, 10);
    ofDrawRectangle(190, 140, 600, 10);
    ofDrawRectangle(180, 70, 10, 80);
    ofDrawRectangle(790, 70, 10, 80);
    
    ofSetColor(224, 179, 141);
    secondFont.drawString("Lifespan", 205, 125);
    
}

void ofApp::checkifTadpoleIsDead() {
    if (cleanlinessStatusBarHeight == 0) {
        isTadpoleDead = true;
    }
    
    if (hungerStatusBarHeight == 0) {
        isTadpoleDead = true;
    }
    
    if (loveStatusBarHeight == 0) {
        isTadpoleDead = true;
    }
}

void ofApp::drawDeadText() {
    
    // convert the number of days lived, which is determined from the length
    // of the lifespan bar, to a string so it can be displayed
    string numberOfDaysLived = to_string(daysLived);
    ofSetColor(53, 53, 53, 200);
    smallerFont.drawString("Game over", 160, 310);
    
    smallestFont.drawString("Unfortunately you didn't look after", 90, 350);
    smallestFont.drawString("your tadpole well enough", 135, 375);
    smallestFont.drawString("and it has died", 190, 400);
    
    
    smallestFont.drawString("Your tadpole lived for: ", 155, 480);
    smallerFont.drawString(numberOfDaysLived + " days", 200, 540);
}
