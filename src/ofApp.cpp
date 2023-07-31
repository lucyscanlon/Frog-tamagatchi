#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
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
    
    hungerStatusBarHeight = 380;
    cleanlinessStatusBarHeight = 380;
    loveStatusBarHeight = 380;

    lifespanBarLength = 0;
    
    isTadpoleDead = false;
    
    daysLived = 0;
   
    stageOfGame = 3;
    
    openingScreenBackground.load("openingscreenbackground2.jpg");
    
    gameFrog.setPosition(380, 250);
    
    // set up the positioning of the tadpole using the class
    gameTadpole.setPosition(650, 500);
    gameGlass.setPosition(540, 280);
    
    gameFrog.setPosition(200, 200);
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if (stageOfGame == 1) {
        if(isTadpoleDead == false) {
            gameTadpole.update();
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
    
    // if the game is at stage one, display the tadpole game
    if (stageOfGame == 0) {
        ofSetColor(255);
        openingScreenBackground.draw(0, 0, ofGetWidth(), ofGetHeight());
        drawOpenScreenOfGame();
    } else if (stageOfGame == 1) {
        calculateStatusBarHeight();
        
        // if the tadpole is alive
        if(isTadpoleDead == false) {
            drawStatusBars();
        } else {
            // if the tadpole is dead
            drawDeadText();
        }
        
        // draw life span bar
        drawLifeSpanBar();
        
        // set the values and draw the tadpole
        gameTadpole.determineTadpoleDead(isTadpoleDead);
        gameTadpole.determineLoveStatusBarHeight(loveStatusBarHeight);
        gameTadpole.determineColoursOfTadpole(hungerStatusBarHeight);
        gameTadpole.draw();
        
        // set the values and draw the waterglass
        gameGlass.determineCleanlinessLevel(cleanlinessStatusBarHeight);
        gameGlass.draw();
        
    
    } else if (stageOfGame == 3) {
        ofPushMatrix();
        ofScale(1.5);
        gameFrog.draw();
        ofPopMatrix();
    }
    
   
 

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    cout << key << endl;
    if(stageOfGame == 0) {
        if(key == 13) {
            stageOfGame = 1;
        }
        
    } else if (stageOfGame == 1) {
        if(isTadpoleDead == false) {
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
        if ((ofGetFrameNum() % 80) == 0) {
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
    
    
    smallestFont.drawString("Your tadpole lived for: ", 145, 480);
    smallerFont.drawString(numberOfDaysLived + " days", 200, 540);
}

void ofApp::drawOpenScreenOfGame() {
    ofSetColor(119, 144, 86, 200);
    secondFont.drawString("Welcome to Tadpole", 250, 190);
    secondFont.drawString("Tamagotchi", 360, 230);
    
    ofSetColor(53, 53, 53, 150);
    smallestFont.drawString("We need your help! The local pond has become", 270, 300);
    smallestFont.drawString("overgrown with tadpoles. We are giving a tadpole", 235, 325);
    smallestFont.drawString("to each person in town to look after. Once they grow", 230, 350);
    smallestFont.drawString("and become frogs they can be transported to the", 255, 375);
    smallestFont.drawString("new pond across town.", 390, 400);
    
    smallestFont.drawString("Tadpoles need lots of love and care to stay alive.", 250, 455);
    smallestFont.drawString("They also need to be fed and their water needs", 270, 480);
    smallestFont.drawString("to be clean. Best of luck!", 370, 505);
    
    ofSetColor(119, 144, 86, 200);
    smallerFont.drawString("Press enter to start", 305, 600);
}


